#include <GL/glut.h>
float X=0,Y=0;///�Q��global�ܼ�,�b��Ƥ����ǭ�(�j�g��)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(X,Y,0);///�u���o���٤���
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}

    glutSwapBuffers();
}
///#include <stdio.h>
void mouse(int botton,int state,int x,int y)
{///��mouse�禡����
    X = (x-150)/150.0;///printf("%d %d %d %d\n",botton,state,x,y);
    Y = -(y-150)/150.0;///�f�Z:��@�b�B���@�b�By�t��
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
}
