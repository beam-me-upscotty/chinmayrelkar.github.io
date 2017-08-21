#include<iostream>
#include<GL\glut.h>

using namespace std;

void init(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

void buildHouse(void)
{
	int a;
	cin>>a;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	
	glBegin(GL_POLYGON);  //start house 
	glColor3f(1.0, 1.0, 0.0);
	glVertex2i(50, 0);
	glVertex2i(50, 100);
	glVertex2i(150, 100);
	glVertex2i(150,0);
	glEnd();   //end house
	
	
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.0, 0.0);
	glVertex2i(50, 100);
	glVertex2i(150, 100);
	glVertex2i(100, 130);
	glEnd(); 

	glBegin(GL_POLYGON);  //start door
	glColor3f(0.3, 0.2, 0.0);
	glVertex2i(80, 0);
	glVertex2i(80, 50);
	glVertex2i(120, 50);
	glVertex2i(120,0);
	glEnd();  //end door

	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("House Section OpenGL");
	init();
	glutDisplayFunc(buildHouse);
	glutMainLoop();
}
