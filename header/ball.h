#ifndef BALL_H__
#define BALL_H__

#include "NCCA/Vec4.h"
#include "NCCA/Mat4.h"
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <scene.h>

const static float TWO_PI= float(2*M_PI); //6.28318530717958647692   //360
const static float PI=float(M_PI); //3.14159265358979323846       //180
const static float PI2=float(M_PI/2.0); //1.57079632679489661923      //90
const static float PI4=float(M_PI/4.0); //0.785398163397448309615     //45


class Ball
{
public:

  Ball(float _x = 1.0f, float _y = 1.0f) :
    PosX(_x),PosY(_y)
  {
    ballPoints[0].m_Sx = ballPoints[0].m_Sy = 0.f; ballCoorGain = false; ballLive = false;
  }

  static void perspective(float _fovy,float _aspect, float _zNear, float _zFar);
  static float radians(float _deg );
  static void sphere(float _radius, int _precision, float _x, float _y, Ball &_b);
  static void Draw(float _x, float _y,Ball &_b);
  static void Pos(float _Sx, float _Sy, Ball &_b, float Rectwidth);
  static void EnviroEffects(Ball &_b);
  bool ballCoorGain, ballDrawTrigger, ballCollison, ballLive;

  struct SpherePos
  {
    float m_Sx;
    float m_Sy;
  };
  SpherePos ballPoints[2];

  float PosX, PosY;

  Ball(){}
  ~Ball(){}


private:
  int xVel, yVel;


};



#endif
