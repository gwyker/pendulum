#include "prototypes.h"

void display(void)
{
    float point[MAX];        
    float *points;              //pointer to pendulum coords

    struct vertex triangles[MAX]; //array of triangles after tesselation
    int triangleCount = 0;

    points = &point[0];         //pointer to the array of points 

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glRecti(VIEWPORT_MIN,VIEWPORT_MIN,VIEWPORT_MAX,VIEWPORT_MAX);

    definePendulumArm(points);
    drawPendulum(points);
    glutSwapBuffers();
}

void definePendulumArm(float *points) //defines the rectangular arm of the pendulum without the bell (a circle)
{
   //remember to display the bell AFTER the arm
   points[ 0] = 300.0;  points[ 1] = 400.0; points[ 2] = 0.0; points[ 3] = 1.0; //top right
   points[ 4] = 625.0;  points[ 5] = 400.0; points[ 6] = 0.0; points[ 7] = 1.0; //top left
   points[ 8] = 600.0;  points[ 9] = 300.0; points[10] = 0.0; points[11] = 1.0; //bottom left
   points[12] = 800.0;  points[13] = 500.0; points[14] = 0.0; points[15] = 1.0; //bottom right
}

void drawPendulum(float *points)
{
    int i;

    glBegin(GL_LINE_LOOP);
    for (i=0;i<points;i++)
        glVertex2f( (points+i)->x, (points+i)->y );
    glEnd();
}