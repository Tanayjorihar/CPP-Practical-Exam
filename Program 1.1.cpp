

#include<iostream>
#include<iomanip>
using namespace std;
class Matrix
{
	private:
	int a[6][6];
	int row, col;
	public:
	Matrix(int row=5, int col=5)
	{
		(*this).row=row;
		(*this).col=col;
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			a[i][j]=0;
		}
	}
void input();
void display();
Matrix matrixadd(Matrix o1);
Matrix matrixsub(Matrix o1);
Matrix matrixmultiply(Matrix o1);
Matrix matrixtranspose();
};
void Matrix::input()
{
	for(int i=0; i<row; i++)
	{
		cout<<"Enter the elements of row "<<(i+1)<<" : ";
		for(int j=0; j<col; j++ )
		cin>>a[i][j];
	}
}
void Matrix::display()
{
	cout<<endl;for(int i=0; i<row; i++)
{
	for(int j=0; j<col; j++ )
	cout<<setw(3)<<a[i][j];
	cout<<endl;
}
	cout<<endl;
}
Matrix Matrix::matrixadd(Matrix o1)
{
	Matrix o3;
	o3.row=row;
	o3.col=col;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++ )
		o3.a[i][j]=a[i][j]+o1.a[i][j];
	}
	return o3;
}
Matrix Matrix::matrixsub(Matrix o1)
{
	Matrix o3;
	o3.row=row;
	o3.col=col;
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++ )o3.a[i][j]=a[i][j]-o1.a[i][j];
	}
	return o3;
}
	Matrix Matrix::matrixtranspose()
{
	Matrix temp;
	temp.row=col;
	temp.col=row;
	for(int i=0; i<temp.row; i++)
{
	for(int j=0; j<temp.col; j++ )
	temp.a[i][j]=a[j][i];
}
return temp;
}
Matrix Matrix::matrixmultiply(Matrix o1)
{
	Matrix o7;
	o7.row=row;
	o7.col=o1.col;
	if(col==o1.row)
	{
		for(int i=0; i<row; i++)
		{
			for(int j=0; j<o1.col; j++ )
			{
				o7.a[i][j]=0;for(int k=0;k<col;k++)
				o7.a[i][j]=o7.a[i][j]+a[i][k]*o1.a[k][j];
			}
		}
	}
	return o7;
}
int main()
{
	Matrix o1(4,3) ,o2(4,3), o3(4,3), o4(4,3), o5(3,4), o6(3,4), o7(3,3), o8(3,4);
	cout<<"Enter the elements of first matrix:- "<<endl;
	o1.input();
	o1.display();
	cout<<"\nEnter the elements of second matrix:- "<<endl;
	o2.input();
	o2.display();
	cout<<"\nEnter the elements of third matrix:- "<<endl;
	o8.input();
	o8.display();
	cout<<"\nMultiplication of the two matrix are: ";
	o7=o1.matrixmultiply(o8);
	o7.display();
	cout<<"\nAddition of the two matrix are: ";
	o3=o1.matrixadd(o2);
	o3.display();
	cout<<"\nSubtraction of the two matrix are: "<<endl;
	o4=o1.matrixsub(o2);
	o4.display();
	cout<<"\nTranspose of the first matrix is: "<<endl;o5=o1.matrixtranspose();
	o5.display();
	cout<<"\nTranspose of the second matrix is: "<<endl;
	o6=o2.matrixtranspose();
	o6.display();
	return 0;
}

