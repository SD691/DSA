/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
     return new Promise((resolve, reject) => {
        const n = functions.length;
        const results = new Array(n);
        let completed = 0;

        // edge case
        if (n === 0) {
            resolve([]);
            return;
        }

        for (let i = 0; i < n; i++) {
            try {
                const promise = functions[i]();
                promise
                    .then(value => {
                        results[i] = value;   // preserve order
                        completed++;

                        if (completed === n) {
                            resolve(results);
                        }
                    })
                    .catch(error => {
                        reject(error); // first rejection wins
                    });
            } catch (error) {

                reject(error);
            }
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */