#ifndef ENVIROMENT_H__
#define ENVIROMENT_H__



#include <cstdlib>
#include <vector>
#include "plank.h"
#include "ball.h"



#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

class Enviroment
{
public :
  Enviroment();
  struct Vector3D
  {
    float x,y,z;

    //basic operatos
    Vector3D(float _x, float _y, float _z);
  };

  static void Gravity(float grav);
  static void Background(float _w, float _h);
  static void shelfColliosion(Plank &_p, Ball &_b);








private:


};





#endif
