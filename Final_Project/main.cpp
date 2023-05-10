#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4]={0, 1, 0, 0};
void keyboard(unsigned char key,int x, int y)
{
    if(key=='0') show[0] = !show[0];
    if(key=='1') show[1] = !show[1];
    if(key=='2') show[2] = !show[2];
    if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}
FILE * fout = NULL;
FILE * fin =NULL;
float teapotX=0, teapotY=0;
float angle=0, angle2=0, angle3=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);
        if(body==NULL){
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");
            //glmUnitize(body);
        }
        if(show[0]) glmDraw(head , GLM_MATERIAL);
        if(show[1]) glmDraw(body , GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(teapotX, teapotY, 0);
            ///glTranslatef(1.040000, 0.066666, 0);
            if(show[2]) glmDraw(uparmR , GLM_MATERIAL);
        glPopMatrix();
        if(show[3]) glmDraw(lowarmR , GLM_MATERIAL);

    glPopMatrix();
    glutSwapBuffers();
}
int oldX = 0, oldY = 0;
void motion(int x,int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY += (y - oldY)/150.0;
    printf("glTranslatef(%f, %f, 0);\n",teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        angle = x;
        ///teapotX = (x-150)/150.0;
        ///teapotY = (150-y)/150.0;
        ///if(fout==NULL) fout = fopen("file4.txt", "w");
        ///fprintf(fout , "%f %f\n",teapotX, teapotY);
    }
    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week13");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
/*void keyboard(unsigned char key, int x, int y)
{
    if(fin==NULL){
        fclose(fout);
        fin = fopen("file4.txt", "r");
    }
    fscanf(fin, "%f %f", &teapotX, &teapotY);
    display();
}*/
