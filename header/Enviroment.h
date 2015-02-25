#ifndef PLANK_H__
#define PLANK_H__

#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

class Enviroment
{
public :
  static void Gravity(float grav);



private:


};





#endif
