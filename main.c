#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>

// Include all of the sprites
#include "assets/mushroom.c"
#include "assets/bridge.c"
#include "assets/child.c"
#include "assets/world.c"

// Prototypes
void drawSprites2x2();
void playerMovement();
void drawSprites();
void loadSprites();
void drawBackground();
void loadBackgrounds();
UINT8 rectCollision(INT8 x1, INT8 y1, INT8 w1, INT8 h1, INT8 x2, INT8 y2, INT8 w2, INT8 h2);
UINT8 abs(INT8 x);
void log(char* m, UINT8 data);

// Set the base location of the sprites and backgrounds
unsigned char memoryCounter = 0x1A;
unsigned char backgroundCounter = 0x00;

// Set the fps
UINT8 FPS = 16; //60 FPS
// UINT8 FPS = 32; // 30 FPS
// UINT8 FPS = 64; // 15 FPS

// Store the location of each sprite
UINT8 ballLocation = 0;
UINT8 mushroomLocation[3] = {1, 2, 3};
UINT8 childLocation[4] = {4, 5, 6, 7};

// Store the number of sprites
const UINT8 spriteCount = 2;

// Store the player data
UINT8 playerData[3] = {0, 8, 88};

// Create data structure to hold the sprite data
UINT8 wispsX[3] = {60, 75, 90};
UINT8 wispsY[3] = {60, 75, 90};

// Store the speed of the player (allows for a grid based instead of pixel based movement if set to 8)
UINT8 playerSpeed = 1;

// Global iterator
UINT8 i;
UINT8 j;

// Store the current state
UINT8 state = 1;

void main() {

    // Load the sprites
    loadSprites();
    loadBackgrounds();

    // Draw the default background
    drawBackground();

    // Game loop
    while(1) {

        // Call player movement
        playerMovement();

        // Check for a collision between the player and the wisps
        for (i = 0; i < 3; i++) {
            if (rectCollision(playerData[1],playerData[2],8,8,wispsX[i],wispsY[i],8,8)) {

                // Move the mushroom
                UINT8 xRand = abs((UINT8)rand());
                UINT8 yRand = abs((UINT8)rand());
                wispsX[i] = 8 + (xRand % 152);
                wispsY[i] = 16 + (yRand % 136);

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

// Procedure to handle drawing 2x2 tile sprites
void drawSprites2x2() {
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            move_sprite(childLocation[(i * 2) + j], playerData[1] + (j * 8), playerData[2] + (i * 8));
        }
    }
}

// Procedure to handle player movement based on button presses (J_PAD)
void playerMovement() {

        // Check for button presses and move the player
        if (joypad() & J_RIGHT) {
            playerData[1] += playerSpeed;
            if (playerData[1] > 160) {
                playerData[1] = 160;
            }
        }
        if (joypad() & J_LEFT) {
            playerData[1] -= playerSpeed;
            if (playerData[1] < 8) {
                playerData[1] = 8;
            }
        }
        if (joypad() & J_UP) {
            playerData[2] -= playerSpeed;
            if (playerData[2] < 16) {
                playerData[2] = 16;
            }
        }
        if (joypad() & J_DOWN) {
            playerData[2] += playerSpeed;
            if (playerData[2] > 152) {
                playerData[2] = 152;
            }
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
    drawSprites2x2();

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
