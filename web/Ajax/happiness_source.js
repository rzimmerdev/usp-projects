function write_happiness(happy) {
    document.getElementById("result").innerHTML = happy;
}


const getHappinessOriginal = (happy, callback) => {
    setTimeout(() => {
        const happiness = Math.random();
        if (happiness > happy) {
            callback(happiness);
        } else {
            callback(new Error("Joe is sad!"));
        }
    }, 2000);
}

function getHappinessPromise(happy, callback) {
    let threshold = document.getElementById("threshold").value;

    setTimeout(() => {
        const happiness = Math.random();
        if (happiness > happy)
            return happy;
        else
            return new Error("Joe is sad!");
    }, 2000).then(function (happiness) {
        callback(happiness);
    }).catch(function (err) {
        callback(err);
    });
}

async function getHappinessAsync() {
    let threshold = document.getElementById("threshold").value;

    try {
        let value = await setTimeout(() => {
            const happiness = Math.random();
            if (happiness > happy)
                return happy;
            else
                return new Error("Joe is sad!");
        }, 2000);

        return value;
    } catch (err) {
        return {
            name: 'default user'
        };
    }
}
