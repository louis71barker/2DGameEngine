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


//void Ball::perspective(float _fovy,float _aspect, float _zNear, float _zFar)
//{
//  float range = tan(radians(_fovy / 2.0)) * _zNear;
//  float left = -range * _aspect;
//  float right = range * _aspect;
//  float bottom = -range;
//  float top = range;
//  Mat4 result;
//  result.m_00 = (2.0f * _zNear) / (right - left);
//  result.m_11 = (2.0f * _zNear) / (top - bottom);
//  result.m_22 = - (_zFar + _zNear) / (_zFar - _zNear);
//  result.m_23 = - 1.0f;
//  result.m_32 = - (2.0f* _zFar * _zNear) / (_zFar - _zNear);
//  result.loadProjection();
//}

// float Ball::radians(float _deg )
//{
//  return (_deg/180.0f) * M_PI;
//}


void Ball::sphere(float _radius, int _precision, float _x, float _y)
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
      vertex += Vec4(_x, _y, z);
      std::cout<<_x<<" x\n"<<_y<<_y<<" y\n\n";

      normal.normalGL();
      vertex.vertexGL();
      normal.set(cosf(theTa1) * cosf(theTa3) , sinf(theTa1), cosf(theTa1) * sinf(theTa3));
      vertex=normal*_radius;
      vertex += Vec4(_x, _y, z);
      normal.normalGL();
      vertex.vertexGL();
    }
  }
  glEnd();


}


void Ball::Draw(float _x, float _y)
{
  Vec4 red(1,0,0);


  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();
    red.colourGL();
    Ball::sphere(15, 26, _x, _y);
    std::cout<<"Ball Drawn"<<"\n";

  glPopMatrix();


}


void Ball::Pos(float _Sx, float _Sy)
{

}
