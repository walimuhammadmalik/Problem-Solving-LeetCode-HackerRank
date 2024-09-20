function countAndSay(n: number): string {
    if (n === 1) return "1";
    
    let result = "1";
    
    for (let i = 2; i <= n; i++) {
        let nextResult = "";
        let count = 1;

        for (let j = 1; j < result.length; j++) {
            if (result[j] === result[j - 1]) {
                count++;
            } else {
                nextResult += count.toString() + result[j - 1];
                count = 1;
            }
        }
        
        // Append the last counted digit
        nextResult += count.toString() + result[result.length - 1];
        result = nextResult;
    }
    
    return result;
}

// Example usage:
console.log(countAndSay(4)); // Output: "1211"
