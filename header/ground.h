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
  static void dirt(GLfloat _w, GLfloat _h, GLfloat _b, GLfloat _d);
  static void grass(GLfloat _w, GLfloat _h, GLfloat _b, GLfloat _d);


private:


};





#endif
