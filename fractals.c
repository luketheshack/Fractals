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
				shrinkingSquares(mrgn, mrgn, wd-mrgn, mrgn, wd-mrgn, ht-mrgn, mrgn, ht-mrgn);
				break;
			case '3':
				spiralSquares(wd/2, ht/2, 0, ht/2);
				break;
			case '4':
				drawLace(wd/2, ht/2, ht/3);
				break;
			case '5':
				snowflake(wd/2, ht/2, ht/3);
				break;
			case '6':
				drawTree(wd/2, ht, wd/2, 3*PI/2);
				break;
			case '7':
				drawFern(wd/2, ht, wd/2, 3*PI/2);
				break;
			case '8':

				break;
			case 'q':
				printf("Goodbye!\n");
				return 0;
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
	int dist = abs(x2-x1)/4;
	if (dist < 5) return;

	drawSquare(x1 + dist, y1 + dist, x2 - dist, y2 + dist, x3 - dist, y3 - dist, x4 + dist, y4 - dist);
	
	shrinkingSquares(x1, y1, x1 + 2*dist, y1, x1 + 2*dist, y1 + 2*dist, x1, y1 + 2*dist); 
	shrinkingSquares(x1 + 2*dist, y1, x1 + 4*dist, y1, x1 + 4*dist, y1 + 2*dist, x1 + 2*dist, y1 + 2*dist); 
	shrinkingSquares(x1 + 2*dist, y1 + 2*dist, x1 + 4*dist, y1 + 2*dist, x1 + 4*dist, y1 + 4*dist, x1 + 2*dist, y1 + 4*dist); 
	shrinkingSquares(x1, y1 + 2*dist, x1 + 2*dist, y1 + 2*dist, x1 + 2*dist, y1 + 4*dist, x1, y1 + 4*dist); 
}

void drawSquare( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4 ) {
	gfx_line(x1,y1,x2,y2);
	gfx_line(x2,y2,x3,y3);
	gfx_line(x3,y3,x4,y4);
	gfx_line(x4,y4,x1,y1);
}

void drawTree( int x1, int y1, int distance, float angle) {
	if (distance < 1) return;
	
	float inc_angle = PI/6;
	gfx_line(x1, y1, x1 + distance*cos(angle), y1 + distance*sin(angle));

	drawTree(x1 + distance*cos(angle), y1 + distance*sin(angle), (int) distance*.5, angle + inc_angle);
	drawTree(x1 + distance*cos(angle), y1 + distance*sin(angle), (int) distance*.5, angle - inc_angle);

}

void drawFern(int x1, int y1, int distance, float angle) {
	if (distance < 20) return;
	float inc_angle = PI/6;
	
	int xoff = distance*cos(angle);
	int yoff = distance*sin(angle);
	gfx_line(x1, y1, x1 + xoff, y1 + yoff);
	
	drawFern(x1 + xoff/4, y1 + yoff/4, (int) distance * .5, angle + inc_angle);
	drawFern(x1 + xoff/4, y1 + yoff/4, (int) distance * .5, angle - inc_angle);
	drawFern(x1 + 2*xoff/4, y1 + 2*yoff/4, (int) distance * .5, angle + inc_angle);
	drawFern(x1 + 2*xoff/4, y1 + 2*yoff/4, (int) distance * .5, angle - inc_angle);
	drawFern(x1 + 3*xoff/4, y1 + 3*yoff/4, (int) distance * .5, angle + inc_angle);
	drawFern(x1 + 3*xoff/4, y1 + 3*yoff/4, (int) distance * .5, angle - inc_angle);
	drawFern(x1 + 4*xoff/4, y1 + 4*yoff/4, (int) distance * .5, angle + inc_angle);
	drawFern(x1 + 4*xoff/4, y1 + 4*yoff/4, (int) distance * .5, angle - inc_angle);
}

void spiralSquares(int xstart, int ystart, float angle, int radius) {
	if (radius < 5) return;
	if (angle > 2*PI) radius -= 2*PI;
	int size = radius/10;
	int xoff = radius * cos(angle); // x offset
	int yoff = radius * sin(angle); // y offset
	square(xstart + xoff, ystart + yoff, size);

	radius *= 0.9;
	spiralSquares(xstart, ystart, angle + PI/10, radius);
}


void square(int xm, int ym, int radius) {
	polygon(xm, ym, 4, radius);
}

void polygon(int xm, int ym, int sides, int radius) {
	float i, part, x1, x2, y1, y2;
	part = 2*PI/sides;
	
	for (i = 0; i <= 2*PI; i += part) {
		x1 = radius * cos(i) + xm;
		x2 = radius * cos(i + part) + xm;
		y1 = -1 * radius * sin(i) + ym;
		y2 = -1 * radius * sin(i + part) + ym;
		gfx_line(x2, y2, x1, y1);	
	}	
}

void drawLace(int x1, int y1, int radius) {
	if (radius < 2) return;
	gfx_circle(x1, y1, radius);
	
	int i;
	int newrad = radius/3;
	
	drawLace(x1 + radius*cos(PI/3), y1 + radius*sin(PI/3), newrad);	
	drawLace(x1 + radius*cos(2*PI/3), y1 + radius*sin(2*PI/3), newrad);		
	drawLace(x1 + radius*cos(PI), y1 + radius*sin(PI), newrad);	
	drawLace(x1 + radius*cos(4*PI/3), y1 + radius*sin(4*PI/3), newrad);		
	drawLace(x1 + radius*cos(5*PI/3), y1 + radius*sin(4*PI/3), newrad);		
	drawLace(x1 + radius*cos(2*PI), y1 + radius*sin(2*PI), newrad);	
}

void snowflake(int x1, int y1, int distance) {
	if (distance < 2) return;
	float angle = 2*PI/5;

	float i;
	for (i = 0; i <= 2*PI; i += angle) {
		gfx_line(x1, y1, x1 + distance*cos(i), y1 + distance*sin(i));
		snowflake(x1 + distance*cos(i), y1 + distance*sin(i), distance * .35);
	}

} 
