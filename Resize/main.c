#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}

int scalX(int x, int sx){
    return x * sx;
}

int scalY(int y, int sy){
    return y * sy;
}

int TranslationX(int x, int tx){
    return x + tx;
}

int TranslationY(int y, int ty){
    return y + ty;
}

void showScalling(void){
    int x1=100, y1=100, x2=200, y2=100;
    int sx=2, sy=2;
    int tx=-100, ty=-100;
    int x1new, y1new, x2new, y2new;
    int x11new, y11new, x22new, y22new;
    glClear(GL_COLOR_BUFFER_BIT);

    //ตำแหน่งเดิม1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

    //ตำแหน่งใหม่ 1
    x1new = scalX(x1,sx);
    y1new = scalY(y1,sy);
    x2new = scalX(x2,sx);
    y2new = scalY(y2,sy);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1new,y1new);
    glVertex2i(x2new,y2new);
    glEnd();

    //ตำแหน่งเคลื่อยนย้าย 1
    x11new = TranslationX(x1new,tx);
    y11new = TranslationY(y1new,ty);
    x22new = TranslationX(x2new,tx);
    y22new = TranslationY(y2new,ty);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2i(x11new,y11new);
    glVertex2i(x22new,y22new);
    glEnd();

    //ตำแหน่งเดิม 2
    x1=200, y1=100, x2=200, y2=200;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

    //ตำแหน่งใหม่ 2
    x1new = scalX(x1,sx);
    y1new = scalY(y1,sy);
    x2new = scalX(x2,sx);
    y2new = scalY(y2,sy);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1new,y1new);
    glVertex2i(x2new,y2new);
    glEnd();

    //ตำแหน่งเคลื่อยนย้าย 2
    x11new = TranslationX(x1new,tx);
    y11new = TranslationY(y1new,ty);
    x22new = TranslationX(x2new,tx);
    y22new = TranslationY(y2new,ty);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2i(x11new,y11new);
    glVertex2i(x22new,y22new);
    glEnd();

    //ตำแหน่งเดิม 3
    x1=100, y1=200, x2=200, y2=200;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

    //ตำแหน่งใหม่ 3
    x1new = scalX(x1,sx);
    y1new = scalY(y1,sy);
    x2new = scalX(x2,sx);
    y2new = scalY(y2,sy);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1new,y1new);
    glVertex2i(x2new,y2new);
    glEnd();

    //ตำแหน่งเคลื่อยนย้าย 3
    x11new = TranslationX(x1new,tx);
    y11new = TranslationY(y1new,ty);
    x22new = TranslationX(x2new,tx);
    y22new = TranslationY(y2new,ty);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2i(x11new,y11new);
    glVertex2i(x22new,y22new);
    glEnd();

    //ตำแหน่งเดิม 4
    x1=100, y1=100, x2=100, y2=200;
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glEnd();

    //ตำแหน่งใหม่ 4
    x1new = scalX(x1,sx);
    y1new = scalY(y1,sy);
    x2new = scalX(x2,sx);
    y2new = scalY(y2,sy);
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2i(x1new,y1new);
    glVertex2i(x2new,y2new);
    glEnd();

    //ตำแหน่งเคลื่อยนย้าย 4
    x11new = TranslationX(x1new,tx);
    y11new = TranslationY(y1new,ty);
    x22new = TranslationX(x2new,tx);
    y22new = TranslationY(y2new,ty);
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINES);
    glVertex2i(x11new,y11new);
    glVertex2i(x22new,y22new);
    glEnd();

    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("showscalling_4_2019");
    myinit();
    glutDisplayFunc(showScalling);
    glutMainLoop();
    return 0;
}
