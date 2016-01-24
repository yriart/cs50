#include <stdio.h>
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
        exit(0);
    } 
    if (height <= 0) {
        exit(0);
    }

    return 0;
}

int printChars(int length, char thechar) {
    for (int i = length; i > 0; i--) {
        printf("%c", thechar);
    }
     
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

