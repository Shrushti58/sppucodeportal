#include <graphics.h>
#include <conio.h>
#include <cmath>
#include <iostream>

const double PI = 3.14159265358979323846;

class Point {
public:
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Translation
    void translate(int tx, int ty) {
        x += tx;
        y += ty;
    }

    // Scaling
    void scale(double factor) {
        x = static_cast<int>(x * factor);
        y = static_cast<int>(y * factor);
    }

    // Rotation (counterclockwise around origin)
    void rotate(double angle) {
        double radians = angle * PI / 180.0;
        int newX = static_cast<int>(x * cos(radians) - y * sin(radians));
        int newY = static_cast<int>(x * sin(radians) + y * cos(radians));
        x = newX;
        y = newY;
    }

    void display() {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

class Shape {
public:
    Point points[4];

    // Constructor for a rectangle
    Shape(Point p1, Point p2, Point p3, Point p4) {
        points[0] = p1;
        points[1] = p2;
        points[2] = p3;
        points[3] = p4;
    }

    // Draw the shape (rectangle)
    void draw(int color) {
        for (int i = 0; i < 4; ++i) {
            int next = (i + 1) % 4;
            line(points[i].x, points[i].y, points[next].x, points[next].y);
        }
    }

    // Operator overloading for transformations
    Shape operator+(const Point& translation) {
        Shape newShape = *this;
        for (int i = 0; i < 4; ++i) {
            newShape.points[i].translate(translation.x, translation.y);
        }
        return newShape;
    }

    Shape operator*(double scaleFactor) {
        Shape newShape = *this;
        for (int i = 0; i < 4; ++i) {
            newShape.points[i].scale(scaleFactor);
        }
        return newShape;
    }

    Shape operator^(double angle) {
        Shape newShape = *this;
        for (int i = 0; i < 4; ++i) {
            newShape.points[i].rotate(angle);
        }
        return newShape;
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Define the initial rectangle
    Point p1(200, 150), p2(300, 150), p3(300, 200), p4(200, 200);
    Shape rectangle(p1, p2, p3, p4);

    // Draw the original rectangle
    rectangle.draw(WHITE);
    outtextxy(210, 220, "Original Rectangle");

    // Transformation options
    int choice;
    std::cout << "Choose a transformation:\n";
    std::cout << "1. Translation\n";
    std::cout << "2. Scaling\n";
    std::cout << "3. Rotation\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    Shape transformedRectangle = rectangle;

    switch (choice) {
        case 1: {
            int tx, ty;
            std::cout << "Enter translation offsets (tx ty): ";
            std::cin >> tx >> ty;
            Point translation(tx, ty);
            transformedRectangle = transformedRectangle + translation;
            break;
        }
        case 2: {
            double factor;
            std::cout << "Enter scaling factor: ";
            std::cin >> factor;
            transformedRectangle = transformedRectangle * factor;
            break;
        }
        case 3: {
            double angle;
            std::cout << "Enter angle of rotation (in degrees): ";
            std::cin >> angle;
            transformedRectangle = transformedRectangle ^ angle;
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
            closegraph();
            return 1;
    }

    // Draw the transformed rectangle
    transformedRectangle.draw(YELLOW);
    outtextxy(210, 240, "Transformed Rectangle");

    getch();
    closegraph();
    return 0;
}
