/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    // retunr an object with the following 2 functions.
    // so this oject will have 2 functions, tobe(val) and thenin this function i am going to compare.
    // for the other itis nottobe(val) and for this we have to return 

    return {
        toBe: function(val2){
            if(val2!==val) throw new Error("Not Equal");
            else return true;
        },
        notToBe: function(val2){
            if(val2===val) throw new Error("Equal");
            else return true;
        }
    }


};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */