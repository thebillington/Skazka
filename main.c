#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>

// Include all of the sprites
#include "assets/ball.c"
#include "assets/mushroom.c"

// Prototypes
void playerMovement();
void drawSprites();
void loadSprites();
int rectCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
int abs(int x);
void log(char* m, int data);

// Set the base location of the tile map
unsigned char memoryCounter = 0x1A;

// Set the fps
int FPS = 16; //60 FPS
// int FPS = 32; // 30 FPS
//int FPS = 64; // 15 FPS

// Store the location of each sprite
int ballLocation = 0;

// Store the number of sprites
const int spriteCount = 2;

// Create data structure to hold the sprite data
int spriteLocations[2] = {0, 1};
int spriteX[2] = {75, 60};
int spriteY[2] = {75, 60};

// Store the speed of the player (allows for a grid based instead of pixel based movement if set to 8)
int playerSpeed = 1;

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
            int xRand = abs((UINT8)rand());
            int yRand = abs((UINT8)rand());
            spriteX[1] = 8 + (xRand % 152);
            spriteY[1] = 16 + (yRand % 136);
            log("X Rand:",xRand);
            log("Y Rand:",yRand);
            log("X loc:",spriteX[1]);
            log("Y Loc:",spriteY[1]);

        }

        // Draw each sprite to the correct location
        drawSprites();

        // Render the sprites
        SHOW_SPRITES;

        // Sleep to keep steady (ish) FPS
        delay(FPS);
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
    int i;
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
    set_sprite_tile(1, memoryCounter);
    memoryCounter++;

}

// Create a function to check for rect collision
int rectCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {

    // Test for a collision between two rects
    return abs((int)x1-(int)x2) < w1/2 + w2/2 & abs((int)y1-(int)y2) < h1/2 + h2/2;

}

// Function to return an absolute value
int abs(int x) {
    if (x == 0) {
        return 0;
    }
    else if (x > 0) {
        return x;
    }
    return -x;
}

// Create a procedure to output a log message
void log(char* m, int data) {

    printf("%s%d\n",m,(UWORD)data);

}
