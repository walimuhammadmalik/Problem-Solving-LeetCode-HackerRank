function simplifyPath(path: string): string {
    const stack: string[] = [];

    // Split the path into components
    const components = path.split('/');

    for (const component of components) {
        if (component === '' || component === '.') {
            // Ignore empty components or current directory (.)
            continue;
        } else if (component === '..') {
            // Pop the last directory (if any)
            if (stack.length > 0) {
                stack.pop();
            }
        } else {
            // Push the valid directory onto the stack
            stack.push(component);
        }
    }

    // Join the stack to form the simplified path
    const simplifiedPath = '/' + stack.join('/');

    return simplifiedPath;
}
