
#include "Broken_line.h"

Broken_line::Broken_line(unsigned int growsize,unsigned int size):size(1),points(nullptr),counter(0),growsize(growsize) {
   this->size=size;
   points= new Point[this->size];
}

void Broken_line::set_size(int newsize){
    this->size=newsize;
}

Point &Broken_line::operator[](int index) {
    return points[index];
}

void Broken_line::operator()(const Point &value, int index) {
   points[index]=value;
}




