//Experiment :- 1
//Bresenham's Line Drawing Algorithm

#include<stdio.h>
#include<GL/glut.h>

void draw_line(int x1, int x2, int y11, int y2);
void draw_pixel(int x, int y);
void myDisplay();
int x1, y11, x2, y2;

int main(int argc, char **argv)
{
	printf("Enter two Coordinates of the Line : ");
	scanf("%d%d%d%d", &x1, &y11, &x2, &y2);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham's Line Drawing Algorithm 4MT19CS073");
	
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);

	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}

void myDisplay()
{
	draw_line(x1, x2, y11, y2);
	glFlush();
}

void draw_pixel(int x, int y)
{
	glPointSize(5);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void draw_line(int x1, int x2, int y11, int y2)
{	
	int x, y, dx, dy, e, i;
	int incx, incy, inc1, inc2;
	incx=1;
	incy=1;

	dx = x2-x1;
	dy = y2-y11;

	if(dx<0)
		dx = -dx;

	if(dy<0)
		dy = -dy;

	if(x2<x1)
		incx = -1;

	if(y2<y11)
		incy = -1;

	x = x1;
	y = y11;

	if(dx > dy)
	{
		draw_pixel(x, y);
		e = (2*dy) - dx;
		inc1 = 2 * (dy-dx);
		inc2 = 2 * dy;
		
		for(i=0; i<dx; i++)
		{
			if(e >= 0)
			{
				y += incy;
				e += inc1;
			}

			else
				e += inc2;
			
			x += incx;
			draw_pixel(x, y);
		}
	}
	
	else
	{
		draw_pixel(x, y);
		e = (2*dx) - dy;
		inc1 = 2 * (dx-dy);
		inc2 = 2 * dx;

		for(i=0; i<dy; i++)
		{
			if(e >= 0)
			{
				x += incx;
				e += inc2;
			}

			else
				e += inc1;
			
			y += incy;
			draw_pixel(x, y);
		}
	}
}