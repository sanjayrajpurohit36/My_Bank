		/*            PROJECT NAME : BANKING

			     BY :- SANJAY RAJ PUROHIT                 */

// INCLUDING THE FOLLOWING HEADER FILES

# include <fstream.h>
# include <process.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <conio.h>
# include <dos.h>
# include <stdlib.h>
# include <iomanip.h>

static int accno=1001;  // GLOBAL VARIABLE FOR SETTING ACCOUNT NO AS 1001
int rec=0;              // GLOBAL VARIABLE FOR COUNTING TOTAL NO. OF RECORDS

 void showtime();   //FUNCTION FOR PRODUCING BOXES..
 void music();      //FUNCTION FOR PRODUCING SOUND WITH DIFFERENT FREQUENCIES..
 void _date();      //FUNCTION FOR SHIWING TODAY's SYSTEM's DATE
 void box();        //FUNCTION FOR PRINTING GRAPHIC BOXES..
 void countrec();   //FUNCTION FOR GETTING NO OF RECORDS TO GET LAST ACCOUNT FROM IT..
 void countrec1();  //FUNCTION FOR GETTING NO OF RECORDS
 int  checkrec1();  //FUNCTION FOR CHECKING AVAILABILITY OF RECORDS..
 void print();      //FUNCTION FOR PRINTING GRAPHICS..
 void addrec();     //FUNCTION FOR ADDING NEW RECORDS..
 void printrec();   //FUNCTION FOR PRINTING ALL RECORDS..
 void modibyacno(); //FUNCTION FOR MODIFYING ACCOUNT INFORMATION BY USING ACCOUNT NO. ..
 void delall();     //FUNCTION FOR DELETING ALL RECORDS..
 void delacno();    //FUNCTION FOR DELETING ACCOUNT BY USING ACCOUNT NO. ..
 void deleterec();  //FUNCTION FOR DELETING RECORDS..
 void showdepowid();//FUNCTION FOR SHOWING MENU OF MODIFY ACCOUNT..
 void trans();      //FUNCTION FRO TRANSISTION IN ACCOUNTS..
 int  position();   //FUNCTION TO GET THE POSITION OF THE WRITER..


/* 1.CLASS CONTAINS NAME , ADDRESS , INITIAL DEPOSIT AS PRIVATE MEMBERS &
     WITHDRAW , DEPOSIT,ACNO AS PUBLIC MEMBERS.

   2.CLASS CONTAINS THE FOLLOWING FUNCTIONS:-

     withamnt() FOR SUBTRACTING THE WITHDRAWN AMOUNT FROM THE INITIAL DEPOSIT..
     depoamnt() FOR ADDING THE DEPOSITED AMOUNT TO THE INITIAL DEPOSIT..
     inidepo() FOR RETURNING INITIAL DEPOSIT FOR WITHDRAW FUNCTION..
     input() FOR TAKING NAME , ADDRESS , INITIAL DEPOSIT OF THE CUSTOMER..
     newinput() FOR INPUTTING DATA WHEN THE OPTION OF MIDIFY HAS BEEN CHOOSEN..
     print() FOR SHOWING ACCOUNT NO. , NAME , ADDRESS , BALANCE OF THE CUSTOMER..


   3.CLASS CONTAINS CONSTRUCTOR RECORD FOR SETTING THE INITIAL , WITHDRAWN ,
   DEPOSITED AMOUNT AS  0..

   4.OBJECT OF CLASS RECORD 's1' HAS BEEN CREATED AT THE END OF THE CLASS..

   5. THE TOTAL SIZE OF THE CLASS IS 74 BYTES..

*/

class record


{ private:
	   char name[20];
	   char address[40];
	   float initial;


  public:
	   float withdraw;
	   float deposit;
	   int acno;

record()            // CONSTRUCTOR
   {
	initial=0;
	withdraw=0;
	deposit=0;
   }

void  withamnt(float k)
   {
	initial=initial-k;

   }

void   depoamnt(float k)
   {
	initial=initial+k;

   }

int inidepo ()
  { return initial;

  }

void input()
   { acno=accno;
     _date();
     gotoxy(30,2);
     textcolor(MAGENTA);
     cprintf("OPEN NEW ACCOUNT");
     textcolor(WHITE);
     gotoxy(30,3);
     cprintf("**** *** *******");
     gotoxy(30,4);
     cprintf("\nACCOUNT NO.: ");
     cout<<acno;
     gotoxy(30,6);
     cprintf("\nNAME: ");
     gets(name);
     gotoxy(30,8);
     cprintf("\nADDRESS: ");
     gets(address);
     gotoxy(30,10);
     cprintf("\nENTER INITIAL DEPOSIT: ");
     cin>>initial;
     gotoxy(20,15);
     cprintf("DATA SAVED...");
     gotoxy(2,24);
     cprintf("PRESS ANY KEY TO RETURN MAIN MENU...");
   }

void newinput()

   { int t;
     _date();
     gotoxy(30,2);
     textcolor(MAGENTA);
     cprintf("MODIFY ACCOUNT");
     textcolor(WHITE);
     gotoxy(30,3);
     cprintf("***** *******");
     gotoxy(30,4);
     cprintf("\nACCOUNT NO.:");
     cout<<acno;
     gotoxy(30,6);
     cprintf("\nNAME: ");
     gets(name);
     gotoxy(30,8);
     cprintf("\nADDRESS: ");
     gets(address);
     gotoxy(10,10);
     cprintf("\nENTER AMOUNT TO DEPOSIT OR ENTER 0 FOR NOTHING:");
     cin>>t;
     if(t>0)
     initial=initial+t;
     gotoxy(20,15);
     cprintf("DATA SAVED...");
     gotoxy(2,24);
     cprintf("PRESS ANY KEY TO RETURN MAIN MENU...");

   }

   void print()
   {
     _date();
     gotoxy(35,3);
     textcolor(RED);
     cprintf("ICICI BANK");
     textcolor(WHITE);
     gotoxy(35,4);
     cprintf("อออออ ออออ");
     gotoxy(4,5);
     cprintf("*************************************************************************");

     gotoxy(5,6);
     cprintf("ACCOUNT NO.");
     gotoxy(27,6);
     cprintf("NAME");
     gotoxy(45,6);
     cprintf("ADDRESS");
     gotoxy(69,6);
     cprintf("BALANCE");

     gotoxy(8,8);
     cout<<acno;
     gotoxy(21,8);
     puts(name);
     gotoxy(40,8);
     puts(address);
     gotoxy(70,8);
     cout<<initial;
     gotoxy(4,12);
     cprintf("*************************************************************************");
     gotoxy(2,24);
     cprintf("PRESS ANY KEY...");
     getch();
   }


} s1;

// FUNCTION 1

void music()
{    int j,k;
     for(j=300;j<2000;j=j+300)
     {   sound(j);
	 delay(25);
	 nosound();
     }

}

// FUNCTION 2

void showtime()
{  int i;

  for(i=1;i<10;i++)
  { //box(i,i,79-i,24-i);
       music();
  }
      getch();
}

// FUNCTION 3

void _date()
{
   date d;
   getdate(&d);
   gotoxy(3,2);
   cout<<(int)d.da_day<<"-"<<(int)d.da_mon<<"-"<<d.da_year;
}

// FUNCTION 4

void box(int t,int l,int r,int b)
{    int i;
     gotoxy(l,t);
     cout<<"ษ";
     for(i=l+1;i<r;i++)
	cout<<"อ";
	gotoxy(t,r);
	cout<<"ป";

    gotoxy(l,t+1);
    for(i=t+1;i<b;i++)
     { gotoxy(l,i);
       cout<<"บ";
       gotoxy(r,i);
       cout<<"บ";
     }


     gotoxy(l,b);
     cout<<"ศ";
     for(i=l+1;i<r;i++)
	cout<<"อ";
     cout<<"ผ";


}

// FUNCTION 5

void countrec()
{       unsigned long int l;
	fstream fin("Account.dat",ios::binary|ios::in);

	if(fin)
	{	fin.seekg(0,ios::end);
		l=fin.tellg();
		l=l/sizeof(s1);
		rec=l;
		fin.close();
	}
}

// FUNCTION 6

void countrec1()
{       unsigned long int l;
	fstream fin("Account.dat",ios::binary|ios::in);

	if(fin)
	{	fin.seekg(0,ios::end);
		l=fin.tellg();
		l=l/sizeof(s1);
		rec=l;
		gotoxy(29,11);
		cprintf("\aTOTAL NO OF RECORDS ARE:");
		cout<<l;
		fin.close();
	}
}

// FUNCTION 7

int checkrec1()
 {      clrscr();
	box(1,1,79,25);
	fstream fin("Account.dat",ios::binary|ios::app|ios::out);
	fin.seekg(0,ios::end);
	int l=fin.tellg();
	     if (l <=0 )

	     {
		gotoxy(23,3);
		cprintf("\aSORRY NO DATA AVAILABLE IN FILE...!");
		gotoxy(2,24);
		cprintf("PRESS ANY KEY TO RETURN...");
		fin.seekg(0);
		return 1;

	     }

	    else
	    return 0;

 }

// FUNCTION 8

void print()
{   textmode(C80);

    box(1,2,79,25);
    int i,k=1;

    box(10,14,66,12);
    gotoxy(38,8);
    textcolor(15);
    cprintf("LOADING...") ;

  for(i=15;i<65;i++)
  {
    gotoxy(i,11);
    textcolor(BLUE);
    textbackground(WHITE);
    textcolor(i);
    cprintf("ฒ");
    delay(100);       //100
    gotoxy(39,10);
    cout<<" "<<k*2<<"% ";
    k++;

  }
    textbackground(BLACK);
    textcolor(WHITE);

    clrscr();
    box(2,2,79,24);
    gotoxy(30,11);
    textcolor(13+BLINK);
    cprintf("B  A  N  K  I  N  G");
    textcolor(WHITE);
    gotoxy(30,12);
    cprintf("อออออออออออออออออออ");
    getch();
    clrscr();

    box(1,2,79,25);
    gotoxy(26,5);
    textcolor(MAGENTA+128);
    cprintf(" WELCOME ");
    gotoxy(35,5);
    textcolor(WHITE+128);
    cprintf(" TO ");
    gotoxy(39,5);
    textcolor(RED+128);
    cprintf(" ICICI ");
    gotoxy(46,5);
    textcolor(RED+128);
    cprintf(" BANK ");
    textcolor(WHITE+128);
    gotoxy(27,6);
    cout<<"*******  **  *****  **** ";
    gotoxy(4,24);
    cout<<"PRESS ANY KEY TO ENTER...";

    getch();

}

// FUNCTION 9

void addrec()
{
    fstream fin("Account.dat",ios::binary|ios::app|ios::out);
    position();
    s1.input();
    fin.write((char *) &s1,sizeof(s1));
    fin.close();
}

// FUNCTION 10

void printrec()
{
    ifstream fin("Account.dat",ios::binary);
    checkrec1();
    if(!fin)
    return;


    while(!fin.eof())
    { fin.read((char *) &s1 , sizeof(s1) ) ;
      if(fin.eof())
       break;
      s1.print();
    }
    fin.close();
}

// FUNCTION 11

void modibyacno()
{       int found =0;
	unsigned  int loc;
	int r;
	char ch;

	fstream fin("Account.dat",ios::binary | ios::in | ios::out );
	_date();
	if(checkrec1())
	return;
	box(1,1,79,25);
	fin.seekg(0);
	gotoxy(13,4);
	cprintf("ENTER THE ACCOUNT NO.TO BE MODIFIED:");
	cin>>r;

	while (!fin.eof())
       {
	  fin.read ( (char *)  & s1 , sizeof(s1) ) ;
	  if(fin.eof())
	       break;
	  if (r==s1.acno)
	  {
		    found=1;
		    clrscr();
		    box(1,1,79,25);
		    gotoxy(2,4);
		    cprintf("ENTER NEW VALUES:\n");
		    s1.newinput();
		    loc  =  fin.tellg() - sizeof(s1);
		    fin.seekp(loc);
		    fin.write((char *) &s1,sizeof(s1));

	  }
       }

	  if(found==0)
	{
		clrscr();
		box(1,1,79,25);
		gotoxy(25,10);
		cprintf("\aSORRY THERE IS NO SUCH ACCOUNT....!!");
	}

	fin.close();


}

//FUNCTION 12

void delall()
{
	ofstream f("Account.dat",ios::binary);
	accno=1001;
	clrscr();
	box(1,1,79,25);
	gotoxy(25,10);
	cprintf("\aALL DATA HAS BEEN DELETED..");
	gotoxy(2,24);
	cprintf("PRESS ANY KEY TO RETURN...");
	f.close();

}

// FUNCTION 13

void delacno()
{
	int r;
	unsigned  int loc;

	if(checkrec1())
	return ;
   else
   {
	  fstream fin("Account.dat",ios::binary|ios::in|ios::out);
	  ofstream f("temp",ios::binary);
	  clrscr();
	  box(1,1,79,25);
	  gotoxy(13,4);
	  cprintf("ENTER A ACCOUNT NO. TO BE DELETED:");
	  cin>>r;

	  int found =0;


	 while(!fin.eof())
	 { fin.read((char *) &s1,sizeof(s1));
	   if(fin.eof())
	    break;
	   if(r!=s1.acno)
	   f.write((char *) &s1,sizeof(s1));
	   else
	   found=1;

   /* checked whether the accno is present or not ..
      first found -> has been put 0
      then the data is copied till the accno are not matched to that of the
      mentioned above but with else if the accno is found then then the found is
      set 1....
   */
	 }
	 if(found)
	 { gotoxy(25,15);
	   printf("THE ACCOUNT HAS BEEN DELETED...");
	 }
	 else
	 { gotoxy(25,15);
	   cprintf("SORRY THERE IS NO SUCH ACCOUNT...!!");
	 }
	   fin.close();
	   f.close();
	   remove("Account.dat");
	   rename("temp","Account.dat");

   }

}

// FUNCTION 14

void deleterec()
{
  clrscr();
  int ch;

  while(1)
  {
	clrscr();
	_date();
	box(1,1,79,25);
	textcolor(4);
	gotoxy(35,3);
	cprintf("D E L E T E");
	textcolor(WHITE);
	gotoxy(34,4);
	cprintf("*************");

	gotoxy(33,5);
	cprintf("\n\n1.DELETE ALL RECORDS");
	gotoxy(33,7);
	cprintf("\n\n2.DELETE BY ACCOUNT NO.");
	gotoxy(33,9);
	cprintf("\n\n3.RETURN TO MAIN MENU");
	gotoxy(33,11);
	cprintf("\n\nENTER YOUR CHOICE:");
	cin>>ch;

 switch(ch)
    {
	case 1 : delall();
		 break;

	case 2 : delacno();
		 break;

	case 3 : return ;

	default: gotoxy(33,18);
		 cprintf("\nSORRY WRONG CHOICE..");

    }
	getch();
  }

}

//FUNCTION 15

void showdepowid()
{
		clrscr();
		box(1,1,79,25);
		_date();
		gotoxy(34,2);
		textcolor(MAGENTA);
		cprintf("TRANSACTION");
		textcolor(WHITE);
		gotoxy(33,3);
		cprintf("*************");
		gotoxy(33,5);
		cprintf("\n\n1.WITHDRAW");
		gotoxy(33,7);
		cprintf("\n\n2.DEPOSIT");
		gotoxy(33,9);
		cprintf("\n\n3.RETURN TO MAIN MENU");
		gotoxy(33,11);
		cprintf("\n\nENTER YOUR CHOICE:");

}

//FUNCTION 16

void trans()
{ clrscr();
  int t=0;
  int i,k,ac;
  float j;
  unsigned l;
  fstream fin("Account.Dat",ios::in|ios::out);
  box(1,1,79,25);
  _date();
  gotoxy(13,4);
  cprintf("ENTER THE ACCOUNT NO.:");
  cin>>ac;
  if(checkrec1())
	return;

 while(!fin.eof())
 {
	      l=fin.tellg();
	      fin.read((char*)&s1,sizeof(s1));
	      if(fin.eof())
		       break;
	      if(s1.acno==ac)
	 {       t=1;
		 showdepowid();
		 cin>>i;
		 if(i==1)
		{
		  clrscr();
		  box(1,1,79,25);
		  _date();
		  gotoxy(5,3);
		  cprintf("\nENTER THE AMOUNT TO BE WITHDRAWN:");
		  cin>>k;

		      if(k>s1.inidepo())
			   { gotoxy(30,10);
			     cprintf("\aNOT ENOUGH BALANCE IN THE ACCOUNT");
			   }
			   else
			   {
			     s1.withamnt(k);
			     gotoxy(30,10);
			     cprintf("AMOUNT IS WITHDRAWN");
			     fin.seekg(l);
			     fin.write((char*)&s1,sizeof(s1));

		}
		     fin.close();
		     break;
	      }
		 if(i==2)
		{ clrscr();
		  t=1;
		  box(1,1,79,25);
		  _date();
		  gotoxy(5,3);
		  cprintf("ENTER THE AMOUNT TO BE DEPOSITED:");
		  cin>>k;
		  s1.depoamnt(k);
		  gotoxy(30,10);
		  cprintf("THE AMOUNT IS DEPOSITED");
		  fin.seekg(l);
		  fin.write((char*)&s1,sizeof(s1));
		  fin.close();
		  break;
		}
	 }
 }
		 if(t==0)
		{
		 gotoxy(25,10);
		 cprintf("\aSORRY THERE IS NO SUCH ACCOUNT...!!");
		 getch();
		 return;
		}

}

// FUNCTION 17

int position()
{  fstream file ("Account.dat", ios::in);
   countrec();
   if(rec>0)
   {	file.seekg( (rec-1)*sizeof(s1));
	file.read((char *)&s1, sizeof(s1));
	accno =s1.acno+1;
   }

   else
	accno=1001;
	file.close();
	return accno ;
}

 // ALL FUNCTIONS END HERE..


void main()
{
   textmode(C80);
   clrscr();
   int i;
   int ch;
   print();
   textcolor(15);

while(1)
{
 clrscr();
 box(1,2,79,25);
 _date();
 gotoxy(30,1);
 textcolor(GREEN+BLINK);
 cprintf("\n\n M A I N  -  M E N U");
 textcolor(WHITE);
 gotoxy(33,3);
 cprintf("\n\n1. ADD A RECORD");
 gotoxy(33,5);
 cprintf("\n\n2. PRINT ALL RECORD");
 gotoxy(33,7);
 cprintf("\n\n3. MODIFY RECORDS");
 gotoxy(33,9);
 cprintf("\n\n4. DELETE RECORD");
 gotoxy(33,11);
 cprintf("\n\n5. DAILY TRANSACTION");
 gotoxy(33,13);
 cprintf("\n\n6. COUNT RECORDS");
 gotoxy(33,15);
 cprintf("\n\n0. PRESS 0 FOR EXIT");
 gotoxy(33,17);
 textcolor(RED+BLINK);
 cprintf("\n\n ENTER YOUR CHOICE:");
 textcolor(WHITE);

 cin>>ch;

 clrscr();
 box(1,1,79,25);
  switch(ch)
  {
   case 0 : gotoxy(35,10);
	    cprintf("GOOD BYE !\n");
	    gotoxy(35,11);
	    textcolor(RED);
	    cprintf("**** *** *");
	    textcolor(WHITE);
	    gotoxy(29,11);
	    cprintf("\nTHANKS FOR VISITING US !!\n");
	    gotoxy(29,13);
	    textcolor(MAGENTA);
	    cprintf("****** *** ******** ** **");
	    textcolor(WHITE);
	    getch();
	    clrscr();

	    for(i=1;i<8;i++)
	    box(i,i,80-i,25-i);
	    showtime();
	    gotoxy(20,8);
	    textcolor(GREEN);
	    cprintf(" MADE BY ");
	    textcolor(WHITE);
	    cprintf(": SANJAY RAJ PUROHIT ");

	    gotoxy(20,10);
	    textcolor(MAGENTA);
	    cprintf("UNDER THE GUIDANCE OF");
	    cout<<": MR.OMESH PALIWAL";
	    exit(1);

	    break;

   case 1 : addrec();
	    break;

   case 2 : printrec();
	    break;

   case 3 : modibyacno();
	    break;

   case 4 : deleterec();
	    break;

   case 5 : trans();
	    break;

   case 6 : countrec1();
	    break;

   default: gotoxy(29,9);
	    cprintf("\n\nSORRY WRONG CHOICE...");

  }    // END OF switch()

	 getch();

 }      // END OF while

}      // END OF while(1)




// END OF THE WHOLE CODING **************************************************