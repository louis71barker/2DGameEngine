#include <cstdlib>
#include <SDL.h>
#include <iostream>
#include <string>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <time.h>
#include "header/scene.h"

int main()
{
  if(SDL_Init(SDL_INIT_VIDEO)<0)
  {
    SDLErrorExit("Unable to init SDL");
  }

  //this grabs the screen size's
  SDL_Rect rect;
  SDL_GetDisplayBounds(0,&rect);
  SDL_Window *win;
  win=SDL_CreateWindow("2D Phyics Game and Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, rect.w/2, rect.w/2, SDL_WINDOW_OPENGL);

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


  Ball b;
  int quit = 0;
  while(!quit)
  {
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




    }





  }

  b.Draw(b.PosX, b.PosY);
  b.PosY += 1;
  std::cout<<b.PosY<<"\n";

  SDL_GL_SwapWindow(win);





}
}
