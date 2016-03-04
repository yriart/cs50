#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

void validateCLI(int argc, char *key);
int isValidKey(char *key);
int isLowerCase(char theChar);
int isUpperCase(char theChar);
void encryptString(char *sourceStr, char *destStr, char *key);
char encryptChar(char sourceChar, int lowerASCIILimit, int upperASCIILimit, char key);

int main(int argc, char *argv[]) {
    char *key = argv[1];
    validateCLI(argc, key);

    char *sourceStr = GetString();
    int length = strlen(sourceStr);
    char destStr[length + 1];

    encryptString(sourceStr, destStr, key);
    printf("%s\n", destStr);

    free(sourceStr);
    return 0;
}

void validateCLI(int argc, char *key) {
    if (argc != 2) {
        printf("Must supply a single key! Exiting.\n");
        exit(1);
    }
    if (!isValidKey(key)) {
        printf("Key cannot contain non-alphabetical characters! Exiting.\n");
        exit(1);
    }
}

int isValidKey(char *key) {
    for (int i = 0, l = strlen(key); i < l; i++) {
        if (isLowerCase(key[i]) || isUpperCase(key[i])) {
            return 1;
        }
    }
    return 0;
}

int isLowerCase(char theChar) {
    if (((int) theChar >= 97) && ((int) theChar <= 122)) {
        return 1;
    }
    return 0;
}

int isUpperCase(char theChar) {
    if (((int) theChar >= 65) && ((int) theChar <= 90)) {
        return 1;
    }
    return 0;
}

char encryptChar(char sourceChar, int lowerASCIILimit, int upperASCIILimit, char key) {
    char encryptedChar;
    int added = (int) sourceChar + (int) key % 26;
    if (added > upperASCIILimit) {
        encryptedChar = (char) ((added % upperASCIILimit) + (lowerASCIILimit - 1));
    } else {
        encryptedChar = (char) added;
    }
    return encryptedChar;
}

void encryptString(char *sourceStr, char *destStr, char *key) {
    int length = strlen(sourceStr);
    int keyIndex = 0;
    for (int i = 0; i < length; i++) {
        keyIndex = i % strlen(key);
        if (isLowerCase(sourceStr[i])) {
            //printf("for %c in sourceStr, using keyIndex %i, which maps to %c\n", sourceStr[i], keyIndex, key[keyIndex]);
            destStr[i] = encryptChar(sourceStr[i], 97, 122, key[keyIndex]);
        } else if (isUpperCase(sourceStr[i])) {
            destStr[i] = encryptChar(sourceStr[i], 65, 90, key[keyIndex]);
        } else {
            destStr[i] = sourceStr[i];
        }
    }
    destStr[length] = '\0';
}
