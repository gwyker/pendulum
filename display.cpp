#include "prototypes.h"

double t=0.0;
double theta=M_PI/2.0;
double omega=0.0;

void display(void)
{
    vertex point[4];     
    int pointCount = 4;   
    vertex *points;              //pointer to pendulum coords

    points = &point[0];         //pointer to the array of points 

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 1.0, 0.0);
    
    //definePendulumArm(points);
    //drawPendulum(points, pointCount);
    glPushMatrix();
    step(t, theta, omega);
    glTranslatef(400.0, 400.0, 0.0);
    glRotatef(theta*(180.0/M_PI), 0.0, 0.0, 1.0);
    glTranslatef(-400.0, -400.0, 0.0);
    glRecti(350, 400, 450, 200);
    cout << "t = " << t << " theta = " << theta << " omega = " << omega << endl;
    cout << "loop\n";
    glutSwapBuffers();
    glPopMatrix();
    glutPostRedisplay();
}

void definePendulumArm(vertex *points) //defines the rectangular arm of the pendulum without the bell
{
   //remember to display the bell AFTER the arm
   points[0].x = 350.0;  points[0].y = 400.0; points[0].z = 0.0; points[0].w = 1.0; //top right
   points[1].x = 450.0;  points[1].y = 400.0; points[1].z = 0.0; points[1].w = 1.0; //top left
   points[2].x = 450.0;  points[2].y = 200.0; points[2].z = 0.0; points[2].w = 1.0; //bottom left
   points[3].x = 350.0;  points[3].y = 200.0; points[3].z = 0.0; points[3].w = 1.0; //bottom right
}
/*
void drawPendulum(vertex *points, int pointCount)
{
    int i;

    glBegin(GL_LINE_LOOP);
    for (i=0;i<pointCount;i++)
        glVertex2f((points+i)->x, (points+i)->y);
    glEnd();
    cout << "pendulum drawn\n";
}
*/

