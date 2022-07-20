//Open-GL Point Line

#include<stdio.h>
#include<GL/glut.h>

void LineStrip();

int main(int argc, char **argv)
{
	printf("\nName : Maanikya\n");
	printf("USN : 4MT19CS073\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(800, 500);	
	glutCreateWindow("Points");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 10.0, 0.0, 10.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(LineStrip);
	glutMainLoop();
	return 0;		
}

void LineStrip()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(10);	
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0, 0.0, 0.0);	
	glVertex2i(2, 2);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(5, 7);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(8, 2);
	glColor3f(1.0, 0.0, 0.0);	
	glVertex2i(2, 2);
	glEnd();
	glFlush();
}	
