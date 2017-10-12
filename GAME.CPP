#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<stdio.h>

fstream o,i;

struct sss
{
char name[25];
int m,w,l,d;
}ss;
class game
{
private:
int a[9],n,r[3],c[3],d[2],flag,rr,ck,m,w,l,dr;
char name[20];
public:
game();
void start();
void instruction();
void menu();
void splayer();
void sc();
void ssc();
int toss();
void hard();
void easy();
void easyc();
void easyp();
void score();
void pturn();
void add();
void cturn1();
void cturn2();
void cturn();
int scan();
int win();
int saveloose();
int doublecase();
int singlecase();
void rallocation();
void display();
void result(int);
~game();
}

	game::game()
{
for(int j=0;j<9;j++)
{
a[j]=0;
}
flag=0,ck=1,w=0,l=0,m=0,dr=0,n=99;
}
	game::~game()
{
}
	void game::start()
{
clrscr();
char ch[68];
int k=10;
gotoxy(28,11);
cout<<"T I K";
gotoxy(36,11);
cout<<"T A K";
gotoxy(44,11);
cout<<"T O E";
delay(3200);
clrscr();
strcpy(ch,"This game is developed by Paras Singh Kaphalia and Gaurav Nautiyal");
for(int j=0;j<66;j++)
{
gotoxy(k,11);
cout<<ch[j];
delay(60);
k=k+1;
}
delay(3000);
menu();
}
		void game::menu()
{
clrscr();
gotoxy(27,5);
cout<<"M  A  I  N      M  E  N  U";
gotoxy(29,9);
cout<<"1.Play against computer";
gotoxy(29,10);
cout<<"2.Instruction";
gotoxy(29,11);
cout<<"3.See scores";
gotoxy(29,12);
cout<<"4.exit";
gotoxy(25,21);
cout<<"please enter your option ";
cin>>flag;
switch(flag)
{
case 1:
splayer();
break;
case 2:
instruction();
break;
case 3:
sc();
break;
case 4:
clrscr();
here:
;
gotoxy(31,13);
char ch;
cout<<"Are you sure(y/n) ";
cin>>ch;
switch(ch)
{
case 'y':
clrscr();
gotoxy(25,11);
cout<<"Thank you for playing the game";
gotoxy(28,13);
cout<<"Press any key to exit";
getch();
exit(0);
break;
case 'n':
menu();
break;
default:
clrscr();
gotoxy(31,11);
cout<<"invalid option!!";
goto here;
}
}
}
void game::instruction()
{
clrscr();
gotoxy(27,2);
cout<<"I N S T R U C T I O N S"<<endl<<endl<<endl;
cout<<"\t\t\t  HOW TO PLAY TIC TAC TOE"<<endl<<endl;
cout<<" Tic Tac Toe (also known as Noughts and Cross) is a simple and fun game that can be played almost anywhere and anytime."<<endl<<endl;
cout<<"1. Players will be provided with a 3x3 table of squares"<<endl;
cout<<"2. In the game player can choose that weather he wants to play with the ai or a human ie. single player or two players."<<endl;
cout<<"3. Who will play first is decided randomly by computer."<<endl;
cout<<"4. Symbol of the computer is by default 'x' and second player is 'o'."<<endl;
cout<<"5. These symbols will be placed on the table,in the attempt to have three of them in a row."<<endl;
cout<<"6. The players take turns putting their symbol on the table."<<endl;
cout<<"7. The first player to have 3 of their symbols in arow, weather it is horizontally, vertically or diagonally "<<endl;
cout<<"\t\t\t    IS THE WINNER";
gotoxy(22,23);
cout<<"press any key to return to main menu";
getch();
menu();
}
		void game::splayer()
{
clrscr();
gotoxy(22,6);
m=0,dr=0,w=0,l=0;
cout<<" S I N G L E P L A Y E R   M E N U";
gotoxy(22,5);
cout<<"*---------------------------------*";
gotoxy(22,7);
cout<<"*---------------------------------*";
gotoxy(29,11);
cout<<"1. Easy";
gotoxy(29,12);
cout<<"2. Hard";
gotoxy(29,13);
cout<<"3. Return to main menu";
gotoxy(25,21);
cout<<"please enter your option ";
cin>>flag;
switch(flag)
{
case 1:
easy();
break;
case 2:
hard();
break;
case 3:
menu();
break;
default:
clrscr();
gotoxy(32,11);
cout<<"invalid option";
gotoxy(20,13);
cout<<"press any key to return to the previous menu";
getch();
splayer();
break;
}

}
		void game::sc()
{
clrscr();
gotoxy(32,4);
cout<<"S  C  O  R  E  S";
gotoxy(28,10);
cout<<"  1.  See scores";
gotoxy(28,12);
cout<<"  2.  Clear all scores";
gotoxy(28,14);
cout<<"  3.  Return to main menu";
gotoxy(25,21);
cout<<"please enter your option ";
cin>>flag;
switch(flag)
{
case 1:
ssc();
break;
case 2:
char ch[25];
strcpy(ch,"xxx");
strcpy(ss.name,ch);
ss.l=0,ss.d=0,ss.m=0,ss.w=0;
o.open("score.dat",ios::out);
o.write((char*)&ss,sizeof(ss));
o.close();
clrscr();
gotoxy(35,11);
cout<<"Scores Cleared";
delay(900);
sc();
break;
case 3:
menu();
break;
default:
clrscr();
gotoxy(32,11);
cout<<"invalid option";
gotoxy(20,13);
cout<<"press any key to return to the previous menu";
getch();
sc();
}
}
		void game::ssc()
{


clrscr();
gotoxy(33,2);
cout<<"S  C  O  R  E  S";
gotoxy(2,4);
cout<<"| S.NO "<<"|          Name           |"<<" matches played |"<<" WON |"<<" LOST |"<<" DRAW |";
gotoxy(2,5);
cout<<"|      "<<"|                         |"<<"                |"<<"     |"<<"      |"<<"      |";
//for showing score
i.open("score.dat",ios::in);
i.read((char*)&ss,sizeof(ss));
int p=5;
while(i)
{

	if(strcmp(ss.name,"xxx")!=0)
	{
	p=p+1;
	gotoxy(2,p);
cout<<"|   "<<p-5<<"  | "<<ss.name;
gotoxy(35,p);
cout<<"|"<<"        "<<ss.m;
gotoxy(52,p);
cout<<"|  "<<ss.w;
gotoxy(58,p);
cout<<"|  "<<ss.l;
gotoxy(65,p);
cout<<"|  "<<ss.d;
gotoxy(72,p);
cout<<"|";
}
i.read((char*)&ss,sizeof(ss));
}
if(p==5)
{
clrscr();
gotoxy(32,4);
cout<<"S  C  O  R  E  S";
gotoxy(29,12);
cout<<"No scores are available";
}
i.close();
getch();
sc();
}
		void  game::display()
{
 clrscr();
gotoxy(71,9);
cout<<"Positions";
gotoxy(70,10);
cout<<"-----------";
for(int y=1;y<8;y++)
{
gotoxy(73,y);
cout<<"|";
gotoxy(77,y);
cout<<"|";
}
for(y=70;y<81;y++)
{
gotoxy(y,3);
cout<<"-";
gotoxy(y,5);
cout<<"-";
}
int j=1;
int x;
for(y=2;y<=7;y=y+2)
{
for(x=71;x<=80;x=x+4)
{
gotoxy(x,y);
cout<<j;
j=j+1;
}
}
for(y=8;y<15;y++)
{
gotoxy(35,y);
cout<<"|";
gotoxy(39,y);
cout<<"|";
}
for(y=32;y<43;y++)
{
gotoxy(y,10);
cout<<"-";
gotoxy(y,12);
cout<<"-";
}
char ch[9];
for(j=0;j<9;j++)
{
if(a[j]==20)
ch[j]='*';
else if(a[j]==5)
ch[j]='0';
else
ch[j]=' ';
}
j=0;
for(y=9;y<=13;y=y+2)
{
for(x=33;x<=41;x=x+4)
{
gotoxy(x,y);
cout<<ch[j];
j=j+1;
}
}
}		//end of fun
		void game::result(int vlue)
{
m=m+1;
 if(vlue==20)
{
l++;
gotoxy(21,20);
cout<<"oops!! you lost,better luck next time ";
}
else if(vlue==5)
{
w++;
gotoxy(24,20);
cout<<"congrats!! You have won the match";
}
else
{
dr++;
gotoxy(24,20);
cout<<" Well played!! But it is a draw";
}
}
			void game::hard()
{
char ch;
int vlue;
do
{
for(int j=0;j<9;j++)		//Re initiallising array
a[j]=0;
ck=1;
do
{
display();
if(ck==1)
cturn1();
else if(ck==2)
cturn2();
else
cturn();
display();
vlue=scan();
if(vlue!=0)			//0 stands for continue
break;
pturn();
vlue=scan();
ck=ck+1;
display();
}
while(vlue==0);
display();
result(vlue);
gotoxy(26,22);
cout<<"do you want to continue(y/n) ";
cin>>ch;
while(ch!='y'&&ch!='n')
{
clrscr();
gotoxy(32,9);
cout<<"invalid option";
gotoxy(25,11);
cout<<"do you want to continue(y/n) ";
cin>>ch;
}
}
while(ch=='y');
clrscr();
gotoxy(30,8);
cout<<"You played- "<<m<<" matches";
gotoxy(37,10);
cout<<"won- "<<w;
gotoxy(36,11);
cout<<"lost- "<<l;
gotoxy(36,12);
cout<<"draw- "<<dr;
getch();
clrscr();
here:
;
gotoxy(22,11);
cout<<"do you want to save your score(y/n) ";
cin>>ch;
if(ch=='y')
score();
else if(ch=='n')
splayer();
else
{
clrscr();
gotoxy(32,9);
cout<<"invalid option";
goto here;
}
splayer();
}
		void game::score()
{
clrscr();
i.open("score.dat",ios::in);
if(!i)
{
gotoxy(14,10);
cout<<"error in opening the file!!  please clear the score first";
getch();
}
else
{
char name[25];
gotoxy(25,10);
cout<<"Please enter your name ";
gets(name);
clrscr();
int c=0;
o.open("tem.dat",ios::out);                //for del previous data
o.close();
o.open("tem.dat",ios::app);
i.read((char*)&ss,sizeof(ss));
while(i)
{
if(strcmp(name,ss.name)==0)
{
ss.m=ss.m+m;
ss.w=ss.w+w;
ss.l=ss.l+l;
ss.d=ss.d+dr;
c=1;
}
o.write((char*)&ss,sizeof(ss));
i.read((char*)&ss,sizeof(ss));
}
if(c==0)
{
strcpy(ss.name,name);
ss.m=m;
ss.w=w;
ss.l=l;
ss.d=dr;
o.write((char*)&ss,sizeof(ss));
}
o.close();
i.close();
i.open("tem.dat",ios::in);
o.open("score.dat",ios::out);
i.read((char*)&ss,sizeof(ss));
while(i)
{
o.write((char*)&ss,sizeof(ss));
i.read((char*)&ss,sizeof(ss));
}
i.close();
o.close();
clrscr();
gotoxy(26,11);
cout<<"Score is saved sucessfully";
delay(900);
}
}
			void game::easy()
{
flag=toss();
if(flag==20)
{
gotoxy(22,11);
cout<<"Result - computer has won the toss";
gotoxy(26,22);
cout<<"press any key to continue";
getch();
easyc();
}
else
{
gotoxy(24,11);
cout<<"Result - you have won the toss";
gotoxy(26,22);
cout<<"press any key to continue";
getch();
easyp();
}
clrscr();
gotoxy(30,8);
cout<<"You played- "<<m<<" matches";
gotoxy(37,10);
cout<<"won- "<<w;
gotoxy(36,11);
cout<<"lost- "<<l;
gotoxy(36,12);
cout<<"draw- "<<dr;
getch();
clrscr();
char ch;
here:
;
gotoxy(22,11);
cout<<"do you want to save your score(y/n) ";
cin>>ch;
if(ch=='y')
score();
else if(ch=='n')
splayer();
else
{
clrscr();
gotoxy(32,9);
cout<<"invalid option";
goto here;
}
splayer();
}
		void game::easyp()
{
int vlue;
char ch;
do
{
for(int j=0;j<9;j++)		//Re initiallising array
{
a[j]=0;
}
ck=1;
do
{
display();
pturn();
vlue=scan();
if(vlue!=0)			//0 stands for continue
{
break;
}
display();
	if(ck==1)
{       gotoxy(32,19);
cout<<"processing";   //g has cordnate(41,19)
for(int j=42;j<46;j++)
{
delay(300);
cout<<".";
}
randomize();
do
{
vlue=random(9);
}
while(a[vlue]!=0);
a[vlue]=20;
}
	else
{
cturn();
}
display();
vlue=scan();
ck=ck+1;
}
while(vlue==0);
display();
result(vlue);
gotoxy(26,22);
cout<<"do you want to continue(y/n) ";
cin>>ch;
while(ch!='y'&&ch!='n')
{
clrscr();
gotoxy(32,9);
cout<<"invalid option";
gotoxy(25,11);
cout<<"do you want to continue(y/n) ";
cin>>ch;
}
}
while(ch=='y');
clrscr();
}
		void game::easyc()
{
char ch;
int vlue;
do
{
for(int j=0;j<9;j++)		//Re initiallising array
a[j]=0;
ck=1;
do
{
display();
if(ck==1)
{
randomize();
vlue=random(9);
gotoxy(32,19);
cout<<"processing";   //g has cordnate(41,19)
for(j=42;j<46;j++)
{
delay(300);
cout<<".";
}
a[vlue]=20;
}
else
{
cturn();
}
display();
vlue=scan();
if(vlue!=0)			//0 stands for continue
{
break;
}
pturn();
vlue=scan();
ck=ck+1;
display();
}
while(vlue==0);
display();
result(vlue);
gotoxy(26,22);
cout<<"do you want to continue(y/n) ";
cin>>ch;
while(ch!='y'&&ch!='n')
{
clrscr();
gotoxy(32,9);
cout<<"invalid option";
gotoxy(25,11);
cout<<"do you want to continue(y/n) ";
cin>>ch;
}
}
while(ch=='y');
clrscr();
}
		int game::toss()
{
clrscr();
gotoxy(33,11);
cout<<"tossing";
for(int j=40;j<44;j++)
{
gotoxy(j,11);
cout<<".";
delay(500);
}
randomize();
flag=random(4);
clrscr();
if(flag==0||flag==3)
{
return(20);
}
else
{
return(5);
}
} 		//end of toss
void game::add()
{
r[0]=a[0]+a[1]+a[2];
r[1]=a[3]+a[4]+a[5];
r[2]=a[6]+a[7]+a[8];
c[0]=a[0]+a[3]+a[6];
c[1]=a[1]+a[4]+a[7];
c[2]=a[2]+a[5]+a[8];
d[0]=a[0]+a[4]+a[8];
d[1]=a[2]+a[4]+a[6];
}
void game::pturn()
{
gotoxy(25,19);
cout<<"Please enter the position ";
char temporary;
temporary=getch();
n=(int)temporary-49;
while(a[n]!=0||(n>8||n<0))
{
display();
gotoxy(25,19);
cout<<"You have entered wrong position ";
gotoxy(24,21);
cout<<"Please enter some other position ";
temporary=getch();

n=(int)temporary-49;
}
a[n]=5;
}
		int game::scan()
{
add();
for(int j=0;j<3;j++)
{
if(r[j]==60||c[j]==60)
{
return(20);
}
if(c[j]==15||r[j]==15)
{
return(5);
}
}		//ending for
if(d[0]==60||d[1]==60)
{
return(20);
}
if(d[0]==15||d[1]==15)
{
return(5);
}

//for draw
flag=0;
for(j=0;j<9;j++)
{
if(a[j]==0)
{
flag=1;
break;
}
}
if (flag==0)
{
return(1);				//1 means draw
}
else
{
return(0);				// 0 means continue
}
}
void game::cturn1()
{
display();
gotoxy(32,19);
cout<<"processing";   //g has cordnate(41,19)
for(int j=42;j<46;j++)
{
delay(300);
cout<<".";
}
randomize();
rr=random(7);
int p;
if(rr<=4)
p=rr*2;
else
p=4;
rr=p;
a[rr]=20;
}
		void game::cturn2()
{
flag=0;
int p,k;
add();
display();
gotoxy(32,19);
cout<<"processing";   //g has cordnate(41,19)
for(int j=42;j<46;j++)
{
delay(300);
cout<<".";
}
if((rr==0&&n==1)||(rr==0&&n==3)||(rr==2&&n==1)||(rr==2&&n==5)||(rr==6&&n==3)||(rr==6&&n==7)||(rr==8&&n==7)||(rr==8&&n==5)||(rr==0&&n==2)||(rr==0&&n==6)||(rr==2&&n==0)||(rr==2&&n==8)||(rr==6&&n==0)||(rr==6&&n==8)||(rr==8&&n==6)||(rr==8&&n==2)||(rr==0&&n==8)||(rr==8&&n==0)||(rr==2&&n==6)||(rr==6&&n==2))		//case 1,2,3
{
if(r[0]==20&&flag==0)
{
if(a[0]==0)
a[0]=20;
else
a[2]=20;
flag=1;
}
else if(r[2]==20&&flag==0)
{
if(a[6]==0)
a[6]=20;
else
a[8]=20;
flag=1;
}
else if(c[0]==20&&flag==0)
{
if(a[0]==0)
a[0]=20;
else
a[6]=20;
flag=1;
}
else
{
if(a[2]==0)
a[2]=20;
else
a[8]=20;
}
}		//endig main if
else if((rr==0&&n==4)||(rr==2&&n==4)||(rr==6&&n==4)||(rr==8&&n==4))			//case 4
{
if(d[0]==25)
{
if(a[0]==0)
a[0]=20;
else
a[8]=20;
}
else
{
if(a[2]==0)
a[2]=20;
else
a[6]=20;
}
}
else if((rr==4&&n==1)||(rr==4&&n==3)||(rr==4&&n==5)||(rr==4&&n==7))		//case 5
{
randomize();
p=random(4);
if(p!=2)
k=p*2;
else
k=8;
p=k;
a[p]=20;
}				//end case 5
	else if((rr==4&&n==0)||(rr==4&&n==2)||(rr==4&&n==6)||(rr==4&&n==8))       //case 6
{
	if(d[0]==20)
a[0]=20;
else
a[2]=20;
}			//end case 6

else				//case 7
{
randomize();
do
{
p=random(4);
if(p!=2)
k=p*2;
else
k=8;
}
while(a[k]!=0);
a[k]=20;
}	//end case 7
}	//end fun cturn2
			void game::cturn()
{
flag=0;
add();
display();
gotoxy(32,19);
cout<<"processing";   //g has cordnate(41,19)
for(int j=42;j<46;j++)
{
delay(300);
cout<<".";
}
flag=win();
if(flag==0)
flag=saveloose();
if(flag==0)
flag=doublecase();
if(flag==0)
flag=singlecase();
if(flag==0)
rallocation();
}		//end cturn
		int game::win()
{
	int cc;
	for(int j=0;j<3;j++)
	{
		if(c[j]==40)
		{
			for(int i=j;i<=j+6;i=i+3)
			{
				if(a[i]==0)
				{
					a[i]=20;
					return(1);
				}
			}
		}
		if(r[j]==40)
		{
			cc=(j*2)+j;
			for(int k=cc;k<cc+3;k++)
			{
				if(a[k]==0)
				{
					a[k]=20;
					return(1);
				}
			}
		}
	}		//end main for

//for diagonals
	if(d[0]==40)
	{
		for(j=0;j<=8;j=j+4)
		{
			if(a[j]==0)
			{
			a[j]=20;
			return(1);
			}
		}
	}
	else if(d[1]==40)
	{
		for(j=2;j<=6;j=j+2)
		{
			if(a[j]==0)
			{
			a[j]=20;
			return(1);
			}
		}
	}
	else
	return(0);
}			//end win
	int game::saveloose()
{
	int cc;
	for(int j=0;j<3;j++)
	{
		if(c[j]==10)
		{
			for(int i=j;i<=j+6;i=i+3)
			{
				if(a[i]==0)
				{
				a[i]=20;
				return(1);
				}
			}
		}
		if(r[j]==10)
		{
		cc=(j*2)+j;
			for(int k=cc;k<cc+3;k++)
			{
				if(a[k]==0)
				{
				a[k]=20;
				return(1);
				}
			}
		}
	}		//end main for

	//for diagonals
	if(d[0]==10)
	{
		for(j=0;j<=8;j=j+4)
		{
			if(a[j]==0)
			{
			a[j]=20;
			return(1);
			}
		}
	}
	else if(d[1]==10)
	{
		for(j=2;j<=6;j=j+2)
		{
			if(a[j]==0)
			{
			a[j]=20;
			return(1);
			}
		}
	}
	else
		return(0);
}	//end saveloose()
		int game::doublecase()
{
	int cc,o;
	for(int k=0;k<9;k++)
	{
		cc=0;
		o=0;
		if(a[k]==0)
		{
			o=1;
			a[k]=20;
			add();
			for(int j=0;j<3;j++)
			{
				if(r[j]==40)
				cc=cc+1;
				if(c[j]==40)
				cc=cc+1;
			}		//ending for
		if(d[0]==40)
		cc=cc+1;
		if(d[1]==40)
		cc=cc+1;
		}
	if(cc>1)
	return(1);
	if(o==1&&cc<=1)
	a[k]=0;
	}
	return(0);

}	//end doublecase
			int game::singlecase()
{
int cc;
for(int j=0;j<3;j++)
{
	if(c[j]==20)
	{
		for(int i=j;i<=j+6;i=i+3)
		{
			if(a[i]==0)
			{
				a[i]=20;
				return(1);
			}
		}
	}
	if(r[j]==20)
	{
		cc=(j*2)+j;
		for(int k=cc;k<cc+3;k++)
		{
			if(a[k]==0)
			{
				a[k]=20;
				return(1);
			}
		}	
	}
}		//end main for
if(d[0]==20)
{
	for(j=0;j<=8;j=j+4)
	{
		if(a[j]==0)
		{	
			a[j]=20;
			return(1);
		}
	}
}
else if(d[1]==20)
{
	for(j=2;j<=6;j=j+2)
	{
		if(a[j]==0)
		{		
			a[j]=20;
			return(1);
		}
	}
}
else
return(0);
}   	//	end singlecase
			void game::rallocation()
{
for(int j=0;j<=8;j++)
{	
	if(a[j]==0)
	{
		a[j]=20;
		break;
	}
}
}

void main()
{
	game g;
	g.start();
	getch();
}
