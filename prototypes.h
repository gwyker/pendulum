#ifndef PROTOTYPE
#define PROTOTYPE

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

void reshape (int w, int h);

typedef struct vertex {
    float x;
    float y;
    float z;
} vertex;

#endif
