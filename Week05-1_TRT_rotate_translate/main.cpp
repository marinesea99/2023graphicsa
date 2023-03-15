///先把上週的04-1程式碼拿來用
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glColor3f(0,1,0);///綠色
    glPushMatrix();
        glTranslatef(0.8,0,0);
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f(1,0,0);///紅色
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glTranslatef(0.8,0,0);
        glutSolidTeapot( 0.3 );
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
