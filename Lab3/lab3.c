//Experiment :- 3
//Scanline Fill Algorithm

#include<stdio.h>
#include<GL/glut.h>

float x1, x2, x3, x4, y11, y2, y3, y4;
int le[1000], re[1000];

void display();
void mainMenu(int c);
void subMenu(int c);
void scanFill(float x1, float y11, float x2, float y2, float x3, float y3, float x4, float y4);
void edgeDetect(float x1, float y11, float x2, float y2);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Scan Line Fill Algorithm_4MT19CS073");
	
	int sub_Menu = glutCreateMenu(subMenu);
	glutAddMenuEntry("Draw Polygon", 1);
	glutAddMenuEntry("Fill Polygon", 2);
	glutCreateMenu(mainMenu);
	glutAddSubMenu("Program to", sub_Menu);
	glutAddMenuEntry("Quit", 3);
	glutDisplayFunc(display);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);	

	glutMainLoop();
	return 0;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);	
	x1 = 400.0;
	y11 = 400.0;
	x2 = 200.0;
	y2 = 600.0;
	x3 = 400.0;
	y3 = 800.0;
	x4 = 600.0;
	y4 = 600.0;
}

void subMenu(int c) {
	switch(c) {
		case 1: {
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(x1, y11);
			glVertex2f(x2, y2);
			glVertex2f(x3, y3);
			glVertex2f(x4, y4);
			glEnd();
			glFlush();
			break;
		}
		
		case 2: {
			glColor3f(1.0, 0.0, 1.0);
			glBegin(GL_LINE_LOOP);
			glVertex2f(x1, y11);
			glVertex2f(x2, y2);
			glVertex2f(x3, y3);
			glVertex2f(x4, y4);
			glEnd();
			scanFill(x1, y11, x2, y2, x3, y3, x4, y4);
			break;
		}
	}
}

void mainMenu(int c) {
	switch(c) {
		case 3:
			exit(0);
	}
}

void scanFill(float x1, float y11, float x2, float y2, float x3, float y3, float x4, float y4) {
	
	int i, y;	
		
	for(i=400; i<=800; i++)
		le[i] = re[i] = 400;
	
	edgeDetect(x1, y11, x2, y2);
	edgeDetect(x2, y2, x3, y3);
	edgeDetect(x4, y4, x3, y3);
	edgeDetect(x1, y11, x4, y4);

	glPointSize(4);
	
	for(y=400; y<=800; y++) {
		for(i=le[y]; i<=re[y]; i++) {
			glColor3f(0.5, 0.0, 1.0);			
			glBegin(GL_POINTS);
			glVertex2f(i, y);
			glEnd();
			glFlush();
		}
	}
}

void edgeDetect(float x1, float y11, float x2, float y2) {
	float mx, x;

	if((y2-y11) != 0)
		mx = (x2-x1) / (y2-y11);

	x = x1;

	for(int i=y11; i<=y2; i++) {
		if(x <= le[i])
			le[i] = x;

		else
			re[i] = x;

		x += mx;
	}
}	