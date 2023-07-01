#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,800.0,0.0,800.0);
}

void show(){
    // 1
    Bresenham(20,30,400,150);
    glFlush();
    Bresenham(20,150,400,30);
    glFlush();
    Bresenham(20,30,400,30);
    glFlush();
    Bresenham(20,150,400,150);
    glFlush();
    Bresenham(400,150,400,30);
    glFlush();
    Bresenham(20,150,20,30);
    glFlush();

    //ทำเพิ่ม



    glEnd();
    glFlush();
}

void Bresenham(iX1,iY1,iX2,iY2){
    //63011212019
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    double x1 = iX1, y1 = iY1, x2 = iX2, y2 = iY2;
    float x,y;
    x = x1;
    y = y1;
    float dx = abs (x2 - x1);
    float dy = abs (y2 - y1);
    float p = 2 * dy - dx;
    if (x1 == x2){
        while(y >= y2){
            glBegin(GL_POINTS);
            glVertex2d(x,y);
            y--;
        }
    }
    else{
        while(x <= x2){
        glBegin(GL_POINTS);
        glVertex2d(x,y);

        x++;
        if(p <= 0)
            p = p + 2 * dy;
        else{
            if(y1 < y2) y++;
            else y--;
            p = p+(2*dy)-(2*dx);
            }
        }
    }

}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenham");
    myinit();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
