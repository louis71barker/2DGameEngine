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

void Ground::floor(GLfloat _w, GLfloat _h,GLfloat _b, GLfloat _d)
{
  SDL_Rect _rect;
  // assume the  cube centered at the origin
  GLfloat w=_rect.w;
  GLfloat h=-90;
  GLfloat b = -120;
  GLfloat d=_d/2.0f;

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
//    glVertex3f(w,h,-d);
//    glVertex3f(w,h,d);
//    // Bottom face
//    glNormal3f(0,-1,0);
//    glVertex3f(-w,-h,d);
//    glVertex3f(-w,-h,-d);
//    glVertex3f(w,-h,-d);
//    glVertex3f(w,-h,d);

  glEnd();
  glPopMatrix();
}


void Ground::Draw()
{



  //glPushMatrix();

    Ground::floor(20.0,-90,-120,1.0);
  //glPopMatrix();
}
