#include <raylib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// rendering settings
const int screen_width = 800;
const int screen_height = 800; 
const float update_interval = 1.0f;

//prototypes
typedef struct {
    bool finished;
    int i;
    int pass;
    int n;
    int *data;
} bubble_sort_state;
void draw_data(bubble_sort_state *state);
void seq_bubble_sort(bubble_sort_state *state);
void swap(int* xp, int* yp);

int main(int argc, char *argv[])
    {

    //parses input and creates sort states
    if(argc<1){printf("bad input");return 1;}
    int n = argc-1;

    int *data = malloc(n * sizeof(int));
    if(data==NULL){printf("malloc error");return 1;}

    for(int i = 0; i < n; i++)
    {
        data[i] = atoi(argv[i + 1]);
    }
    bubble_sort_state bss = {false, 0, 0, n, data};

    //rendering
    float time_counter = 0.0f;
    InitWindow(screen_width, screen_height, "PENIS WINDOW");
    SetTargetFPS(60);
    while (!WindowShouldClose()) 
    {
        time_counter += GetFrameTime();
        if(time_counter >= update_interval){
            time_counter = 0;
            seq_bubble_sort(&bss);
        }
        draw_data(&bss);
    }    
    CloseWindow(); 

    return 0;
}


void draw_data(bubble_sort_state *s)
{
    int current = s->i;
    int passed = s->n - s->pass;
    int staple_pixelwidth = screen_width/s->n;

    BeginDrawing();
    ClearBackground(BLACK);
    int i;
    for(i=0; i <= s->n-1; i++)
    {
        Color current_color = RAYWHITE;
        if(i == current) {current_color = RED;}
        if(i >= passed || s->finished) {current_color = GREEN;}

        int current_posX = i*staple_pixelwidth;
        int current_height = s->data[i] * 40;

        DrawRectangle(
                current_posX , 
                screen_height-current_height, 
                staple_pixelwidth, 
                current_height, 
                current_color);
    }

    DrawText(TextFormat("VAL = %i", s->data[current]), 0, 0, 20, RAYWHITE);
    DrawText(TextFormat("I   = %i", current), 0, 20, 20, RAYWHITE);
    EndDrawing();
}

void seq_bubble_sort(bubble_sort_state *s)
{

    if(s->finished)
    {
        return;
    }

    int i = s->i;
    if(s->data[i]>s->data[i+1])
    {
        swap(&s->data[i], &s->data[i+1]);
    }
    s->i++;

    int comparisons_this_pass = s->n - 1 - s->pass;

    if(s->i >= comparisons_this_pass)
    {
        s->i = 0;
        s->pass++;
    }
    
    if(s->pass >= s->n-1)
    {
        s->finished = true;
    }
}

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
} 

