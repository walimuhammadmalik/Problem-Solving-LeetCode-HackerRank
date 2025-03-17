function countDigitOne(n: number): number {
    let count = 0;
    let factor = 1; // Tracks digit place (1s, 10s, 100s, etc.)
    
    while (factor <= n) {
        let higher = Math.floor(n / (factor * 10)); // Digits to the left
        let current = Math.floor((n / factor) % 10); // Current digit
        let lower = n % factor; // Digits to the right

        // Count occurrences of '1' in the current digit place
        if (current === 0) {
            count += higher * factor;
        } else if (current === 1) {
            count += higher * factor + (lower + 1);
        } else {
            count += (higher + 1) * factor;
        }

        factor *= 10; // Move to the next place value (ones → tens → hundreds)
    }

    return count;
}
