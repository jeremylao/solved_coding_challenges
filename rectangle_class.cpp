#include <iostream>
using namespace std;

class Rectangle {
	int width, height;
   
  public:
	Rectangle(int, int);
	Rectangle();
    void set_values (int,int);
    int area () {return width*height;}
	 
};

Rectangle::Rectangle(){
	width = 234;
	height = 2348;
}

Rectangle::Rectangle (int x, int y) : width(x), height(y) {}

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int main () {
  Rectangle::Rectangle rect (3,4);
  Rectangle::Rectangle rectb (5,6);
  Rectangle::Rectangle rectc;
  //rect.set_values (3,4);
 // rectb.set_values (5,6);
 
 Rectangle::Rectangle *point_rec, *baz;
 
 point_rec = new Rectangle(234,3984);
 
 baz = new Rectangle[2] { {2,8}, {9,9}};
 
  cout << "rect area: " << rect.area() << endl;
  cout << "rectb area: " << rectb.area() << endl;
  cout << "rectc area: " << rectc.area() << endl;
  
  cout << "point_rec area: " << point_rec->area() << endl;
  
  cout<< "baz area 1 " << baz[0].area() << endl;
  cout<< "baz area 2 " << baz[1].area() << endl;
  
  return 0;
}