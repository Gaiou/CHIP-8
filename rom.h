#ifndef ROM_H
#define ROM_H

FILE* openROM();
void closeROM(FILE* file);
long getSize(FILE* file);

#endif