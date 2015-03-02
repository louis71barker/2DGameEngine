#include <iostream>
#include "plank.h"
#include <SDL.h>
#include <ctime>

#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void Plank::Draw(Plank &_p)
{
  int mX, mY;

  mX = (_p.plankPoints[0].m_Px > _p.plankPoints[1].m_Px ? 1 : 0);
  mY = (_p.plankPoints[mX].m_Py > _p.plankPoints[(mX + 1)%2].m_Py ? 1 : -1);

  glPushMatrix();
  glPointSize(10);
  GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
  glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
  glEnable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);

  if (_p.pointsDrawn == true)
  {
    std::clock_t start = std::clock();
    for(int i = 1; i < STEPS; ++i)
     {
      glVertex3f(_p.plankPoints[mX].m_Px+i*(fabs(_p.plankPoints[(mX+1)%2].m_Px - _p.plankPoints[mX].m_Px))/STEPS,
                  _p.plankPoints[mX].m_Py+(-1*mY)*i*(fabs(_p.plankPoints[(mX+1)%2].m_Py - _p.plankPoints[mX].m_Py)/STEPS), 0.0f);
      _p.collisionPoints[i-1].m_Cx = _p.plankPoints[mX].m_Px+i*(fabs(_p.plankPoints[(mX+1)%2].m_Px - _p.plankPoints[mX].m_Px))/STEPS;
      _p.collisionPoints[i-1].m_Cy = _p.plankPoints[mX].m_Py+(-1*mY)*i*(fabs(_p.plankPoints[(mX+1)%2].m_Py - _p.plankPoints[mX].m_Py)/STEPS);
      //std::cout<<_p.collisionPoints[i-1].m_Cx<<"   x    "<<_p.collisionPoints[i-1].m_Cy<<"    y";
      //_p.collisionPoints[i].m_Cx = 1.0f;
    }
    //std::cout << "Ran in :" << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << "ms\n";
  }
  glEnd();
  glPopMatrix();

  //std::cout << fabs(_p.plankPoints[(mX+1)%2].m_Py - _p.plankPoints[mX].m_Py)/_p.STEPS << "\n";

  //std::cout << "P1:" << fabs(_p.plankPoints[1].m_Py) - fabs(_p.plankPoints[0].m_Py) << "\n";


}



void Plank::Planeish(Plank &_p)
{
  //p.pointNum = 0;
  static int x,y;
  SDL_Rect _rect;
  SDL_GetDisplayBounds(0, &_rect);
  SDL_GetMouseState(&x, &y);
  //std::cout<<_p.pointNum<<"\n";

  if ( /*!(_p.pointNum = 2)*/ _p.pointNum == 1)
  {
      _p.plankPoints[0].m_Px = (((float) x * 2.0 / (float)_rect.w)*200.0 - 100);
      _p.plankPoints[0].m_Py = -(((float) y * 2.0 / (float)_rect.w)*200.0 - 100);
      _p.pointNum++;
      std::cout<<_p.plankPoints[0].m_Px << " x    " << _p.plankPoints[0].m_Py << " y     \n";
  }
  //checks to see if the i value is and even number
  if ( /*(_p.pointNum % 2)*/ _p.pointNum == 3)
  {
      if (_p.drawTrigger == true)
      {
          _p.plankPoints[1].m_Px = (((float) x * 2.0 / (float)_rect.w)*200.0 - 100);
          _p.plankPoints[1].m_Py = -(((float) y * 2.0 / (float)_rect.w)*200.0 - 100);
          _p.pointsDrawn = true;
          std::cout<<_p.plankPoints[1].m_Px << " x    " << _p.plankPoints[1].m_Py << " y    \n";
          _p.pointNum++;
          std::cout<<"boomboop"<<"\n";
      }
  }
  if (_p.pointNum >=4)
  {
    _p.pointNum = 0;
  }



}
