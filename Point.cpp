
#include "Point.h"
#include <cmath>

double Point::GetPointX()const{return x;}
double Point::GetPointY()const{return y;}

void Point::SetPointX(double x){this->x=x;}
void Point::SetPointY(double y){this->y=y;}

Point::Point(double x,double y){this->x=x;this->y=y;}

double Point::GetDistance(const Point &A,const Point &B){ return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));}