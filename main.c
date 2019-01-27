#include <gb/gb.h>
#include <rand.h>

#include "dialogue.c"

// Include all of the sprites
#include "assets/wisp.c"
#include "assets/child.c"
#include "assets/BabaYagaLeft.c"
#include "assets/BabaYagaRight.c"

// include all the story backgrounds
#include "assets/title_screen.c"
#include "assets/babayaga_background.c"
#include "assets/main_character.c"
#include "assets/woodman.c"
#include "assets/stepmother.c"

// include dungeon background
#include "assets/world.c"

// Enums
typedef enum {
    dungeon,
    title_screen,
    baba_background,
    maincharacter,
    woodman,
    stepmother
} backgrounds;

// Prototypes
void loadBabayaga();
void babayagaMovement();
void playerMovement();
void drawSprites();
void loadSprites();
void drawBackground(backgrounds b);
void moveWisps(UINT8 x, UINT8 y);
UINT8 rectCollision(INT8 x1, INT8 y1, INT8 w1, INT8 h1, INT8 x2, INT8 y2, INT8 w2, INT8 h2);
UINT8 abs(INT8 x);
void log(char* m, UINT8 data);
void clearBackground();
void loadDungeon();
void speak(backgrounds b, UINT8 start, UINT8 len, UINT8 d);
void footsteps();

// Set the base location of the sprites and backgrounds
unsigned char memoryCounter = 0x1A;
unsigned char backgroundCounter = 0x00;
unsigned char dungeonCounter = 0x80;

// Set the fps
UINT8 FPS = 16; // 60 FPS
//UINT8 FPS = 41; // 24 FPS
//UINT8 FPS = 64; // 15 FPS

// Store the location of each sprite
UINT8 ballLocation = 0;
UINT8 wispLocation[3] = {1, 2, 3};
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

// Store a boolean to check whether this is the first wisp of the game
UINT8 firstWisp = 1;

// State whether Babayaga moved last turn or not
UINT8 babayagaMoved = 0;

// Store the current state
UINT8 state = 1;

void main() {

    // Load everything
    clearBackground();
	DISPLAY_ON;
	SHOW_BKG;
    loadSprites();

    // Menu loop
    while(1) {

        // // Title screen
        // drawBackground(title_screen);
        // while(!(joypad() & J_START || joypad() & J_A));

        // // // Introduction dialogue
        // clearBackground();
        // initWin();
        // displayMessage(0, 6);
        // speak(maincharacter,6,1,2);
        // speak(stepmother,7,4,2);
        // speak(maincharacter,11,1,1);
        // speak(stepmother,12,3,1);
        // speak(maincharacter,15,1,1);
        // speak(maincharacter,16,4,1);
        // speak(stepmother,20,3,1);
        // speak(maincharacter,23,1,1);
        // speak(maincharacter,24,1,1);
        // delay(1000);
        // clearBackground();
        // initWin();
        // displayMessage(25, 11);

        // // Load the first dungeon
        // drawBackground(dungeon);
        // delay(1000);
        // displayMessage(36,4);
        // delay(1000);
        // displayMessage(40,4);
        // loadDungeon();

        // Footsteps decision
        initWin();
        delay(1000);
        if (makeDecision(80, 2)) {
            clearBackground();
            initWin();
            displayMessage(82, 4);
            speak(maincharacter,86,2,1);
            delay(1000);
            clearBackground();
            initWin();
            displayMessage(88, 3);
            speak(maincharacter,91,1,1);
            delay(2000);
            speak(baba_background,92,1,2);
            speak(maincharacter,93,2,2);
            speak(baba_background,95,4,2);
            delay(1000);
            clearBackground();
            initWin();
            displayMessage(99,5);
            delay(2000);
            clearBackground();
            initWin();
            displayMessage(104, 1);
        }
        else {
            clearBackground();
            initWin();
            displayMessage(105, 2);
            delay(1000);
            if(makeDecision(107,2)) {
                clearBackground();
                initWin();
                displayMessage(109, 22);
                speak(woodman,131,3,2);
                speak(maincharacter,134,1,1);
                speak(woodman,135,5,1);
            }
            else {
                drawBackground(baba_background);
                delay(5000);
            }
        }
    }

}

// Create a function to allow characters to speak
void speak(backgrounds b, UINT8 start, UINT8 len, UINT8 d) {
    drawBackground(b);
    delay(d * 1000);
    clearBackground();
	initWin();
    displayMessage(start, len);
}

// Function to run the dungeon
void loadDungeon() {

    // Set the wisp count to 3
    UINT8 wispCount = 3;

    SHOW_SPRITES;

    // Game loop
    while(wispCount) {

        // Call player movement
        playerMovement();

        babayagaMovement();

        // Check for a collision between the player and the wisps
        for (i = 0; i < 3; i++) {
            if (rectCollision(playerData[1],playerData[2],16,16,wispsX[i],wispsY[i],8,8)) {
                
                // Check if this is the first wisp
                if(firstWisp) {
                    if (wispCount == 3) {
                        displayMessage(44,15);
                    }
                    else if (wispCount == 2) {
                        displayMessage(59,12);
                    }
                    else if(wispCount == 1) {
                        displayMessage(71,9);
                        firstWisp = 0;
                    }
                }
                wispsX[i] = 0;
                wispsY[i] = 0;

                wispCount--;

            }
        }

        // Draw each sprite to the correct location
        drawSprites();

        // Sleep to keep steady (ish) FPS
        delay(FPS);
    }

    HIDE_SPRITES;
}


// Function to clear the background
void clearBackground() {

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 18; j++) {
            set_bkg_tiles(i, j, 1, 1, 7);
        }
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
        move_sprite(wispLocation[i], wispsX[i], wispsY[i]);

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
    set_sprite_data(memoryCounter, wispTileLen, wispTile);
    for (i = 0; i < 3; i++) {
        set_sprite_tile(wispLocation[i], memoryCounter);
    }
    memoryCounter+=wispTileLen;

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
void drawBackground(backgrounds b) {

     // Hide the background
    HIDE_BKG;

    switch (b) {
        case dungeon:
            set_bkg_data(dungeonCounter, world_tile_len, world_tile);
            set_bkg_tiles(0x00, 0x00, world_data_width, world_data_height, world_data);
            break;
        case title_screen:
            set_bkg_data(backgroundCounter, title_screen_main_tile_count, title_screen_main_tile_data);
            set_bkg_tiles(0x00, 0x00, title_screen_main_tile_map_width, title_screen_main_tile_map_height, title_screen_main_map_data);
            break;
        case baba_background:
            set_bkg_data(backgroundCounter, baba_background_tile_count, baba_background_tile_data);
            set_bkg_tiles(0x00, 0x00, baba_background_tile_map_width, baba_background_tile_map_height, baba_background_map_data);
            break;
        case maincharacter:
            set_bkg_data(backgroundCounter, maincharacter_tile_count, maincharacter_tile_data);
            set_bkg_tiles(0x00, 0x00, maincharacter_tile_map_width, maincharacter_tile_map_height, maincharacter_map_data);
            break;
        case woodman:
            set_bkg_data(backgroundCounter, woodman_tile_count, woodman_tile_data);
            set_bkg_tiles(0x00, 0x00, woodman_tile_map_width, woodman_tile_map_height, woodman_map_data);
            break;
        case stepmother:
            set_bkg_data(backgroundCounter, stepmother_tile_count, stepmother_tile_data);
            set_bkg_tiles(0x00, 0x00, stepmother_tile_map_width, stepmother_tile_map_height, stepmother_map_data);
            break;
    }

    // Render the background
    SHOW_BKG;
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
