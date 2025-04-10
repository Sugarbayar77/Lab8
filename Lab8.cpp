#include <iostream>
#include <cmath>  // For sqrt()
#include <string>
 
using namespace std;
 
class Shape {
public:
    string name;
    float side;
 
    void Input() {
        cout << "Enter shape name: ";
        cin >> name;
        cout << "Enter a side length or radius: ";
        cin >> side;
	}
};
 
class Vertex {
public:
    float x_p;
    float y_p;
};
 
class TwoDShape : public Shape {
public:
    float x_coordinate;
    float y_coordinate;
    float area;
    float perimeter;
 
    TwoDShape(float x_p, float y_p) : x_coordinate(x_p), y_coordinate(y_p), area(0), perimeter(0) {}
};
 
const float pi = 3.14159;
 
class Circle : public TwoDShape {
public:
    Circle(float x_p, float y_p, float radius) : TwoDShape(x_p, y_p) { side = radius; }
 
    void Area1() {
        area = side * side * pi;
    }
 
    void Perimeter1() {
        perimeter = side * 2 * pi;
    }
 
    void Input() {
        cout << "Enter the radius of the circle: ";
        cin >> side;
        cout << "Enter the coordinate x of the center: ";
        cin >> x_coordinate;
        cout << "Enter the coordinate y of the center: ";
        cin >> y_coordinate;
    }
 
    void Display() {
        cout << "Circle with radius " << side << " and center coordinate (" << x_coordinate << ", " << y_coordinate << "): Area = " << area << ", Perimeter = " << perimeter << endl;
    }
};
 
class Square : public TwoDShape {
public:
    Vertex UpLeft, UpRight, DownLeft, DownRight;
 
    Square(float x_p, float y_p, float side_length) : TwoDShape(x_p, y_p) {
        side = side_length;
    }
 
    void Area1() {
        area = side * side;
    }
 
    void Perimeter1() {
        perimeter = side * 4;
    }
 
    void Input() {
        cout << "Enter the side length of the square: ";
        cin >> side;
        cout << "Enter coordinate x: ";
        cin >> x_coordinate;
        cout << "Enter coordinate y: ";
        cin >> y_coordinate;
    }
 
    void findingvertexes() {
 
        DownRight.x_p = x_coordinate + side;
        DownRight.y_p = y_coordinate - side;
 
        UpRight.x_p = x_coordinate + side;
        UpRight.y_p = y_coordinate;
		DownLeft.x_p = x_coordinate; 
		DownLeft.y_p = y_coordinate - side;
        cout << "Square Vertexes:\n";
        cout << "DownLeft: (" << DownLeft.x_p << ", " << DownLeft.y_p << ")\n";
        cout << "DownRight: (" << DownRight.x_p << ", " << DownRight.y_p << ")\n";
        cout << "UpRight: (" << UpRight.x_p << ", " << UpRight.y_p << ")\n";
        cout << "UpLeft: (" << x_coordinate << ", " << y_coordinate<< ")\n";
    }
 
    void Display() {
        cout << "Square with side " << side << ": Area = " << area << ", Perimeter = " << perimeter << endl;
    }
};
 
class EquiTriangle : public TwoDShape {
public:
    Vertex bottomLeft, bottomRight, topVertex;
 
    EquiTriangle(float x_p, float y_p, float side_length) : TwoDShape(x_p, y_p) {
        side = side_length;
    }
 
    void Area1() {
        area = (sqrt(3) / 4) * side * side;
    }
 
    void Perimeter1() {
        perimeter = side * 3;
    }
 
    void Input() {
        cout << "Enter the side length of the equilateral triangle: ";
        cin >> side;
        cout << "Enter coordinate x: ";
        cin >> x_coordinate;
        cout << "Enter coordinate y: ";
        cin >> y_coordinate;
    }
 
    void findingvertexes() {
        bottomRight.x_p = x_coordinate - (side/2) ;
        bottomRight.y_p = y_coordinate;
 
        float height = (sqrt(3) / 2) * side;
        bottomLeft.x_p = x_coordinate + (side / 2);
        bottomLeft.y_p = y_coordinate - height;
 
        cout << "Equilateral Triangle Vertexes:\n";
        cout << "Bottom Left: (" << bottomLeft.x_p << ", " << bottomLeft.y_p << ")\n";
        cout << "Bottom Right: (" << bottomRight.x_p << ", " << bottomRight.y_p << ")\n";
        cout << "Top: (" << x_coordinate << ", " << y_coordinate << ")\n";
    }
 
    void Display() {
        cout << "Equilateral Triangle with side " << side << ": Area = " << area << ", Perimeter = " << perimeter << endl;
    }
};
 
int main() {
    int choice;
    int continue1;
 
    cout << "Do you want to enter a shape? (Yes - 1, No - 0): ";
    cin >> continue1;
 
    while (continue1 == 1) {
        cout << "Select a shape:\n1. Circle\n2. Square\n3. Equilateral Triangle\nEnter choice: ";
        cin >> choice;
 
        if (choice == 1) {
            Circle c(0, 0, 0);
            c.Input();
            c.Area1();
            c.Perimeter1();
            c.Display();
        } else if (choice == 2) {
            Square s(0, 0, 0);
            s.Input();
            s.Area1();
            s.Perimeter1();
            s.Display();
            s.findingvertexes();
        } else if (choice == 3) {
            EquiTriangle t(0, 0, 0);
            t.Input();
            t.Area1();
            t.Perimeter1();
            t.Display();
            t.findingvertexes();
        } else {
            cout << "Error! Please enter 1, 2, or 3." << endl;
        }
 
        cout << "Do you want to enter another shape? (Yes - 1, No - 0): ";
        cin >> continue1;
    }
 
    return 0;
}