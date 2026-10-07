#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    
    if (strsSize == 0) return "";

    
    static char result[201];
    int index = 0;

    
    while (strs[0][index] != '\0') {
        char current_char = strs[0][index]; 
        for (int i = 1; i < strsSize; i++) {
            
            if (strs[i][index] == '\0' || strs[i][index] != current_char) {
                result[index] = '\0'; 
                return result;
            }
        }

        
        result[index] = current_char;
        index++;
    }

    result[index] = '\0'; 
    return result;
}
