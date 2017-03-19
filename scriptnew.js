document.getElementById("para").innerHTML = "    #include <GL/glut.h><br>
#include <iostream><br>
using namespace std;<br>
GLfloat xRotated, yRotated, zRotated;<br>
void init(void)<br>
{<br>
    glClearColor(0,0,0,0);<br>
}<br>
bool xpos = false;<br>
<br>
void DrawCube(void)<br>
{<br>

     glMatrixMode(GL_MODELVIEW);<br>
    // clear the drawing buffer.<br>
    glClear(GL_COLOR_BUFFER_BIT);<br>
    glLoadIdentity();<br>
    glTranslatef(0.0,0.0,-10.5);<br>
    
    if(xpos)<br>
        yRotated += 1;<br>
    else
        yRotated -= 1;<br>
    cout<<xpos;<br>
    // rotation about Y axis<br>
    glRotatef(yRotated,0.0,1.0,0.0);<br>
    glColor3f(0.0f,0.0f,1.0f);<br>
    glutWireCube(3);<br>            // End Drawing The Cube
    glutSwapBuffers();<br>
    glutPostRedisplay();<br>
}<br>


<br>
void reshape(int x, int y)<br>
{<br>
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return<br>
    //Set a new projection matrix<br>
    glMatrixMode(GL_PROJECTION);  <br>
    glLoadIdentity();<br>
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);<br>
    glMatrixMode(GL_MODELVIEW);<br>
    glViewport(0,0,x,y);  //Use the whole window for rendering<br>
}<br>
void Mouse(int button,int state,int x, int y)<br>
{<br>
    if(x>150)<br>
        xpos=true;<br>
    else <br>
        xpos=false;<br>
    glutPostRedisplay();<br>
}<br>
int main(int argc, char** argv)<br>
{<br>
    glutInit(&argc, argv);<br>
    //we initizlilze the glut. functions<br>
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);<br>
    glutInitWindowPosition(100, 100);<br>
    glutCreateWindow(argv[0]);<br>
    init();<br>
    glutDisplayFunc(DrawCube);<br>
    glutReshapeFunc(reshape);<br>
    glutMouseFunc(Mouse);<br>
    glutMainLoop();<br>
    return 0;<br>
}<br>
";
