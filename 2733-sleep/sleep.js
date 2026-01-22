/**
 * @param {number} millis
 * @return {Promise}
 */


async function sleep(millis) {
    //While a standard setTimeout is fine for simple "fire and forget" tasks (like showing an alert), it cannot directly return a value to the code that called it because it relies on callbacks. Wrapping it in a Promise allows you to use async/await, making your code cleaner and more predictable. 

    const p = new Promise((resolve)=>{
        setTimeout(()=>{
            resolve(millis)
        }, millis);
    })

    return p.then((value)=>{
        return value;
    })

    // return async function(){
    //     return await p;
    // }

//     Important rule (memorize this):

// An async FUNCTION returns a Promise only when it is CALLED.

// Not when it is returned.

// 🔍 Tiny proof
// async function f() {
//     return 42;
// }

// console.log(f);     // function
// console.log(f());   // Promise


// Same mistake you made.

    // so using then i can read a promise.
    // using async i can also read promise. but that will be done via?
    // so create async function

    // const res = millis=> new Promise((resolve)=>{
    //     setTimeout(()=>{
    //         resolve(millis)
    //     },millis);
    // });

    // return await res;

    // const p = new Promise((resolve, reject)=>{
    //     if(true){
    //         resolve(yes);
    //     }
    //     else{
    //         reject(no)''
    //     }
    // })

    // return await p.then((value)=>{
    //     return value;
    // })
    // .catch((value)=>{
    //     return catch;
    // })

    // async function func(()=>{
    //     try{
    //         const result = await p;
    //     }
    //     catch{
    //         console.log('error');
    //     }
    // })
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */