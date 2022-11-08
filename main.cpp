#include <iostream>
#include "Broken_line.h"
using namespace std;
#include <conio.h>
#include "Graphics.h"
#include "ESetErrors.h"

int get_key(){
    int key = _getch();
    if  ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54) || (key == 55) || (key == 56) || (key == 57))  key = _getch();
    return key;
}

void print_image(Broken_line& line, int num_reg, int shift) {
    
    cout << "Print image" << endl;
    // draw line with tops graphics.h library
    Graphics window(800, 600);
    for (int i = 0; i < line.get_counter()-1; i++) {
        Point A = line[i];
		
       
            Point B = line[i + 1];
            window.DrawLine(A.GetPointX() * 100, A.GetPointY() * 100, B.GetPointX() * 100, B.GetPointY() * 100);
        }

    
    Point A = line[num_reg-1+shift];
    Point B = line[0+shift];
    window.DrawLine(A.GetPointX() * 100, A.GetPointY() * 100, B.GetPointX() * 100, B.GetPointY() * 100);
}

void print_image_first(Broken_line& line) {
    cout << "Print image" << endl;
    // draw line with tops graphics.h library
    Graphics window(800, 600);
    for (int i = 0; i < line.get_counter()-1; i++) {
        Point A = line[i];
        Point B = line[i + 1];
        window.DrawLine(A.GetPointX() * 100, A.GetPointY() * 100, B.GetPointX() * 100, B.GetPointY() * 100);

    }
}

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
        cout << "Enter the tup["<<i+1<<"]values"<< endl;
        cout << "x["<<i+1<<"]= " << endl;
        cin >> x;
        cout << "y["<<i+1<<"]= " << endl;
        cin >> y;
        tmp.SetPointX(x);tmp.SetPointY(y);
        new_line += tmp;
    }
    return new_line;
}

Point get_top(Broken_line& line,int index){
    return line[index];
}

void set_top(Broken_line& line, int index){
    Point new_point;
    int x=0,y=0;
    cout << "Enter the tup[" << index+1 << "]values" << endl;
    cout << "x["<<index<<"]= " << endl;
    cin >> x;
    cout << "y["<<index<<"]= " << endl;
    cin >> y;
    new_point.SetPointX(x);new_point.SetPointY(y);
    line(new_point,index-1);
}

Broken_line sum(Broken_line&  line){
    cout << "Summarize" << endl;
    Broken_line second_line = create_new_line();
    print_image_first(second_line);
    getchar();
	line = line + second_line;
    return line;
}

void add_to_end(Broken_line& line){
    cout << "Add to end of line" << endl;
    int x=0,y=0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "x = " << endl;
    cin >> x;
    cout << "y = " << endl;
    cin >> y;
    Point new_point(x,y);
    line += new_point;
}

void add_to_start(Broken_line& line){
    cout << "Add to start of line" << endl;
    int x=0,y=0;
    cout << "Creating top" << endl;
    cout << "Enter the tup[i+1] values" << endl;
    cout << "x = " << endl;
    cin >> x;
    cout << "y = " << endl;
    cin >> y;
    Point new_point(x,y);
    line + new_point;
}

double get_length(Broken_line& line){
    cout << "Calculating line's length" << endl;
    return line.get_length();
}

void show_all_tops(Broken_line& line){
    cout << "Show all tops" << endl;
    Point tmp;
    for(int i=0;i<line.get_counter();i++){
        tmp = line[i];
        cout << "["<<i<<"]:";
        cout <<"("<<tmp.GetPointX() << "," << tmp.GetPointY()<<")"<<endl;
    }
}

void show_one_tops(Broken_line& line){
    int index=0;
    cout << "index = " << endl;
    cin >> index;
    while (index <= 0 || index> line.get_counter()){
       cout << "Incorrect value" << endl;
      cout << "index = ";
      cin >> index;
     }
    Point tmp;
    tmp = line[index-1];
    cout << "["<<index<<"]:";
    cout << "(" << tmp.GetPointX() << "," << tmp.GetPointY() << ")" << endl;
}


int menu2() {
    cout << "What are you want to do? To press.." << endl;
    cout << "1 - summarize with new line"<< endl;
    cout << "2 - Add new top to end"<< endl;
    cout << "3 - Add new top to start"<< endl;
    cout << "4 - Get length"<< endl;
    cout << "5 - Change one element" << endl;
    cout << "6 - Show all tops" << endl;
    cout << "7 - Show one top" << endl;
    cout << "8 - Print image" << endl;
    cout << "9 - Go out" << endl;
    int m2;
    m2= get_key();
    return m2;
}

bool check_regular_polygon(Broken_line& line) {
    cout << "Checking regular polygon..." << endl;
    //create massive of length of polygon's sides
    auto *length_of_sides = new double[line.get_counter()];
    for (int i = 0; i < line.get_counter(); i++) {
        Point A = line[i];
        if (i == line.get_counter() - 1) {
            Point B = line[0];
            length_of_sides[i] = Broken_line::get_length_two_tops(A, B);
        }
        else {
            Point B = line[i + 1];
            length_of_sides[i] = Broken_line::get_length_two_tops(A, B);
        }
    }
	
    int index = 0;
    //create massive of nulls
    auto *uncorrected_tops = new Point[line.get_counter()];
    int index_massive = -1;
    //check if all sides are equal
    for (int i = 0; i < line.get_counter()-2; i++) {
        if (length_of_sides[0] != length_of_sides[i + 1]) {
            index = i + 1;
            uncorrected_tops[index_massive + 1] = line[index + 1]; 
            index_massive++;
            break;
        }
    }
    // check if massive is empty
    if (index_massive == -1) {
        return true;
    } else {
        cout << "This is not regular polygon" << endl;
        cout << "Uncorrected tops:" << endl;
        for (int i = 0; i < index_massive; i++) {
            cout << "[" << i << "]:" << endl;
            cout << uncorrected_tops[i].GetPointX() << " " << uncorrected_tops[i].GetPointY() << endl;
        }
        
        
        return false;
    }
}
 

       int main() {
		
         
         int num_tops;
         cout << "Hello! Enter the number of tops of the polygon" << endl;
         cin >> num_tops;
         while (num_tops <= 0) {
             cout << "Incorrect value" << endl;
             cout << "Num of top = ";
             cin >> num_tops;
         }
         Broken_line line(5, num_tops+1);
         Point tmp;
         bool reg = false;
		 bool sum_cheak = false;
         int shift = 0;
         int x = 0, y = 0;
         for (int i = 0; i < num_tops; i++) {
             cout << "Enter the tup[" << i + 1 <<"]values"<< endl;
             cout << "x[" << i + 1 << "]= ";
             cin >> x;
             cout << "y[" << i + 1 << "]= ";
             cin >> y;
             tmp.SetPointX(x);
             tmp.SetPointY(y);
             line += tmp;
         }
         if (check_regular_polygon(line)) {
            // line[line.get_counter()] = line[0];
             cout << "This is regular polygon" << endl;
             reg = true;
             _getch();
         } else {
             cout << "All uncorrected tops is change" << endl;
             _getch();
         }
         int m2;
         do {
             system("cls");
             m2 = menu2();

             switch (m2) {
                 case 49:
                     system("cls");
                     sum(line);
                     sum_cheak = true;
                     if (reg) {
                         print_image(line, num_tops, shift);
                     }
                     else { print_image_first(line); }
                     getchar();
                     break;
                 case 50:
                     try {
                         add_to_end(line);
                         getchar();
                     }
                     catch (ESetErrors& err) {
                         err.print_error();
                     }
                     break;
                 case 51:
                     try {
                         add_to_start(line);
                         show_all_tops(line);
                         shift++;
                         getchar();
                     }
                     catch (ESetErrors& err) {
                         err.print_error();
                     }
                     break;
                 case 52:
                     system("cls");
                     cout << "Length = " << get_length(line) << endl;
                     _getch();
                     break;
                 case 53:
                     try {
                         system("cls");
                         show_all_tops(line);
                         // enter index of top
                         int index;
                         cout << "index = " << endl;
                         cin >> index;
                         while (index <= 0 || index > line.get_counter()) {
                             cout << "Incorrect value" << endl;
                             cout << "index = ";
                             cin >> index;
                         }
                         set_top(line, index);
                     }
                     catch (ESetErrors& err) {
                         err.print_error();
                     }
                     break;
                 case 54:
                     system("cls");
                     show_all_tops(line);
                     getchar();
                     break;
                 case 55:
                     system("cls");
                     show_one_tops(line);
                     _getch();
                     
                     break;
                 case 56:
                     system("cls");
                     if (reg == true) {
						 print_image(line,num_tops,shift);
                     }
                     else {
                         print_image_first(line);
                     }
					
                     break;
                 case 57:
                     cout << "Goodbye!" << endl;
                     return 0;
                 default:
                     cout << "Incorrect value" << endl;
                     break;
             }
         } while (m2 != 9);
     }
