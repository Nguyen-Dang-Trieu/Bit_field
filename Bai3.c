#include <stdio.h>

struct MyMap
{
   unsigned int  b31:1;
   unsigned int  b30:1;
   unsigned int  b29:1;
   unsigned int  b28:1;
   unsigned int  b27:1;
   unsigned int  b26:1;
   unsigned int  b25:1;
   unsigned int  b24:1;
   unsigned int  b23:1;
   unsigned int  b22:1;
   unsigned int  b21:1;
   unsigned int  b20:1;
   unsigned int  b19:1;
   unsigned int  b18:1;
   unsigned int  b17:1;
   unsigned int  b16:1;
   unsigned int  b15:1;
   unsigned int  b14:1;
   unsigned int  b13:1;
   unsigned int  b12:1;
   unsigned int  b11:1;
   unsigned int  b10:1;
   unsigned int  b9:1;
   unsigned int  b8:1;
   unsigned int  b7:1;
   unsigned int  b6:1;
   unsigned int  b5:1;
   unsigned int  b4:1;
   unsigned int  b3:1;
   unsigned int  b2:1;
   unsigned int  b1:1;
   unsigned int  b0:1;


};


void printBits( int a )
{
   int i;
 
   for ( i = 31; i >= 0; i-- )
   {
	 if ( (a & (1<<i) ) != 0 )
	    putchar('1');
	 else
	    putchar('0');
   }
 
}
 
int main( int argc, char* argv[] )
{
   struct MyMap r;

   printf( "sizeof(r) = %lu\n", sizeof(r) );

   int *p = (int *) &r;        // Make p point to r

   *p = 0;                     // Clear all 32 bits in r
   printBits( *p );            // Print the bits in r
   putchar('\n');

   r.b0 = 1;
   printBits( *p );            // Print the bits in r
   putchar('\n');

   r.b8 = 1;
   r.b9 = 1;
   printBits( *p );            // Print the bits in r
   putchar('\n');

   r.b16 = 1;
   r.b17 = 1;
   r.b18 = 1;
   printBits( *p );            // Print the bits in r
   putchar('\n');

   r.b30 = 1;
   printBits( *p );            // Print the bits in r
   putchar('\n');

}
1
