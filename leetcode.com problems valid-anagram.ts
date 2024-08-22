function isAnagram(s: string, t: string): boolean {
    // If the lengths of the strings are different, they cannot be anagrams
    if (s.length !== t.length) {
        return false;
    }

    // Sort the characters of both strings and compare
    return s.split('').sort().join('') === t.split('').sort().join('');
}
