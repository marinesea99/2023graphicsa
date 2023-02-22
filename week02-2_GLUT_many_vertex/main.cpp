#include <GL/glut.h>
void display()
{
    glColor3f(247/255.0,247/255.0,247/255.0);
    glBegin(GL_POLYGON);///開始畫
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f( 1,-1);
    glEnd();///結束畫

    glColor3f(244/255.0,209/255.0,33/255.0);
    glBegin(GL_POLYGON);
        glVertex2f((45-100)/100.0,-(134-100)/100.0);
        glVertex2f((36-100)/100.0,-(171-100)/100.0);
        glVertex2f((108-100)/100.0,-(179-100)/100.0);
        glVertex2f((104-100)/100.0,-(117-100)/100.0);
        ///口訣:減一半，除一半，y變負號
    glEnd();

    glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}



int main(int argc, char *argv[])///特別的main函式(有很多參數)
{
	glutInit(&argc, argv);///把GLUT開起來
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");///開視窗
	glutDisplayFunc(display);///顯示對應函式
	glutMainLoop();///用main迴圈壓在最後面
}
