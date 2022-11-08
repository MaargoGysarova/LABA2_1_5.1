
#ifndef LLABA2_5_1_BROKEN_LINE_H
#define LLABA2_5_1_BROKEN_LINE_H
#include "Point.h"

class Broken_line{
private:
    Point *points;
    unsigned int counter;
    unsigned int size;
    unsigned int grow_size;
public:
     explicit Broken_line(unsigned int grow_size=5,unsigned int size=1);

     void set_size(int new_size); //задание кол-ва вершин

     Point& operator[](int index)const; //чтение вершины
     void operator()(const Point& value,int index); //запись вершины

     Broken_line& operator+(const Broken_line& second_line); //канкатенация линий

     Broken_line& operator+=(const Point& src) ; //добавление вершины в конец
     Broken_line& operator+(const Point& src); //в начало

     double get_length()const;
     static double get_length_two_tops(const Point& A,const Point& B);
     int get_counter() const;









};


#endif //LLABA2_5_1_BROKEN_LINE_H
