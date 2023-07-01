#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}

void lab2_3(void){
    glColor3f(0.0f, 1.0f, 0.0f);
    int p1[]={50,100};
    int p2[]={100,100};
    int p3[]={100,150};
    int p4[]={50,150};
    glBegin(GL_POLYGON);
    glVertex2iv(p1);
    glVertex2iv(p2);
    glVertex2iv(p3);
    glVertex2iv(p4);
    glEnd();
    glFlush();

    glColor4f(1.0f, 0.0f, 0.0f, 0.0f);
    int p11[]={50,150};
    int p21[]={75,175};
    int p31[]={100,150};
    glBegin(GL_TRIANGLES);
    glVertex2iv(p11);
    glVertex2iv(p21);
    glVertex2iv(p31);
    glEnd();
    glFlush();

    glColor3f(0.0f, 0.0f, 1.0f);
    int p12[]={75,175};
    int p22[]={150,185};
    int p32[]={170,160};
    int p42[]={100,150};
    glBegin(GL_POLYGON);
    glVertex2iv(p12);
    glVertex2iv(p22);
    glVertex2iv(p32);
    glVertex2iv(p42);
    glEnd();
    glFlush();

    glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
    int p123[]={100,150};
    int p223[]={170,160};
    int p323[]={170,115};
    int p423[]={100,100};

    glBegin(GL_POLYGON);
    glVertex2iv(p123);
    glVertex2iv(p223);
    glVertex2iv(p323);
    glVertex2iv(p423);
    glEnd();
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("BasicOpenGL");
    myinit();
    glutDisplayFunc(lab2_3);
    glutMainLoop();
    return 0;
}
