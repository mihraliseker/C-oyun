#include<stdio.h>
#include<windows.h>
#define SAG 77
#define SOL 75
FILE *topkayma,*topyukari;
char karakter;
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
                    
                    
void gotoxy(int x, int y)
{
	COORD Pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Pos);
}

void hidecursor(){
	CONSOLE_CURSOR_INFO cursor_info={1,0}; 
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);	
}


void hareket() 
{ 
 int karx=6,kary=4;
 hidecursor();
 while(1)
 {
  topyukari=fopen("topyukari.txt","r+");
  do
   {
   karakter=getc(topyukari);
   while(fscanf(topyukari,"%d %d",&karx,&kary)!=EOF);
   }
   while(karakter!=EOF);
   fclose(topyukari);
   remove("topyukari.txt");
 Sleep(1500);
 if(harita[kary][karx-1]==92){
 	++karx;
	++kary;
 }
 if(harita[kary][karx+1]==47){
 	--karx;
	++kary;

 }
 printf("%d %d\n",karx,kary);
 topkayma=fopen("topkayma.txt","w");
 fprintf(topkayma," %d %d",karx,kary);
 fclose(topkayma);
 topyukari=fopen("topyukari.txt","r");
  do
   {
   karakter=getc(topyukari);
   while(fscanf(topyukari,"%d %d",&karx,&kary)!=EOF);
   }
   while(karakter!=EOF);
   fclose(topyukari);
}
}



void main()
{
remove("topkayma.txt");
hareket();	
}


