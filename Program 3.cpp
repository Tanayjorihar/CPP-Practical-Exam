#include<iostream>
#include<math.h>
using namespace std;
class Triangle
{
	private:
	float area;
	public:
	Triangle()
	{
		area=0;
	}
	void triangleArea(float a);
	void triangleArea(float a,float b);
	void triangleArea(float a,float b,float c);
	Triangle operator=(Triangle o2);
	int operator==(Triangle o2);
	void display()
	{
		cout<<"The area of triangle is: "<<area<<endl;
	}
};
	void Triangle::triangleArea(float a)
	{
		area= (sqrt(3)/4)*a*a;
		cout<<"Area of an equilateral triangle is: "<<area<<endl;
	}
	void Triangle::triangleArea(float a, float b)
	{
		area= 0.5*a*b;
		cout<<"Area of an isosceles triangle is: "<<area<<endl;
	}
	void Triangle::triangleArea(float a, float b, float c)
	{
		float s= (a+b+c)/2;
		float m=(s-a)*(s-b)*(s-c);
		area= sqrt(m);
		cout<<"Area of a scalene triangle is: "<<area<<endl;
	}
	Triangle Triangle::operator=(Triangle o2)
	{
		area=o2.area;
		return o2;
	}
	int Triangle::operator==(Triangle o2)
	{
		if(area==o2.area)
		return 1;
		else
		return 0;
	}
int main()
{
	Triangle o1,o2,o3,o4;
	o1.triangleArea(6);
	o2.triangleArea(8.7,5.2);
	o3.triangleArea(9,7,2);
	o4=o1;
	o4.display();
	o1.display();
	if(o1==o4)
	cout<<"\nArea is equal. "<<endl;
	else
	cout<<"\nArea is not equal. "<<endl;
	return 0;
}

