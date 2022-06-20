#include "cpu.h"
#include <stdio.h>

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
    current_opcode = memory[program_counter] << 8 | memory[program_counter + 1];
    program_counter += 2;
    
    switch (current_opcode & 0xF000) {
        case 0x0000:
            switch (current_opcode & 0x000F) {
                case 0x0000:
                    break;
                case 0x000E:
                    break;
            }
            break;
        case 0x1000:
            break;
        case 0x2000:
            break;
        case 0x3000:
            break;
        case 0x4000:
            break;
        case 0x5000:
            break;
        case 0x6000:
            break;
        case 0x7000:
            break;
        case 0x8000:
            switch (current_opcode & 0x000F) {
                case 0x0000:
                    break;
                case 0x0001:
                    break;
                case 0x0002:
                    break;
                case 0x0003:
                    break;
                case 0x0004:
                    break;
                case 0x0005:
                    break;
                case 0x0006:
                    break;
                case 0x0007:
                    break;
                case 0x000E:
                    break;
            }
            break;
        case 0x9000:
            break;
        case 0xA000:
            break;
        case 0xB000:
            break;
        case 0xC000:
            break;
        case 0xD000:
            break;
        case 0xE000:
            switch (current_opcode & 0x00FF) {
                case 0x009E:
                    break;
                case 0x00A1:
                    break;
            }
            break;
        case 0xF000:
            switch (current_opcode & 0x00FF) {
                case 0x0007:
                    break;
                case 0x000A:
                    break;
                case 0x0015:
                    break;
                case 0x0018:
                    break;
                case 0x001E:
                    break;
                case 0x0029:
                    break;
                case 0x0033:
                    break;
                case 0x0055:
                    break;
                case 0x0065:
                    break;
            }
            break;
        default:
            printf("Error Opcode: [0x%X] ", current_opcode);
            break;
        }
}