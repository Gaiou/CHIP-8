#include <stdio.h>
#include "rom.h"

FILE* openROM() {
    char path[30];

    printf("Filepath to ROM: ");
    scanf("%s", path);

    printf("Opening ROM...\n");
    FILE* file = fopen(path, "rb");

    return file;
}

void closeROM(FILE* file) {
    fclose(file);
    printf("Closing ROM...\n");

    return;
}

long getSize(FILE* file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    printf("Size of ROM file: %ld bytes\n", size);

    return size;
}