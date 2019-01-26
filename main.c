#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>

// Include all of the sprites
#include "assets/ball.c"
#include "assets/mushroom.c"

#include "assets/square.c"

// Prototypes
void drawSprites2x2();
void playerMovement();
void drawSprites();
void loadSprites();
UINT8 rectCollision(INT8 x1, INT8 y1, INT8 w1, INT8 h1, INT8 x2, INT8 y2, INT8 w2, INT8 h2);
UINT8 abs(INT8 x);
void log(char* m, UINT8 data);

// Set the base location of the tile map
unsigned char memoryCounter = 0x1A;

// Set the fps
UINT8 FPS = 16; //60 FPS
// UINT8 FPS = 32; // 30 FPS
//UINT8 FPS = 64; // 15 FPS

// Store the location of each sprite
UINT8 ballLocation = 0;
UINT8 mushroomLocation = 1;
UINT8 squareLocation[4] = {2, 3, 4, 5};

// Store the number of sprites
const UINT8 spriteCount = 2;

// Create data structure to hold the sprite data
UINT8 spriteLocations[2] = {0, 1};
UINT8 spriteX[2] = {75, 60};
UINT8 spriteY[2] = {75, 60};

// Store the speed of the player (allows for a grid based instead of pixel based movement if set to 8)
UINT8 playerSpeed = 1;

// Global iterator
UINT8 i;
UINT8 j;

void main() {

    // Load the sprites
    loadSprites();

    // Game loop
    while(1) {

        // Call player movement
        playerMovement();

        // Check for a collision between the two sprites
        if (rectCollision(spriteX[0],spriteY[0],8,8,spriteX[1],spriteY[1],8,8)) {

            // Move the mushroom
            UINT8 xRand = abs((UINT8)rand());
            UINT8 yRand = abs((UINT8)rand());
            spriteX[1] = 8 + (xRand % 152);
            spriteY[1] = 16 + (yRand % 136);
            // log("X Rand:",xRand);
            // log("Y Rand:",yRand);
            // log("X loc:",spriteX[1]);
            // log("Y Loc:",spriteY[1]);

        }

        // Draw each sprite to the correct location
        drawSprites();
        drawSprites2x2();

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
            move_sprite(squareLocation[(i * 2) + j], 80 + (i * 8), 80 + (j * 8));
        }
    }
}

// Procedure to handle player movement based on button presses (J_PAD)
void playerMovement() {

        // Check for button presses and move the player
        if (joypad() & J_RIGHT) {
            spriteX[ballLocation] += playerSpeed;
            if (spriteX[ballLocation] > 160) {
                spriteX[ballLocation] = 160;
            }
        }
        if (joypad() & J_LEFT) {
            spriteX[ballLocation] -= playerSpeed;
            if (spriteX[ballLocation] < 8) {
                spriteX[ballLocation] = 8;
            }
        }
        if (joypad() & J_UP) {
            spriteY[ballLocation] -= playerSpeed;
            if (spriteY[ballLocation] < 16) {
                spriteY[ballLocation] = 16;
            }
        }
        if (joypad() & J_DOWN) {
            spriteY[ballLocation] += playerSpeed;
            if (spriteY[ballLocation] > 152) {
                spriteY[ballLocation] = 152;
            }
        }
}

// Procedure to render each sprite
void drawSprites() {

    // Look at each sprite
    for (i = 0; i < spriteCount; i++) {

        // Render the sprite (move it to the correct location to be rendered)
        move_sprite(spriteLocations[i], spriteX[i], spriteY[i]);

    }

}

// Procedure to load sprites
void loadSprites() {

    // Create a new sprite to hold the tile map
    SPRITES_8x8;
    set_sprite_data(memoryCounter, ballLen, ball);
    set_sprite_tile(ballLocation, memoryCounter);
    memoryCounter++;

    // Create a new sprite to hold the tile map
    SPRITES_8x8;
    set_sprite_data(memoryCounter, mushroomLen, mushroom);
    set_sprite_tile(mushroomLocation, memoryCounter);
    memoryCounter++;

    SPRITES_8x8;
    set_sprite_data(memoryCounter, SquareTileLen, SquareTile);

    for (i = 0; i < SquareTileLen; i++) {
        set_sprite_tile(squareLocation[i], memoryCounter);
        memoryCounter++;
    }

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
