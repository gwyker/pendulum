#include "prototypes.h"

void myinit( void )
{
/* attributes */

      glClearColor(0.0, 0.0, 0.0, 1.0); /* black background */
      glPointSize(1.0);

/* set up viewing */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) WINDOW_MAX, 
                 0.0, (float) WINDOW_MAX);
      glMatrixMode(GL_MODELVIEW);
}

void keyboard( unsigned char key, int x, int y ) {
    if ( key == 'q') //exit program
    	exit(0);
    if (key == 's') //stop animation

    if (key == 'r') //reset pendulum to the initial position AND restart motion

}

void arrowkeys ( int key, int x, int y)
{
    if ( key == GLUT_KEY_RIGHT) {
        // increase pendulum speed
    }
    if ( key == GLUT_KEY_LEFT) {
        // decrease pendulum speed
    }
}

void reshape (int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    changeView();
    glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (/*GLUT_DOUBLE | */ GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX,WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Git and the Pendulum"); 
    myinit(); 
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowkeys);
    glutDisplayFunc(display); 
    glutMainLoop();
}
