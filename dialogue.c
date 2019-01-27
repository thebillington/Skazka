#include <gb/gb.h>
#include <string.h>

#include "assets/alpha.c" // Sprite sheet with ASCII characters

// Constants
#define ASCII_START 0x20

// Macros

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

#define PRINT(line, message) set_win_tiles(1, line, strlen(message), 1, message)

// Initialise the window layer for printing messages
void initWin() {

	move_win(7, 112);

	// Load ASCII tiles into window layer
	set_win_data(ASCII_START, 64, alpha);

}

char* lines[] = { "ACCORDING TO ALL", "KNOWN LAWS OF", "AVIATION, THERE", "IS NO WAY A BEE", "SHOULD BE ABLE TO", "FLY." };

void displayMessage(UINT8 openingLine, UINT8 numberOfLines) {

	char* clear = "                  "; // 18 spaces
	UINT8 i;

	PRINT(1, clear);
	PRINT(2, clear);

	SHOW_WIN;

	for (i = openingLine; i < openingLine + numberOfLines; i++) {

		PRINT(2, lines[i]);

		waitpad(J_A);
		waitpadup();

		PRINT(1, clear);
		PRINT(2, clear);

		PRINT(1, lines[i]);

	}

	HIDE_WIN;

}