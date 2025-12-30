/**
 * @param {number} millis
 * @return {Promise}
 */
async function sleep(millis) {

    // return new Promise((resolve)=>{
    //         setTimeout(()=>{
    //             resolve(millis)
    //         },millis);
    //     })
    
    function func(millis){
        return new Promise((resolve)=>{
            setTimeout(()=>{
                resolve(millis)
            },millis);
        })
    }

    

        return await func(millis);
        
    
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */