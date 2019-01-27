#include <gb/gb.h>
#include <string.h>

#include "assets/alpha.c" // Sprite sheet with ASCII characters
#include "assets/frame.c"
#include "assets/arrow.c"

extern void clearBackground();

#include "narrative.c"
#include "credits.c"

// Constants
#define ASCII_START 0x20
#define CLEAR "                  "

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

	UINT8 i;

	PRINT(1, CLEAR);
	PRINT(2, CLEAR);

	SHOW_WIN;

	for (i = openingLine; i < openingLine + numberOfLines; i++) {

		PRINT(2, lines[i]);

		waitpad(J_A);
		waitpadup();

		PRINT(1, CLEAR);
		PRINT(2, CLEAR);

		PRINT(1, lines[i]);

	}

	HIDE_WIN;

}

UINT8 makeDecision(UINT8 openingLine, UINT8 dummy) {
	
	UINT8 i;
	UINT8 decision = 0;

	dummy = dummy; // Avoid compiler warnings

	BGP_REG = 0x1BU;
	
	clearBackground();
	
	SHOW_WIN;
	PRINT(1, lines[openingLine]);
	PRINT(2, lines[openingLine + 1]);

	for (i = 0; i < 20; i++) {
		move_sprite(i, -1, -1);
	}

	SHOW_SPRITES;
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
	HIDE_SPRITES;


	// Bring back the sprites and the background here

	return decision;

}

void rollCreds() {
	
	UINT8 i;

	BGP_REG = 0x1BU;

	SHOW_WIN;

	for (i = 0; i < LEN(credits); i += 2) {
		PRINT(1, CLEAR);
		PRINT(2, CLEAR);
		PRINT(1, credits[i]);
		PRINT(2, credits[i + 1]);
		delay(1500);
	}

	BGP_REG = 0xE4U;

}