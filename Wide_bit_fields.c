
#include<stdio.h>

//https://c-for-dummies.com/blog/?p=1874
int main()
{
    //VD: Queen đứng ở hàng 3, cột 8
    unsigned char board,row,column; // 8bits

    board = 23; // board : 0x17 <=> 0001 0111 
    //bit 0,1,2: biểu diễn cho COLUMN, bit 3,4,5: biểu diễn cho ROW
    row = board & 0x38;
    row = row >> 3;

    column = board & 0x07;

    printf("The Queen is at row %d, column %d\n",row + 1, column + 1);
    return 0;
}