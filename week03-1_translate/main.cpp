#include <GL/glut.h>
float X=0,Y=0;///利用global變數,在函數之間傳值(大寫的)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清背景
    glPushMatrix();///備份矩陣
        glTranslatef(X,Y,0);///只有這行還不夠
        glutSolidTeapot(0.3);
    glPopMatrix();///還原矩陣

    glutSwapBuffers();
}
///#include <stdio.h>
void mouse(int botton,int state,int x,int y)
{///請mouse函式幫忙
    X = (x-150)/150.0;///printf("%d %d %d %d\n",botton,state,x,y);
    Y = -(y-150)/150.0;///口訣:減一半、除一半、y負號
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
