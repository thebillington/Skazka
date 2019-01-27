#include <gb/gb.h>
#include <string.h>

#include "assets/alpha.c" // Sprite sheet with ASCII characters
#include "assets/frame.c"
#include "assets/arrow.c"

extern void clearBackground();

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

char* lines[] = { "ACCORDING TO ALL", "KNOWN LAWS OF", "AVIATION, THERE", "IS NO WAY A BEE", "SHOULD BE ABLE TO", "FLY.", "NO", "YES"};

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

UINT8 makeDecision(UINT8 openingLine, UINT8 numberOfLines) {
	
	UINT8 decision = 0;

	BGP_REG = 0x1BU;

	
	clearBackground();
	
	displayMessage(openingLine, numberOfLines);
	SHOW_WIN;

	// All overworld sprites should be removed here

	set_bkg_tiles(5, 8, 10, 1, "YES     NO");
	set_sprite_data(0x2F, 1, arrow);
	set_sprite_tile(20, 0x2F);
	move_sprite(20, 116, 88);

	while (!(joypad() & J_A)) {
		if (joypad() & J_LEFT) {
			decision = 1;
			move_sprite(20, 56, 88);
			waitpadup();
		}
		if (joypad() & J_RIGHT) {
			decision = 0;
			move_sprite(20, 116, 88);
			waitpadup();
		}
	}
	waitpadup();
	
	HIDE_WIN;
	BGP_REG = 0xE4U;

	// Bring back the sprites and the background here

	return decision;

}