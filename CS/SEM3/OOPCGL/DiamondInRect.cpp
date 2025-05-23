#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int sign(int x)
{
if(x<0)
return -1;
else if(x>0)
return 1;
else
return 0;
}
void bline(int x1,int y1,int x2,int y2,int col)
{
	int dx,dy,e,x,y,i=1;
	dx=x2-x1;
	dy=y2-y1;
	x=x1;
	y=y1;
	e=2*dy-dx;
	while(i<=dx)
	{
	while(e>=0)
	{
		y++;
		e=e-2*dx;
	}
	x++;
	e=e+2*dy;
	putpixel(x,y,col);
	i++;
	}
}
void ddaline(int x1,int y1,int x2,int y2,int col)
{
	int x,y,len,i;
	float dx,dy;
	if(x1==x2 && y1==y2)
	putpixel(x1,y1,col);
	else
	{
	dx=x2-x1;
	dy=y2-y1;
	if(dx>dy)
	len=dx;
	else
	len=dy;
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);
	i=1;
	while(i<len)
	{
		putpixel(x,y,col);
		x=x+dx;
		y=y+dy;
		i++;
	}
}
}
int main()
{

	int ch,col,x1,x2,y1,y2;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	setbkcolor(WHITE);
	ddaline(50,50,50,200,2); 
	ddaline(50,50,350,50,4); 
	ddaline(350,50,350,200,6); 
	ddaline(50,200,350,200,7); 
	ddaline(200,50,50,125,9); 
	bline(50,125,200,200,12); 
	ddaline(350,125,200,200,14);
	bline(200,50,350,125,3); 
	ddaline(275,87,275,163,4);
	ddaline(125,87,275,87,5);
	ddaline(125,87,125,163,6);
	ddaline(125,163,275,163,2);
	getch();
	closegraph();
	return 0;
}
