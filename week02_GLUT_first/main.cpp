#include <GL/glut.h>
void display()
{
    glColor3f(0,1,0);///綠色
    glBegin(GL_POLYGON);///開始畫多邊形
        glColor3f(1,0,0); glVertex2f( 0, 1);///紅色頂點Vertex
        glColor3f(0,1,0); glVertex2f(-1,-1);///綠色頂點Vertex
        glColor3f(0,0,1); glVertex2f( 1,-1);///藍色頂點Vertex
    glEnd();///結束畫


    glColor3f(1,1,0);///黃色
    glutSolidTeapot(0.3);///畫出一個實心的茶壺
    glutSwapBuffers();///請GLUT把畫面swap送到顯示位置
}
int main(int argc, char *argv[])///特別的main函式(有很多參數)
{
	glutInit(&argc, argv);///把GLUT開起來
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("GLUT Shapes");///開視窗
	glutDisplayFunc(display);///顯示對應函式
	glutMainLoop();///用main迴圈壓在最後面
}
