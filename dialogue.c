#include <gb/gb.h>
#include <string.h>

#include "assets/alpha.c" // Sprite sheet with ASCII characters
#include "assets/frame.c"

#include "narrative.c"

// Constants
#define ASCII_START 0x20

// Macros

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

#define PRINT(line, message) set_win_tiles(1, line, strlen(message), 1, message)

// Initialise the window layer for printing messages
void initWin() {

	move_win(7, 112);

	// Load ASCII tiles and box frame into window layer
	set_win_data(0x10, 8, frame_tile_data);
	set_win_data(ASCII_START, 64, alpha);

	set_win_tiles(0, 0, 20, 4, frame_map_data);

}

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