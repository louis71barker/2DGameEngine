#include <cmath>
#include <iostream>
#include "Enviroment.h"
#include <SDL.h>


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif


Enviroment::Enviroment()
{
}

void Enviroment::Gravity(float grav)
{
  grav = 1;
}


