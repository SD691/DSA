/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // const [val1, val2] = await Promise.all([promise1, promise2]);
    // return val1+val2;

    return await Promise.all([promise1, promise2])
    .then(([val1, val2])=>{
        return val1+val2;
    })
    //In 2026, it remains a fundamental rule of JavaScript that you cannot "extract" a value from a promise into a variable and return it synchronously. Because promises are asynchronous, any variable assigned inside a .then() block is not yet available when the outer function tries to return
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */