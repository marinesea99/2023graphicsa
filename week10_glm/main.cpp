///�⤧�e��10�� GLUT�{���X���ӥ�
#include <stdio.h>
#include "glm.h" ///�U�� source.zip��glm.h��bweek10_glm�ؿ���
///glm.c���ҦW��glm.cpp��bweek10_glm�ؿ���
///��glm.cpp�[��M�׸�
///��ҫ�(ex. Al.obj A.mtl)�ƻs��u�@�ؿ�
GLMmodel * pmodel = NULL;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(pmodel==NULL){
        pmodel = glmReadOBJ("Al.obj");
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel ,90);
    }
    glmDraw(pmodel , GLM_MATERIAL);
    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10");

    glutDisplayFunc(display);
    glutMainLoop();
}
