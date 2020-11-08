// Luke Marushack
// Fundamentals of Computing : Lab #10
// fractals.c

#include "gfx.h"

int main() {
	int wd = 700, ht = 700, mrgn = 20;
	gfx_open(wd, ht, "Fractals!");
	char c;
	while (1) {
		c = gfx_wait();
		gfx_clear();
		switch (c) {
			case '1':
				sierpinski(mrgn, mrgn, wd-mrgn, mrgn, wd/2, ht-mrgn);
				break;	
			case '2':
				
				break;
			case '3':
			
				break;
			case '4':

				break;
			case '5':

				break;
			case '6':

				break;
			case '7':

				break;
			case '8':

				break;
			case 'q':
				printf("Goodbye!\n");
				break;
			default:
				printf("Please enter valid input.\n");	
				break;
		}	
	}	
	return 0;
}


void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 )
{
   // Base case. 
   if( abs(x2-x1) < 5 ) return;

   // Draw the triangle
   drawTriangle( x1, y1, x2, y2, x3, y3 );

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );
}


void drawTriangle( int x1, int y1, int x2, int y2, int x3, int y3 )
{
    gfx_line(x1,y1,x2,y2);
    gfx_line(x2,y2,x3,y3);
    gfx_line(x3,y3,x1,y1);
}

void shrinkingSquares( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 ) {
	
}

void drawSquare( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 ) {
	gfx_line(x1,y1,x2,y2);
	gfx_line(x2,y2,x3,y3);
	gfx_line(x3,y3,x4,y4);
	gfx_line(x4,y4,x1,y1);
}

