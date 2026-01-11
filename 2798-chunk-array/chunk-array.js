/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    let answer= [];
    let count = 0;
    let temp = [];
    for(let i=0; i<arr.length; i++){
        if(count<size){
            count++;
            temp.push(arr[i]);
        }
        else{
            count=1;
            answer.push(temp);
            temp=[];
            temp.push(arr[i]);

        }
    }
    if(count>0){
        answer.push(temp);
    }
    return answer;
};
