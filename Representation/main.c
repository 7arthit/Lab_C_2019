#include<windows.h>
#include<gl\gl.h>
#include<gl\glu.h>
#include<gl\glut.h>

float vertices[6][3];
float verticesnew[6][3];
float edges[8][2];
float surfaces[3][5];

void draw(void);
void representation() {
    vertices[0][0] = -1;
    vertices[0][1] = 2;
    vertices[0][2] = 1;
    vertices[1][0] = 2;
    vertices[1][1] = 3;
    vertices[1][2] = -2;
    vertices[2][0] = 4;
    vertices[2][1] = 1;
    vertices[2][2] = -1;
    // e0
    edges[0][0] = 0;
    edges[0][1] = 1;
    // e1
    edges[1][0] = 0;
    edges[1][1] = 2;
    // e2
    edges[2][0] = 1;
    edges[2][1] = 2;
    //s0
    surfaces[0][0] = 0;
    surfaces[0][1] = 1;
    surfaces[0][1] = 2;
}

void setSurfaces(int s, int ne) {
    int e[ne];
    int v[ne][2];

    for(int i = 0; i < ne; i++) {
        e[i] = surfaces[s][i];
    }
    for(int i = 0; i < ne; i++) {
        int j = e[i];
        v[i][0] = edges[j][0];
        v[i][1] = edges[j][1];
    }
    int idx1, idx2;
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < ne; i++) {
        idx1 = v[i][0];
        idx2 = v[i][1];
        glVertex3f(vertices[idx1][0],vertices[idx1][1],vertices[idx1][2]);
        glVertex3f(vertices[idx2][0],vertices[idx2][1],vertices[idx2][2]);
    }
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    for(int i = 0; i < ne; i++) {
        idx1 = v[i][0];
        idx2 = v[i][1];
        glVertex3f(verticesnew[idx1][0],verticesnew[idx1][1],verticesnew[idx1][2]);
        glVertex3f(verticesnew[idx2][0],verticesnew[idx2][1],verticesnew[idx2][2]);
    }
    glEnd();
}

void draw(){
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.0,0.0,-10.0);
    representation();
    glBegin(GL_LINES);
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(vertices[0][0],vertices[0][1],vertices[0][2]);
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(vertices[1][0],vertices[1][1],vertices[1][2]);
    glVertex3f(vertices[2][0],vertices[2][1],vertices[2][2]);
    glEnd();
    // Translation
    int tx = 2, ty = 1, tz = 1;
    verticesnew[0][0] = vertices[0][0] + tx;
    verticesnew[0][1] = vertices[0][1] + ty;
    verticesnew[0][2] = vertices[0][2] + tz;
    verticesnew[1][0] = vertices[1][0] + tx;
    verticesnew[1][1] = vertices[1][1] + ty;
    verticesnew[1][2] = vertices[1][2] + tz;
    verticesnew[2][0] = vertices[2][0] + tx;
    verticesnew[2][1] = vertices[2][1] + ty;
    verticesnew[2][2] = vertices[2][2] + tz;
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex3f(verticesnew[0][0],verticesnew[0][1],verticesnew[0][2]);
    glVertex3f(verticesnew[1][0],verticesnew[1][1],verticesnew[1][2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(verticesnew[0][0],verticesnew[0][1],verticesnew[0][2]);
    glVertex3f(verticesnew[2][0],verticesnew[2][1],verticesnew[2][2]);
    glEnd();
    glBegin(GL_LINES);
    glVertex3f(verticesnew[1][0],verticesnew[1][1],verticesnew[1][2]);
    glVertex3f(verticesnew[2][0],verticesnew[2][1],verticesnew[2][2]);
    glEnd();
    setSurfaces(0,3);
    glFlush();
}
void reshape(int x,int y){
    if(y==0||x==0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100,(GLdouble)x/(GLdouble)y,0.6,40);
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitWindowSize(750,750);
    glutCreateWindow("Demo3D_2019");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
