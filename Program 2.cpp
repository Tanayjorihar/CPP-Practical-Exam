#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class student
{
   public:
   int Rollno,Year;
   char Name[20];
   char Class[20];
   double TotalMarks;
   void getinpt()
   {
     cout<<"Enter student details:- "<<endl;
     cout<<"\nEnter student roll number: ";
   cin>>Rollno;
   cout<<"Enter student year: ";
   cin>>Year;
   cout<<"Enter student name: ";
   cin>>Name;
   cout<<"Enter student class: ";
   cin>>Class;
   cout<<"Enter student total marks: ";
   cin>>TotalMarks;
   }
};
int main()
{  
student s1[5];
   char ch;
   for(int i=0;i<3;i++)
   s1[i].getinpt();
   ofstream f1;
   f1.open("C:\\Users\\22sho\\OneDrive\\Desktop\\C++\\helloworld\\prog1\\program1\\Student.txt");
   if(!f1)
   { 
     cout<<"Error in opening the read file!! ";
   exit(100);
   }
   for(int i=0;i<3;i++)
   {
     f1<<setw(5)<<s1[i].Rollno;
   f1<<setw(5)<<s1[i].Name;
   f1<<setw(5)<<s1[i].Class;
   f1<<setw(5)<<s1[i].Year;
   f1<<setw(5)<<s1[i].TotalMarks<<endl;
   }
   f1.close();
   ifstream f2;
   f2.open("C:\\Users\\22sho\\OneDrive\\Desktop\\C++\\helloworld\\prog1\\program1\\Student.txt");
   while(f2.get(ch));
     cout<<ch; 
   return 0;
}

