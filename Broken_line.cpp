
#include "Broken_line.h"
#include "Point.h"
#include "ESetErrors.h"

Broken_line::Broken_line(unsigned int grow_size,unsigned int size):size(1),points(nullptr),counter(0),grow_size(grow_size) {
   this->size=size;
   points= new Point[this->size];
}

void Broken_line::set_size(int new_size){
    this->size=new_size;
}

Point &Broken_line::operator[](int index)const {
    if (index < 0 || index > counter)
        throw out_of_range("Index out of range");
    return points[index];
}

void Broken_line::operator()(const Point &value, int index) {
	if (index < 0 || index > counter)
		throw std::out_of_range("Index out of range");
	
    points[index] = value;
}

Broken_line &Broken_line::operator+(const Broken_line &second_line) {
    Broken_line line;
    line.points= new Point[this->size+second_line.size];
    for(int i=0;i< this->counter;i++){
        line.points[i]=points[i];
    }
    for(int i=0;i< second_line.get_counter(); i++) {
        line.points[this->counter+i]=second_line.points[i];
    }
    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter);
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
        for (int i = 1; i < this->counter + 1; i++) {
            tmp[i] = points[i - 1];
        
        }
    }
    else{
        tmp = new Point[this->counter+1];
        tmp[0]=src;
        for (int i = 1; i<this->counter+1; i++) {
            tmp[i] = points[i-1];
        }
    }
    this->counter++;
    points = tmp;
    return *this;
}

double Broken_line::get_length() const{
    double length=0;
    if(size>1) {
        for (int i = 0; i < size; i++) {
            if (i == size - 1) { length += Point::GetDistance(points[i], points[0]); }
            else { length += Point::GetDistance(points[i], points[i + 1]); }
        }
    }
    return length;
}

int Broken_line::get_counter() const {
    return (int)counter;
}

double Broken_line::get_length_two_tops(const Point &A, const Point &B) {
    return Point::GetDistance(A,B);
}









