#include <cstdlib>
#include <cmath>
#include <SDL.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <time.h>
#include "header/scene.h"

#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

int main()
{
  if(SDL_Init(SDL_INIT_VIDEO)<0)
  {
    SDLErrorExit("Unable to init SDL");
  }

  static int mouseX,mouseY;


  //this grabs the screen size's
  SDL_Rect _rect;

  SDL_GetDisplayBounds(0, &_rect);


  SDL_Window *win;
  Window w;
  w.screenH = _rect.w;
  w.screenH = _rect.h;
  win=SDL_CreateWindow("2D Phyics Game and Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _rect.w/2, _rect.w/2, SDL_WINDOW_OPENGL);

  if (!win)
  {
    SDLErrorExit("Unable to create a window");
  }

  SDL_GLContext gl=createOpenGLContext(win);
  if(!gl)
  {
    SDLErrorExit("Problem creating OpenGL Context");
  }

  Vec4 red(1,0,0);
  Vec4 green(0,1,0);
  Vec4 blue(0,0,1);
  Vec4 white(1,1,1);
  Vec4 yellow(1,1,0);

  SDL_GL_MakeCurrent(win,gl);
  SDL_GL_SetSwapInterval(1);

  glMatrixMode(GL_PROJECTION);
  glOrtho(-100, 100, -100, 100,-100 ,100);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
  // Enable lighting
//  glEnable(GL_LIGHTING);
//  glEnable(GL_LIGHT0);
  glClearColor(0,222,222,1);


//for the angle of the shelf, check olegs slide for the vector plane angle
//use the vector of the lines plane with the areana vector and normalise to gain the angle of collision.





  Ball b(1.0f);
  Ground g;
  Plank p;
  Enviroment ev;
  g.groundLevel = -90;
  int quit = 0;
  while(!quit)
  {
    SDL_GetMouseState(&mouseX, &mouseY);
    SDL_Event e;

    while(SDL_PollEvent(&e))
    {
       switch(e.type)
       {
        case SDL_WINDOWEVENT : {int w,h;
                                SDL_GetWindowSize(win, &w, &h);
                                glViewport(0,0,w,h);
                               }break;

        case SDL_QUIT:quit = 1;break;

        case SDL_KEYDOWN : {
                            switch(e.key.keysym.sym)
                            {
                            case SDLK_ESCAPE : quit = 1; break;
                            case SDLK_w : glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); break;
                            case SDLK_s : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); break;

                            }
                          }break;
       case SDL_MOUSEBUTTONDOWN:
           {
               if(e.button.button == SDL_BUTTON_LEFT)
               {
                   p.xCoorGained = true;

                   if (p.xCoorGained == true && p.yCoorGained == false)
                   {
                     p.yCoorGained = true;

                   }
                   if (p.xCoorGained == true && p.yCoorGained == true)
                   {
                     p.coorGained = true;
                     p.drawTrigger = true;
                     p.pointNum++;
                     //p.getShelpCo();

                   }
               }
               if(e.button.button == SDL_BUTTON_RIGHT)
               {
                  if (b.ballCoorGain == false)
                  {
                    b.Pos(mouseX, mouseY,b, _rect.w);


                    //std::cout << "BEEPBOOP";
                  }
               }
            }
         break;

       case SDL_MOUSEBUTTONUP:
       {
         if (e.button.button == SDL_BUTTON_LEFT)
         {
           if (p.yCoorGained == true && p.xCoorGained == true)
           {
             p.xCoorGained = false;
             p.yCoorGained = false;

           }
         }
       }
         break;

       }




    }


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //double grav = b.PosY *0.1;

    //b.Pos(10,10);
    b.Draw(b.PosX, b.PosY, b);
//    b.PosY -= 1;
//    b.PosX = 0;


    p.Planeish(p);
    p.Draw(p);
    b.EnviroEffects(b);



    g.Draw();



    SDL_GL_SwapWindow(win);





  }






  SDL_Quit();
  return 0;
}

