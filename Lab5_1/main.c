#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,800.0,0.0,800.0);
}

void plotQLac(int x,int y,int xc,int yc){
    //circle (100 , 100) 80
    glVertex2d(xc+x,yc+y);//Q1
    glVertex2d(xc+y,yc+x);//Q2
    glVertex2d(xc+y,yc-x);//Q3
    glVertex2d(xc+x,yc-y);//Q4
    glVertex2d(xc-x,yc-y);//Q5
    glVertex2d(xc-y,yc-x);//Q6
    glVertex2d(xc-y,yc+x);//Q7
    glVertex2d(xc-x,yc+y);//Q8
}

void plotQLab1(int x,int y,int xc,int yc){
    //circle (200,200) 140
    glVertex2d(xc+x,yc+y);//Q1
    glVertex2d(xc+y,yc+x);//Q2
    glVertex2d(xc-y,yc+x);//Q7
    glVertex2d(xc-x,yc+y);//Q8
}

void MidpointCircle(){
    //63011212019
    int xc = 200, yc = 200 , r = 140;
    int x = 0, y = r;
    int p = 1 - r;
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
        plotQLab1(x,y,xc,yc);
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
            plotQLab1(x,y,xc,yc);
        glEnd();
        glFlush();
    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("MidpointCircle_1");
    myinit();
    glutDisplayFunc(MidpointCircle);
    glutMainLoop();
    return 0;
}
