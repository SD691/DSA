// Absolutely! Here’s a **concise, beginner-friendly summary of JavaScript Promises** that you can save and refer to anytime:

// ---

// ## **JavaScript Promises – Quick Reference**

// ### **What is a Promise?**

// * A **promise** is a JavaScript object that represents a task that will **finish in the future**.
// * It can be in **three states**:

//   1. **Pending** – the task is still running.
//   2. **Fulfilled / Resolved** – the task succeeded.
//   3. **Rejected** – the task failed.

// ---

// ### **Creating a Promise**

// ```javascript
// const myPromise = new Promise((resolve, reject) => {
//     const success = true; 
//     if(success) resolve("Yay! It worked!");
//     else reject("Oops! Something went wrong!");
// });
// ```

// * `resolve(value)` → marks the promise as fulfilled.
// * `reject(error)` → marks the promise as rejected.

// ---

// ### **Getting the Result**

// 1. **Using `.then()` and `.catch()`**

// ```javascript
// myPromise
//     .then(result => console.log("Success:", result))
//     .catch(error => console.log("Error:", error));
// ```

// 2. **Using `async/await`**

// ```javascript
// async function run() {
//     try {
//         const result = await myPromise;
//         console.log("Success:", result);
//     } catch (error) {
//         console.log("Error:", error);
//     }
// }
// run();
// ```

// ---

// ### **Promises With Timeouts / Delays**

// ```javascript
// const wait = ms => new Promise(res => setTimeout(() => res(`Waited ${ms}ms`), ms));
// wait(1000).then(console.log); // "Waited 1000ms" after 1 second
// ```

// ---

// ### **Multiple Promises**

// * `Promise.all([p1, p2])` → waits for **all promises** to finish.
// * `Promise.race([p1, p2])` → settles as soon as **the first promise** finishes.

// ---

// ### **Async Functions**

// * `async` functions **always return a promise**, even if you return a normal value.
// * Example:

// ```javascript
// async function add(a, b) {
//     return a + b; // returns a promise that resolves to a + b
// }

// add(2, 3).then(console.log); // 5
// ```

// * **Thrown errors** inside async functions automatically **reject the promise**.
// * `await` can be used to pause execution until a promise resolves.

// ---

// ### **Key Points**

// * `.then()` → handles resolved value.
// * `.catch()` → handles rejected value.
// * `async/await` → cleaner way to work with promises.
// * Returning a value in async → resolves a promise.
// * Throwing an error in async → rejects a promise.

// ---

// If you want, I can also make a **one-page visual diagram** showing **how promises go from pending → resolved/rejected**, which is even easier to remember than text.

// Do you want me to do that?




/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // const p1 = promise1;
    // const p2 = promise2;
    // const [result1, result2] = await Promise.all([promise1,promise2]);
    // return result1+result2;

    // let sum = 0;
    // var addTwo = async function func(promise1, promise2){
    //     const [result1, result2] = await Promise.all([promise1,promise2]);
    //     return result1+result2;
    // }
    // return sum = await addTwo(promise1,promise2);

    // return await Promise.all(
    //     [
    //         promise1,
    //         promise2
    //     ]
    // ).then(([result1,result2])=>{
    //     return result1+result2;
    // })
    
    return await Promise.all(
        [
            promise1,
            promise2
        ]
    ).then(([result1,result2])=>{
        return result1+result2;
    })
    // let promise = new Promise((resolve,reject)=>{
    //     let a = 1;
    //     let b = 2;
    //     if((a+b)%2==0){
    //         resolve("true");
    //     }
    //     else{
    //         reject("false");
    //     }
    // })

    // promise
    // .then(result=>{
    //     console.log(result);
    // })
    // .catch(result=>{
    //     console.log(result);
    // })


    // function myfunc(){
    //     return new Promise((resolve,reject)=>{
    //         let success = true;
    //         if(success){
    //             resolve("completed");
    //         }
    //         else{
    //             resolve("incomplete");
    //         }
    //     })
    // }

    // myfunc().then(result=>{
    //     console.log(result);
    // })
    // .catch(result=>{
    //     console.log(result);
    // })

    // async function showpop(){
    //     const getData = await myfunc();
    //     console.log(getData);
    // }
    // showpop();
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */