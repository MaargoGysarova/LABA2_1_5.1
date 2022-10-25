
#include "Broken_line.h"
#include "Point.h"

Broken_line::Broken_line(unsigned int grow_size,unsigned int size):size(1),points(nullptr),counter(0),grow_size(grow_size) {
   this->size=size;
   points= new Point[this->size];
}

void Broken_line::set_size(int new_size){
    this->size=new_size;
}

Point &Broken_line::operator[](int index) {
    return points[index];
}

void Broken_line::operator()(const Point &value, int index) {
   points[index]=value;
}

Broken_line &Broken_line::operator+(const Broken_line &second_line) {
    Broken_line line;
    line.points= new Point[this->size+second_line.size];
    for(int i=0;i< this->size;i++){
        line.points[i]=points[i];
    }
    for(int i=0;i< this->size;i++){
        line.points[size+i]=second_line.points[i];
    }
    return line;
}

Broken_line &Broken_line::operator+=(const Point &src)  {
    if(counter==size) {
        Point *tmp;
        tmp = new Point[this->size + grow_size];
        for (int i = 0; i < size; i++) {
            tmp[i] = points[i];
        }
        tmp[size] = src;
        points = tmp;
    }
    else {
        points[counter]=src;
    }
    counter++;
    return *this;
}

Broken_line &Broken_line::operator+(const Point &src) {
    Point *tmp;
    if(counter==size) {
        tmp = new Point[this->size + grow_size];
        tmp[0]=src;
        for (int i = (int)size; i > 0; i--) {
            tmp[size] = points[size-i];
        }
    }
    else{
        tmp = new Point[this->size];
        tmp[0]=src;
        for (int i = (int)size; i > 0; i--) {
            tmp[size-i] = points[size-1-i];
        }
    }
    points = tmp;
    counter++;
    return *this;
}

double Broken_line::get_length() const{
    double length=0;
    if(size>1) {
        for (int i = 0; i < size; i++) {
            length += Point::GetDistance(points[i], points[i + 1]);
        }
    }
    return length;
}

int Broken_line::get_counter() const {
    return (int)counter;
}









