#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere( 0.02, 30, 30 );///正中心的圓球

    glutSolidTeapot(0.3);///身體

    glPushMatrix();
        ///glTranslatef(-0.5,0.5,0);
        glTranslatef(0.49,0.13,0);
        glRotatef(angle, 0, 0, 1);///可以轉動
        glTranslatef( 0.46, -0.05, 0 );///將轉動的中心放到中心
        glutSolidTeapot(0.3);

        glPushMatrix();
            glTranslatef(0.49,0.13,0);
            glRotatef(angle, 0, 0, 1);///可以轉動
            glTranslatef( 0.46, -0.05, 0 );///將轉動的中心放到中心
            glutSolidTeapot(0.3);
        glPopMatrix();

    glPopMatrix();



    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
