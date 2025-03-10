#include <stdio.h>
#include <windows.h>
#include "time.h"

#define SHIFTING    4
#define WHITE       15
#define RED         4

void goto_row_col(int row,int col);
void delay(int number_of_seconds);
void SetColor(int ForgC);


void main(void) {
    int row = 0;
    int col = 0;
    int size = 0;
    int val = 0;

    printf("Enter the size: ");
    scanf("%d",&size);

    row=1;
    col=(size+1)/2;
    val=1;
    do{
        goto_row_col(row,col*SHIFTING);
        printf("%4d",val);
        delay(1);
        if(val%size==0)
        {
            row++;
            SetColor(RED);
            printf("\a");

        }

        else
        {
            row--;
            col--;
            if (row==0) row=size;
            if (col==0) col=size;
            SetColor(WHITE);
        }
        val++;

    }while(val<=size*size);

        SetColor(15);

}
void goto_row_col(int row,int col)
{
    COORD coord= {0,0};

    coord.X=col;
    coord.Y=row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void delay(int number_of_seconds)
{

    int milli_seconds = 1000 * number_of_seconds;


    clock_t start_time = clock();


    while (clock() < start_time + milli_seconds)
        ;
}
void SetColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;


    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
