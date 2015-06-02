#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<math.h>
void spaceshuttle(int,int,int,int,int,int);
void spaceshuttleenemy();
void toUp(int,int,int,int,int,int);
void toDown(int,int,int,int,int,int);
void fire(int,int);
void main()
{
	int i,x1=50,x2=50,x3=100,y1=200,y2=300,y3=250;
	char ch;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	spaceshuttle(x1,y1,x2,y2,x3,y3);
	spaceshuttleenemy();
	printf("Press the W Button to MOVE UP and S to MOVE DOWN and SPACE to Fire and Q to QUIT!");

	do
	{
		ch = getchar();
		i = (int)ch;
		if(i ==119)
			toUp(x1,y1,x2,y2,x3,y3);
		if(i==115)
			toDown(x1,y1,x2,y2,x3,y3);
		if(i==32)
			fire(x3,y3);
		if(i==113)
			exit();
	} while(1);
}
void spaceshuttle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	outtextxy(50,100,"Space Shuttle Game");
	outtextxy(600,50,"SCORE : ");
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x3,y3,x2,y2);
}
void spaceshuttleenemy()
{       int x4=500,x5=500,x6=400,y4=150,y5=250,y6=200;
	line(x4,y4,x5,y5);
	line(x4,y4,x6,y6);
	line(x6,y6,x5,y5);
}

void toUp(int x1, int y1, int x2, int y2, int x3, int y3)
{
	char ch =getchar();
	int i=(int)ch;
	y1 = y1-30;
	y2 = y2-30;
	y3 = y3-30;
	cleardevice();
	spaceshuttle(x1,y1,x2,y2,x3,y3);
	spaceshuttleenemy();
	if(i==32)
	{
		fire(x3,y3);
		printf("Fire");
	}
	else
		printf("Fire Missed!");
}

void toDown(int x1, int y1, int x2, int y2, int x3, int y3)
{
	char ch = getchar();
	int i=ch;
	y1 = y1+30;
	y2 = y2+30;
	y3 = y3+30;
	cleardevice();
	spaceshuttle(x1,y1,x2,y2,x3,y3);
	spaceshuttleenemy();
	if(i==32)
		fire(x3,y3);
}
void fire(int x,int y)
{
	int i=0;
	putpixel(x,y,5);
	for(i=0;i<300;i++)
	{
		x=x+10;
		putpixel(x,y,5);
	}
}