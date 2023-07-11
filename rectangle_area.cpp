#include <iostream>

using namespace std;
/*
 * Create classes Rectangle and RectangleArea
 */
class Rectangle {
public:
	void set_sides() {
		cin >> w >> h;
	}
	int get_w() {
		return w;
	}
	int get_h() {
		return h;
	}
	void display() {
		cout << w << ' ' << h << endl;
	}
private:	// protected is the right choise
	int w, h;
};

class RectangleArea: public Rectangle {
public:
	void read_input() {
		set_sides();
	}
	void display() {
		cout << get_w() * get_h();
	}
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}