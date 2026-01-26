/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let count = 0;
    let ans = [];
    let temp = [];
    for(let i = 0; i<arr.length; i++){
        if(count<size){
            count = count+1;
            temp.push(arr[i]);
        }
        else{
            ans.push(temp);
            temp=[];
            temp.push(arr[i]);
            count=1;
        }
    }

    if(count>0){
        ans.push(temp);
    }
    return ans;
};
