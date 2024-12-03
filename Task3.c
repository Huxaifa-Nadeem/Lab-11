#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWordInFile(const char *filename, const char *oldWord, const char *newWord) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) return;

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *fileContent = (char *)malloc(fileSize + 1);
    if (fileContent == NULL) return;

    fread(fileContent, 1, fileSize, file);
    fileContent[fileSize] = '\0';

    char *pos;
    while ((pos = strstr(fileContent, oldWord)) != NULL) {
        size_t lenBefore = pos - fileContent;
        size_t oldWordLen = strlen(oldWord);
        size_t newWordLen = strlen(newWord);

        char *newContent = (char *)malloc(fileSize + newWordLen - oldWordLen + 1);
        if (newContent == NULL) return;

        strncpy(newContent, fileContent, lenBefore);
        newContent[lenBefore] = '\0';
        strcat(newContent, newWord);
        strcat(newContent, pos + oldWordLen);

        free(fileContent);
        fileContent = newContent;
        fileSize = strlen(fileContent);
    }

    fseek(file, 0, SEEK_SET);
    fwrite(fileContent, 1, fileSize, file);
    ftruncate(fileno(file), fileSize);

    free(fileContent);
    fclose(file);
}

int main() {
    replaceWordInFile("example.txt", "old", "new");
    return 0;
}
