#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char* stripInvalidChars(int length, string theString);
int isLowerCase(char thechar);
int isUpperCase(char thechar);
int isSpace(char thechar);
char toUpperCase(char thechar);

int main(void) {
    string name = GetString();

    //for (int i = 0, n = strlen(name); i < n; i++) {
    //    if (name[i] == ' ') {
    //        printf("%c", name[i+1]);
    //    }        
    //}
    
    printf("%s", stripInvalidChars(strlen(name), name));
    printf("\n");

    return 0;
}

char* stripInvalidChars(int length, string theString) {
    char *result;
    result = (char *)malloc(sizeof(char) * (length+1));

    for (int i = 0; i < length; i++) {
        if (isSpace(theString[i]) == 1 || isLowerCase(theString[i]) == 1 || isUpperCase(theString[i]) == 1) {
            char safeToCat[2] = {theString[i], '\0'};
            strcat(result, safeToCat);
        }
    }

    if (strlen(result) > 0) {
        return result;
    } else {
        printf("Not a valid name.");
        exit(0);
    }
}

int isLowerCase(char thechar) {
    // use ASCII table values to check case
    if (((int) thechar >= 97) && ((int) thechar <= 122)) {
        return 1;
    } else {
        return 0;
    }
}

int isUpperCase(char thechar) {
    // use ASCII table values to check case
    if (((int) thechar >= 65) && ((int) thechar <= 90)) {
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

char toUpperCase(char thechar) {
    return (int) thechar - 32;
}
