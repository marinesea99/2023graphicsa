///把之前的10行 GLUT程式碼拿來用
#include <stdio.h>
#include "glm.h" ///下載 source.zip有glm.h放在week10_glm目錄裡
///glm.c改黨名城glm.cpp放在week10_glm目錄裡
///把glm.cpp加到專案裡
///把模型(ex. Al.obj A.mtl)複製到工作目錄
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
