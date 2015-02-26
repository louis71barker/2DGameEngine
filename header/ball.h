#ifndef BALL_H__
#define BALL_H__

#include "NCCA/Vec4.h""
#include "NCCA/Mat4.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "opencv2/core/core.hpp"


const static float TWO_PI= float(2*M_PI); //6.28318530717958647692   //360
const static float PI=float(M_PI); //3.14159265358979323846       //180
const static float PI2=float(M_PI/2.0); //1.57079632679489661923      //90
const static float PI4=float(M_PI/4.0); //0.785398163397448309615     //45


class Ball
{
public:

  Ball(float _x, float _y) :
    PosX(_x),PosY(_y)
  {
    Points[0].m_Sx = Points[0].m_Sy = Points[1].m_Sx = Points[1].m_Sy = 0.f;
  }

  static void perspective(float _fovy,float _aspect, float _zNear, float _zFar);
  static float radians(float _deg );
  static void sphere(float _radius, int _precision, float _x, float _y);
  static void Draw(float _x, float _y);
  static void Pos(float _Sx, float _Sy);

  struct SpherePos
  {
    float m_Sx;
    float m_Sy;
  };
  SpherePos Points[2];

  float PosX, PosY;

  Ball(){}
  ~Ball(){}


private:


};








#endif
