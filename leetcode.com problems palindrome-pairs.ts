class TrieNode {
    children: Map<string, TrieNode> = new Map();
    index: number = -1;
    palindromesBelow: number[] = [];
}

class Trie {
    root: TrieNode = new TrieNode();

    insert(word: string, index: number) {
        let node = this.root;
        for (let i = word.length - 1; i >= 0; i--) {
            if (isPalindrome(word, 0, i)) {
                node.palindromesBelow.push(index);
            }
            if (!node.children.has(word[i])) {
                node.children.set(word[i], new TrieNode());
            }
            node = node.children.get(word[i])!;
        }
        node.index = index;
        node.palindromesBelow.push(index);
    }

    search(word: string, index: number, res: Set<string>) {
        let node = this.root;
        for (let i = 0; i < word.length; i++) {
            if (node.index !== -1 && node.index !== index && isPalindrome(word, i, word.length - 1)) {
                res.add(`${index},${node.index}`);
            }
            if (!node.children.has(word[i])) return;
            node = node.children.get(word[i])!;
        }

        for (let otherIndex of node.palindromesBelow) {
            if (index !== otherIndex) res.add(`${index},${otherIndex}`);
        }
    }
}

function isPalindrome(s: string, left: number, right: number): boolean {
    while (left < right) {
        if (s[left++] !== s[right--]) return false;
    }
    return true;
}

function palindromePairs(words: string[]): number[][] {
    let trie = new Trie();
    let res = new Set<string>();
    let wordMap = new Map<string, number>();

    for (let i = 0; i < words.length; i++) {
        trie.insert(words[i], i);
        wordMap.set(words[i], i);
    }

    for (let i = 0; i < words.length; i++) {
        trie.search(words[i], i, res);
    }

    for (let i = 0; i < words.length; i++) {
        let reversed = words[i].split('').reverse().join('');
        if (wordMap.has(reversed) && wordMap.get(reversed)! !== i) {
            res.add(`${i},${wordMap.get(reversed)!}`);
        }
    }

    // Convert Set of unique pairs to an array
    return Array.from(res).map(pair => pair.split(',').map(Number));
}
