//Experiment :- 7
//Clip a line using Cohen-Sutherland Algorithm

#include<stdio.h>
#include<GL/glut.h>

float xvmin=200, yvmin=200, xvmax=300, yvmax=300;
float xmin, ymin, xmax, ymax;
double x, y;
float x0, y0, x1, y11;
int TOP=8, BOTTOM=4, RIGHT=2, LEFT=1;

void myinit();
void display();
int computeoutcode(float x,float y);
void CSLCA(float x0,float y0,float x1,float y11);
void drawline();
void drawrect();

int main(int argc,char **argv) 
{
	printf("Enter the End-Points of Clipping Window : ");
	scanf("%f%f%f%f", &xmin, &ymin, &xmax, &ymax);
	printf("\nEnter the End-Points : ");
	scanf("%f%f%f%f", &x0, &y0, &x1, &y11);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Cohen-Sutherland Line-Clipping 4MT19CS073");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	drawline();
	glColor3f(0.0, 0.0, 1.0);
	drawrect();
	CSLCA(x0, y0, x1, y11);
	glFlush();
}

void drawline()
{
	glBegin(GL_LINES);
	glVertex2f(x0, y0);
	glVertex2f(x1, y11);
	glEnd();
}

void drawrect()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);
	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);
	glEnd();
}

void CSLCA(float x0, float y0, float x1, float y11)
{
	int outcode0, outcode1, outcodeout;
	int accept = 0;
	int done = 0;
	outcode0 = computeoutcode(x0, y0);
	outcode1 = computeoutcode(x1, y11);
	while(done == 0)
	{
		if(!(outcode0 | outcode1))
		{
			accept = 1;
			done = 1;
		}
		
		else if(outcode0 & outcode1)
			done = 1;
		
		else
		{
			outcodeout = outcode0?outcode0:outcode1;
			
			if(outcodeout & TOP)
			{
				x = x0 + (x1-x0)*(ymax-y0)/(y11-y0);
				y = ymax;
			}
			
			else if(outcodeout & BOTTOM)
			{
				x = x0 + (x1-x0)*(ymin-y0)/(y11-y0);
				y = ymin;
			}
			
			else if(outcodeout & RIGHT)
			{
				y = y0 + (y11-y0)*(xmax-x0)/(x1-x0);
				x = xmax;
			}
			
			else
			{
				y = y0 + (y11-y0)*(xmin-x0)/(x1-x0);
				x = xmin;
			}
				
			if(outcodeout==outcode0)
			{
				x0 = x;
				y0 = y;
				outcode0 = computeoutcode(x0, y0);
			}
			
			else
			{
				x1 = x;
				y11 = y;
				outcode1 = computeoutcode(x1, y11);
			}
		}
	}
				
	if(accept==1)
	{
		double Sx = (xvmax-xvmin)/(xmax-xmin);
		double Sy=(yvmax-yvmin)/(ymax-ymin);
		double vx0 = xvmin + (x0-xmin)*Sx;
		double vy0 = yvmin + (y0-ymin)*Sy;
		double vx1 = xvmin + (x1-xmin)*Sx;
		double vy1 = yvmin + (y11-ymin)*Sy;
				
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(xvmin, yvmin);
		glVertex2f(xvmax, yvmin);
		glVertex2f(xvmax, yvmax);
		glVertex2f(xvmin, yvmax);
		glEnd();
				
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_LINES);
		glVertex2d(vx0, vy0);
		glVertex2d(vx1, vy1);
		glEnd();
	}
}
			
int computeoutcode(float x, float y)
{
	int code=0;
	if(y > ymax)
		code|=TOP;
		
	else if(y < ymin)
		code|=BOTTOM;
		
	if(x > xmax)
		code|=LEFT;
		
	else if(x < xmin)
		code |=RIGHT;
		
	return code;
}