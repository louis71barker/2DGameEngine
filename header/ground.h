#ifndef PLANK_H__
#define PLANK_H__

#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

class Ground
{
public :
  float groundLevel;
  static void Draw();
  static void floor(GLfloat _w, GLfloat _h, GLfloat _d);


private:


};





#endif
