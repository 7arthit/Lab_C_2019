#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}
void lab2_1(void){
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(50,150);
    glVertex2i(90,175);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2i(50,150);
    glVertex2i(90,175);
    glEnd();
    glFlush();

    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(110,135);
    glVertex2i(90,85);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2i(110,135);
    glVertex2i(90,85);
    glEnd();
    glFlush();

    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(65,115);
    glVertex2i(50,85);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2i(65,115);
    glVertex2i(50,85);
    glEnd();
    glFlush();

    glBegin(GL_POINTS);
    glVertex2i(150,150);
    glVertex2i(190,175);
    glVertex2i(210,135);
    glVertex2i(190,85);
    glVertex2i(165,115);
    glVertex2i(150,85);
    glEnd();
    glFlush();
    glBegin(GL_LINE_STRIP);
    glVertex2i(150,150);
    glVertex2i(190,175);
    glVertex2i(210,135);
    glVertex2i(190,85);
    glVertex2i(150,85);
    glVertex2i(165,115);
    glEnd();
    glFlush();

    glBegin(GL_POINTS);
    glVertex2i(250,150);
    glVertex2i(290,175);
    glVertex2i(310,135);
    glVertex2i(290,85);
    glVertex2i(265,115);
    glVertex2i(250,85);
    glEnd();
    glFlush();
    glBegin(GL_LINE_LOOP);
    glVertex2i(250,150);
    glVertex2i(290,175);
    glVertex2i(310,135);
    glVertex2i(290,85);
    glVertex2i(250,85);
    glVertex2i(265,115);
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
    glutDisplayFunc(lab2_1);
    glutMainLoop();
    return 0;
}
