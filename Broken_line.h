
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

     void set_size(int new_size); //������� ���-�� ���設

     Point& operator[](int index); //�⥭�� ���設�
     void operator()(const Point& value,int index); //������ ���設�

     Broken_line& operator+(const Broken_line& second_line); //�����⥭��� �����

     Broken_line& operator+=(const Point& src) ; //���������� ���設� � �����
     Broken_line& operator+(const Point& src);

     double get_length()const;









};


#endif //LLABA2_5_1_BROKEN_LINE_H
