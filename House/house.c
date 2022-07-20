//Open-GL House

#include<stdio.h>
#include<GL/glut.h>

void House();

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
	glutDisplayFunc(House);
	glutMainLoop();
	return 0;		
}

void House()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);	
	glVertex2i(4, 5);
	glVertex2i(5, 8);
	glVertex2i(6, 5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(4, 5);
	glVertex2i(6, 5);
	glVertex2i(6, 2);
	glVertex2i(4, 2);
	glEnd();
	glFlush();
}	
