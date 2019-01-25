#include <gb/gb.h>

// Include all of the sprites
#include "assets/ball.c"
#include "assets/mushroom.c"

// Prototypes
void playerMovement();
void drawSprites();
void loadSprites();

// Set the base location of the tile map
unsigned char memoryCounter = 0x1A;

// Set the fps
int FPS = 16;

// Store the location of each sprite
int ballLocation = 0;

// Store the number of sprites
const int spriteCount = 2;

// Create data structure to hold the sprite data
int spriteLocations[2] = {0, 1};
int spriteX[2] = {75, 60};
int spriteY[2] = {75, 60};

void main() {

    // Load the sprites
    loadSprites();

    // Game loop
    while(1) {

        // Call player movement
        playerMovement();

        // Draw each sprite to the correct location
        drawSprites();

        // Render the sprites
        SHOW_SPRITES;

        // Sleep to keep steady (ish) FPS
        delay(FPS);
    }

}

// Create a function to handle player movement
void playerMovement() {

        // Check for button presses and move the player
        if (joypad() & J_RIGHT) {
            spriteX[ballLocation]++;
            if (spriteX[ballLocation] > 160) {
                spriteX[ballLocation] = 160;
            }
        }
        if (joypad() & J_LEFT) {
            spriteX[ballLocation]--;
            if (spriteX[ballLocation] < 8) {
                spriteX[ballLocation] = 8;
            }
        }
        if (joypad() & J_UP) {
            spriteY[ballLocation]--;
            if (spriteY[ballLocation] < 16) {
                spriteY[ballLocation] = 16;
            }
        }
        if (joypad() & J_DOWN) {
            spriteY[ballLocation]++;
            if (spriteY[ballLocation] > 152) {
                spriteY[ballLocation] = 152;
            }
        }
}

// Function to render each sprite
void drawSprites() {

    // Look at each sprite
    int i;
    for (i = 0; i < spriteCount; i++) {

        // Render the sprite (move it to the correct location to be rendered)
        move_sprite(spriteLocations[i], spriteX[i], spriteY[i]);

    }

}

// Function to load sprites
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