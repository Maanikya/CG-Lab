//Experiment :- 2
//Rotate Triangle about Origin and Fixed Point

#include<stdio.h>
#include<GL/glut.h>

void display_about_origin();
void display_about_pivot();
void draw_triangle();

int choice;
float theta, h, k;

int main(int argc, char **argv)
{
	printf("Enter 1 for Rotation about Origin\n");
	printf("Enter 2 for Fixed Point Rotation(Pivot Point)\nEnter Choice : ");
	scanf("%d", &choice);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	
	if(choice == 1)
	{
		printf("Enter the Angle of Rotation : ");
		scanf("%f", &theta);
		glutCreateWindow("Rotation About Origin_4MT19CS073");
		glutDisplayFunc(display_about_origin);
	}

	else if(choice == 2)
	{
		printf("Enter the Angle of Rotation : ");
		scanf("%f", &theta);
		printf("Enter 'x' and 'y' value of Pivot Point : ");
		scanf("%f%f", &h, &k);
		glutCreateWindow("Fixed Point Rotation_4MT19CS073");
		glutDisplayFunc(display_about_pivot);
	}

	else
		printf("\nInvalid Choice\n");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutMainLoop();
	return 0;
}

void draw_triangle()
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);	
	glVertex2i(100, 100);
	glVertex2i(400, 100);
	glVertex2i(450, 250);
	glEnd();
}

void display_about_origin()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();		
	draw_triangle();
	glRotatef(theta, 0, 0, 1);
	draw_triangle();
	glFlush();
}

void display_about_pivot()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	draw_triangle();
	glTranslatef(h, k, 0);
	glRotatef(theta, 0, 0, 1);
	glTranslatef(-h, -k, 0);
	draw_triangle();
	glFlush();
}
