///將05-1程式碼拿來用
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(0,1,0);///綠色的身體
    glPushMatrix();
        glutSolidCube( 0.5 );

        glPushMatrix();
            glTranslatef(0.5,0.5,0);
            glColor3f(1,0,0);
            glutSolidCube(0.5);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week03");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
