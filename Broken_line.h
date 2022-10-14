
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

     void set_size(int newsize); //задание кол-ва вершин

     Point& operator[](int index); //чтение вершины
     void operator()(const Point& value,int index); //запись вершины








};


#endif //LLABA2_5_1_BROKEN_LINE_H
