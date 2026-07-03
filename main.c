#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

const int screen_width = 800;
const int screen_height = 800;
const float update_interval = 1.0f;
static int I,J;

void draw_data(int data[], int n, int spesh);
void bubble_sort(int data[], int n);
void test();


int main()
    {

    float time_counter = 0.0f;

    int data[] = {12, 5, 6, 1 ,5 ,8 ,2 ,3 ,4, 9};
    int n = sizeof(data)/sizeof(data[0]);

    InitWindow(screen_width, screen_height, "PENIS WINDOW");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        time_counter += GetFrameTime();
        if(time_counter >= update_interval){
            time_counter = 0;
            bubble_sort(data, n);
        }
        draw_data(data, n, I);
    }    

    CloseWindow(); 

    return 0;
}

void draw_data(int data[], int n, int spesh)
{

    int staple_pixelwidth = screen_width/n;

    ClearBackground(BLACK);
    BeginDrawing();
    int i;
    for(i=0; i <= n-1; i++)
    {
        Color current_color = RAYWHITE;
        if(i == spesh) {current_color = RED;}

        //printf("DEBUG(drawing): i=%i, data=%i \n ", i, data[i]);

        int current_posX = i*staple_pixelwidth;
        int current_height = data[i] * 40;

        DrawRectangle(
                current_posX , 
                screen_height-current_height, 
                staple_pixelwidth, 
                current_height, 
                current_color);
    }

    DrawText(TextFormat("VAL = %i", data[I]), screen_width/2 - 22, screen_height/2 - 22, 22, RAYWHITE);
    DrawText(TextFormat("I   = %i", I), screen_width/2, screen_height/2, 22, RAYWHITE);
    EndDrawing();
}

void bubble_sort(int data[], int n)
{
    int temp;
    int k = n;

    if(k>=0)
    {
        I = 0;
        if(I < n-1)
            {
                if(data[I]>data[I+1])
                {
                    temp = data[I];
                    data[I] = data[I+1];
                    data[I+1] = temp;
                }
                I++;
            }
    }
    k--;
}
