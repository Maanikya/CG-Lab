//Open-GL Point Line

#include<stdio.h>
#include<GL/glut.h>

void Polygon();
void Sphere();
void Timer();

float x=0;

int main(int argc, char **argv)
{
	printf("\nName : Maanikya\n");
	printf("USN : 4MT19CS073\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(1000, 800);	
	glutCreateWindow("Points");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 10.0, 0.0, 10.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(Polygon);
	Timer(0);
	glutMainLoop();
	return 0;		
}

void Polygon()
{
	glClear(GL_COLOR_BUFFER_BIT);	

	//Sky
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.5);	
	glVertex2i(0, 5);
	glVertex2i(0, 10);
	glVertex2i(10, 10);
	glVertex2i(10, 5);
	glEnd();

	//Stars
	glPointSize(7);	
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);	
	glVertex2i(1.0, 7);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(4, 9);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2i(9, 8);
	glEnd();	

	//Sun	
	glColor3f(1.0, 0.55, 0.01);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(7, 5+x, 0);
	glutSolidSphere(0.7, 100, 100);
	glPopMatrix();
	
	//Mountain 1
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0.0);	
	glVertex2i(0, 5);
	glVertex2i(2, 7);
	glVertex2i(4, 5);
	glEnd();

	//Mountain 2
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0.0);	
	glVertex2i(3.5, 5);
	glVertex2i(5.5, 8);
	glVertex2i(7.5, 5);
	glEnd();

	//Mountain 3
	glBegin(GL_POLYGON);
	glColor3f(0.6, 0.3, 0.0);	
	glVertex2i(6.5, 5);
	glVertex2i(9.5, 7);
	glVertex2i(11.5, 5);
	glEnd();

	//Ground
	glBegin(GL_POLYGON);
	glColor3f(0.1, 0.7, 0.0);	
	glVertex2i(0, 0);
	glVertex2i(0, 5);
	glVertex2i(10, 5);
	glVertex2i(10, 0);
	glEnd();

	//House Base
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.1, 0.0);	
	glVertex2f(0.6, 0.6);
	glVertex2f(0.6, 2.6);
	glVertex2f(3.0, 2.6);
	glVertex2f(3.0, 0.6);
	glEnd();

	//House Top
	glBegin(GL_POLYGON);
	glColor3f(0.15, 0.1, 0.0);	
	glVertex2f(0.6, 2.6);
	glVertex2f(1.8, 4.6);
	glVertex2f(3.0, 2.6);	
	glEnd();

	//House Door
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.0, 0.0);	
	glVertex2f(1.4, 0.6);
	glVertex2f(1.4, 2.0);
	glVertex2f(2.2, 2.0);
	glVertex2f(2.2, 0.6);
	glEnd();

	//Well Base
	glColor3f(0.3, 0.1, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(6.9, 1, 0);
	glScalef(1, 0.5, 1);
	glutSolidSphere(0.8, 100, 100);
	glPopMatrix();

	//Well Body
	glBegin(GL_POLYGON);
	glColor3f(0.3, 0.1, 0.0);	
	glVertex2f(6.1, 1.0);
	glVertex2f(6.1, 2.0);
	glVertex2f(7.7, 2.0);
	glVertex2f(7.7, 1.0);
	glEnd();

	//Well Outer-Ring Top
	glColor3f(0.3, 0.1, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(6.9, 2.0, 0);
	glScalef(1, 0.5, 1);
	glutSolidSphere(0.8, 100, 100);
	glPopMatrix();

	//Well Inner-Ring Top
	glColor3f(0.0, 0.7, 0.7);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(6.9, 2.0, 0);
	glScalef(1, 0.5, 1);
	glutSolidSphere(0.7, 100, 100);
	glPopMatrix();

	//Well Supports
	glLineWidth(2);	
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);	
	glVertex2f(6.1, 2.0);
	glVertex2f(6.1, 3.0);
	glVertex2f(7.7, 3.0);	
	glVertex2f(7.7, 2.0);
	glEnd();

	//Well Block
	/*glLineWidth(2);	
	glBegin(GL_LINE_STRIP);
	glColor3f(0.0, 0.0, 0.0);	
	glVertex2f(6.1, 2.0);
	glVertex2f(7.7, 2.0);
	glEnd();*/
	
	glFlush();
}

void Timer(int v)
{
	if(x == 2)
		x=2;
	
	else
		x = x + 0.125;

	glutPostRedisplay();
	glutTimerFunc(100, Timer, 0);
}	
