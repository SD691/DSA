/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let n = Object.keys(obj).length; // to find the length of an object in javasctipt
    console.log(n);
    if(n>0){
        return false;
    }
    return true;
};