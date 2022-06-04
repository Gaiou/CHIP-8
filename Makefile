chip8:
	gcc cpu.c rom.c main.c -o chip8

clean:
	rm chip8