#include <iostream>
#include <graphics.h>
using namespace std;

// Region codes for the clipping window
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Clipping window boundaries
const int X_MIN = 200;
const int X_MAX = 350;
const int Y_MIN = 200;
const int Y_MAX = 350;

// Function to compute region code for a point
int computeCode(float x, float y) 
{
    int code = 0;
    if (x < X_MIN) code |= LEFT;
    if (x > X_MAX) code |= RIGHT;
    if (y < Y_MIN) code |= BOTTOM;
    if (y > Y_MAX) code |= TOP;
    return code;
}

// Function to implement Cohen-Sutherland Line Clipping Algorithm
void cohenSutherlandClip(float x1, float y1, float x2, float y2) {
    int code1 = computeCode(x1, y1); // Region code for point 1
    int code2 = computeCode(x2, y2); // Region code for point 2
    bool accept = false;

    while (true) {
        if ((code1 | code2) == 0) {
            // Both endpoints are inside the window
            accept = true;
            break;
        } else if ((code1 & code2) != 0) {
            // Both endpoints share an outside region; line is outside
            break;
        } else {
            // Line needs clipping
            int codeOut;
            float x, y;

            // Choose an endpoint that is outside
            if (code1 != 0) {
                codeOut = code1;
            } else {
                codeOut = code2;
            }

            // Find intersection point with the clipping boundary
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (Y_MAX - y1) / (y2 - y1);
                y = Y_MAX;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (Y_MIN - y1) / (y2 - y1);
                y = Y_MIN;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (X_MAX - x1) / (x2 - x1);
                x = X_MAX;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (X_MIN - x1) / (x2 - x1);
                x = X_MIN;
            }

            // Replace the outside point with the intersection point
            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    // If the line is accepted, draw it
    if (accept) {
        cout << "Line accepted from (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")" << endl;
        rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX); // Draw clipping window
        line(x1, y1, x2, y2);                 // Draw clipped line
    } else {
        cout << "Line rejected." << endl;
    }
}

// Main function
int main() {
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    float x1, y1, x2, y2;

    // Input line endpoints
    cout << "Enter the coordinates of the line (x1, y1, x2, y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    // Draw the original line and clipping window
    cout << "Before Clipping..." << endl;
    rectangle(X_MIN, Y_MIN, X_MAX, Y_MAX); // Draw clipping window
    line(x1, y1, x2, y2);                 // Draw original line
    delay(2000);
    cleardevice();

    // Perform clipping
    cout << "After Clipping..." << endl;
    cohenSutherlandClip(x1, y1, x2, y2);

    // Wait for user input and close graphics
    getch();
    closegraph();
    return 0;
}

