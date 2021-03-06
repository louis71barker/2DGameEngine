#ifndef SHELF_H__
#define SHELF_H__

#include <cstdlib>
#include <cmath>
#include <algorithm>

#define STEPS 5000


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
    mousePosX(_x), mousePosY(_y), pointNum(0)/*, steps(5000)*/
  {
    plankPoints[0].m_Px = plankPoints[0].m_Py = plankPoints[1].m_Px = plankPoints[1].m_Py = 9.0f;
    for (int i = 0;i<STEPS;i++)
    {
      collisionPoints[i].m_Cx = 0.0f;
      collisionPoints[i].m_Cy = 0.0f;
    }
  }
  static void Draw(Plank &_p);
  static void Planeish(Plank &_p);
  bool xCoorGained, yCoorGained, coorGained, drawLine, pos1Drawn, pointsGiven;
  bool drawTrigger, pointsDrawn;

  float mousePosX, mousePosY;
  int pointNum;
//  int const steps;

  struct PlankPos
  {
    float m_Px;
    float m_Py;
  };
  PlankPos plankPoints[2];
  struct PlankColPos
  {
    float m_Cx;
    float m_Cy;
  };
  PlankColPos collisionPoints[STEPS];





  //~Plank();



protected:


};







#endif
