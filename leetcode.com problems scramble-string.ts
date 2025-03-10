function isScramble(s1: string, s2: string): boolean {
    if (s1 === s2) return true;
    if (s1.length !== s2.length) return false;
    if ([...s1].sort().join('') !== [...s2].sort().join('')) return false; // Prune impossible cases

    let memo: Map<string, boolean> = new Map();

    function dfs(str1: string, str2: string): boolean {
        if (str1 === str2) return true;
        if (str1.length !== str2.length) return false;

        let key = str1 + "-" + str2;
        if (memo.has(key)) return memo.get(key)!;

        let n = str1.length;
        for (let i = 1; i < n; i++) {
            // Case 1: No swap (left-left, right-right)
            if (dfs(str1.substring(0, i), str2.substring(0, i)) &&
                dfs(str1.substring(i), str2.substring(i))) {
                memo.set(key, true);
                return true;
            }

            // Case 2: Swap (left-right, right-left)
            if (dfs(str1.substring(0, i), str2.substring(n - i)) &&
                dfs(str1.substring(i), str2.substring(0, n - i))) {
                memo.set(key, true);
                return true;
            }
        }

        memo.set(key, false);
        return false;
    }

    return dfs(s1, s2);
}
