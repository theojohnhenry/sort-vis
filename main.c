#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sorter.h"

const int screen_width = 800;
const int screen_height = 800;

void draw_data(int data[], int n, int spesh);

int main()
    {

    int data[] = {12, 5, 6, 1 ,5 ,8 ,2 ,3 ,4, 9};
    int n = sizeof(data)/sizeof(data[0]);


    InitWindow(screen_width, screen_height, "PENIS WINDOW");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        draw_data(data, n, rand()%n);
    }    

    CloseWindow(); 

    return 0;
}

void draw_data(int data[], int n, int spesh)
{

    int staple_pixelwidth = screen_width/n;

    BeginDrawing();
    int i;
    for(i=0; i <= n-1; i++)
    {
        Color current_color = RAYWHITE;
        if(i == spesh) {current_color = RED;}

        printf("DEBUG(drawing): i=%i, data=%i \n ", i, data[i]);

        int current_posX = i*staple_pixelwidth;
        int current_height = data[i] * 40;

        DrawRectangle(
                current_posX , 
                screen_height-current_height, 
                staple_pixelwidth, 
                current_height, 
                current_color);
    }
    EndDrawing();
}

