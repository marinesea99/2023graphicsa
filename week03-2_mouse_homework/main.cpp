#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glBegin(GL_POLYGON);
    glVertex2f(-0.540, 0.468);
    glVertex2f(-0.544, -0.404);
    glVertex2f(0.584, -0.388);
    glVertex2f(0.444, 0.612);
    glEnd();

    glutSwapBuffers();
}
void mouse(int botton,int state,int x,int y)
{
    float X = (x-250)/250.0;
    float Y = -(y-250)/250.0;///口訣:減一半、除一半、y負號
    if(state==GLUT_DOWN){
        printf("    glVertex2f(%.3f, %.3f);\n", X, Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}

















