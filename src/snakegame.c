#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

#define w 20 
#define h 10

// Helper functions for console operations
HANDLE getConsole() 
{
    return GetStdHandle(STD_OUTPUT_HANDLE);
}

// Function to hide the cursor
void hideCursor() 
{
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = FALSE;
    SetConsoleCursorInfo(getConsole(), &cursor);
}

void moveCursor(int x, int y) 
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(getConsole(), pos);
}

int main() 
{
    // screen buffer including walls
    char screen[h+2][w+2];
    // snake head 
    int headx = w/2, heady = h/2;
    // food
    int foodx, foody;             
    int score = 0;
    // starting direction
    char direction = 'd';         

    srand(time(0));

    // initial food
    foodx = rand()%w + 1;
    foody = rand()%h + 1;

    // Hide the cursor
    hideCursor();

    while(1) 
    {
        // build screen buffer
        for(int y=0;y<=h+1;y++)
        {
            for(int x=0;x<=w+1;x++)
            {
                // walls
                if(x==0 || x==w+1 || y==0 || y==h+1) screen[y][x] = '#';
                 // snake head 
                else if(x==headx && y==heady) screen[y][x] = 'O';
                  // food             
                else if(x==foodx && y==foody) screen[y][x] = 'F';            
                else screen[y][x] = ' ';                                 
            }
        }

        // move cursor to top-left
        moveCursor(0, 0);

        // print buffer
        for(int y=0;y<=h+1;y++)
        {
            for(int x=0;x<=w+1;x++) 
            putchar(screen[y][x]);
            putchar('\n');
        }

        // print score below
        printf("Score: %d /100 \n", score);
        printf("Press w/a/s/d to move, x to exit.\n");
        
        // input
        if(_kbhit()) 
        {
            char c = _getch();
            if(c=='w' && direction!='s') direction='w';
            if(c=='s' && direction!='w') direction='s';
            if(c=='a' && direction!='d') direction='a';
            if(c=='d' && direction!='a') direction='d';
            if(c=='x') break;
        }

        // move head
        if(direction=='w') heady--;
        if(direction=='s') heady++;
        if(direction=='a') headx--;
        if(direction=='d') headx++;

        // wrap-around walls
        if(headx<1) headx=w;
        if(headx>w) headx=1;
        if(heady<1) heady=h;
        if(heady>h) heady=1;

        // eat food
        if(headx==foodx && heady==foody)
        {
            score += 10;
            //To keep food at random places
            foodx = rand()%w + 1;
            foody = rand()%h + 1;
        }

        // winning criteria
        if(score>=100)
        {
            moveCursor(0, h+3);
            printf("YOU WIN! Final Score = %d\n", score);
            break;
        }
        // control speed
        Sleep(120);
         // control speed
    }

    return 0;
}