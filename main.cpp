#include "prototypes.h"

int WINDOW_MAX = 800;
float angle, length, gravity, damping, amplitude, freq;

void myinit( void )
{
/* attributes */

      glClearColor(1.0, 1.0, 1.0, 1.0); /* white background */
      glPointSize(1.0);

/* set up viewing */

      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0.0, (float) WINDOW_MAX, 
                 0.0, (float) WINDOW_MAX);
      glMatrixMode(GL_MODELVIEW);

/* set up initial values */

      //initialize();
}

void keyboard( unsigned char key, int x, int y ) {
    if ( key == 'q') //exit program
    	exit(0);
    if (key == 's') {} //stop animation

    if (key == 'r') {}//reset pendulum to the initial position AND restart motion

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
    glMatrixMode (GL_MODELVIEW);
}

void initialize(void) {
    cout << "Please enter the initial values for this simulation.\n\n";
    cout << "Initial angle: ";
        cin >> angle;
    cout << "Pendulum length: ";
        cin >> length;
    cout << "Gravitational constant: ";
        cin >> gravity;
    cout << "Damping constant: ";
        cin >> damping;
    cout << "Amplitude of the impulse: ";
        cin >> amplitude;
    cout << "Frequency of the impulse: ";
        cin >> freq;                    
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (/*GLUT_DOUBLE | */ GLUT_RGB); 
    glutInitWindowSize(WINDOW_MAX, WINDOW_MAX); 
    glutInitWindowPosition(0,0); 
    glutCreateWindow("The Git and the Pendulum"); 
    myinit(); 
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(arrowkeys);
    glutDisplayFunc(display); 
    glutMainLoop();
}
