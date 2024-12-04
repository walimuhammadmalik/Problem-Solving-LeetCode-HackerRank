function isNumber(s: string): boolean {
    // The regular expression to match a valid number
    const regex = /^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$/;
    
    // Test the input string against the regex
    return regex.test(s.trim()); // .trim() removes leading/trailing whitespaces
}
