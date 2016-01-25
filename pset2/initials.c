#include <stdio.h>
#include <cs50.h>
#include <string.h>

int isLowerCase(char theChar);
char toUpperCase(char theChar);

int main(void) {
    string name = GetString();

    char initials[strlen(name)+1];
    initials[0] = name[0];
    int count = 1;
    for (int i = 1, n = strlen(name); i < n; i++) {
        if (name[i] == ' ') {
            initials[count] = name[i+1];
            count++;
        }        
    }
    initials[count] = '\0';
    
    for (int j = 0, n = strlen(initials); j < n; j++) {
        if (isLowerCase(initials[j]) == 1) {
            initials[j] = toUpperCase(initials[j]);
        }
    }

    printf("%s\n", initials);

    return 0;
}

int isLowerCase(char theChar) {
    // use ASCII table values to check case
    if (((int) theChar >= 97) && ((int) theChar <= 122)) {
        return 1;
    } else {
        return 0;
    }
}

char toUpperCase(char theChar) {
    return (int) theChar - 32;
}
