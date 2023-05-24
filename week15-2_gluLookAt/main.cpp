#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void reshape(int w, int h)
{
    glViewport(0, 0, w, h);

    float ar = w / (float) h;

    glMatrixMode(GL_PROJECTION);///先切換到Project矩陣
    glLoadIdentity();///矩陣清空
    gluPerspective(60, ar, 0.01, 1000);///現在一片空白，因為我們在茶壺裡

    glMatrixMode(GL_MODELVIEW);///做好後馬上回到 model view 矩陣
    glLoadIdentity();///矩陣清空
    gluLookAt(0, 0, 1,   0, 0, 0,   0, 1, 0);
            ///在0,0,1 看茶壺0,0,0 up是0,1,0
    glutPostRedisplay();
}
float eyeX = 0, eyeY = 0;
void motion(int x, int y)
{
    eyeX = (x-150.0) / 150.0;
    eyeY = (150.0-y) / 150.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, eyeY, 1,   0, 0, 0,   0, 1, 0);
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
}
