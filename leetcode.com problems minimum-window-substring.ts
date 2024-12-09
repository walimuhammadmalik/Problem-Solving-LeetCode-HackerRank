function minWindow(s: string, t: string): string {
    // Edge case: If `t` is longer than `s`, return an empty string
    if (s.length < t.length) return '';

    // Frequency map for characters in `t`
    let tFreq: { [key: string]: number } = {};
    for (let char of t) {
        tFreq[char] = (tFreq[char] || 0) + 1;
    }

    let required = Object.keys(tFreq).length;  // Number of distinct characters in `t`

    // Sliding window variables
    let windowFreq: { [key: string]: number } = {};
    let left = 0;  // Left pointer of the window
    let right = 0; // Right pointer of the window
    let formed = 0; // Number of characters in the current window that match the required frequency in `t`
    let minLength = Infinity;
    let minLeft = 0; // Left index of the smallest valid window

    while (right < s.length) {
        // Add the character at `right` to the window
        let char = s[right];
        windowFreq[char] = (windowFreq[char] || 0) + 1;

        // If the character's frequency matches the one required in `t`
        if (windowFreq[char] === tFreq[char]) {
            formed++;
        }

        // Try to shrink the window when all required characters are found
        while (left <= right && formed === required) {
            char = s[left];
            let windowSize = right - left + 1;
            if (windowSize < minLength) {
                minLength = windowSize;
                minLeft = left;
            }

            // Shrink the window from the left
            windowFreq[char]--;
            if (windowFreq[char] < tFreq[char]) {
                formed--;
            }

            left++;
        }

        // Expand the window from the right
        right++;
    }

    // If no valid window is found, return an empty string
    return minLength === Infinity ? '' : s.slice(minLeft, minLeft + minLength);
}
