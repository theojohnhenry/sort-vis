#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

const int screen_width = 800;
const int screen_height = 800;
const float update_interval = 1.0f;

typedef struct {
    bool finished;
    int i;
    int pass;
    int n;
    int *data;
} bubble_sort_state;


void draw_data(int data[], int n, bubble_sort_state *state);
void seq_bubble_sort(int data[], int n, bubble_sort_state *state);
void swap(int* xp, int* yp);

int main(int argc, char *argv[])
    {

    if(argc<1){printf("bad input");return 1;}
    int n = argc-1;

    int *data = malloc(n * sizeof(int));
    if(data==NULL){printf("malloc error");return 1;}

    for(int i = 0; i < n; i++)
    {
        printf("placing value %i into data slot %i \n", atoi(argv[i+1]), i);
        data[i] = atoi(argv[i + 1]);
    }

    bubble_sort_state bss = {false, 0, 0, n, data};

    float time_counter = 0.0f;
    InitWindow(screen_width, screen_height, "PENIS WINDOW");
    SetTargetFPS(60);

    while (!WindowShouldClose()) 
    {
        time_counter += GetFrameTime();
        if(time_counter >= update_interval){
            time_counter = 0;
            seq_bubble_sort(data, n, &bss);
        }
        draw_data(data, n, &bss);
    }    

    CloseWindow(); 

    return 0;
}

void draw_data(int data[], int n, bubble_sort_state *state)
{

    int current = state->i;
    int passed = n - state->pass;
    int staple_pixelwidth = screen_width/n;

    BeginDrawing();
    ClearBackground(BLACK);
    int i;
    for(i=0; i <= n-1; i++)
    {
        Color current_color = RAYWHITE;
        if(i == current) {current_color = RED;}
        if(i >= passed || state->finished) {current_color = GREEN;}

        int current_posX = i*staple_pixelwidth;
        int current_height = data[i] * 40;

        DrawRectangle(
                current_posX , 
                screen_height-current_height, 
                staple_pixelwidth, 
                current_height, 
                current_color);
    }

    DrawText(TextFormat("VAL = %i", data[current]), screen_width/2, screen_height/2 - 22, 22, RAYWHITE);
    DrawText(TextFormat("I   = %i", current), screen_width/2, screen_height/2, 22, RAYWHITE);
    EndDrawing();
}

void seq_bubble_sort(int *data, int n, bubble_sort_state *state)
{

    if(state->finished)
    {
        return;
    }

    int i = state->i;

    if(data[i]>data[i+1])
    {
        swap(&data[i], &data[i+1]);
    }

    state->i++;

    int comparisons_this_pass = n - 1 - state->pass;

    if(state->i >= comparisons_this_pass)
    {
        state->i = 0;
        state->pass++;
    }
    
    if(state->pass >= n-1)
    {
        state->finished = true;
    }
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
} 

