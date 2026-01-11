/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    let ans = new Map();

    for(let i=0; i<this.length; i++){
        let obj = this[i];
        let key = fn(obj);

        if(ans[key]===undefined){
            ans[key]=[];
        }
        ans[key].push(obj);
    }
    return ans;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */