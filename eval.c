#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>                  //contains strcmp(),strcpy(),strlen(),etc
#include<ctype.h>                   //contains toupper(), tolower(),etc
#include<dos.h>                     //contains _dos_getdate
#include<time.h>

#define RETURNTIME 15

struct eva{
    int id;
    char name[30];
    char pass[15];
};

FILE *fs,*fp;

struct eva e;

int main(){
    adduser();
}

void adduser(void)
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
printf("USER ID:\t");
gotoxy(30,5);
scanf("%d",&t);
int y = checkid(t);
if(y)
{
gotoxy(21,13);
printf("\aThe user with this id already exists\a");
getch();
adduser();

return 0;
}
else{
        char che[15];
e.id=t;
gotoxy(21,7);
printf("USER Name:");gotoxy(33,7);
scanf("%s",e.name);
gotoxy(21,8);
printf("Password:");gotoxy(30,8);
scanf("%s",e.pass);
gotoxy(21,9);
printf("PassWord:");gotoxy(33,9);
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
