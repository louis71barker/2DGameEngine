#ifndef SHELF_H__
#define SHELF_H__

#include <cstdlib>
#include <cmath>
#include <algorithm>


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif




class Plank
{
public :

  Plank(float _x = 0.0f, float _y = 0.0f) :
    mousePosX(_x), mousePosY(_y)
  {
    plankPoints[0].m_Px = plankPoints[0].m_Py = plankPoints[1].m_Px = plankPoints[1].m_Py = 0.0f;
  }
  static void Draw();
  static void Planeish();
  bool xCoorGained, yCoorGained, coorGained, drawLine, pos1Drawn, pointsGiven, pointsDrawn;
  bool drawTrigger;

  int const steps = 5000;
  extern int pointNum = 1;
  float mousePosX, mousePosY;
  struct PlankPos
  {
    float m_Px;
    float m_Py;
  };
  PlankPos plankPoints[2];





  //~Plank();



protected:


};







#endif
