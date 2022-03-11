#include <iostream>
#include <iomanip>
using namespace std;
class matrix
{
  int a[5][5];
  int row, col;
  public:
  void input ();
  void display ();
  matrix operator * (matrix o1);
  matrix operator + (matrix o1);
  matrix operator - (matrix o1);
  matrix transpose ();
    matrix (int row = 5, int col = 5)
  {
    (*this).row = row;
    (*this).col = col;
    for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
    a[i][j] = 0;
  }
};
void matrix::input ()
{
  for (int i = 0; i < row; i++)
    {
      cout << " Enter the elements of row "<< (i + 1)<<": ";
      for (int j = 0; j < col; j++)
      cin >> a[i][j];
    }
}
matrix matrix::operator * (matrix o1)
{
  cout <<"Multiplication of matrix 1st and 2nd\n";
  matrix o3;
 
  if (col == o1.row)
    {
      o3.row = row;
      o3.col = o1.col;
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < o1.col; j++)
         {
           o3.a[i][j] = 0;
           for (int k = 0; k < col; k++)
           o3.a[i][j] = o3.a[i][j] + a[i][k] * o1.a[k][j];
         }
      }
    }
  return o3;
}
 
matrix matrix::transpose ()
{
  matrix temp;
  temp.row = col;
  temp.col = row;
 
  for (int i = 0; i < temp.row; i++)
    for (int j = 0; j < temp.col; j++)
      temp.a[i][j] = a[j][i];
  return temp;
}
 
matrix matrix::operator + (matrix o1)
{
  cout <<"Addition of 1st and 3rd matrix\n";
  matrix o6;
  o6.row = row;
  o6.col = o1.col;
 
  if (row != o1.row || col != o1.col)
    throw "\n Incompatible matrix\n";
 
    for (int i = 0; i < row; i++)
    for (int j = 0; j < o1.col; j++)
    o6.a[i][j] = a[i][j] + o1.a[i][j];
    return o6;
}
matrix matrix::operator - (matrix o1)
{
  cout <<"Subtraction of 1st and 3rd matrix\n ";
  matrix o6;
  o6.row = row;
  o6.col = o1.col;
  if (row != o1.row || col != o1.col)
    throw "\nIncompatible matrix\n";
    for (int i = 0; i < row; i++)
    for (int j = 0; j < o1.col; j++)
    o6.a[i][j] = a[i][j] - o1.a[i][j];
    return o6;
}
void matrix::display ()
{
  cout <<"\n***** Your matrix is *****"<< endl;
  for (int i = 0; i < row; i++)
    {
      for (int j = 0; j < col; j++)
      cout << setw (3) << a[i][j];
      cout << endl;
    }
}
 
int main ()
{
  int c, x;
  char ch = 'y';
  matrix o1 (3, 4), o2 (4, 3), o3 (3, 3), o4 (4, 3), o5 (3, 4), o6 (3, 4);
 
  cout <<  "\n***MATRIX CLASS(EXCEPTION HANDLING)***\n";
  while (ch == 'y')
 
    {
      cout << " 1.Input . \n";
      cout << " 2.Multiplication of two matrices . \n";
      cout << " 3.Transpose of a matrix .\n";
      cout << " 4.Addition of two matrices . \n";
      cout << " 5.Subtraction of two matrices . \n\n";
      cout << " Enter your choice : ";
      cin >> x;
 
      switch (x)
    {
    case 1 :   o1.input ();
               o1.display ();
               o2.input ();
               o2.display ();
               o5.input ();
               o5.display ();
               break;
    case 2 : try
        {
         o3 = o1 * o2;
         o3.display ();
        }
    catch (const char *p)
         {
          cout << p;
         }
         break;
 	case 3:
        try
        {
          o4 = o1.transpose ();
          cout << "Transpose of matrix is:- " << endl;
          o4.display ();
        }
    	catch (const char *p)
     	{
        	cout << p;
      	}
        break;
	case 4:
      	try
      	{
        	o6 = o1 + o5;
        	o6.display ();
      	}
      	catch (const char *p)
      	{
      	  cout << p;
     	}
      	break;
	case 5:
      	try
      	{
     	   o6 = o1 - o5;
      	  o6.display ();
      	}
      	catch (const char *p)
      	{
      	  cout << p;
     	 }
     	 break;
    default:
     	{
		 	cout << " Doesn't find your choice,enter the correct choice ";
    		break;
		}
		cout << "DO YOU WANT TO CONTINUE: ";
    	cin >> ch;

		return 0;
	}
}
}

