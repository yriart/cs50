#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[]) {
    for (int i = 0; i < argc; i++) {
        // how come in the below line, I don't have to say 'int n' since I'm declaring n for the first time?
        for (int j = 0, n = strlen(argv[i]); j < n; j++) {
            printf("%c\n", argv[i][j]);
        }
        printf("\n");
    }

    return 0;
}
