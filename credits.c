#include <gb/gb.h>
#include <string.h>

#define LEN(arr) sizeof(arr)/sizeof(arr[0])

#define PRINT(line, message) set_win_tiles(1, line, strlen(message), 1, message)

#define CLEAR "                  "

const char* credits[][] = {
	
	{"MUSIC",
	"JOSH HERBERT"},
	
	{"ARTIST",
	"LIZA SARATOVA"},
	
	{"ARTIST",
	"M BOGDANIS"},
	
	{"NARRATIVE",
	"JUSTYNA",
	"CHOROSZCZAK"},
	
	{"STORY CONCEPT",
	"ADAM KIRKUP"},
	
	{"PROGRAMMER",
	"AMITAI GAUNT"},
	
	{"PROGRAMMER",
	"LUKE WOOD"},
	
	{"TEAM LEADER/CODER",
	"BILLY REBECCHI"},
	 
	{" "},

	{"GLOBAL GAME",
	"JAM 2019"},
	
	{"SKAZKA"}
};

void rollCreds() {
	
	UINT8 i;

	for (i = 0; i < 11; i++) {
		PRINT(1, CLEAR);
		PRINT(2, CLEAR);
		PRINT(1, credits[i][1]);
		PRINT(2, credits[i][2]);
		waitpad(J_A);
	}

}