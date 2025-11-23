#include <iostream>
using namespace std;
int sum(int x,int y)
	{
	return x + y;
	
    }
int diff(int x,int y)
    {
    	return x - y;	
	}

int main ()
{
	int num1,num2;
	cout <<" Enter two integers:";
	cin >> num1 >> num2;
	cout << "Sum: " << sum(num1,num2) << endl;
	cout << "Difference: " << diff(num1,num2) <<endl;
	return 0;
}
