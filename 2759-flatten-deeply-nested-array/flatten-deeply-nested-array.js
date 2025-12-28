/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    
    function dfs(current, depth){
        let result = [];

        for(let i=0; i<current.length; i++){
            if(Array.isArray(current[i]) && depth<n){
                result.push(...dfs(current[i],depth+1));
            }
            else{
                result.push(current[i]);
            }
        }
        return result;
    }
    return dfs(arr,0);
    
};