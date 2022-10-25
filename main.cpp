#include <iostream>
#include "Broken_line.h"
using namespace std;

Broken_line create_new_line(){

    cout << "Creating broken line" << endl;
    cout << "What is the num of top" << endl;
    cout << "Num of top = ";
    int num_of_top;
    cin >> num_of_top;
    while (num_of_top <= 0)
    {
        cout << "Incorrect value" << endl;
        cout << "Num of top = ";
        cin >> num_of_top;
    }
    Broken_line new_line(5,num_of_top);
    Point tmp;
    int x=0,y=0;
    for(int i=0;i<num_of_top;i++){
        cout << "Enter the tup[i+1] values" << endl;
        cout << "x[i+1]= " << endl;
        cin >> x;
        cout << "y[i+1]= " << endl;
        cin >> y;
        tmp.SetPointX(x);tmp.SetPointY(y);
        new_line += tmp;
    }
    return new_line;
}

Point get_top(Broken_line& line,int index){
    return line[index];
}

void set_top(Broken_line& line,const Point& new_point, int index){
    line(new_point,index);
}

Broken_line sum(Broken_line&  line){
    cout << "Summarize" << endl;
    Broken_line second_line = create_new_line();
    line + second_line;
}

void add_to_end(Broken_line& line){
    cout << "Add to end of line" << endl;
    int x=0,y=0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "x[i+1]= " << endl;
    cin >> x;
    cout << "y[i+1]= " << endl;
    cin >> y;
    Point new_point(x,y);
    line += new_point;
}

void add_to_start(Broken_line& line){
    cout << "Add to start of line" << endl;
    int x=0,y=0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "x[i+1]= " << endl;
    cin >> x;
    cout << "y[i+1]= " << endl;
    cin >> y;
    Point new_point(x,y);
    line + new_point;
}

double get_length(Broken_line& line){
    cout << "Calculating line's length" << endl;
    return line.get_length();
}

int muny1() {
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - summarize"<< endl;
    cout << "2 - summarize with bool"<< endl;
    cout << "3 - multiply"<< endl;
    cout << "4 - multiply with bool"<< endl;
    cout << "5 - invert image" << endl;
    cout << "6 - image fullness calculation" << endl;
    cout << "7 - áhange one element" << endl;
    cout << "8 - show one element" << endl;
    cout << "9 - print image" << endl;
    cout << "10 - go out" << endl;
    cout << "Operation ü";
    while (true)
    {
        int key = get_key();
        if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 27)) return key;
    }
}
