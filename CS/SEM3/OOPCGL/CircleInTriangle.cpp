#include <iostream>
#include <cmath>
#include <graphics.h> // Include graphics.h for drawing in C++

using namespace std;

// Function to draw a line using DDA algorithm
void ddaLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float xIncrement = dx / float(steps);
    float yIncrement = dy / float(steps);
    
    float x = x1;
    float y = y1;
    
    putpixel(round(x), round(y), WHITE); // Plot the first point
    
    for (int i = 0; i < steps; i++) {
        x += xIncrement;
        y += yIncrement;
        putpixel(round(x), round(y), WHITE); // Plot the next point
    }
}

// Function to draw a circle using Bresenham's Circle algorithm
void bresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 3 - 2 * r;

    // Plot the initial points in all eight octants
    while (x <= y) {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);
        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
        
        x++;
        
        if (p < 0) {
            p = p + 4 * x + 6;
        } else {
            y--;
            p = p + 4 * (x - y) + 10;
        }
    }
}

int main() {
    // Initialize graphics mode
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Coordinates of the triangle vertices
    int x1 = 100, y1 = 150;
    int x2 = 300, y2 = 50;
    int x3 = 500, y3 = 150;

    // Draw the triangle using DDA line drawing algorithm
    ddaLine(x1, y1, x2, y2);
    ddaLine(x2, y2, x3, y3);
    ddaLine(x3, y3, x1, y1);

    // Fixed center and radius for the circumscribed circle
    int cx = 300, cy = 100; // Approximate center of the circumscribed circle
    int radius = 200; // Approximate radius of the circumscribed circle
    bresenhamCircle(cx, cy, radius); // Draw the circumscribed circle

    // Fixed center and radius for the inscribed circle
    cx = 300, cy = 130; // Approximate center of the inscribed circle
    radius = 50; // Approximate radius of the inscribed circle
    bresenhamCircle(cx, cy, radius); // Draw the inscribed circle

    // Wait for user input to close
    getch();
    closegraph();
    return 0;
}

