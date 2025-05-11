#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;
int sign(int x) 
{
    if (x < 0) 
	{
        return -1;
    } 
	else if (x > 0) 
	{
        return 1;
    } 
	else 
	{
        return 0;
    }
}
void dda(int x1, int y1, int x2, int y2) 
{
    float dx, dy, len;
    if (x1 == x2 && y1 == y2) 
	{
        putpixel(x1, y1, 4);
        return;
    }
    dx = x2 - x1; 
    dy = y2 - y1;
    if (abs(dx) > abs(dy)) 
	{
        len = abs(dx);
    } 
	else 
	{
        len = abs(dy);
    }
    if (len == 0)
	{
        putpixel(x1, y1, 4);
        return;
    }
    dx = dx / len;
    dy = dy / len;
    float x = x1 + 0.5 * sign(dx);
    float y = y1 + 0.5 * sign(dy);
    for (int i = 0; i <= len; i++)
	{
        putpixel(round(x), round(y), 4);
        x += dx;
        y += dy;
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

     dda(200, 300, 400, 300);
    dda(400, 300, 400, 200); 
    dda(400, 200, 200, 200); 
    dda(200, 200, 200, 300); 

    dda(200, 200, 300, 100); 
    dda(300, 100, 400, 200); 
    dda(200, 200, 400, 200); 

    dda(260, 300, 260, 250);
    dda(260, 250, 340, 250); 
    dda(340, 250, 340, 300); 
    dda(260, 300, 340, 300); 

    dda(220, 240, 250, 240); 
    dda(250, 240, 250, 270); 
    dda(250, 270, 220, 270); 
    dda(220, 270, 220, 240); 

    dda(350, 240, 380, 240); 
    dda(380, 240, 380, 270);
    dda(380, 270, 350, 270); 
    dda(350, 270, 350, 240); 

    getch(); 
    closegraph(); 
    return 0;
}

