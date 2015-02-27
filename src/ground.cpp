#include <cmath>
#include <iostream>
#include "ground.h"
#include <SDL.h>
#include "NCCA/Vec4.h"


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif

void Ground::dirt(GLfloat _w, GLfloat _h,GLfloat _b, GLfloat _d)
{
  SDL_Rect _rect;
  SDL_GetDisplayBounds(0, &_rect);
  // assume the  cube centered at the origin
  GLfloat w=_rect.w;
  GLfloat h=-90;
  GLfloat b = -120;
  GLfloat d=_d/2.0f;
  GLfloat brown[] = {.43f, .21f, .11f, 1.f};
  glMaterialfv(GL_FRONT, GL_DIFFUSE, brown);

  glPushMatrix();

  glBegin(GL_QUADS);
  Vec4 green(0,1,0);
    green.colourGL();
    // front face



    glNormal3f(0,0,1);
    glVertex3f(-w,h,d);
    glVertex3f(w,h,d);
    glVertex3f(w,b,d);
    glVertex3f(-w,b,d);
    //top ground face


//    // back face
//    glNormal3d(0,0,-1);
//    glVertex3f(-w,h,-d);
//    glVertex3f(w,h,-d);
//    glVertex3f(w,-h,-d);
//    glVertex3f(-w,-h,-d);
//    // Left face
//    glNormal3f(1,0,0);
//    glVertex3f(-w,-h,d);
//    glVertex3f(-w,-h,-d);
//    glVertex3f(-w,h,-d);
//    glVertex3f(-w,h,d);
//    // Right face
//    glNormal3f(-1,0,0);
//    glVertex3f(w,-h,d);
//    glVertex3f(w,-h,-d);
//    glVertex3f(w,h,-d);
//    glVertex3f(w,h,d);
//    // Top face
//    glNormal3f(0,1,0);
//    glVertex3f(-w,h,d);
//    glVertex3f(-w,h,-d);
//    glVertex3f(w,b,-d);
//    glVertex3f(w,b,d);
//    // Bottom face
//    glNormal3f(0,-1,0);
//    glVertex3f(-w,-h,d);
//    glVertex3f(-w,-h,-d);
//    glVertex3f(w,-h,-d);
//    glVertex3f(w,-h,d);

  glEnd();
  glPopMatrix();
}

void Ground::grass(GLfloat _w, GLfloat _h, GLfloat _b, GLfloat _d)
{
  SDL_Rect _rect;
  // assume the  cube centered at the origin
  GLfloat w=_rect.w;
  GLfloat h=-90;
  GLfloat b = -120;
  GLfloat d=_d/2.0f;

  glPushMatrix();
  GLfloat green[] = {0.f, 1.23f, .12f, 1.f};
  glMaterialfv(GL_FRONT, GL_DIFFUSE, green);

  glBegin(GL_QUADS);
    glNormal3f(0,0,1);
    glVertex3f(-w,h,d);
    glVertex3f(w,h,d);
    glVertex3f(w,-85,d);
    glVertex3f(-w,-85,d);
  glEnd();
  glPopMatrix();

}


void Ground::Draw()
{
  glPushMatrix();

    Ground::dirt(20.0,-90,-120,1.0);
  glPopMatrix();
  glPushMatrix();

    Ground::grass(20.0,-90,-120,1.0);
  glPopMatrix();

}
