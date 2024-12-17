function getPermutation(n: number, k: number): string {
    // Create an array of numbers 1 to n
    const numbers = Array.from({ length: n }, (_, i) => i + 1);
    
    // Calculate factorials up to n
    const factorials: number[] = [1];
    for (let i = 1; i <= n; i++) {
        factorials[i] = factorials[i - 1] * i;
    }
    
    // Adjust k to be zero-indexed
    k -= 1;

    // Build the result string
    let result = "";
    for (let i = n; i > 0; i--) {
        const blockSize = factorials[i - 1];  // Number of permutations for each block
        const index = Math.floor(k / blockSize);  // Find the index of the next number in the list
        result += numbers[index].toString();  // Add the number to the result
        numbers.splice(index, 1);  // Remove the used number
        k %= blockSize;  // Update k for the next block
    }
    
    return result;
}
