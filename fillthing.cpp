/*
 * main.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: root
 */
#include<iostream>
#include<GL/glut.h>
using namespace std;
int height = 800;
int width = 800;
int xco,yco;
void myDisplay()
{
	  glClearColor(0.0, 0.0, 0.5, 1);
	  glColor3f(1, 1, 1);
	  glClear(GL_COLOR_BUFFER_BIT);
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();

	  gluOrtho2D(0,800,0,800);
	  glBegin(GL_POLYGON);
	  	 glVertex2f(50,50);
	  	glVertex2f(450,50);
	  	glVertex2f(450,450);
	  	glVertex2f(50,450);
	  glEnd();
	  glFlush();
	}
void getPixel(int x, int y,float color[4])
{
	glReadPixels(x,y,1,1,GL_RGBA,GL_UNSIGNED_BYTE,color);
}
void setPixel(int x, int y,float color[4])
{
	glColor4fv(color);
}
void boundaryFill(int x,int y,float fillColor[4],float borderFill[4])
{
	float interiorColor[4];
	getPixel(x,y,interiorColor);
	if(x>0 && y>0 && x<=width && y<= height && interiorColor!=fillColor && interiorColor!=borderFill )
	{
		setPixel(x,y,fillColor);
		boundaryFill(x+1,y+1,fillColor,borderFill);
		boundaryFill(x,y+1,fillColor,borderFill);
		boundaryFill(x-1,y+1,fillColor,borderFill);
		boundaryFill(x+1,y,fillColor,borderFill);
		boundaryFill(x,y,fillColor,borderFill);
		boundaryFill(x-1,y,fillColor,borderFill);
		boundaryFill(x+1,y+1,fillColor,borderFill);
		boundaryFill(x,y+1,fillColor,borderFill);
	}
}

void ShapeMenu(int item){
	float fill[4]={1.0,0.0,0.0,1.0} ,border[4]={0.0,0.0,1.0,1.0};
	cout<<"o my god u selected this item="<<item;
	switch(item)
	{
	case 1:		boundaryFill(xco,yco,fill,border);
				cout<<"jkfddfvfd";
				break;
	}
}
void func(int button, int state,int x, int y)
{
	if(button == GLUT_RIGHT_BUTTON)
	{
		xco = x;
		yco = y;
	}
}
void myInit(){
}

int main(int argc,char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment 3");
	glutDisplayFunc(myDisplay);
	myInit();
	void glutMouseFunc();
	glutCreateMenu(ShapeMenu);
	glutAddMenuEntry("White",1);
	glutAddMenuEntry("Red",2);
	glutAddMenuEntry("Yellow",3);
	glutAddMenuEntry("Green",4);
	glutAddMenuEntry("Orange",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

}


