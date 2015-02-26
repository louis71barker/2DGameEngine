#include <iostream>
#include "plank.h"
#include <SDL.h>



//void Plank::Draw()
//{



//}



void Plank::Planeish()
{
  Plank p;
  //p.pointNum = 0;
  static int x,y;
  SDL_Rect _rect;
  SDL_GetDisplayBounds(0, &_rect);
  SDL_GetMouseState(&x, &y);
  std::cout<<pointNum<<"\n";

  if ( !(pointNum % 2))
  {
      p.plankPoints[0].m_Px = (((float) x * 2.0 / (float)_rect.w)*200.0 - 100);
      p.plankPoints[0].m_Py = -(((float) y * 2.0 / (float)_rect.w)*200.0 - 100);
      pointNum++;
      std::cout<<p.plankPoints[0].m_Px << " " << p.plankPoints[0].m_Py << "\n";


  }
  //checks to see if the i value is and even number
  if ( (pointNum % 2))
  {
      if (p.drawTrigger == true)
      {

          p.plankPoints[1].m_Px = (((float) x * 2.0 / (float)_rect.w)*200.0 - 100);
          p.plankPoints[1].m_Py = -(((float) y * 2.0 / (float)_rect.w)*200.0 - 100);
          p.pointsDrawn = true;
          pointNum++;
          std::cout<<"boomboop"<<"\n";




      }



  }



}
