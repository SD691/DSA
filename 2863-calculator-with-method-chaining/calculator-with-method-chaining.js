class Calculator {
    // cval: numeber = 0;
    /** 
     * @param {number} value
     */
  
    constructor(value) {
        // cval = value;
        this.cval = value;
    }
    // so the confusing part here is how am i going to figure out whihc value to pick + do ineed to traverse the arry or not?
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    add(value){
        this.cval += value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    subtract(value){
        this.cval -= value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */  
    multiply(value) {
        this.cval *= value;
        return this; 
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    divide(value) {
         if(value === 0) throw "Division by zero is not allowed";
        this.cval /= value;
        return this;
    }
    
    /** 
     * @param {number} value
     * @return {Calculator}
     */
    power(value) {
        this.cval **= value;
        return this;
    }
    
    /** 
     * @return {number}
     */
    getResult() {
        return this.cval;
    }
}