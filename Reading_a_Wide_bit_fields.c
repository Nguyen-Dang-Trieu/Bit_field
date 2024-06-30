#include<stdio.h>


char bit_field_read(char bit, char width, char byte);
int main(){
    unsigned char board;
    board = 23;
    printf("The Queen is at row %d, column %d\n",
    bit_field_read(3,3,board) + 1,
    bit_field_read(0,3,board) + 1
    );
    return 0;
}

char bit_field_read(char bit, char width, char byte)
{
    unsigned char mask = 0;
    while (width--)
    {
        mask = mask << 1;
        mask |= 1;
    }
    
    byte = byte >> bit;
    return (byte & mask);
}
