/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    
    let ans = [];
    let count=0;
    let temp = [];
    for(let i=0; i<arr.length; i++){
        if(count==size){
            count=0;
            ans.push(temp);
            temp = [];
        }
        if(count<size){
            count++;
            temp.push(arr[i]);
        }
    }

    if(temp.length){
        ans.push(temp);
    }
    return ans;
};
