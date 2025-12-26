/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let matrix = [];
    let val = 0;
    let curr = 0;
    let n = arr.length;
    let a=[];
    for(const v in arr){
        if(val==size){
            val=0;
            matrix.push(a);
            a=[];
        }
        if(val<size){
            a.push(arr[v]);
            val=val+1;
        }
    }
    if(a.length>0){
        matrix.push(a);
    }
    return matrix;
};
