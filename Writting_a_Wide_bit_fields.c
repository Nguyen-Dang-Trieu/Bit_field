
#include <stdio.h>

void bit_field_write(char bit, char width, char value, char *byte);
char bit_field_read(char bit, char width, char byte);

#define ROW_BIT 3
#define COL_BIT 0
#define FIELD_WIDTH 3

int main()
{
	char board,row,column;

	row = 3;    // row : 0 -> 7 tương ứng với hàng 1 -> hàng 8
	column = 4; // column: 0 -> 7 tương ứng với cột 1 -> cột 8
	board = 0;

	bit_field_write(ROW_BIT,FIELD_WIDTH,row,&board);
	bit_field_write(COL_BIT,FIELD_WIDTH,column,&board);

    printf("Gia tri cua board %d\n", board);

	printf("The Queen is at row %d, column %d\n",
			bit_field_read(ROW_BIT,FIELD_WIDTH,board) + 1,
			bit_field_read(COL_BIT,FIELD_WIDTH,board) + 1
			);

	return(0);
}

void bit_field_write(char bit, char width, char value, char *byte)
{
    //bit ở đây là vị trí bắt đầu của bit fields
	unsigned char mask = 0;
	while(width--)
	{
		mask = mask << 1;
		mask |= 1;	
	}

	/* position the value and the mask */
	value = value << bit;
	mask = mask << bit;
    /*Kiểm tra giá trị 1 lần trước khi set ở board*/
    value = value & mask;
	/* set the bit field */
    *byte = *byte | value;
	
}

char bit_field_read(char bit, char width, char byte)
{
	unsigned char mask = 0;
	while(width--)
	{
		mask = mask << 1;
		mask |= 1;	
	}
	byte = byte >> bit;
	return( byte & mask );
}
