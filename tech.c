#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

#define RETURNTIME 15

COORD coord = {0, 0};
//list of global variable
int s;
char findques;
char password[10]={"astsat"};

void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


struct eva{
    int id;
    char name[30];
    char pass[15];
};

FILE *fs,*fp;

struct eva e;

int main(){
    Password();
}

void addeval(void)
{
    system("cls");

    int x=getdata();
    if(x){
    fs=fopen("evals.dat","ab+");

    fseek(fs,0,SEEK_END);
    fwrite(&e,sizeof(e),1,fs);
    fclose(fs);

    printf("\n\n\nEvaluater added successful !!!");
    getch();
    }

}

int getdata()
{
int t;
gotoxy(20,3);printf("Enter the Information Below");
gotoxy(20,4);printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5);
printf("\xB2");gotoxy(46,5);printf("\xB2");
gotoxy(20,6);
printf("\xB2");gotoxy(46,6);printf("\xB2");
gotoxy(20,7);
printf("\xB2");gotoxy(46,7);printf("\xB2");
gotoxy(20,8);
printf("\xB2");gotoxy(46,8);printf("\xB2");
gotoxy(20,9);
printf("\xB2");gotoxy(46,9);printf("\xB2");
gotoxy(20,10);
printf("\xB2");gotoxy(46,10);printf("\xB2");
gotoxy(20,11);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Evaluater ID:\t");
gotoxy(35,5);
scanf("%d",&t);
int y = checkid(t);
if(y)
{
gotoxy(21,13);
printf("\aThe user with this id already exists\a");
getch();
addeval();

return 0;
}
else{
        char che[15];
e.id=t;
gotoxy(21,7);
printf("Eval Name:");gotoxy(33,7);
scanf("%s",e.name);
gotoxy(21,8);
printf("Password:");gotoxy(30,8);
scanf("%s",e.pass);
gotoxy(21,9);
printf("PassWord:");gotoxy(30,9);
scanf("%s",che);
gotoxy(21,10);


if(strcmp(e.pass, che)==0)
    return 1;
else
{
    printf("\nPassword doesn't match");
    return 0;
}

}
}
int checkid(int t)
{
fp = fopen("evals.dat","ab+");
rewind(fs);
while(fread(&e,sizeof(e),1,fp)==1)
{if(e.id==t)
{
    fclose(fp);
    return 1;
}
}
fclose(fp);
return 0;
}


void Password(void) //for password option
{

system("cls");
char d[25]="Password Protected";
char ch,pass[10];
int i=0,j;

gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("*");
}
gotoxy(10,10);
gotoxy(15,7);
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{

gotoxy(15,9);
//textcolor(BLINK);
printf("Password match");
gotoxy(17,10);
printf("Press any key to countinue.....");
getch();
addeval();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}
