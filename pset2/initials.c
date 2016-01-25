#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char* stripInvalidChars(int length, string str);
char* stripExcessWhitespace(int length, string str);
int isLowerCase(char theChar);
int isUpperCase(char theChar);
int isSpace(char theChar);
char toUpperCase(char theChar);

int main(void) {
    string name = GetString();
    name = stripInvalidChars(strlen(name), name);

    //for (int i = 0, n = strlen(name); i < n; i++) {
    //    if (name[i] == ' ') {
    //        printf("%c", name[i+1]);
    //    }        
    //}
    
    printf("%s\n", name);

    return 0;
}

char* stripInvalidChars(int length, string str) {
    // how could I have done this in-place instead of creating a second string?
    char *result;
    // had to do the below because it wouldn't let me create an array of variable length
    //how do you check that malloc returned a valid (non-null) pointer before you copy data there
    // how do you dealloc when you don't need result anymore?
    result = (char *)malloc(sizeof(char) * (length+1));

    for (int i = 0; i < length; i++) {
        if (isSpace(str[i]) == 1 || isLowerCase(str[i]) == 1 || isUpperCase(str[i]) == 1) {
            char safeToCat[2] = {str[i], '\0'};
            strcat(result, safeToCat);
        }
    }

    // this requires more processing but kills it early if there's nothing input.
    // good design? bad design?
    if (strlen(result) > 0) {
        return result;
        free(result);
    } else {
        printf("Not a valid name.");
        exit(0);
    }
}

char* stripExcessWhitespace(int length, string str) {
    char *result;
    result = (char *)malloc(sizeof(char) * (length+1));

    int strStartIndex = -1;
    for (int i = 0; i < length; i++) {
        if (isSpace(str[i]) == 0) {
            strStartIndex = i;
            break;
        }
    }

    // if nothing but whitespace, die
    if (strStartIndex == -1) {
        exit(0);
    }
    
    return str;
    free(result);
}

int isLowerCase(char theChar) {
    // use ASCII table values to check case
    if (((int) theChar >= 97) && ((int) theChar <= 122)) {
        return 1;
    } else {
        return 0;
    }
}

int isUpperCase(char theChar) {
    // use ASCII table values to check case
    if (((int) theChar >= 65) && ((int) theChar <= 90)) {
        return 1;
    } else {
        return 0;
    }
}

int isSpace(char theChar) {
    // use ASCII table values to check
    if ((int) theChar == 32) {
        return 1;
    } else {
        return 0;
    }
}

char toUpperCase(char theChar) {
    return (int) theChar - 32;
}
