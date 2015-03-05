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
    //std::cout << i << " ith num     "<< fabs(_p.collisionPoints[i].m_Cx - _b.ballPoints[0].m_Sx) << "\n";
    //std::cout <<_b.ballPoints[0].m_Sx << "    x   " << _b.ballPoints[0].m_Sy << "   y     \n";
    if ((fabs(_p.collisionPoints[i].m_Cx - _b.ballPoints[0].m_Sx)-4) < 2.0f && (fabs(_p.collisionPoints[i].m_Cy - _b.ballPoints[0].m_Sy)-4) < 7.0)
    {
      std::cout<<"boom boom boom there is a crash arrrrrrrrrrr!!!!!!!!!!!!!!!!\n";
      _b.speed = 0.0f;
      if (fabs(_p.collisionPoints[i].m_Cy - _b.ballPoints[0].m_Sy)< 7.0f)
      {
        _b.ballPoints[0].m_Sy = _p.collisionPoints[i].m_Cy;
      }
    }
  }
}


