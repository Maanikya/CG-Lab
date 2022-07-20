//Sphere

#include<stdio.h>
#include<GL/glut.h>

void Sphere();
void Timer(int v);

float x=0;

int main(int argc, char **argv)
{
	printf("\nName : Maanikya\n");
	printf("\nUSN : 4MT19CS073\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);	
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Sphere");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 10.0, 0.0, 10.0, 0.0, 10.0);
	glutDisplayFunc(Sphere);
	Timer(0);
	glutMainLoop();
	return 0;
}

void Sphere()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8, 0.2, 0.4);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0+x, 5, 0);
	//glRotatef(x, 1, 1, 0);
	glutSolidSphere(1, 10, 10);
	glPopMatrix();
	glFlush();
}

void Timer(int v)
{
	x = x + 0.05;
	glutPostRedisplay();
	glutTimerFunc(10, Timer, 0);
}
