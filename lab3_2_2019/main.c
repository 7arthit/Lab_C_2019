#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}

void DDAline(void){
    float X1 = 20.00;
    float Y1 = 30.00;
    float X2 = 400.00;
    float Y2 = 150.00;

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
        glEnd();
        glFlush();
    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("DDAline");
    myinit();
    glutDisplayFunc(DDAline);
    glutMainLoop();
    return 0;
}
