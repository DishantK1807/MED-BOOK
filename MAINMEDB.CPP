/*************************************************************************
PROJECT
Made by: DISHANT KHANNA
ROLL NO. 

**************************************************************************/



/**************************************************************
****************  HEADER FILES USED  **************************
***************************************************************/
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
char fn[20];
char nm1[20];
char nm[12];
/*struct date {
  int da_year;      current year
  char da_day;      day of the month
  char da_mon;      month (1 = Jan)
};              */
/*
 
   BOX CODE 
 
*/
void h_line(int col1,int col2,int r1,char c){
 for(int j=col1; j<=col2;j++){
  gotoxy(j,r1);
  cprintf("%c",c);
  }
 }
void v_line(int row1,int row2,int c1,char c){
 for(; row1<row2;row1++){
  gotoxy(c1,row1);
  cprintf("%c",c);
  }
 }
void corner(int c,int r, char ch){
 gotoxy(c,r);
 cprintf("%c",ch);
}
void box(int sr, int er,int sc,int ec,char ch)
{
 h_line(sc,ec,sr,ch);
v_line(sr,er,ec,ch);
  h_line(sc,ec,er,ch);
 v_line(sr,er,sc,ch);
}
/*

  END CODE 

*/



/*

 CLASS CODE BEGINS 

*/

class patient{
       char name[40];
       int  age;
       char add[100];
       char bg[3];
       char aller[50];
       char gen;
       long double pno;
       char occup[50];
       char maritialsts[50];
public:
       void acceptd();
       void displayd();
       char *retname() { return name;}
       char *retbg() {return bg;}
};

void patient::acceptd(){
 box(1,50,1,79,'');
 gotoxy(17,24);
 cout<<" Enter name                     :";
 gets(name);
 gotoxy(17,25);
 cout<<" Enter gender(M/F)              :";
 cin>>gen;
 gen=toupper(gen);
 gotoxy(17,26);
 cout<<" Enter Age                      :";
 cin>>age;
 gotoxy(17,27);
 cout<<" Enter address                  :";
 gets(add);
 gotoxy(17,28);
 cout<<" Enter blood group              :";
 cin>>bg;
 gotoxy(17,29);
 cout<<" Enter allergies                :";
 gets(aller);
 gotoxy(17,30);
 cout<<" Enter contact no               :";
 cin>>pno;
 gotoxy(17,31);
 cout<<" Enter occupation               :";
 gets(occup);
 gotoxy(17,32);
 cout<<" Enter maritial status          :";
 cin>>maritialsts;
 }

void patient::displayd(){
 box(1,50,1,79,'');
 gotoxy(17,24);
 cout<<" Enter name            :"<<name;
 gotoxy(17,25);
 cout<<" Enter gender          :"<<gen;
 gotoxy(17,26);
 cout<<" Enter Age             :"<<age;
 gotoxy(17,27);
 cout<<" Enter address         :"<<add;
 gotoxy(17,28);
 cout<<" Enter blood group     :"<<bg;
 gotoxy(17,29);
 cout<<" Enter allergies       :"<<aller;
 gotoxy(17,30);
 cout<<" Enter contact no      :"<<pno;
 gotoxy(17,31);
 cout<<" Enter occupation      :"<<occup;
 gotoxy(17,32);
 cout<<" Enter maritial status :"<<maritialsts;
}


/*

 CLASS CODE ENDS 

*/


void enter_pres(char *);
void file_nm();
void pres(char*);
void dpres(char *);
void cd();




/****************************************************************************
******************************   WRITE FUNCTION   ***************************
*****************************************************************************/
void writeobj(){
 ofstream f("doc.dat",ios::binary|ios::out|ios::app);
  patient s;
  char resp;
   do{
    s.acceptd();
    f.write((char*)&s,sizeof(s));
    enter_pres(s.retname());
    cout<<" Want to enter more records(y/n) ";
    cin>>resp;

   }while(resp=='y');
  f.close();
}



/****************************************************************************
*****************************  DISPLAY FUNCTION   ***************************
*****************************************************************************/
void dispobj(){
 ifstream f("doc.dat",ios::binary|ios::out|ios::app);
  patient s;
  while(f.read((char*)&s,sizeof(s)))
   s.displayd();
  f.close();
}



/****************************************************************************
**********************  SEARCH RECORDS via BLOOD GROUP  *********************
*****************************************************************************/
void rec_bg()
{box(1,50,1,79,'');
 ifstream f("doc.dat",ios::binary);
   if(!f){cout<<"error in opening file";getch(); return;}
   patient s;
  char r[2];
  gotoxy(16,24);
  cout<<"Enter Blood Group to search"; cin>>r;
    while(f.read((char*)&s,sizeof(s))){
  if(strcmpi(s.retbg(),r)==0)
  {clrscr();
   gotoxy(18,28);
   s.displayd();
   getch();
   clrscr();}
   clrscr();
   }

f.close();
}




/****************************************************************************
***************************  SEARCH RECORDS via NAME  ***********************
*****************************************************************************/
char *sdispobj(){
 ifstream f("doc.dat",ios::binary);
  patient s;
  char name[30];
  fflush(stdin);
  cout<<"Enter name to search";
  fflush(stdout);
  gets(name);
  while(f.read((char*)&s,sizeof(s))){
  if(strcmpi(s.retname(),name)==0)
  {
   s.displayd();
   getch();
   return s.retname();
   }
   }
  f.close();
  return "NULL";
  }
  void enter_pres(char *pn)
  {
  strcpy(nm1,pn);
  file_nm();
  pres(nm1);
  cout<<"See the prescription ";
  dpres(nm1);
}




/***************************************************************************
************************  PRESCRIPTION FUNCTION  ***************************
****************************************************************************/
void pres(char *n){
clrscr();
 ofstream f1;
 f1.open(n,ios::app|ios::out);
 struct date d;
   getdate(&d);
   clrscr();
   gotoxy(10,3);
 int d1_year;
 int d1_day;
 int d1_mon;
 d1_year=d.da_year;
 d1_day=d.da_day;
 d1_mon=d.da_mon;


 char ps[200];
 cout<<"\n\t Enter Prescription\t('$' to end)";
 //cin>>cd();
 cin.getline(ps,200,'$');
 f1<<d1_day<<"/"<<d1_mon<<"/"<<d1_year<<":";
 f1<<ps<<endl;
 f1.close();
}



/***************************************************************************
**********************   CURRENT DATE FUNCTION *****************************
****************************************************************************/
void ddmmyy()
{
   struct date d;
   getdate(&d);
   clrscr();
   gotoxy(10,3);
   printf("Current Date : %d - %d - %d\n", d.da_day,d.da_mon,d.da_year);
   return ;
}




/*************************************************************************
**********************  COPY DATE FUNCTION  ******************************
**************************************************************************/
void cd(){
 date d;
 int d1_year;
 int d1_day;
 int d1_mon;
 d1_year=d.da_year;
 d1_day=d.da_day;
 d1_mon=d.da_mon;
 cout<<d1_day<<"/"<<d1_mon<<"/"<<d1_year<<":";
}




/************************************************************************
***********************  DISPALY PRESCRIPTION FUNCTION  *****************
*************************************************************************/
void dpres(char *n){
clrscr();
 ifstream f(n);
 if(!n)
 {
 cout<<"New PAtient"; getch();pres(n);}
 char ch,dmy[20];
 cout<<"\n\n\n\t";

 ddmmyy();
 //cd();
 while(f.get(ch))
  {cout<<ch;}
 cout<<"\n\n\t";
// getch();
 f.close();

}



/************************************************************************
*************************  FILE NAME FUNCTION  **************************
*************************************************************************/
void file_nm()
{int l=strlen(nm1);
 if(l>=8){
  for(int i=0;i<8;i++)
   nm[i]=nm1[i];
   nm[i++]='.';
   nm[i++]='d';
   nm[i++]='e';
   nm[i++]='s' ;
   nm[i]='\0';
 }
 else
{ strcpy(nm,nm1);
 strcat(nm,".des"); }
		   }




/************************************************************************
*************************   MENU 1  *************************************
*************************************************************************/
void menu1()
 {clrscr();
 box(1,50,1,79,'');
 int ch;    gotoxy(18,20);
	    cout<<"NEW PATIENT ";
	    gotoxy(16,24);
	    writeobj();
	//    dispobj();
	  //  strcpy(nm1,sdispobj());
	  //  file_nm();
  //	cout<<nm1;getch();

	    do{clrscr();
	    box(1,50,1,79,'');
	     gotoxy(18,20);
	     cout<<" NEW PATIENT ";
	     gotoxy(16,24);
	     cout<<" 1) Want to enter prescription";
	     gotoxy(18,26);
	     cout<<" 2) Go to main screen ";
	     gotoxy(20,28);
	     cin>>ch;
	      switch(ch){
	       case 1 : pres(nm);
			break;
	       case 2 : clrscr();
			return;
	       default: clrscr();
			cout<<"\n\t Invalid choice ";
			break;
	      }
	     }while(ch!=2);
 }



/********************************************************************
******************************  MENU 2  *****************************
*********************************************************************/
void menu2()
{
 clrscr();
 box(1,50,1,79,'');
 int ch;
 char ans;
 gotoxy(14,18);
 cout<<" OLD PATIENT ";
 gotoxy(18,20);
  strcpy(nm1,sdispobj());
	file_nm();
	 do{clrscr();
	   box(1,50,1,79,'');
	     gotoxy(18,20);
	     cout<<"OLD PATIENT ";
	     gotoxy(16,24);
	     cout<<"1) Want to enter prescription";
	     gotoxy(18,26);
	     cout<<"2) Go to main screen ";
	     cin>>ch;
	      switch(ch){
	       case 1 : dpres(nm);
			cout<<"Press E to Enter more , A to Abort";
			cin>>ans;
			if(ans=='E'||ans=='e')
			pres(nm);
			break;
	       case 2 : clrscr();
			return;
	       default: clrscr();
			cout<<" Invalid choice ";
			break;
	      }
	     }while(ch!=2);
	}




/*****************************************************************
*************************  MAIN MENU *****************************
******************************************************************/
 void main_menu()
 { int ch1;
 do{
  box(1,50,1,79,'');
    gotoxy(18,20);
   cout<<" MAIN MENU ";
   gotoxy(16,24);
   cout<<"1) New Patient ";
   gotoxy(18,26);
   cout<<"2) Old Patient ";
   gotoxy(20,28);
   cout<<"3) Search Blood Group ";
   gotoxy(22,30);
   cout<<"0) Exit \t";
    cin>>ch1;
    switch(ch1){
    case 1 : clrscr();menu1();break;
    case 2 : clrscr();menu2();break;
    case 3 : clrscr();
	     rec_bg();
	     break;
    case 0 : exit(0);
    default : cout<<"\n\t Invalid choice";
	      getch();
	      clrscr();
    }
    }while(ch1!=0);
 }


void main(){
 clrscr();
main_menu();
  }
