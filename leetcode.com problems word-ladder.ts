function ladderLength(beginWord: string, endWord: string, wordList: string[]): number {
    const wordSet = new Set(wordList);
    
    // If the endWord is not in the word list, return 0
    if (!wordSet.has(endWord)) return 0;
    
    // Initialize the queue with the beginning word and count of 1
    const queue: [string, number][] = [[beginWord, 1]];
    
    // BFS traversal
    while (queue.length > 0) {
        const [currentWord, count] = queue.shift()!;
        
        // Try changing each character of the word
        for (let i = 0; i < currentWord.length; i++) {
            const prefix = currentWord.substring(0, i);
            const suffix = currentWord.substring(i + 1);
            
            // Try all possible letters for the current position
            for (let charCode = 97; charCode <= 122; charCode++) {
                const newChar = String.fromCharCode(charCode);
                const newWord = prefix + newChar + suffix;
                
                // If we found the endWord, return the count of transformations
                if (newWord === endWord) return count + 1;
                
                // If newWord is in the word list, add it to the queue
                if (wordSet.has(newWord)) {
                    wordSet.delete(newWord);  // Remove to avoid revisiting
                    queue.push([newWord, count + 1]);
                }
            }
        }
    }
    
    // If no transformation is found
    return 0;
}
