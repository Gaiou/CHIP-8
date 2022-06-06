#include "cpu.h"

const uint8_t fontset[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,   // 0
    0x20, 0x60, 0x20, 0x20, 0x70,   // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,   // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,   // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,   // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0,   // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0,   // 6
    0xF0, 0x10, 0x20, 0x40, 0x40,   // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0,   // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0,   // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90,   // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0,   // B
    0xF0, 0x80, 0x80, 0x80, 0xF0,   // C
    0xE0, 0x90, 0x90, 0x90, 0xE0,   // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0,   // E
    0xF0, 0x80, 0xF0, 0x80, 0x80    // F
};

void initializeCPU() {
    current_opcode = 0;

    program_counter = 0x200;
    index_register = 0;
    stack_pointer = 0;
	
    delay_timer = 0;
    sound_timer = 0;

    for (int i = 0; i < 4096; i++)
        memory[i] = 0;

    for (int i = 0; i < 80; i++)
        memory[i + 0x050] = fontset[i]; 

    for (int i = 0; i < (64*32); i++)
        display[i] = 0;

    for (int i = 0; i < 16; i++) {
        v_register[i] = 0;
        stack[i] = 0;
        keyboard[i] = false;
    }
}

void cycleCPU() {

}