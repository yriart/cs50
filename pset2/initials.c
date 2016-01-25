#include <stdio.h>
#include <cs50.h>
#include <string.h>

void stripInvalidChars(int sourceStrLen, char *sourceStr, char *destStr);
void populateInitials(int sourceStrLen, char *sourceStr, char *destStr);
int isLowerCase(char theChar);
int isUpperCase(char theChar);
char toUpperCase(char theChar);

int main(void) {
    char *name = GetString();
    int nameLength = strlen(name);
    char normalizedName[nameLength + 1];
    char initials[nameLength + 1];

    stripInvalidChars(nameLength, name, normalizedName);
    populateInitials(nameLength, normalizedName, initials);

    for (int j = 0, n = strlen(initials); j < n; j++) {
        if (isLowerCase(initials[j])) {
            initials[j] = toUpperCase(initials[j]);
        }
    }
    printf("%s\n", initials);

    free(name);
    return 0;
}

void stripInvalidChars(int sourceStrLen, char *sourceStr, char *destStr) {
    int destStrIndex = 0;
    for (int i = 0; i < sourceStrLen; i++) {
        if (sourceStr[i] == ' ' || isLowerCase(sourceStr[i]) || isUpperCase(sourceStr[i])) {
            destStr[destStrIndex] = sourceStr[i];
            destStrIndex++;
        }
    }
    destStr[destStrIndex] = '\0';
}

void populateInitials(int sourceStrLen, char *sourceStr, char *destStr) {
    destStr[0] = sourceStr[0];
    int destStrIndex = 1;
    for (int i = 1; i < sourceStrLen; i++) {
        if (sourceStr[i] == ' ') {
            destStr[destStrIndex] = sourceStr[i + 1];
            destStrIndex++;
        }        
    }
    destStr[destStrIndex] = '\0';
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

char toUpperCase(char theChar) {
    return (int) theChar - 32;
}
