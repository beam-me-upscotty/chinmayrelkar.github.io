/*
 * main.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: Chinmay Relkar
 */
#include<GL/glut.h>

int xco=0,yco = 0;
void getPixel(int x, int y,float color[3])
{
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}


void setPixel(int x, int y,float fill[4])
{	
	glColor3fv(fill);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd(); 
}

bool arraycheck(float x[3],float y [3])
{
	for(int i = 0 ;i<3;i++)
		if(x[i]!=y[i])
			return false;
	return true;
}



void boundaryFill(int x,int y,float fillColor[3],float borderColor[3])  
{  
	float interiorColor[3];  
	getPixel(x,y,interiorColor);
		
	if(x>400||x<000||y>400||y<000) return;  	
       	
	if(	(interiorColor[0]!=borderColor[0])
		&&(interiorColor[1]!=borderColor[1])
		&&(interiorColor[2]!=borderColor[2]) 
		&&(interiorColor[0]!=fillColor[0])
		&&(interiorColor[1]!=fillColor[1])
		&&(interiorColor[2]!=fillColor[2]))
       {  
	    setPixel(x,y,fillColor);
            boundaryFill(x+1,y,fillColor,borderColor);  
            boundaryFill(x-1,y,fillColor,borderColor);  
            boundaryFill(x,y+1,fillColor,borderColor);
            boundaryFill(x,y-1,fillColor,borderColor);  
       }  
  }  

void myDisplay()
{  
	 glColor3f(0, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(100,100);
		glVertex2f(300,100);
		glVertex2f(300,100);
		glVertex2f(300,300);
		glVertex2f(300,300);
		glVertex2f(100,300);
		glVertex2f(100,300);
		glVertex2f(100,100);
		
		
		glVertex2f(00,00);
		glVertex2f(400,000);
		glVertex2f(400,000);
		glVertex2f(400,400);
		glVertex2f(400,400);
		glVertex2f(00,400);
		glVertex2f(00,400);
		glVertex2f(00,00);
		glEnd();
	glFlush();
}


void myInit()
{

	glClearColor(0.8, 0.8, 0.8, 1.0);
	 
	  glMatrixMode(GL_PROJECTION);
	  glLoadIdentity();
	  gluOrtho2D(0,400,0,400);
		glClear(GL_COLOR_BUFFER_BIT);
	
}
void ShapeMenu(int item)
{

	float fill[3]={1.0,1.0,1.0};
	float border[3]={0.0,0.0,0.0};
	switch(item)
	{
		case 1:		fill[0]=1.0;fill[1]=1.0;fill[2]=1.0;
				boundaryFill(xco,yco,fill,border);
				break;

		case 2:		
				fill[0]=1.0;fill[1]=0.0;fill[2]=0.0;
				boundaryFill(xco,yco,fill,border);
				break;
	
		case 3:		
				fill[0]=1.0;fill[1]=1.0;fill[2]=0.0;
				boundaryFill(xco,yco,fill,border);
				break;

		case 4:		
				fill[0]=0.0;fill[1]=1.0;fill[2]=0.0;
				boundaryFill(xco,yco,fill,border);
				break;

		case 5:		
				fill[0]=0.0;fill[1]=0.0;fill[2]=1.0;
				boundaryFill(xco,yco,fill,border);
				break;
		
		case 6:	
				exit(0);
	}
}


void func(int button, int state,int x, int y)
{
	static bool flag = false;
	if(button==GLUT_LEFT_BUTTON)
	{	
		if(!flag)
		{	
			xco = x;
			yco = 400-y;
			flag = true;
		}
		else
			flag = false;
	}

	float interiorColor[3];
	  getPixel(x,y,interiorColor);
}


int main(int argc,char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(100,100);
	glutCreateWindow("wow");
	myInit();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(func);
	glutCreateMenu(ShapeMenu);
	glutAddMenuEntry("White",1);
	glutAddMenuEntry("Red",2);
	glutAddMenuEntry("Yellow",3);
	glutAddMenuEntry("Green",4);
	glutAddMenuEntry("Blue",5);
	glutAddMenuEntry("Exit",6);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}

