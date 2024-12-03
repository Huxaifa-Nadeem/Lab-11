#include <stdio.h>
#include <stdlib.h>

void copyFile(const char *sourceFile, const char *destinationFile) {
    FILE *source = fopen(sourceFile, "r");
    FILE *destination = fopen(destinationFile, "w");
    char ch;

    if (source == NULL || destination == NULL) {
        perror("Error");
        exit(1);
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);
}

int main() {
    copyFile("source.txt", "destination.txt");
    return 0;
}
