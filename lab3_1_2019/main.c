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
    // 3
    //DDAline(20,30,400,150);
    //DDAline(20,30,400,30);
    //DDAline(400,150,400,30);

    //4
    //DDAline(20,150,400,150);
    //DDAline(20,30,400,30);
    //DDAline(400,150,400,30);
    //DDAline(20,150,20,30);

    //6
    //DDAline(150,150,300,150);
    //DDAline(150,300,300,300);

    //DDAline(100,225,150,300);
    //DDAline(100,225,150,150);

    //DDAline(350,225,300,150);
    //DDAline(350,225,300,300);

    //8
    //DDAline(150,150,300,150);
    //DDAline(150,300,300,300);

    //DDAline(100,275,150,300);
    //DDAline(100,175,150,150);

    //DDAline(350,175,300,150);
    //DDAline(350,275,300,300);

    //DDAline(100,275,100,175);
    //DDAline(350,275,350,175);
    glEnd();
    glFlush();
}

void DDAline(iX1,iY1,iX2,iY2){
    //63011212019

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

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
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
    glutCreateWindow("DDAline1");
    myinit();
    glutDisplayFunc(show);
    glutMainLoop();
    return 0;
}
