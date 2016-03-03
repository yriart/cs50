#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int isLowerCase(char theChar);
int isUpperCase(char theChar);

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
    for (int i = 0; i < length; i++) {
        if (isLowerCase(sourceStr[i])) {
            int added = (int) sourceStr[i] + key;
            if (added > 122) {
                destStr[i] = (char) ((added % 122) + 96);
            } else {
                destStr[i] = (char) added;
            }
        } else if (isUpperCase(sourceStr[i])) {
            int added = (int) sourceStr[i] + key;
            if (added > 90) {
                destStr[i] = (char) ((added % 90) + 64);
            } else {
                destStr[i] = (char) added;
            }
        } else {
            destStr[i] = sourceStr[i];
        }
    }
    destStr[length] = '\0';

    printf("%s\n", destStr);

    free(sourceStr);
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
