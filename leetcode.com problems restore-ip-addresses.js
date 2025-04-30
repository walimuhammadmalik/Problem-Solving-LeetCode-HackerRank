/**
 * @param {string} s
 * @return {string[]}
 */
var restoreIpAddresses = function(s) {
    const result = [];

    const backtrack = (start, path) => {
        // If we've reached the end of the string and have exactly 4 segments, it's a valid IP
        if (start === s.length && path.length === 4) {
            result.push(path.join('.'));
            return;
        }

        // If we already have 4 segments but haven't used all characters, stop
        if (path.length === 4) {
            return;
        }

        for (let len = 1; len <= 3; len++) {
            if (start + len > s.length) break;
            let segment = s.slice(start, start + len);

            // Skip segments with leading zeros (except '0') or value > 255
            if ((segment.length > 1 && segment[0] === '0') || parseInt(segment) > 255) {
                continue;
            }

            path.push(segment);
            backtrack(start + len, path);
            path.pop();
        }
    };

    backtrack(0, []);
    return result;
};
