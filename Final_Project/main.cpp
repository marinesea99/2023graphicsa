#include <stdio.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"
#include "CMP3_MCI.h"  ///�n�ϥΥt�@�ӥ~��
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * hand1 = NULL;
GLMmodel * hand2 = NULL;
GLMmodel * leg1 = NULL;
GLMmodel * leg2 = NULL;
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
FILE * fin = NULL;
FILE * fout = NULL;
float teapotX=0, teapotY=0, oldX=0, oldY=0;  ///�����P
float angle[20]={}, angle2[20]={};
float OldAngle[20]={}, NewAngle[20]={};
float OldAngle2[20]={}, NewAngle2[20]={};
//float Tangle = 0;
int ID=0; ///0:head, 1,2:left, 3,4:right hand, 5,6,7:left leg, 8,9,10:right leg
void timer(int t) {
    glutTimerFunc(20, timer, t+1);
    if(t%50==0){ ///�s���}�l,�nŪ�s���ʧ@
        if(fin==NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i] );
            fscanf(fin, "%f", &NewAngle2[i] );
        }
    }
    float alpha = (t%50) / 50.0;
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        angle2[i] = alpha * NewAngle2[i] + (1-alpha) * OldAngle2[i];
    }
    glutPostRedisplay();
}
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    if(key=='4') ID=4;
    if(key=='5') ID=5;
    if(key=='s'){ ///save �T��@: save, read, play (���})
        if(fout==NULL) fout = fopen("motion.txt", "w");
        for(int i=0; i<20; i++){
            fprintf(fout, "%.2f ", angle[i] );
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("�A�g�F1��\n");
    }
    if(key=='r'){ ///read �T��@: save, read, play (���})
        if(fin==NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i] );
            fscanf(fin, "%f", &angle2[i] );
        }
        glutPostRedisplay();
    }
    if(key=='p'){ ///play �T��@: save, read, play (���})
        glutTimerFunc(0, timer, 0);
    }
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    teapotX += (x - oldX)/10.0; ///�����P
    teapotY += (oldY - y)/10.0; ///�����P
    angle[ID] += x - oldX;
    angle2[ID] += y - oldY; ///�����P
    oldX = x;
    oldY = y; ///�����P
    ///printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
int imgxbw;
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,imgxbw);
    glScalef(1,2,1);
    glTranslatef(0,0,0.9);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,0); glVertex2f(-1.1,+0.7);
        glTexCoord2f(1,0); glVertex2f(+1.1,+0.7);
        glTexCoord2f(1,1); glVertex2f(+1.1,-0.7);
        glTexCoord2f(0,1); glVertex2f(-1.1,-0.7);
    glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(angle[0], 0, 1, 0);
        glRotatef(angle2[0], 1, 0, 0);
        glScalef(1, 1, 1);
        glTranslatef(0, -0.3, 0);
        glRotatef(180, 0, 1, 0);
        glPushMatrix();
            glColor3f(1,1,1);///glColor3f(1,0,0);
            glScalef(0.1, 0.1, 0.1);
            ///glRotatef(angle, 0, 1, 0);
            glColor3f(1,0,0);
            glmDraw(body, GLM_MATERIAL); ///glmDraw(gundam, GLM_MATERIAL | GLM_TEXTURE);


            glPushMatrix();
                glTranslatef(-0.000 , 6.300 , 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef(0.000 , -6.300 , 0 );
                //glTranslatef(teapotX, teapotY, 0);
                glColor3f(1,1,0);
                glmDraw(head, GLM_MATERIAL);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-1.500 , 5.800 , 0 );
                glRotatef(angle[2], 0, 1, 0);
                glRotatef(angle2[2], 1, 0, 0);
                glTranslatef(1.500 , -5.800 , 0 );
                //glTranslatef(teapotX, teapotY, 0);
                glColor3f(1,0,0);
                glmDraw(hand1, GLM_MATERIAL);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(1.500 , 5.800 , 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(-1.500 , -5.800 , 0 );
                //glTranslatef(teapotX, teapotY, 0);
                glColor3f(1,0,0);
                glmDraw(hand2, GLM_MATERIAL);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.500 , 2.800 , 0 );
                glRotatef(angle[4], 0, 1, 0);
                glRotatef(angle2[4], 1, 0, 0);
                glTranslatef(0.500 , -2.800 , 0 );
                //glTranslatef(teapotX, teapotY, 0);
                glColor3f(0,0,1);
                glmDraw(leg1, GLM_MATERIAL);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0.500 , 2.800 , 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(-0.500 , -2.800 , 0 );
                //glTranslatef(teapotX, teapotY, 0);
                glColor3f(0,0,1);
                glmDraw(leg2, GLM_MATERIAL);
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
    //Tangle++;///�⨤��++
}
/*myLight()
{
    const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[] = { 100.0f };


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}*/

CMP3_MCI myMP3;  ///�n�ŧi�@���ܼ�
int main(int argc, char** argv)
{
    myMP3.Load("background.mp3"); ///�۹���|
    myMP3.Play();///����

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    //glutIdleFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    imgxbw = myTexture("background.jpg");

    head = glmReadOBJ("lego/head.obj");
    body = glmReadOBJ("lego/body.obj");
    hand1 = glmReadOBJ("lego/hand1.obj");
    hand2 = glmReadOBJ("lego/hand2.obj");
    leg1 = glmReadOBJ("lego/leg1.obj");
    leg2 = glmReadOBJ("lego/leg2.obj");
    glEnable(GL_DEPTH_TEST);

    //myLight();
    glutMainLoop();
}
