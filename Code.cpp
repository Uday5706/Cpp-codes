#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double breadth;
public:
    Rectangle() {
        length = 1.0;
        breadth = 1.0;
    }
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }
    double calculateArea() {
        return length * breadth;
    }
    void displayDimensions() {
        cout << "Length: " << length << ", Breadth: " << breadth << endl;
    }
};

int main() {
    Rectangle rect1;
    cout << "Rectangle 1 (Default):" << endl;
    rect1.displayDimensions();
    cout << "Area: " << rect1.calculateArea() << endl;
    
    Rectangle rect2(5.0, 3.5);
    cout << "Rectangle 2 (Parameterized):" << endl;
    rect2.displayDimensions();
    cout << "Area: " << rect2.calculateArea() << endl;

    return 0;
}