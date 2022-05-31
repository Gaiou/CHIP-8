#ifndef CHIP8_H
#define CHIP8_H

#include <stdint.h>
#include <stdbool.h>

uint16_t current_opcode;

uint8_t memory[4096];
uint8_t display[64*32];
uint8_t v_register[16];

uint16_t program_counter;
uint16_t index_register;

uint16_t stack[16];
uint16_t stack_pointer;

uint8_t delay_timer;
uint8_t sound_timer;

bool keyboard[16];

void initialize();
void cycle();

#endif