/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    
    const map = {};
    
    for(let obj of arr1){
        map[obj.id]=obj;
    }

    for(let obj of arr2){
        if(map[obj.id]){
            map[obj.id] = {...map[obj.id],...obj};
        }
        else{
            map[obj.id]=obj;
        } 
    }

    // convert map to obkect.
    const result = Object.values(map);

    result.sort((a,b)=>a-b);
    return result;
};