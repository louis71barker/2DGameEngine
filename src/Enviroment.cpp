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

void Enviroment::shelfColliosion(Plank &_p,Ball &_b)
{
  for (int i = 0; i<STEPS; i++)
  {
    //std::cout << _p.collisionPoints[i].m_Cx - _b.ballPoints[0].m_Sx << " " << _p.collisionPoints[i].m_Cy - _b.ballPoints[0].m_Sy << "\n";
    if (fabs(_p.collisionPoints[i].m_Cx - _b.ballPoints[0].m_Sx) < 0.5f && fabs(_p.collisionPoints[i].m_Cy - _b.ballPoints[0].m_Sy) < 0.5f)
    {
      std::cout<<"boom boom boom there is a crash arrrrrrrrrrr!!!!!!!!!!!!!!!!\n";
    }
  }
}


