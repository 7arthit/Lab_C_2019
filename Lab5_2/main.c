#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,800.0,0.0,800.0);
}

void plotQLab2(int x,int y,int xc,int yc){
    //circle (200,200) 140
    glVertex2d(xc+x,yc+y);//Q1
    glVertex2d(xc+x,yc-y);//Q4
    glVertex2d(xc-x,yc-y);//Q5
    glVertex2d(xc-x,yc+y);//Q8
}

void MidpointCircle(iX1,iY1,iX2,iY2){
    //63011212019
    int xc = 200, yc = 200 , r = 140;
    int x = 0, y = r;
    int p = 1 - r;
    glColor3f(1.0,1.0,1.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
        plotQLab2(x,y,xc,yc);
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
            plotQLab2(x,y,xc,yc);

        glEnd();
        glFlush();
    }

    DDAline(xc+x,yc+y , xc-x,yc-y);
    DDAline(xc+x,yc-y , xc-x,yc+y);

    glEnd();
    glFlush();
}

void DDAline(iX1,iY1,iX2,iY2){
    double X1=iX1,Y1=iY1,X2=iX2,Y2=iY2;

    float dx = (X2 - X1);
    float dy = (Y2 - Y1);

    float steps;
    float xInc,yInc,x,y;
    x = X1;
    y = Y1;
    if(abs(dx) > abs(dy)){
        steps = abs(dx);
    }
    else steps = abs(dy);

    xInc = dx / (float)steps;
    yInc = dy / (float)steps;

    glBegin(GL_POINTS);
    glVertex2d(x,y);
    glEnd();
    glFlush();

    for(int k = 0 ; k < steps ; k++){
        x = x + xInc;
        y = y + yInc;
        glBegin(GL_POINTS);
        glVertex2d(round(x),round(y));
    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("MidpointCircle_2");
    myinit();
    glutDisplayFunc(MidpointCircle);
    glutMainLoop();
    return 0;
}
