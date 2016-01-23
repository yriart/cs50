#include <stdio.h>
#include <string.h>
#include <cs50.h>

int printLine(int length);
int validate(int height);

int main(void) {
    printf("Height: ");
    int height = GetInt();
    validate(height);

    for (int i = height; i > 0; i--) {
        printLine(i);
    }

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

int printLine(int length) {
    char line[40] = {'#', '\0'};
    for (int i = length - 1; i > 0; i--) {
        strcat(line, "#");
    }
    printf("%s\n", line);
     
    return 0;
}
