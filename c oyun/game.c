#include<stdio.h>
#include<windows.h>
#define SAG 77
#define BOSLUK 32
#define SOL 75
FILE *topkayma,*topyukari;
int satir,sutun;
char karakter;
int esc;
int tus,karx=6,kary=4;
//OYUN HARITASI
char harita[19][30]={{"                              "},
                    {"                              "},
					{"                              "},
					{"       _________________      "},
					{"     \\                        "},
					{"      \\                       "},
					{"       \\       /              "},
					{"        \\     /               "},
					{"         \\   /Zipla           "},				 
					{"            /                 "},	
					{"           /                  "},				 
				    {"  \\       /                  "},	
					{"   \\     /                    "},
					{"    \\   /Zipla                 "},
					{"     \\                        "},
					{"      \\                       "},
                    {"       \\                      "},
                    {"        \\                     "},
                    {"         \\                    "}};
        

void haritaciz()
{
	for(satir=0;satir<19;satir++){
		for(sutun=0;sutun<30;sutun++){
			printf("%c",harita[satir][sutun]);
		}
		printf("\n");
	}
}

void top()
{
gotoxy(karx,kary);
printf(" ");
topkayma=fopen("topkayma.txt","r");
do
   {
   karakter=getc(topkayma);
   while(fscanf(topkayma,"%d %d",&karx,&kary)!=EOF);
   }
   while(karakter!=EOF);
   fclose(topkayma);
   gotoxy(karx,kary);
 	printf("o");
 }


void hareket() 
{ 
 hidecursor();
 while(1)
 {

 if (kbhit()) 
 {
 	tus = getch();
 	switch(tus)
 	{
 	case SOL:
 	 if(harita[kary][karx-1]==92){
 	 gotoxy(karx,kary);
     printf(" ");
     gotoxy(--karx,--kary);
     printf("o");      
     topyukari=fopen("topyukari.txt","w");
     fprintf(topyukari," %d %d",karx,kary);
     fclose(topyukari);
     remove("topkayma.txt");
     }
     break;
    case SAG: 
     if(harita[kary][karx+1]==47){
     gotoxy(karx,kary);
     printf(" ");
     gotoxy(++karx,--kary);
     printf("o");
     topyukari=fopen("topyukari.txt","w");
     fprintf(topyukari," %d %d",karx,kary);
     fclose(topyukari);
     remove("topkayma.txt");
     }
     break;
     case BOSLUK:
     if(karx==12 && kary==8)
	 {
	 gotoxy(karx,kary);
     printf(" ");
     karx=10;
	 kary=8;	 
	 }
	 if(karx==5 && kary==13)
	 {
	 gotoxy(karx,kary);
     printf(" ");
	 karx=8;
	 kary=12;
	 }
	 break;
    }
 }
 top();
 if(karx==5 && kary==3)
 {
 gotoxy(0,0);
 printf("Oyunu Kazandin");
 esc=getch();
 if(esc==23)
 system("PAUSE");
}
 if(karx==11 && kary==19)
 {
 gotoxy(0,0);
 printf("Oyunu Kaybettin");
}
 }
}


void gotoxy(int x, int y)
{
	COORD Pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void hidecursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);	
}


void main()
{
haritaciz();
hareket();	
}
