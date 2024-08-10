function searchRange(nums: number[], target: number): number[] {
    const result: number[] = [-1, -1];

    // Function to find the first occurrence of the target
    const findFirst = (nums: number[], target: number): number => {
        let left = 0;
        let right = nums.length - 1;

        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (nums[mid] === target) {
                if (mid === 0 || nums[mid - 1] !== target) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    };

    // Function to find the last occurrence of the target
    const findLast = (nums: number[], target: number): number => {
        let left = 0;
        let right = nums.length - 1;

        while (left <= right) {
            const mid = Math.floor((left + right) / 2);

            if (nums[mid] === target) {
                if (mid === nums.length - 1 || nums[mid + 1] !== target) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    };

    // Find the first and last positions of the target
    result[0] = findFirst(nums, target);
    if (result[0] !== -1) {
        result[1] = findLast(nums, target);
    }

    return result;
}
