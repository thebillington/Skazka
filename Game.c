// http://www.loirak.com/gameboy/gbprog.php

#include <gb/gb.h>
#include <stdio.h>

void main()
{
        printf("Hello World!");
        printf("\nPress Start");
        waitpad(J_START);  // other keys are J_A, J_UP, J_SELECT, etc.
        printf("\nGGJ 2019");
}
