# -*- coding: utf-8 -*-
"""# Uma Epidemia de Poisson

Um modelo basico de epidemia numa população de N indivíduos considera eles divididos em quatro grupos:

* S: Suscetíveis (sem imunidade)
* I: Infectados (não hospitalizados)
* H: Infectados Hospitalizados
* R: Recuperados (com imunidade)

De acordo com uma unidade temporal $\delta t$, os números de indivíduos dos grupos acima seguem as seguintes regras:

- Taxa média de novos contágios $r_{I}(t) = \beta(t) * \frac{(I(t) + H(t)) * S(t)}{N}$ por dia.
- Em média, 5% dos novos infectados são levados ao hospital.
- $\beta(t) = \beta(0) = 0.2592$, com $\frac{1}{15}$ de chance de $\beta(t) = 3 \cdot \beta_{0}$ em determinado dia.
- Taxa de recuperação de infectados não hospitalizados $r_{(I)} = 0.07143$ ao dia.
- Taxa de recuperação de infectados hospitalizados $r_{(H)} = 0.03571$ ao dia.


# Parâmetros da simulação:

* $N = 10^{4}$ é o tamanho da população inicial.
* $I(0) = \text{randint}(10, 20)$ (infectados iniciais)
* Repetir os cálculos até que $H(t) = 0$ por três dias seguidos.

# Valores observados

Ao final da simulação, foram observados uma sequência de parâmetros importantes, e realizado operações em cima deles:

* Máximo de hospitalizados simultâneos $\text{max}_{t}[H(t)]$
* O tempo $T_{*}$ até ocorrer o máximo.
* Quanto da população pegou a doença (Recuperados + Hospitalizados + Infectados)
* Quanto da população foi hospitalizada.
* O tempo até a 10° hospitalização, e até a 40° hospitalização ($T_{10}$ e $T_{40}$)
"""

from random import random, randint
import copy

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from typing import Union
import plotly.express as px

def compare_sign(effective, received):
    if not received:
        return False
    for sign in received:
        if not effective.get(sign):
            continue
        if effective[sign][-1] != received[sign][-1]:
            return False
    return True

def vectorized_min(baseline: Union[int, float], array: np.ndarray) -> np.ndarray:
    """
    Maps the min function to a np.ndarray given desired baseline minimum.

    Args:
        baseline: Minimum value to substitute if values within array are bigger
        array: Array with values to be compared to baseilne

    Returns:
        Array with leveraged numbers, all equal to or lower than the baseline

    >>> vectorized_min(2, np.array([1, 3, 4, -1])
    array([1, 2, 2, -1])
    """
    return np.array([min(baseline, x) for x in array])

def avg(array) -> Union[np.ndarray, pd.DataFrame]:
    """
    Calculates the average between multiple numpy arrays or pandas dataframe columns.

    Args:
        array: Array containing multiple numpy arrays or pandas dataframes

    Returns:
        Single numpy array or dataframe with average values element or column-wise
        respectivelly

    >>> avg([pd.DataFrame.from_dict({"x": [1, 2, 3]}), pd.DataFrame.from_dict({"x": [3, 3, 3]})])
        x
    0   2
    1   2
    2   3
    """
    result = sum(array) / len(array)
    if isinstance(result, np.ndarray):
        return result.astype(np.int32)
    else:
        return result.astype('int')

class SimulateEpidemic:
    def __init__(self, starting_values, model=np.random.poisson, rates=None):
        """
        Simulates an Epidemic Scenario given starting values and desired rate model for
        predicting new contagions and recovery values.

        Args:
            starting_values: A dictionary containing arrays of starting values:
                {"num_susceptible",
                "num_infected",
                "num_hospitalized",
                "num_recovered"}
            model: Model to generate new rates for each simulation time step, defaults to the Poisson Distribution.
        """
        self.susceptible = starting_values.get("num_susceptible", [int(1e4)])
        self.infected = starting_values.get("num_infected", [20])
        self.hospitalized = starting_values.get("num_hospitalized", [0])
        self.recovered = starting_values.get("num_recovered", [0])
        self.population_size = np.sum(list(starting_values.values()))
        self.population_size = int(self.population_size)

        self.curr_time = 1
        if rates is None:
            rates = {}
        self.agglomeration_frequency = rates.get("agglomeration_frequency", 1/15)
        self.hospitalized_rate = rates.get("hospitalized_rate", 0.05)
        self.model = model

    # Default constants to perform rate and average values update calculations
    beta_zero = 0.2592
    gamma_infected = 0.07143
    gamma_hospitalized = 0.03751

    @property
    def keys(self):
        """Returns the simulation population update history as a dictionary."""
        return {"susceptible": self.susceptible, "infected": self.infected,
                "hospitalized": self.hospitalized, "recovered": self.recovered}

    @property
    def df(self):
        """Returns the simulation population update history as a Pandas DataFrame."""
        return pd.DataFrame.from_dict(self.keys)

    @property
    def beta(self):
        """Calculate the used beta variable given agglomeration_frequency and initial beta values."""
        if random() <= self.agglomeration_frequency:
            return self.beta_zero * 3
        else:
            return self.beta_zero

    def update(self, variable, increment, is_new=True, timeframe=-1):
        """
        Adds a new timeframe to a single population variable, with given increment,
        or update variable at given timeframe if is_new=False.

        Args:
            variable: Instance population variable to increment, can be either self.infected,
            self.hospitalized, self.recovered or self.susceptible
            increment: Value to increase selected timeframe by
            is_new: Defaults to True, in which case a new entry is added to the end of the selected
            population history. If False, value at given timeframe is incremented
            timeframe: Used if is_new = False to update a single timeframe value

        Examples:
            >>> self.update(self.infected, 100)
            # self.infected[-1] = self.infected[-2] + 100
        """
        if is_new:
            next_value = variable[timeframe] + increment
            variable.append(next_value)
        else:
            variable[self.curr_time] += increment
            if variable[self.curr_time] < 0:
                variable[self.curr_time] = 0

    def step(self, recoveries, contagions):
        """Performs a single simulation step, given new recoveries and new contagions."""
        self.update(self.recovered, sum(recoveries))
        self.update(self.susceptible, -sum(contagions))

        self.update(self.hospitalized, contagions[0])
        self.update(self.hospitalized, -recoveries[0], False)

        self.update(self.infected, contagions[1])
        self.update(self.infected, -recoveries[1], False)

    def apply_model(self, iterable: iter) -> list:
        """Maps the desired Instance model to a given iterable variable, returning generated list"""
        return list(map(self.model, iterable))

    def avg_recovery(self, is_hospitalized=False):
        """Calculate the expected recoveries using the last time frame values."""
        if is_hospitalized:
            return self.gamma_hospitalized * self.hospitalized[-1]
        else:
            return self.gamma_infected * self.infected[-1]

    def avg_contagions(self, time_step=1):
        """Calculate the expected new contagions using the last time frame values."""
        return self.beta * (self.infected[-1] + self.hospitalized[-1]) * self.susceptible[-1] / self.population_size

    def run(self, remaining_time, stop_sign=None, time_step=1):
        """
        Performs simulation of the given input parameters up until remaining time is
        zero or the stop_sign has been reached.
        The simulation updates the history of each population variable per loop, with given
        constant rates and considering the inputed time_step.

        The final state of the simulation can be access either through the return value
        of this function or by calling the :func:self.df method from the simulation instance.

        Args:
            remaining_time: How long to run the experiment for after the stop_sign has been reached, if any at all
            stop_sign: Comparison values to current population stamp to determine when to stop simulation
            time_step: Time difference between two simulation loops, measured in days

        Examples:
            >>> self.run(remaining_time=1, stop_sign={"hospitalized": [0], "days_without_hosp": 3, "day_counter": 3})
        """
        min_count = False
        if stop_sign is None:
            stop_sign = {"day_counter": 0}

        while (remaining_time > 0 or stop_sign["day_counter"] > 0) or not min_count:
            avg_contagions = self.avg_contagions(time_step=time_step)

            # Calculate expected average for contagions and recoveries at current time frame
            avg_contagions = np.array([avg_contagions * self.hospitalized_rate, avg_contagions * (1 - self.hospitalized_rate)])
            avg_recoveries = np.array([self.avg_recovery(is_hospitalized=True), self.avg_recovery()])

            # Apply desired model given the expected average, and save the obtained values
            contagions = self.apply_model(time_step * avg_contagions)
            recoveries = self.apply_model(time_step * avg_recoveries)

            # If either the modeled contagions or recoveries are bigger than their respective counterparts,
            # susceptible and infected + hospitalized populations, fix maximum allowed value to the
            # minimum between the values and their counterparts.
            contagions[0] = min(contagions[0], int(self.susceptible[-1] * self.hospitalized_rate))
            contagions[1] = min(contagions[1], int(self.susceptible[-1] * (1 - self.hospitalized_rate)))
            recoveries = vectorized_min(self.infected[-1] + self.hospitalized[-1], recoveries)

            # Update final increment values using the :func:step method
            self.step(recoveries, contagions)
            self.curr_time += 1

            # If the stop_sign condition is true (evaluated using the compare_sign function),
            # decrement remaining days from day_counter, else, reset counter and decrement remaining time
            if stop_sign["day_counter"] > 0 and compare_sign(self.keys, stop_sign):
                stop_sign["day_counter"] = stop_sign["day_counter"] - 1
            else:
                stop_sign["day_counter"] = stop_sign.get("days_without_hosp", 0)
                remaining_time -= 1

            # Base case to verify if at least one day passed before the first new hospitalized contagion
            if contagions[0] != 0:
                min_count = True
        return self.df

def reset_default_constants():
    """Resets class variables to initial problem statement values."""
    SimulateEpidemic.beta_zero = 0.2592
    SimulateEpidemic.gamma_infected = 0.07143
    SimulateEpidemic.gamma_hospitalized = 0.03751
    SimulateEpidemic.avg_hospitalized = 0.05

class SimulationGenerator:
    def __init__(self, model=np.random.poisson, starting_values=None, rates=None, time_step=1):
        self.model = model
        if starting_values is None:
            num_susceptible = int(1e4)
            num_infected = randint(10, 20)
            self.starting_values = {"num_susceptible": [num_susceptible], "num_infected": [num_infected]}
        else:
            self.starting_values = starting_values
        self.time_step = time_step
        self.rates = rates

    @property
    def stop_sign(self):
        return {"hospitalized": [0], "days_without_hosp": np.ceil(3/self.time_step), "day_counter": np.ceil(3/self.time_step)}

    def __next__(self):
        simulation = SimulateEpidemic(copy.deepcopy(self.starting_values), self.model, self.rates)
        return simulation

    def run(self, simulation=None):
        if simulation is None:
            simulation = self.__next__()
        simulation.run(0, self.stop_sign, self.time_step)
        return simulation

    def create_single(self):
        simulation = self.__next__()
        self.run(simulation)
        return simulation

    def create_sequence(self, n=10):
        simulations = [self.__next__() for _ in range(n)]
        dataframes = [self.run(simulation).df for simulation in simulations]

        dataframes = [df for df in dataframes if len(df) > 15]

        lengths = [len(df) for df in dataframes]
        max_length = min([length for length in lengths])
        dataframes = [df.iloc[:max_length] for df in dataframes]

        return dataframes

    def moving_average(self, sequence=None, n=10):
        if sequence is None:
            sequence = self.create_sequence(n)
        iterations = sequence

        mavg = []
        for i in range(len(iterations)):
            mavg.append(avg(iterations[:i + 1]))
        return mavg

    def step_difference(self, dataframe=None):
        if dataframe is None:
            dataframe = self.create_single().df

        mdiff = [dataframe.iloc[0]]
        for i in range(1, len(dataframe)):
            mdiff.append(dataframe.iloc[i] - dataframe.iloc[i - 1])
        return pd.DataFrame(mdiff)

class SimulationViewer:
    def __init__(self, generator=None):
        if generator is None:
            self.generator = SimulationGenerator()
        else:
            self.generator = generator

    def simple_graph(self, dataframe=None, fixed=200):
        if dataframe is None:
            dataframe = self.generator.create_single().df

        color = {"susceptible": "blue", "infected": "red", "hospitalized": "orange", "recovered": "green"}
        fig = dataframe.plot(title="Simulação da Pandemia",
                             template="simple_white",
                             labels=dict(index="dT passados", value="Pessoas", variable="Situação da População"),
                             color_discrete_map=color)
        if fixed < 200:
            fig.update_xaxes(range=[0, fixed])
        fig.show()


    def heatmap(self, dataframe=None):
        if dataframe is None:
            dataframe = self.generator.create_single().df

        fig = px.imshow(dataframe.corr(), template="simple_white", text_auto=True, color_continuous_scale='RdBu_r')
        fig.show()

    @staticmethod
    def describe_iteration(simulation):
        hospitalized_peak = max(simulation.hospitalized)
        peak_index = np.argmax(simulation.hospitalized)
        hospitalized_first = np.nonzero(simulation.hospitalized)[0][0]

        t_star = peak_index - hospitalized_first
        t_10 = np.where(np.array(simulation.hospitalized) >= 10)[0][0]
        t_40 = np.where(np.array(simulation.hospitalized) >= 40)[0][0]

        return {"peak": hospitalized_peak, "t_star": t_star, "t_10": t_10, "t_40": t_40}


    @staticmethod
    def describe(simulation):
        arr = np.array(simulation["hospitalized"])
        hospitalized_peak = max(arr)
        peak_index = np.argmax(arr)
        hospitalized_first = np.nonzero(arr)[0][0]

        t_star = peak_index - hospitalized_first
        t_10 = np.where(arr >= 10)[0][0]
        t_40 = np.where(arr >= 40)[0][0]

        return {"peak": hospitalized_peak, "t_star": t_star, "t_10": t_10, "t_40": t_40}

