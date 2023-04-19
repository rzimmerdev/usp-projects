import random
import numpy as np
import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt


def compare_sign(effective, received):
    for sign in received:
        if not effective.get(sign):
            continue
        if effective[sign][-1] != received[sign][-1]:
            return False
    return True


class SimulateEpidemic:
    def __init__(self, s, i=0, h=0, r=0):
        self.susceptible, self.infected, self.hospitalized, self.recovered = ([s], [i], [h], [r])
        self.population_size = s + i + h + r

    curr_time = 1
    beta_zero = 0.2592
    avg_hospitalized = 0.05

    @property
    def keys(self):
        return {"susceptible": self.susceptible, "infected": self.infected,
                "hospitalized": self.hospitalized, "recovered": self.recovered}

    @property
    def beta(self):
        return self.beta_zero * (3 if random.random() <= 1 / 15 else 1)

    @property
    def last_time(self):
        return self.curr_time - 1

    def last(self, variable):
        return variable[self.last_time]

    def update(self, variable, increment, is_new=True):
        new = self.last(variable) + increment
        if is_new:
            variable.append(new)
        else:
            variable[self.curr_time] += increment

    def run(self, t, stop_sign=None, is_random=True):

        min_count = False
        func = (np.random.poisson if is_random else int)

        while (t > 0 or stop_sign["t"] > 0) or not min_count:
            new_contagions = self.new_contagions()
            new_contagions = list(map(func,
                                      [new_contagions * self.avg_hospitalized,
                                       new_contagions * (1 - self.avg_hospitalized)]))
            recoveries = list(map(func,
                                  [self.avg_recovery(is_hospitalized=True), self.avg_recovery()]))

            self.update(self.recovered, sum(recoveries))
            self.update(self.susceptible, -sum(new_contagions))

            self.update(self.hospitalized, new_contagions[0])
            self.update(self.hospitalized, -recoveries[0], False)

            self.update(self.infected, new_contagions[1])
            self.update(self.infected, -recoveries[1], False)

            stop_sign["t"] = (stop_sign["t"] - 1 if compare_sign(self.keys, stop_sign) else stop_sign["latent_t"])
            if new_contagions[0] != 0:
                min_count = True

            self.curr_time += 1
            t -= 1

    def avg_recovery(self, is_hospitalized=False):
        if is_hospitalized:
            return 0.03751 * self.last(self.hospitalized)
        else:
            return 0.07143 * self.last(self.infected)

    def new_contagions(self):
        return self.beta * (self.last(self.infected) + self.last(self.hospitalized)) * self.last(
            self.susceptible) / self.population_size


def plot_pandemic(df: pd.DataFrame):
    graph = sns.lineplot(data=df)
    graph.axes.set_title("Simulação de uma pandemia com distribuições de Poisson", fontsize=15)
    graph.set_xlabel("Dias", fontsize=15)
    graph.set(yscale='log')
    graph.set_ylabel("Pessoas", fontsize=15)
    graph.legend(title='Situação', labels=['Suscetível', 'Infectado', "Hospitalizado", "Recuperados"])
    plt.show()


def main():
    infected = random.randint(10, 20)
    simulation = SimulateEpidemic(10 ** 4, i=infected)
    simulation.run(0, stop_sign={"hospitalized": [0], "latent_t": 3, "t": 3})

    df = pd.DataFrame.from_dict(simulation.keys)
    plot_pandemic(df)


if __name__ == "__main__":
    main()