#include <stdbool.h>
#include <string.h>

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int top = -1; // -1 means stack is empty

    for (int i = 0; i < len; i++) {
        // Trick: Push the matching CLOSING bracket onto the stack
        if (s[i] == '(') {
            stack[++top] = ')';
        } else if (s[i] == '[') {
            stack[++top] = ']';
        } else if (s[i] == '{') {
            stack[++top] = '}';
        } 
        // If it is a closing bracket, it MUST match the top of the stack
        else {
            // If stack is empty OR the brackets don't match, it's invalid
            if (top == -1 || stack[top] != s[i]) {
                return false;
            }
            top--; // Match found, pop it out
        }
    }

    // If top is -1, all brackets were matched and closed perfectly
    return top == -1;
}
