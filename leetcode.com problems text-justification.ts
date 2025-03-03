function fullJustify(words: string[], maxWidth: number): string[] {
    let res: string[] = [];
    let line: string[] = [];
    let lineLength = 0;

    for (let word of words) {
        if (lineLength + line.length + word.length > maxWidth) {
            res.push(justify(line, lineLength, maxWidth));
            line = [];
            lineLength = 0;
        }
        line.push(word);
        lineLength += word.length;
    }

    // Handle the last line (left-justified)
    let lastLine = line.join(" ");
    res.push(lastLine + " ".repeat(maxWidth - lastLine.length));

    return res;
}

// Helper function to justify a line of words
function justify(line: string[], lineLength: number, maxWidth: number): string {
    if (line.length === 1) {
        return line[0] + " ".repeat(maxWidth - lineLength);
    }

    let spaces = maxWidth - lineLength;
    let gaps = line.length - 1;
    let spaceBetween = Math.floor(spaces / gaps);
    let extraSpaces = spaces % gaps;

    let justifiedLine = "";
    for (let i = 0; i < line.length - 1; i++) {
        justifiedLine += line[i] + " ".repeat(spaceBetween + (i < extraSpaces ? 1 : 0));
    }
    justifiedLine += line[line.length - 1];

    return justifiedLine;
}
