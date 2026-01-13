/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let result = [{"calls":1,"value":0}];
    let count=true;
    return function(...args){
        if(count){
            count = false;
            return fn(...args);
            
        }
    }
    
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
