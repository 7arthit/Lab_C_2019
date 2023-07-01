#include<gl\gl.h>
#include<gl\glut.h>
#include<math.h>
#include<windows.h>

void myinit(void){
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,600.0,0.0,600.0);
}

void plotQ(int xc,int yc,int x,int y){
    glVertex2d(xc+x,yc+y);
    glVertex2d(xc+x,yc-y);
    glVertex2d(xc-x,yc-y);
    glVertex2d(xc-x,yc+y);

}

void ellipse(void){
    int rx=150, ry=100, xc=300, yc=300;
    int x=0, y=ry;
    int rx2 = rx*rx;
    int ry2 = ry*ry;
    int tworx2 = 2*rx2;
    int twory2 = 2*ry2;
    int p = ry2 - (rx*ry) + (0.25*rx2);
    int px=0;
    int py=tworx2*ry;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);
    glEnd();

    while(px<py) {
        x++;
        px = px + twory2;
        if(p<0) {
            p = p+twory2*x+ry2;
        } else {
            y--;
            py = py-tworx2;
            p = p+twory2*x+ry2-tworx2*y;
        }
        glBegin(GL_POINTS);
        plotQ(xc, yc, x, y);
        glEnd();

    }

    glFlush();
    p = ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2;
    while(y>0) {
        y--;
        if(p>0) {
            p = p+rx2-tworx2*y;
        } else {
            x++;
            p = p+twory2*x-tworx2*y+rx2;
        }
        glBegin(GL_POINTS);
        plotQ(xc, yc, x, y);
        glEnd();
    }
    glFlush();
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab6_1");
    myinit();
    glutDisplayFunc(ellipse);
    glutMainLoop();
    return 0;
}
