#include <cmath>
#include <iostream>
#include "ball.h"
#include <SDL.h>


#ifdef LINUX
  #include <GL/gl.h>
#endif
#ifdef DARWIN
  #include <OpenGL/gl.h>
#endif



void Ball::sphere(float _radius, int _precision, float _x, float _y, Ball &_b)
{
  float theTa1 = 0.0;
  float theTa2 = 0.0;
  float theTa3 = 0.0;
  float z = 0.0f;

  Vec4 normal;
  Vec4 vertex;
  glBegin(GL_TRIANGLE_STRIP);

  if(_radius < 0 )
  {
    _radius = -_radius;
  }
  //Disallow a negative number for _precision
  if(_precision < 4)
  {
    _precision = 4;
  }
  //now fill in a vertData structure and add to the data list
  for (int i = 0; i < _precision; ++i)
  {
    theTa1 = i * TWO_PI / _precision - PI2;
    theTa2 = (i + 1) * TWO_PI / _precision - PI2;

    for (int j = 0; j <= _precision; ++j)
    {
      theTa3 = j * TWO_PI / _precision;
      normal.set(cosf(theTa2) * cosf(theTa3) , sinf(theTa2), cosf(theTa2) * sinf(theTa3));
      vertex=normal*_radius;
      vertex += Vec4(_b.ballPoints[0].m_Sx, _b.ballPoints[0].m_Sy/*_x,_y*/, z);
     //std::cout<<_x<<" x\n"<<_y<<_y<<" y\n\n";

      normal.normalGL();
      vertex.vertexGL();
      normal.set(cosf(theTa1) * cosf(theTa3) , sinf(theTa1), cosf(theTa1) * sinf(theTa3));
      vertex=normal*_radius;
      vertex += Vec4(_b.ballPoints[0].m_Sx, _b.ballPoints[0].m_Sy/*_x,_y*/, z);
      normal.normalGL();
      vertex.vertexGL();
    }
  }
  glEnd();


}


void Ball::Draw(float _x, float _y, Ball &_b)
{
  if (_b.ballDrawTrigger == true)
  {
    GLfloat blueish[] = {0.1f, .6f, .8f, 1.0f};
    GLfloat white[] = {0.8f, .8f, .8f, 1.0f};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blueish);
  //  glMaterialfv(GL_FRONT, GL_SPECULAR, white);
  //  GLfloat shininess[] = {10};
  //  glMaterialfv(GL_FRONT, GL_SHININESS, shininess);



    glPushMatrix();
      Ball::sphere(10, 20, _x, _y, _b);
      //std::cout<<"Ball Drawn"<<"\n";

    glPopMatrix();
    //std::cout<<"pppooooonnnaaannyyyy";

    std::cout<<_b.PosY;

  }

}


void Ball::Pos(float _Sx, float _Sy, Ball &_b, float Rectwidth)
{
  if (_b.ballCoorGain == false && _b.ballLive == false)
  {
    _b.ballPoints[0].m_Sx = (((float) _Sx * 2.0 / (float)Rectwidth)*200.0 - 100);
    _b.ballPoints[0].m_Sy = -(((float) _Sy * 2.0 / (float)Rectwidth)*200.0 - 100);
    std::cout<< _b.ballPoints[0].m_Sx << " x    " << _b.ballPoints[0].m_Sy << " y     ";
    _b.ballDrawTrigger = true;
    _b.ballLive = true;
  }
}


void Ball::EnviroEffects(Ball &_b)
{
  _b.ballPoints[0].m_Sy -= 1;
  if ((_b.PosY + -BALLRADIUS) <= GROUNDLEVEL)
  {

   _b.ballPoints[0].m_Sy = _b.ballPoints[0].m_Sy * -0.2 ;
   std::cout<<"arrrrrrrrrrr why are you not working that hurts \n";

  }
}
