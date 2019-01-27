#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>

#include "dialogue.c"

// Include all of the sprites
#include "assets/mushroom.c"
#include "assets/bridge.c"
#include "assets/child.c"
#include "assets/BabaYagaLeft.c"
#include "assets/BabaYagaRight.c"
#include "assets/world.c"

// Prototypes
void loadBabayaga();
void babayagaMovement();
void playerMovement();
void drawSprites();
void loadSprites();
void drawBackground();
void loadBackgrounds();
void moveWisps(UINT8 x, UINT8 y);
UINT8 rectCollision(INT8 x1, INT8 y1, INT8 w1, INT8 h1, INT8 x2, INT8 y2, INT8 w2, INT8 h2);
UINT8 abs(INT8 x);
void log(char* m, UINT8 data);

// Set the base location of the sprites and backgrounds
unsigned char memoryCounter = 0x1A;
unsigned char backgroundCounter = 0x80;

// Set the fps
UINT8 FPS = 16; // 60 FPS
//UINT8 FPS = 41; // 24 FPS
//UINT8 FPS = 64; // 15 FPS

// Store the location of each sprite
UINT8 ballLocation = 0;
UINT8 mushroomLocation[3] = {1, 2, 3};
UINT8 childLocation[4] = {4, 5, 6, 7};
UINT8 babayagaLocation[8] = {12, 13, 14, 15, 16, 17, 18, 19};

// Store the number of sprites
const UINT8 spriteCount = 2;

// Store the player data
UINT8 playerData[3] = {0, 5, 88};

// Create data structure to hold the sprite data
UINT8 wispsX[3] = {60, 75, 90};
UINT8 wispsY[3] = {60, 75, 90};

// Store BabaYaga data
UINT8 babayagaX = 152;
UINT8 babayagaY = 40;
UINT8 babayagaDirection = 1;

// Store the speed of the player (allows for a grid based instead of pixel based movement if set to 8)
UINT8 playerSpeed = 1;
UINT8 babayagaSpeed = 14;

UINT8 babayagaMem;

// Global iterator
UINT8 i;
UINT8 j;

// Store the horizontal and vertical screen scroll
UINT8 xScroll = 5;
UINT8 yScroll = 16;

// Store the max scroll allowed of the screen
const UINT8 xScrollMax = 12 * 8;
const UINT8 yScrollMax = 14 * 8;

// State whether Babayaga moved last turn or not
UINT8 babayagaMoved = 0;

// Store the current state
UINT8 state = 1;

void main() {

	DISPLAY_ON;

	SHOW_BKG;

    // Load the sprites
    loadSprites();
    loadBackgrounds();
	initWin();

    // Draw the default background
    drawBackground();

    // Game loop
    while(1) {

        // Call player movement
        playerMovement();

        babayagaMovement();

        // Check for a collision between the player and the wisps
        for (i = 0; i < 3; i++) {
            if (rectCollision(playerData[1],playerData[2],16,16,wispsX[i],wispsY[i],8,8)) {

                // Move the wisp
                UINT8 xRand = abs((UINT8)rand());
                UINT8 yRand = abs((UINT8)rand());
                wispsX[i] = 8 + (xRand % 152);
                wispsY[i] = 16 + (yRand % 136);

                displayMessage(0, 6);

            }
        }

        // Draw each sprite to the correct location
        drawSprites();

        // Render the sprites
        SHOW_SPRITES;

        // Sleep to keep steady (ish) FPS
        delay(FPS);
    }

}

void loadBabayaga() {
    for (i = 0; i < BabaYagaLeftTilesLen; i++) {
        set_sprite_tile(babayagaLocation[i], (babayagaDirection * 8) + babayagaMem + i);
        // memoryCounter++;
    }
}

void babayagaMovement() {

    // Check whether Babayaga should moved
    if (babayagaMoved == 0) {

        babayagaMoved = 30;

        if (babayagaX > playerData[1]) {
            babayagaX -= babayagaSpeed;
            babayagaDirection = 0; 
            loadBabayaga();
        } else if (babayagaX < playerData[1]) {
            babayagaX += babayagaSpeed;
            babayagaDirection = 1;
            loadBabayaga();
        }

        if (babayagaY < playerData[2]) {
            babayagaY += babayagaSpeed;
        } else if (babayagaY > playerData[2]) {
            babayagaY -= babayagaSpeed;
        }
        
        if (babayagaX > 248) {
            babayagaX = 248;
            
        } else if (babayagaX < 8) {
            babayagaX = 8;
            
        }
    }
    else if(babayagaMoved == 10) {
        babayagaX += 1;
        babayagaMoved--;

    }
    else if(babayagaMoved == 9) {
        babayagaX -=2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 8) {
        babayagaX += 1;
        babayagaY += 2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 7) {
        babayagaX -= 1;
        babayagaY -= 2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 6) {
        babayagaX += 2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 5) {
        babayagaX -= 1;
        babayagaY += 2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 4) {
        babayagaY += 2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 3) {
        babayagaX -= 2;
        babayagaY -= 1;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 2) {
        babayagaX += 1;
        babayagaY += 2;
        babayagaMoved--;
        
    }
    else if(babayagaMoved == 1) {
        babayagaY += 2;
        babayagaMoved--;
        
    }
    else {
        babayagaMoved--;
    }
}

// Procedure to handle player movement based on button presses (J_PAD)
void playerMovement() {

    // Check for button presses and move the player
    if (joypad() & J_RIGHT) {
        playerData[1] += playerSpeed;
        if (playerData[1] > 155) {
            // Check whether the screen should scroll
            if (xScroll < xScrollMax) {
                babayagaX-=playerSpeed;
                moveWisps(-playerSpeed,0);
                scroll_bkg(playerSpeed,0);
                xScroll++;
            }
            playerData[1] = 155;
        }
    }
    if (joypad() & J_LEFT) {
        playerData[1] -= playerSpeed;
        if (playerData[1] < 5) {
            // Check whether the screen should scroll
            if (xScroll > 5) {
                babayagaX+=playerSpeed;
                moveWisps(playerSpeed, 0);
                scroll_bkg(-playerSpeed,0);
                xScroll--;
            }
            playerData[1] = 5;
        }
    }
    if (joypad() & J_UP) {
        playerData[2] -= playerSpeed;
        if (playerData[2] < 16) {
            // Check whether the screen should scroll
            if (yScroll > 16) {
                babayagaY+=playerSpeed;
                moveWisps(0, playerSpeed);
                scroll_bkg(0,-playerSpeed);
                yScroll--;
            }
            playerData[2] = 16;
        }
    }
    if (joypad() & J_DOWN) {
        playerData[2] += playerSpeed;
        if (playerData[2] > 144) {
            // Check whether the screen should scroll
            if (yScroll < yScrollMax) {
                babayagaY-=playerSpeed;
                moveWisps(0, -playerSpeed);
                scroll_bkg(0,playerSpeed);
                yScroll++;
            }
            playerData[2] = 144;
        }
    }
}

// Procedure to move all of the wisps
void moveWisps(UINT8 x, UINT8 y) {

    // Iterate over the wisp data and move them all
    for (i = 0; i < 3; i++) {
        wispsX[i] += x;
        wispsY[i] += y;
    }

}

// Procedure to render each sprite
void drawSprites() {

    // Look at each sprite
    for (i = 0; i < 3; i++) {

        // Render the sprite (move it to the correct location to be rendered)
        move_sprite(mushroomLocation[i], wispsX[i], wispsY[i]);

    }

    // Draw the 2x2 sprites
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            move_sprite(childLocation[(i * 2) + j], playerData[1] + (j * 8), playerData[2] + (i * 8));
        }
    }

    // Draw the 4x4 sprites
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 2; j++) {
            move_sprite(babayagaLocation[(i * 2) + j], babayagaX + (j * 8), babayagaY + (i * 8));
        }
    }
}

// Procedure to load sprites
void loadSprites() {

    // Create all of the wisp sprites
    SPRITES_8x8;
    set_sprite_data(memoryCounter, mushroomLen, mushroom);
    for (i = 0; i < 3; i++) {
        set_sprite_tile(mushroomLocation[i], memoryCounter);
    }
    memoryCounter+=mushroomLen;

    // Load the child
    SPRITES_8x8;
    set_sprite_data(memoryCounter, childTilesLen, childTiles);

    for (i = 0; i < childTilesLen; i++) {
        set_sprite_tile(childLocation[i], memoryCounter);
        memoryCounter++;
    }

    // Load BabaYaga
    SPRITES_8x8;
    babayagaMem = memoryCounter;
    set_sprite_data(memoryCounter, BabaYagaLeftTilesLen, BabaYagaLeftTiles);
    memoryCounter += BabaYagaLeftTilesLen;
    set_sprite_data(memoryCounter, BabaYagaRightTilesLen, BabaYagaRightTiles);
    memoryCounter += BabaYagaRightTilesLen;

    loadBabayaga();
}

// Procedure to draw the background 
void drawBackground() {

    // Hide the background
    HIDE_BKG;

    // Check the background we want to show
    if (state == 1) {

        // Set the background to the world map
        set_bkg_tiles(0x00, 0x00, world_data_width, world_data_height, world_data);

    }
        
    // Render the background
    SHOW_BKG;

}

// Procedure to load the backgrounds
void loadBackgrounds() {

    // Fix the tile map to work for the given background counter
    // for (i = 0; i <= 256; i++) {
    //     world_data[i] += backgroundCounter;
    // }

    // Create the bridge background
    DISPLAY_ON;
    set_bkg_data(backgroundCounter, world_tile_len, world_tile);

}

// Create a function to check for rect collision
UINT8 rectCollision(INT8 x1, INT8 y1, INT8 w1, INT8 h1, INT8 x2, INT8 y2, INT8 w2, INT8 h2) {

    // Test for a collision between two rects
    return abs(x1-x2) < w1/2 + w2/2 & abs(y1-y2) < h1/2 + h2/2;

}

// Function to return an absolute value
UINT8 abs(INT8 x) {
    if (x == 0) {
        return 0;
    }
    else if (x > 0) {
        return x;
    }
    return -x;
}

// Create a procedure to output a log message
void log(char* m, UINT8 data) {

    printf("%s%d\n",m,(UWORD)data);

}
