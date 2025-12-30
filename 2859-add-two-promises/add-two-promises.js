/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    // const p1 = promise1;
    // const p2 = promise2;
    const [result1, result2] = await Promise.all([promise1,promise2]);
    return result1+result2;
    // let sum = 0;
    // var addTwo = async function func(promise1, promise2){
    //     const [result1, result2] = await Promise.all([promise1,promise2]);
    //     sum = result1+result2;
    // }
    // return sum;
    // Promise.all(
    //     [
    //         promise1,
    //         promise2
    //     ]
    // ).then(([result1,result2])=>{
    //     return result1+result2;
    // })
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