/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const transformedArr = [];
    let k = 0;
    for(let i=0; i<arr.length; i++){
        if(fn(arr[i],i)){
            transformedArr[k] = arr[i];
            k++;
        }
    }
    return transformedArr;
};