#include<iostream.h>
#include<dos.h>
#include<bios.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define RIGHT 0x4d00
#define LEFT 0x4b00
#define UP 0x4800
#define DOWN 0x5000
#define speed 15

// Global Variables
int hr,ht,hu,hd,j;
long int score1=10;
int o11,o12,o13,o14,o21,o22,o23,o24,o31,o32,o33,o34;
int o41,o42,o43,o44,o51,o52,o53,o54,o61,o62,o63,o64;
int o71,o72,o73,o74,o81,o82,o83,o84,o91,o92,o93,o94;


void heli(int a,int b);
void obstacles(long int i,int sp);
void instructions();
void main();
void score()
{
 gotoxy(35,20);
 cout<<score1;
}

void result()
{
 cleardevice();
 int ch;
 int   midx = getmaxx() / 2;
 int   midy = getmaxy() / 2;

  settextjustify(CENTER_TEXT, CENTER_TEXT);
   {
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
      setcolor(8);
      //outtextxy(midx,midy,"you have travelled:");
      outtextxy(midx,midy,"Your score is:");
      score();
      delay(2000);
   repeat:
      cleardevice();
      outtextxy(midx,midy,"Wanna fly again?");
      outtextxy(midx,midy+40,"1.YES");
      outtextxy(midx,midy+80,"2.NO");
   }
      ch=getch();
      switch(ch)
      {
       case '1':
       case 'y':
       case 'Y':
        heli(0,0);
        obstacles(0,1);
       case '2':
       case 'n':
       case 'N':
        exit(0);

       default:
        goto repeat;
      }
}

void start()
{
 int   midx = getmaxx() / 2;
 char  ch;
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 {
  settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
  setcolor(WHITE);
  outtextxy(midx,65,"1.PLAY");
  outtextxy(midx,125,"2.INSTRUCTIONS");
  outtextxy(midx,185,"3.QUIT");
 }
 ch=getch();
 switch(ch)
 {
  case '1':
   heli(0,0);
   obstacles(0,200);
   break;

  case '2':
   instructions();
   break;

  case '3':
   exit(0);
 }
}

void instructions()
{
 cleardevice();
 settextjustify(CENTER_TEXT, CENTER_TEXT);
 {
  /* loop through the available text styles */
  /* select the text style */
  settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
  setcolor(1);
  /* output a message */
  outtextxy(300,65, "Keep moving the helicopter using the");
  outtextxy(300,95,"control keys so as to prevent the");
  outtextxy(300,125,"collisions with obstacles");
  outtextxy(300,155," > move right");
  outtextxy(300,185," < move right");
  outtextxy(300,215,"^ move up");
  outtextxy(300,245," v move down");
 }
 //wait for a key
 getch();
 cleardevice();
}

void blast()
{
 for(int r=0;r<240;r++)
 {
  setcolor(6);
  circle(320,240,r);
  delay(5);
 }
 cleardevice();
 result();
}

void crash()
{
 nosound();
 if(hu<=0||ht<=0||hd>=getmaxy()||hr>=getmaxx())
  blast();
 if(hr>=o11&&ht<=o13&&hu<=o14&&hd>=o12)
  blast();
 if(hr>=o21&&ht<=o23&&hu<=o24&&hd>=o22)
  blast();
 if(hr>=o31&&ht<=o33&&hu<=o34&&hd>=o32)
  blast();
 if(hr>=o41&&ht<=o43&&hu<=o44&&hd>=o42)
  blast();
 if(hr>=o51&&ht<=o53&&hu<=o54&&hd>=o52)
  blast();
 if(hr>=o61&&ht<=o63&&hu<=o64&&hd>=o62)
  blast();
 if(hr>=o71&&ht<=o73&&hu<=o74&&hd>=o72)
  blast();
 if(hr>=o81&&ht<=o83&&hu<=o84&&hd>=o82)
  blast();
 if(hr>=o91&&ht<=o93&&hu<=o94&&hd>=o92)
  blast();

 //if((hr==o31&&hd>=o32&&hu<=o34))
  //blast(hr);
}

void heli(int a,int b)
{
 //setlinestyle(0,0,3);
 setcolor(7);
 for(int z=20;z<75;z=z+5)
 {
  sound(z);
 }
 line(25+a,62+b,96+a,54+b);
 line(25+a,62+b,96+a,74+b);
 ellipse(125+a,62+b,0,360,32,24);
 line(125+a,39+b,125+a,32+b);
 line(125+a,32+b,175+a,18+b);
 line(125+a,32+b,175+a,42+b);
 arc(175+a,30+b,270,90,12);
 line(125+a,32+b,75+a,18+b);
 line(125+a,32+b,75+a,42+b);
 arc(75+a,30+b,90,270,12);
 //Tail fan

 line(26+a,50+b,32+a,74+b);
 line(26+a,74+b,32+a,50+b);
 arc(29+a,50+b,0,180,3);
 arc(29+a,74+b,180,360,3);
 //setlinestyle(0,0,1);
}

void obstacles(long int i,int sp)
{
 int d1=1,d2=1,d3=1,d4=1,j1=0,j2=0,j3=0,j4=0;
 int right=0,up=0,key,det=0;
 int init=i;
 //for(int n=0;n<3;n++)
 for(;i<init+3600;i+=sp)
 {
  //Obstacles' coordinates
  o11=325-i;o12=200;o13=375-i;o14=400;
  o21=655-i;o22=0;o23=795-i;o24=60;
  o31=815-i;o32=420;o33=855-i;o34=478;
  o41=1215-i;o42=200;o43=1325-i;o44=280;
  o51=1615-i;o52=50;o53=1665-i;o54=200;
  o61=2075-i;o62=200;o63=2125-i;o64=400;
  o71=2500-i;o72=0+j1;o73=2580-i;o74=80+j1;
  o81=3050-i;o82=0+j2;o83=3100-i;o84=80+j2;
  o91=3400-i;o92=0+j3;o93=3700-i;o94=55+j3;



  while(bioskey(1)) //output is 0 when no key is pressed and 1 when we press a key
  {
   key=_bios_keybrd(_KEYBRD_READ);  //keyboard press ni read cheyadaniki
   switch(key)
   {
    case RIGHT:
     right+=speed;
     heli(right,up);
     break;

    case LEFT:
     right-=speed;
     heli(right,up);
     break;

    case UP:
     up-=speed;
     heli(right,up);
     break;

    case DOWN:
     up+=speed;
     heli(right,up);
     break;

    default:
    ;
   }
  }
  if(det==1)
   {
    heli(right,++up);
    det=0;
   }
  else
   {
    heli(right,up);
    det=1;
   }
  //obstacles
  setcolor(4);
  rectangle(o11,o12,o13,o14);
  rectangle(o21,o22,o23,o24);
  rectangle(o31,o32,o33,o34);
  rectangle(o41,o42,o43,o44);
  rectangle(o51,o52,o53,o54);
  rectangle(o61,o62,o63,o64);
  rectangle(o71,o72,o73,o74);
  rectangle(o81,o82,o83,o84);
  rectangle(o91,o92,o93,o94);
  //rectangle(1375-i,0,1425-i,450);
  //rectangle(1475-i,700,1525-i,400);
  /* rectangle(i/8-500,200,i/8-450,440);
  rectangle(i/8-270,0,i/8-130,50);
  rectangle(i/8-210,j/2+120,i/8-170,j/2+180);
  rectangle(i/8,500,i/8+50,j/2+300);
  rectangle(i/8+190,j/2-50,i/8+240,j);
  rectangle(i/8+450,j,i/8+500,j+200);
  rectangle(i/8+750,0,i/8+800,450);
  rectangle(i/8+850,700,i/8+900,j/2+300); */
  delay(10);
  hr=187+right;
  hd=86+up;
  hu=19+up;
  ht=25+right;
  score1+=10;
  crash();
  if(j1==400)
   d1=2;
  else if(j1==0)
   d1=1;
  if(d1==1)
   j1++;
  else if(d1==2)
   j1--;
  if(o82==440)
   d2=2;
  else if(o82==0)
   d2=1;
  if(d2==1)
   j2++;
  else if(d2==2)
   j2--;
  if(o92==424)
   d3=2;
  else if(o92==0)
   d3=1;
  if(d3==1)
   j3+=2;
  else if(d3==2)
   j3-=2;
  cleardevice();
 }
}

void main()
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int key;
   int midx,midy;
   int size=8;
   char ch;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\turboc3");

   /* read result of initialization */
   errorcode = graphresult();
   /* an error occurred */
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
   midx = getmaxx() / 2;
   midy = getmaxy() / 2;
   settextjustify(CENTER_TEXT, CENTER_TEXT);
   {
   /* loop through the available text styles */
      /* select the text style */
      settextstyle(4, HORIZ_DIR, size);
      setcolor(1);
      /* output a message */
      outtextxy(midx,midy-40, "HELICOPTER");
      outtextxy(midx,midy+40,"HURDLES");
      delay(4444);
      cleardevice();
   start:
      setcolor(WHITE);
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 5);
      outtextxy(midx,65,"1.PLAY");
      outtextxy(midx,125,"2.INSTRUCTIONS");
      outtextxy(midx,185,"3.QUIT");
  }

   ch=getch();
   switch(ch)
   {
    case '1':
	heli(0,0);
	obstacles(0,1);
	setcolor(GREEN);
	outtextxy(290,220,"LEVEL 1 COMPLETE");
	delay(3000);
	cleardevice();
	outtextxy(300,220,"LEVEL 2");
	delay(2000);
	setcolor(WHITE);
	cleardevice();
	obstacles(-350,2);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 8);
	setcolor(13);
	outtextxy(320,200, "YAY!!!");
	outtextxy(320,280,"U WON ;)!");
	delay(4444);
	cleardevice();
	main();
	break;
    case '2':
	instructions();
	goto start;

    case '3':
	exit(0);
    default:
	goto start;
   }
   getch();
   closegraph();
}

