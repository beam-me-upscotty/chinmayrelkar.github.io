window.onload = function () {
document.getElementById("para").innerHTML = "#include<iostream>"+
"<br>#include<GL/glut.h>"+
"<br>using namespace std;"+
"<br>GLfloat xRotated, yRotated, zRotated;"+
"<br>void init(void)"+
"<br>{"+
"<br>glClearColor(0,0,0,0);"+
"<br>}"+
"<br>bool xpos = false;"+
"<br>void DrawCube(void)"+
"<br>{"+
"<br>glMatrixMode(GL_MODELVIEW);"+
"<br>// clear the drawing buffer."+
"<br>glClear(GL_COLOR_BUFFER_BIT);"+
"<br>glLoadIdentity();"+
"<br>glTranslatef(0.0,0.0,-10.5);"+
"<br>// rotation about Y axis glRotatef(yRotated,0.0,1.0,0.0);"+
"<br>glColor3f(0.0f,0.0f,1.0f);"+
"<br>glutWireCube(3);"+
"<br>// End Drawing The Cube glutSwapBuffers();"+
"<br>}"+
"<br>void menu(int item)"+
"<br>{"+
"<br>	if(item == 1)"+
"<br>		yRotated+=45;"+
"<br>	else if (item == 2)"+
"<br>		yRotated-=45;"+
"<br>	else"+
"<br>		exit(0);"+
"<br>	glutPostRedisplay();"+
"<br>}"+
"<br>int main(int argc, char** argv)"+
"<br>{"+
"<br>	glutInit(&argc, argv);"+
"<br>	//we initizlilze the glut. functions	"+
"<br>	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);"+
"<br>	glutInitWindowPosition(100, 100);"+
"<br>	glutCreateWindow(argv[0]);"+
"<br>	init();"+
"<br>	glutDisplayFunc(DrawCube);"+
"<br>	glutCreateMenu(menu);"+
"<br>		glutAddMenuEntry("right",1);"+
"<br>		glutAddMenuEntry("left",2);"+
"<br>		glutAddMenuEntry("Exit",3);"+
"<br>		glutAttachMenu(GLUT_RIGHT_BUTTON);"+	
"<br>	glutMainLoop();"+
"<br>	return 0;"+
"<br>}";
}
