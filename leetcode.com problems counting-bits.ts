function countBits(n: number): number[] {
    // Initialize an array to store the number of 1's for each number from 0 to n
    const result = new Array(n + 1).fill(0);

    // Loop through each number from 1 to n
    for (let i = 1; i <= n; i++) {
        // The number of 1's in the binary representation of i is the number of 1's in the binary representation
        // of i >> 1 (i divided by 2) plus the last bit of i (i & 1)
        result[i] = result[i >> 1] + (i & 1);
    }

    return result;
}

// Example usage:
console.log(countBits(5)); // Output: [0, 1, 1, 2, 1, 2]
