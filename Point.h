
#ifndef LLABA2_5_1_POINT_H
#define LLABA2_5_1_POINT_H

class Point {
private:
    double x,y;
public:
    double GetPointX()const;
    double GetPointY()const;
    void SetPointX(double x);
    void SetPointY(double y);

    explicit Point(double x=0,double y=0);
    static double GetDistance(const Point &A,const Point &B);
};


#endif //LLABA2_5_1_POINT_H
