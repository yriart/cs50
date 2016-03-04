#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int isLowerCase(char theChar);
int isUpperCase(char theChar);
void encryptString(char *sourceStr, char *destStr, int key);
char encryptChar(char sourceChar, int lowerASCIILimit, int upperASCIILimit, int key);

int main(int argc, string argv[]) {
    int key;
    if (argc != 2) {
        printf("Must supply key value! Exiting.\n");
        return 1;
    } else {
        key = atoi(argv[1]) % 26;
    }

    char *sourceStr = GetString();
    int length = strlen(sourceStr);
    char destStr[length + 1];

    encryptString(sourceStr, destStr, key);
    printf("%s\n", destStr);

    return 0;
}

int isLowerCase(char theChar) {
    if (((int) theChar >= 97) && ((int) theChar <= 122)) {
        return 1;
    } else {
        return 0;
    }
}

int isUpperCase(char theChar) {
    if (((int) theChar >= 65) && ((int) theChar <= 90)) {
        return 1;
    } else {
        return 0;
    }
}

char encryptChar(char sourceChar, int lowerASCIILimit, int upperASCIILimit, int key) {
    char encryptedChar;
    int added = (int) sourceChar + key;
    if (added > upperASCIILimit) {
        encryptedChar = (char) ((added % upperASCIILimit) + (lowerASCIILimit - 1));
    } else {
        encryptedChar = (char) added;
    }
    return encryptedChar;
}

void encryptString(char *sourceStr, char *destStr, int key) {
    int length = strlen(sourceStr);
    for (int i = 0; i < length; i++) {
        if (isLowerCase(sourceStr[i])) {
            destStr[i] = encryptChar(sourceStr[i], 97, 122, key);
        } else if (isUpperCase(sourceStr[i])) {
            destStr[i] = encryptChar(sourceStr[i], 65, 90, key);
        } else {
            destStr[i] = sourceStr[i];
        }
    }
    destStr[length] = '\0';
}
