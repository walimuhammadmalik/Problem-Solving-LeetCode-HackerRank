// A global list of paths from beginWord to endWord
let allPaths: string[][] = [];

// A global map to track the predecessors of each word in the shortest paths
let predecessorsMap: Map<string, Set<string>> = new Map();

// Function to find all the shortest transformation sequences from begin word to end word
function findLadders(beginWord: string, endWord: string, wordList: string[]): string[][] {
    allPaths = [];
    const wordSet: Set<string> = new Set(wordList);

    // If endWord is not in the word list, return an empty list of paths
    if (!wordSet.has(endWord)) {
        return allPaths;
    }

    wordSet.delete(beginWord); // Remove beginWord to avoid cycles

    // Map to track the shortest path distances for words from the beginWord
    const distanceMap: Map<string, number> = new Map();
    distanceMap.set(beginWord, 0);

    predecessorsMap = new Map(); // Initialize the predecessor map

    // Queue for performing BFS
    const queue: string[] = [beginWord];

    // Flag to check if the endWord was found
    let isEndWordFound: boolean = false;

    // Step counter for BFS
    let steps: number = 0;

    while (queue.length > 0 && !isEndWordFound) {
        steps++;
        for (let i = queue.length; i > 0; --i) {
            const currentWord: string = <string>queue.shift();
            const currentChars: string[] = [...currentWord];

            for (let j = 0; j < currentChars.length; ++j) {
                const originalChar: string = currentChars[j];

                // Try all possible one-letter mutations
                for (let c = 'a'.charCodeAt(0); c <= 'z'.charCodeAt(0); ++c) {
                    currentChars[j] = String.fromCharCode(c);
                    const newWord: string = currentChars.join('');

                    if (distanceMap.get(newWord) === steps) {
                        predecessorsMap.get(newWord)?.add(currentWord);
                    }

                    if (!wordSet.has(newWord)) {
                        continue; // Skip if the new word isn't in the set
                    }

                    // Update distance map and predecessors map for new words found
                    if (!predecessorsMap.has(newWord)) {
                        predecessorsMap.set(newWord, new Set());
                    }
                    predecessorsMap.get(newWord)?.add(currentWord);

                    wordSet.delete(newWord); // Remove to prevent revisiting
                    queue.push(newWord);
                    distanceMap.set(newWord, steps);

                    if (endWord === newWord) {
                        // Found the endWord; will finish after this level
                        isEndWordFound = true;
                    }
                }
                currentChars[j] = originalChar; // Restore original character before next modification
            }
        }
    }

    // If the end word has been reached, construct all shortest paths
    if (isEndWordFound) {
        let path: string[] = [endWord]; // Path stack for reconstructing paths
        backtrackPath(path, beginWord, endWord);
    }
    return allPaths;
}

// Helper function to perform DFS and build all shortest transformation paths
function backtrackPath(path: string[], beginWord: string, currentWord: string) {
    if (currentWord === beginWord) {
        // If the beginning of the path is reached, add the path to allPaths
        allPaths.push([...path].reverse()); // Reverse before adding as we construct path from end to start
        return;
    }

    // Recursively go through all predecessors of the current word
    const predecessors: Set<string> | undefined = predecessorsMap.get(currentWord);
    if (predecessors) {
        for (const predecessor of predecessors) {
            path.push(predecessor); // Push the predecessor onto the path
            backtrackPath(path, beginWord, predecessor);
            path.pop(); // Remove the predecessor to backtrack for the next path
        }
    }
}
