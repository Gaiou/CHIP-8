#include <stdio.h>
#include "rom.h"

FILE* openROM() {
	char path[30];

	printf("Filepath to ROM: ");
	scanf("%s", path);
	printf("%s \n", path);

	FILE* file = fopen(path, "rb");

	return file;
}

void closeROM(FILE* file) {
	fclose(file);
	printf("Closed ROM");

	return;
}

long getSize(FILE* file) {
	fseek(file, 0, SEEK_END);
	long size = ftell(file);
	fseek(file, 0, SEEK_SET);

	printf("Size of ROM file: %ld bytes\n", size);

	return size;
}