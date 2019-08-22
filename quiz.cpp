 #include<stdlib.h>
 #include<string.h>
 #include<conio.h>
 #include<fstream.h>
 #include<process.h>
 #include<ctype.h>
 #include<stdio.h>

 class Quiz //to enter and display examinee data
 {
 private:
	  char name[20];
	  int roll;
	  char classs[10];
	  char email[30];
	  char mob_no[10];

 public:
	  void getdata()
	  {
	  cout<<"\nExaminee Name:";
	  gets(name);
	  cout<<"\nExaminee roll no.:";
	  cin>>roll;
	  cout<<"\nExaminee class:";
	  gets(classs);
	  cout<<"\nExaminee Email id:";
	  gets(email);
	  cout<<"\nExaminee Mobile no.:";
	  gets(mob_no);
	  }

	  void display()
	  {
	  cout<<"\nNAME:"<<name;
	  cout<<"\nRoll NO.:"<<roll;
	  cout<<"\nClass:"<<classs;
	  cout<<"\nEmail id:"<<email;
	  cout<<"\nMobile no.:"<<mob_no;
	  }

	  int return_ino()
	  {
	  return roll;
	  }
	  char *returnname()
	  {
	  return name;
	  }
 };

 class admin //to add and and read ques
 {
 private:
	  char sub[20];
	  char ans[20];
 public:
	  void addques();
	  void readques();
 };

 class Ques  //add and read ques
 {
 char Que[80];
 char op1[50];
 char op2[50];
 char op3[50];
 char op4[50];
 int ans;
 public:
 void getdata1()
 {
 cout<<"\nEnter question: ";
 gets(Que);
 cout<<"\nEnter option 1: ";
 gets(op1);
 cout<<"\nEnter option 2: ";
 gets(op2);
 cout<<"\nEnter option 3: ";
 gets(op3);
 cout<<"\nEnter option 4: ";
 gets(op4);
 cout<<"\nCorrect option is: ";
 cin>>ans;
 }
 void putdata()
 {
 cout<<Que<<endl;
 cout<<"1."<<op1<<endl;
 cout<<"2."<<op2<<endl;
 cout<<"3."<<op3<<endl;
 cout<<"4."<<op4<<endl;
 }
 int return_ans()
 {
 return ans;
 }
 };


 void admin :: addques() //add ques
 {
 int ch2;
 char ch3;
 Ques Q;
 fstream ofile1,ofile2,ofile3,ofile4;
 Main:
 clrscr();
 cout<<"\nSubject-> ";
 cout<<"\n1.COMPUTER SCIENCE"<<endl;
 cout<<"\n2.MATHEMATICS"<<endl;
 cout<<"\n3.SCIENCE"<<endl;
 cout<<"\n4.GENERAL KNOWLEDGE"<<endl;
 cout<<"\n5.BACK";
 cout<<"\nENTER YOUR CHOICE TO ADD QUESTION- "<<endl;
 cin>>ch2;
 clrscr();
 switch(ch2)
 {
 case 1:
 ofile1.open("cs.dat",ios::binary|ios::out|ios::app);
 do
 {
 Q.getdata1();
 ofile1.write((char*)&Q,sizeof(Q));
 cout<<"Do you want to enter more questions(Y/N): ";
 cin>>ch3;
 clrscr();
 }
 while(toupper(ch3)=='Y');
 ofile1.close();
 goto Main;
 break;

 case 2:
 ofile2.open("math.dat",ios::binary|ios::out|ios::app);
 do
 {
 Q.getdata1();
 ofile2.write((char*)&Q,sizeof(Q));
 cout<<"\nDo you want to add another question(Y/N): ";
 cin>>ch3;
 clrscr();
 }
 while(toupper(ch3)=='Y');
 ofile2.close();
 goto Main;
 break;

 case 3:
 ofile3.open("sc.dat",ios::binary|ios::out|ios::app);
 do
 {
 Q.getdata1();
 ofile3.write((char*)&Q,sizeof(Q));
 cout<<"\nDo you want to add another question(Y/N): ";
 cin>>ch3;
 clrscr();
 }
 while(toupper(ch3)=='Y');
 ofile3.close();
 goto Main;
 break;

 case 4:
 ofile4.open("gk.dat",ios::binary|ios::out|ios::app);
 do
 {
 Q.getdata1();
 ofile4.write((char*)&Q,sizeof(Q));
 cout<<"\nDo you want to add another question(Y/N): ";
 cin>>ch3;
 clrscr();
 }
 while(toupper(ch3)=='Y');
 ofile4.close();
 goto Main;
 break;

 case 5:
 goto ADMI;
 default:
 cout<<"\nWrong choice";
 goto Main;
 }
 ADMI:
 }

  void admin :: readques() //read all ques
  {
  Ques Q1;
  fstream ifile1,ifile2,ifile3,ifile4;
  ifile1.open("cs.dat",ios::in| ios:: binary|ios::app);
  clrscr();
  cout<<"\nCOMPUTER SCIENCE\n";
  while(ifile1.read((char*)&Q1,sizeof(Q1)))
  {
  Q1.putdata();
  }
  getch();
  ifile2.open("math.dat",ios::in| ios:: binary|ios::app);
  clrscr();
  cout<<"\nMATHEMATICS\n";
  while(ifile2.read((char*)&Q1,sizeof(Q1)))
  {
  Q1.putdata();
  }
  getch();
  ifile3.open("sc.dat",ios::in| ios:: binary|ios::app);
  clrscr();
  cout<<"\nSCIENCE\n";
  while(ifile3.read((char*)&Q1,sizeof(Q1)))
  {
  Q1.putdata();
  }
  getch();
  ifile4.open("gk.dat",ios::in| ios:: binary|ios::app);
  clrscr();
  cout<<"\nGENERAL KNOWLEDGE\n";
  while(ifile4.read((char*)&Q1,sizeof(Q1)))
  {
  Q1.putdata();
  }
  getch();
  ifile1.close();
  ifile2.close();
  ifile3.close();
  ifile4.close();

  clrscr();
  }


  void adminpro() //admin account
  {
  admin A;
  int ch1;
  ADMI:
  cout<<"\n1.Add a question";
  cout<<"\n2.View all questions";
  cout<<"\n3.LOGOUT";
  cout<<"\nEnter your choice: ";
  cin>>ch1;
  switch(ch1)
  {
  case 1:
  clrscr();
  A.addques();
  goto ADMI;
  getch();
  break;
  case 2:
  clrscr();
  A.readques();
  goto ADMI;
  getch();
  getch();
  case 3:
  clrscr();
  break;
  }
  }

void play() //Quiz start
{
int score=0,marks_cs=0,marks_m=0,marks_sc=0,marks_gk=0;
Ques Q1;
int response;
fstream ifile1,ifile2,ifile3,ifile4;
clrscr();
ifile1.open("cs.dat",ios::in| ios:: binary);
while(ifile1.read((char*)&Q1,sizeof(Q1)))
{
Q1.putdata();
cout<<"\nEnter your answer: ";
cin>>response;
if(Q1.return_ans()==response)
{
cout<<"\nYour answer is correct\n" ;
score+=5;
marks_cs+=5;
}
else
{
cout<<"\nWrong answer\n";
score-=2;
marks_cs-=2;
}
}
ifile1.close();
getch();
clrscr();

ifile2.open("math.dat",ios::in| ios:: binary);
while(ifile2.read((char*)&Q1,sizeof(Q1)))
{
Q1.putdata();
cout<<"\nEnter your answer: ";
cin>>response;
if(Q1.return_ans()==response)
{
cout<<"\nYour answer is correct\n" ;
score+=5;
marks_m+=5;
}
else
{
cout<<"\nWrong answer\n";
score-=2;
marks_m-=2;
}
}
ifile2.close();
getch();
clrscr();

ifile3.open("sc.dat",ios::in| ios:: binary);
while(ifile3.read((char*)&Q1,sizeof(Q1)))
{
Q1.putdata();
cout<<"\nEnter your answer: ";
cin>>response;
if(Q1.return_ans()==response)
{
cout<<"\nYour answer is correct\n" ;
score+=5;
marks_sc+=5;
}
else
{
cout<<"\nWrong answer\n";
score-=2;
marks_sc-=2;
}
}
ifile3.close();
getch();
clrscr();

ifile4.open("gk.dat",ios::in| ios:: binary);
while(ifile4.read((char*)&Q1,sizeof(Q1)))
{
Q1.putdata();
cout<<"\nEnter your answer: ";
cin>>response;
if(Q1.return_ans()==response)
{
cout<<"\nYour answer is correct\n" ;
score+=5;
marks_gk+=5;
}
else
{
cout<<"\nWrong answer\n";
score-=2;
marks_gk-=2;
}
}
ifile4.close();
getch();
clrscr();

char marks;
cout<<"\nYOUR QUIZ IS OVER\n";
cout<<"\nPRESS 'V' TO VIEW YOUR SCORE: ";
cin>>marks;
clrscr();
cout<<"\nCOMPUTER SCIENCE:  "<<marks_cs;
cout<<"\nMATHEMATICS:       "<<marks_m;
cout<<"\nSCIENCE:           "<<marks_sc;
cout<<"\nGENERAL KNOWLEDGE: "<<marks_gk;
cout<<"\nYOUR TOTAL SCORE IS "<<score;
cout<<" MARKS, OUT OF 100";
getch();
}
  void define() //instructions and marks distribution
  {
  cout<<"\n\t\t*** WELCOME ***\n";
  cout<<"\nINSTRUCTIONS";
  cout<<"\n1.Quiz consists of 4 subjects";
  cout<<"\n2.Each subject have 5 Questions";
  cout<<"\n3.All the questions are compulsory";
  cout<<"\n4.Each correct answer gives u +5 marks";
  cout<<"\n5.And each wrong answer gives u -2 marks\n";
  getch();
  }

  void createfile() //New user profile
  {
  char start;
  fstream ofile;
  Quiz Q;
  ofile.open("profile.dat",ios::out|ios::binary|ios::app);
  Q.getdata();
  ofile.write((char*)&Q,sizeof Q);
  ofile.close();

  cout<<"\nPRESS ANY KEY TO START QUIZ"<<endl;
  cin>>start;
  clrscr();
  define();
  clrscr();
  play();
  }

  void displayfile() //display all examinee details
  {
  cout<<"\nDisplaying Records!!";

  fstream ifile;
  Quiz Q;
  ifile.open("profile.dat",ios::in|ios::binary);
  while(ifile.read((char*)&Q,sizeof(Q)))
  {
  Q.display();
  }
  ifile.close();
  getch();
  }

void Delete()  //delete examinee record
{
fstream file,fil;
Quiz q;
int rn;
cout<<"Enter your roll number to delete your profile: ";
cin>>rn;
file.open("profile.dat",ios::in|ios::binary);
fil.open("temp.dat",ios::out|ios::binary);
while(file.read((char*)&q,sizeof q))
{
if(q.return_ino()!=rn)
fil.write((char*)&q,sizeof q);
}
file.close();
fil.close();

fil.open("temp.dat",ios::in|ios::binary);
file.open("profile.dat",ios::out|ios::binary);
while(fil.read((char*)&q,sizeof q))
{
file.write((char*)&q,sizeof q);
}
delete("temp.dat");
file.close();
fil.close();
}

void modify()  //modify examinee record
{
fstream file;
Quiz q;
file.open("profile.dat",ios::in|ios::out|ios::binary);
int rn;
cout<<"Enter your roll number to modify your profile: ";
cin>>rn;
while(file.read((char*)&q,sizeof(q)))
{
cout<<q.return_ino();
if(q.return_ino()==rn)
{
file.seekp(file.tellg()-sizeof(q),ios::beg);
q.getdata();
file.write((char*)&q,sizeof(q));
}
}
file.close();
getch();
}

void count() //count records
{
fstream file;
file.open("profile.dat",ios::in|ios::binary);
file.seekg(0,ios::end);
long int end=file.tellg();
long int num=end/sizeof (Quiz);
cout<<"Number of profiles are: "<<num;
file.close();
getch();
}

void search_roll() //search record by roll no
{
fstream file;
Quiz q;
file.open("profile.dat",ios::in|ios::binary);
char flag='N';
int rn;
cout<<"Enter your roll number to search your profile: ";
cin>>rn;
while(file.read((char*)&q,sizeof q))
{
if(q.return_ino()==rn)
{
q.display();
flag='Y';
}
}
if (flag=='N')
cout<<"This roll number not found!!";
file.close();
getch();
}

void search_name() //search record by name
{
fstream file;
Quiz q;
file.open("profile.dat",ios::in|ios::binary);
char flag='N';
char name[20];
cout<<"Enter your name to search your profile: ";
gets(name);
while(file.read((char*)&q,sizeof q));
{
if(strcmp(q.returnname(),name)==0)
{
q.display();
flag='Y';
}
}
if (flag=='N')
cout<<"This name not found!!";
file.close();
getch();
}

  void student()  //student account
  {
  int c2;
  do
  {
  lable:
  clrscr();
  cout<<"      \t\t\t~~~*** QUIZ CONTEST ***~~~\t      \n\n";
  cout<<"\n1.CREATE A NEW PROFILE";
  cout<<"\n2.DISPLAY EXISTING PROFILE";
  cout<<"\n3.MODIFY PROFILE";
  cout<<"\n4.DELETE PROFILE";
  cout<<"\n5.SEARCH PROFILE BY NAME";
  cout<<"\n6.SEARCH PROFILE BY ROLL NO.";
  cout<<"\n7.COUNT PROFILES";
  cout<<"\n8.QUIT";
  cout<<"\n9.BACK";
  cout<<"\nEnter your choice: ";
  cin>>c2;
  switch(c2)
  {
  case 1:
  clrscr();
  createfile();
  goto lable;
  getch();
  break;
  case 2:
  clrscr();
  displayfile();
  goto lable;
  getch();
  break;
  case 3:
  clrscr();
  modify();
  goto lable;
  getch();
  break;
  case 4:
  clrscr();
  Delete();
  goto lable;
  getch();
  break;
  case 5:
  clrscr();
  search_name();
  goto lable;
  getch();
  break;
  case 6:
  clrscr();
  search_roll();
  goto lable;
  getch();
  break;
  case 7:
  clrscr();
  count();
  goto lable;
  getch();
  break;
  case 8:
  exit(0);
  default:
  cout<<"invalid choice!!";
  }
  }while(c2!=9);
  clrscr();
  }

 void main()
 {
 clrscr();
 int c1,c2;
 char pass[10];
 Quiz Q;
 L:
 cout<<"      \t\t\t~~~*** HOME PAGE ***~~~\t      \n\n";
 cout<<"\n1.STUDENT";
 cout<<"\n2.ADMIN";
 cout<<"\n3.EXIT";
 cout<<"\nENTER YOUR CHOICE: ";
 cin>>c1;
 switch(c1)
 {
 case 1:
 clrscr();
 student();
 goto L;
 getch();
 break;
 case 2:
 clrscr();
 cout<<"\nEnter Password: ";
 gets(pass);
 if(strcmp(pass,"kanhav123")==0)
 {
 clrscr();
 adminpro();
 goto L;
 getch();
 }
 else
 {
 clrscr();
 cout<<"\nInvalid Password";
 getch();
 goto L;
 }
 break;
 case 3:
 exit(0);
 break;
 default:
 cout<<"\nInvalid choice!!";
 }
 getch();
 }












