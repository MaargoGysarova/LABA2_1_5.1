
#ifndef LLABA2_5_1_BROKEN_LINE_H
#define LLABA2_5_1_BROKEN_LINE_H
#include "Point.h"

class Broken_line{
private:
    Point *points;
    unsigned int counter;
    unsigned int size;
    unsigned int growsize;
public:
     explicit Broken_line(unsigned int growsize=5,unsigned int size=1);

     void set_size(int newsize); //������� ���-�� ���設

     Point& operator[](int index); //�⥭�� ���設�
     void operator()(const Point& value,int index); //������ ���設�








};


#endif //LLABA2_5_1_BROKEN_LINE_H
