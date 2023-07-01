#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}

void lab2_2(void){
    glColor3f(1,1,0);
    glLineWidth(5);

    glBegin(GL_LINE_STRIP);
    glVertex2i(60,160);
    glVertex2i(60,195);

    glVertex2i(60,195);
    glVertex2i(70,195);

    glVertex2i(75,195);
    glVertex2i(75,175);

    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2i(60,75);
    glVertex2i(60,75);

    glVertex2i(60,100);
    glVertex2i(70,100);

    glVertex2i(75,100);
    glVertex2i(75,75);

    glEnd();
    glFlush();

    glBegin(GL_LINE_STRIP);
    glVertex2i(90,100);
    glVertex2i(90,110);

    glVertex2i(90,110);
    glVertex2i(120,110);

    glVertex2i(120,110);
    glVertex2i(120,100);

    glVertex2i(120,100);
    glVertex2i(90,100);

    glEnd();
    glFlush();

    glBegin(GL_LINE_LOOP);
    glVertex2i(50,150);
    glVertex2i(90,195);

    glVertex2i(90,195);
    glVertex2i(130,150);

    glVertex2i(130,75);
    glVertex2i(50,75);

    glVertex2i(50,150);
    glVertex2i(90,195);

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
    glutDisplayFunc(lab2_2);
    glutMainLoop();
    return 0;
}
