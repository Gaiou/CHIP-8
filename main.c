#include <stdio.h>
#include <stdlib.h>
#include "cpu.h"
#include "rom.h"

int main(int argc, char *argv[]) {
    FILE* file = openROM();
    if (file == NULL) {
        printf("ERROR: ROM does not exist\n");
        return 0;
    }

    initializeCPU();
    
    long size = getSize(file);
    uint8_t* buffer = (uint8_t*) malloc(size * sizeof(uint8_t)); // allocate memory for 132 elements/uint8 (132 bytes)
    fread(buffer, sizeof(buffer), size, file);   

    for (int i = 0; i < size; i++) {
        memory[i + 0x200] = buffer[i];
        printf("Index: %d = %X \n", i + 0x200, memory[i + 0x200]);
    }

    closeROM(file);
    free(buffer);

    return 0;
}