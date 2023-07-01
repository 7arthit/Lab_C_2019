#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,800.0,0.0,800.0);
}

void plotQLab3(int x,int y,int xc,int yc){
    //circle (200,200) 140
    glVertex2d(xc+x,yc+y);//Q1
    glVertex2d(xc+y,yc+x);//Q2
    glVertex2d(xc+y,yc-x);//Q3
    glVertex2d(xc+x,yc-y);//Q4
    glVertex2d(xc-x,yc-y);//Q5
    glVertex2d(xc-y,yc-x);//Q6
    glVertex2d(xc-y,yc+x);//Q7
    glVertex2d(xc-x,yc+y);//Q8
}

void MidpointCircle(){
    //63011212019
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    Bresenham(100,250,400,250);
    glFlush();
    Bresenham(100,250,250,400);
    glFlush();
    Bresenham(250,400,400,250);
    glFlush();
    glEnd();
    glFlush();
    MidpointCircle_loop(100,250,10);
    MidpointCircle_loop(250,400,10);
    MidpointCircle_loop(400,250,10);
}

void MidpointCircle_loop(int x, int y , int ra){
    //63011212019
    int xc = x, yc = y , r = ra;
    for(int i=0 ; i<5 ; i++){
        int x = 0, y = r;
        int p = 1 - r;
        plotQLab3(x,y,xc,yc);
        glEnd();
        while(x < y){
            x++;
            if(p<0){
                p = p + 2 * (x) + 1;
            }
            else {
                y--;
                p = p + 2 * (x) + 1 - 2 * (y);
            }
            glBegin(GL_POINTS);
            plotQLab3(x,y,xc,yc);
            glEnd();
            glFlush();
        }
        r += 15;
    }
    glEnd();
    glFlush();
}

void Bresenham(iX1,iY1,iX2,iY2){
    //63011212019
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

void show(void){
    MidpointCircle();
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("MidpointCircle_3");
    myinit();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
