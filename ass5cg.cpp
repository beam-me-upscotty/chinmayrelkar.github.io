/*
 * main.cpp
 *
 *  Created on: Feb 20, 2017
 *      Author: root
 */
#include<GL/glut.h>
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int origin_x=50,origin_y=50;
template <class t>
void mat_mul(t a[2][2],t b[2])
{
	int c[2];
		c[0]=b[0]*a[0][0]+b[1]*a[1][0];
		c[1]=b[0]*a[0][1]+b[1]*a[1][1];
	b[1]=c[1];
	b[0]=c[0];
}


class triangle
{
	float coordinates[3][2];
	bool drawn;

	void draw()
	{
		glBegin(GL_LINES);
		for(int i =0;i<2;i++)
		{
			glVertex2f(coordinates[i][0],coordinates[i][1]);
			glVertex2f(coordinates[i+1][0],coordinates[i+1][1]);
		}
		glVertex2f(coordinates[2][0],coordinates[2][1]);
		glVertex2f(coordinates[0][0],coordinates[0][1]);
		glEnd();
	}

	void translate(int T_X,int T_Y)
	{
		for(int i=0;i<3;i++)
		{
			coordinates[i][0]+=T_X;
			coordinates[i][1]+=T_Y;
		}

	}
public:
	triangle(){
		drawn=false;
	}
	void draw_new();
	void translate();
	void scale();
	void rotate();
}t;

class Quad
{
	float coordinates[4][2];
	bool drawn;

	void draw()
	{
		glBegin(GL_LINES);
		for(int i =0;i<3;i++)
		{
			glVertex2f(coordinates[i][0],coordinates[i][1]);
			glVertex2f(coordinates[i+1][0],coordinates[i+1][1]);
		}
		glVertex2f(coordinates[3][0],coordinates[3][1]);
		glVertex2f(coordinates[0][0],coordinates[0][1]);
		glEnd();
	}

	void translate(int T_X,int T_Y)
	{
		for(int i=0;i<4;i++)
		{
			coordinates[i][0]+=T_X;
			coordinates[i][1]+=T_Y;
		}

	}
public:
	Quad()
	{
		drawn=false;
	}
	void draw_new();
	void translate();
	void scale();
	void rotate();
}Q;

void myDisplay()
{
	  glClearColor(0.0, 0.0, 0.5, 1);
	  glColor3f(1, 1, 1);
	  glClear(GL_COLOR_BUFFER_BIT);
// plotting x and y axis
	  glBegin(GL_LINES);
	  glVertex2f(origin_x,0);
	  glVertex2f(origin_x,500);
	  glEnd();
	  glBegin(GL_LINES);
	  glVertex2f(0,origin_y);
	  glVertex2f(500,origin_y);
	  glEnd();
	  glFlush();
}
void myInit(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);

}
void ShapeMenu(int item){
	if (item==1)
		exit(0);
}

void TransformMenuT(int item){
	switch(item)
	{
		case 1:t.draw_new();break;
		case 2:t.scale();break;
		case 3:t.translate();break;
		case 4:t.rotate();break;
		case 6:Q.draw_new();break;
		case 7:Q.scale();break;
		case 8:Q.translate();break;
		case 9:Q.rotate();break;
	}

}

int main(int argc,char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Assignment 3");
	glutDisplayFunc(myDisplay);
	myInit();

	int triangle = glutCreateMenu(TransformMenuT);
	glutAddMenuEntry("Draw",1);
	glutAddMenuEntry("Scale",2);
	glutAddMenuEntry("Translate",3);
	glutAddMenuEntry("Rotate",4);
	glutAddMenuEntry("Shear",5);

	int rhombus = glutCreateMenu(TransformMenuT);
	glutAddMenuEntry("Draw",6);
	glutAddMenuEntry("Scale",7);
	glutAddMenuEntry("Translate",8);
	glutAddMenuEntry("Rotate",9);
	glutAddMenuEntry("Shear",10);

	int MainMenu = glutCreateMenu(ShapeMenu);
	glutAddSubMenu("Triangle",triangle);
	glutAddSubMenu("Rhombus",rhombus);
	glutAddMenuEntry("Exit",1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

}


	void Quad::draw_new()
	{
		drawn=true;
		for(int i = 0;i< 4; i++)
		{
			cout<<"Enter point :";
			cin>>coordinates[i][0]>>coordinates[i][1];
		}
		for(int i = 0;i< 4; i++)
		{
			coordinates[i][0]+=origin_x;
			coordinates[i][1]+=origin_y;
		}
		draw();
	}
	void Quad::translate()
	{
		if(drawn==false)
		{
			cout<<"NO Quad Drawn...draw it first";
			return;
		}
			int T_X,T_Y;
			cout<<"Enter translation factor\nT_X=";
			cin>>T_X;
			cout<<"T_Y=";
			cin>>T_Y;
			translate(T_X,T_Y);
			draw();
		}
	void Quad::scale()
	{
		if(drawn==false)
		{
			cout<<"NO Quad Drawn...draw it first";
			return;
		}

			float S[2][2];
			cout<<"Enter Scaling Factor\nS_X=";
			cin>>S[0][0];
			cout<<"S_Y=";
			cin>>S[1][1];
			int x=-coordinates[0][0],y=-coordinates[0][1];
			translate(x,y);
			mat_mul(S,coordinates[0]);
			mat_mul(S,coordinates[1]);
			mat_mul(S,coordinates[2]);
			mat_mul(S,coordinates[3]);
			translate(-x,-y);
			draw();
	}
	void Quad::rotate()
	{
		if(drawn==false)
		{
			cout<<"NO Quad Drawn...draw it first";
			return;
		}

			float R[2][2];
			int x;
			cout<<"Enter angle of rotation";
			cin>>x;
			R[0][0]=cos((x*3.14/180));
			R[0][1]=-sin(x*3.14/180);
			R[1][0]=sin(x*3.14/180);
			R[1][1]=cos(x*3.14/180);
			mat_mul(R,coordinates[0]);
			mat_mul(R,coordinates[1]);
			mat_mul(R,coordinates[2]);
			mat_mul(R,coordinates[3]);
			draw();
		}

	void triangle::draw_new()
	{
		drawn=true;
		for(int i = 0;i< 3; i++)
		{
			cout<<"Enter point :";
			cin>>coordinates[i][0]>>coordinates[i][1];
		}
		for(int i = 0;i< 3; i++)
		{
			coordinates[i][0]+=origin_x;
			coordinates[i][1]+=origin_y;
		}
		draw();
	}
	void triangle::translate()
	{
		if(drawn==false)
		{
			cout<<"NO triangle Drawn...draw it first";
			return;
		}

		int T_X,T_Y;
		cout<<"Enter translation factor\nT_X=";
		cin>>T_X;
		cout<<"T_Y=";
		cin>>T_Y;
		translate(T_X,T_Y);
		draw();
	}

	void triangle::scale()
	{


		if(drawn==false)
		{
			cout<<"NO triangle Drawn...draw it first";
			return;
		}
		float S[2][2];
		cout<<"Enter Scaling Factor\nS_X=";
		cin>>S[0][0];
		cout<<"S_Y=";
		cin>>S[1][1];
		int x=-coordinates[0][0],y=-coordinates[0][1];
		translate(x,y);
		mat_mul(S,coordinates[0]);
		mat_mul(S,coordinates[1]);
		mat_mul(S,coordinates[2]);
		translate(-x,-y);
		draw();
	}
	void triangle::rotate()
	{

		if(drawn==false)
		{
			cout<<"NO triangle Drawn...draw it first";
			return;
		}

		float R[2][2];
		int x;
		cout<<"Enter angle of rotation";
		cin>>x;
		R[0][0]=cos((x*3.14/180));
		R[0][1]=-sin(x*3.14/180);
		R[1][0]=sin(x*3.14/180);
		R[1][1]=cos(x*3.14/180);
		mat_mul(R,coordinates[0]);
		mat_mul(R,coordinates[1]);
		mat_mul(R,coordinates[2]);
		draw();
	}
