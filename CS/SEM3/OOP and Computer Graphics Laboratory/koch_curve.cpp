#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
void koch1(int i,int x1,int y1,int x5,int y5)
{
	int x2,x3,x4,y2,y3,y4;
	int dx,dy;
	if(i==0)
	{
		line(x1,y1,x5,y5);
	}
	else
	{
		delay(100);
	
	dx=(x5-x1)/3;
	dy=(y5-y1)/3;
	x2=x1+dx;
	y2=y1+dy;
	x3=(int)(0.5*(x1+x5)+sqrt(3)*(y1-y5)/6);
	y3=(int)(0.5*(y1+y5)+sqrt(3)*(x5-x1)/6);
	x4=2*dx+x1;
	y4=2*dy+y1;
	koch1(i-1,x1,y1,x2,y2);
	koch1(i-1,x2,y2,x3,y3);
	koch1(i-1,x3,y3,x4,y4);
	koch1(i-1,x4,y4,x5,y5);
}
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	koch1(3,150,20,20,280);
	koch1(3,280,280,150,20);
	koch1(3,20,280,280,280);
	getch();
	closegraph();
}