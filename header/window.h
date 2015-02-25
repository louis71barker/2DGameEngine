#ifndef WINDOW_H__
#define WINDOW_H__

#include <SDL.h>

void SDLErrorExit(const std::string &_err);
SDL_GLContext createOpenGLContext(SDL_Window *_win);

#endif
