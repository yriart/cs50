#include <stdio.h>
#include <string.h>
#include <cs50.h>

int printPyramids(int length);
int printChars(int length, char thechar);
int validate(int height);

int main(void) {
    printf("Height: ");
    int height = GetInt();
    validate(height);

    printPyramids(height);
    
    return 0;
}

int validate(int height) {
    if (height > 23) {
        printf("Height must be no greater than 23.\n");
        exit(1);
    }
    if (height <= 0) {
        exit(0);
    }
}

int printChars(int length, char thechar) {
    char line[40] = {'\0'};
    char safe_string[2] = {thechar, '\0'};
    for (int i = length; i > 0; i--) {
        strcat(line, safe_string);
    }
    printf("%s", line);
     
    return 0;
}

int printPyramids(int height) {
    int count = 1;
    for (int i = height; i > 0; i--) {
        printChars(height - count, ' ');
        printChars(count, '#');
        printChars(2, ' ');
        printChars(count, '#');
        printf("\n");
        count += 1;
    }

    return 0;
}

