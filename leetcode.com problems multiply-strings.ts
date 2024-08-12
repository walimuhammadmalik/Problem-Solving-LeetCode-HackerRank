function multiply(num1: string, num2: string): string {
    if (num1 === "0" || num2 === "0") return "0";

    const result = new Array(num1.length + num2.length).fill(0);

    for (let i = num1.length - 1; i >= 0; i--) {
        for (let j = num2.length - 1; j >= 0; j--) {
            const mul = parseInt(num1[i]) * parseInt(num2[j]);
            const sum = mul + result[i + j + 1];
            
            result[i + j + 1] = sum % 10;
            result[i + j] += Math.floor(sum / 10);
        }
    }

    while (result[0] === 0) {
        result.shift();
    }

    return result.join('');
}
