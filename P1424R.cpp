#include <iostream>
using namespace std;
int main()
{
	unsigned long long a,b,total=0,days=0;
	cin>>a>>b;
	a %= 7;	
	for(unsigned long long i=a;days<b;i++) 
	{
		i=i%7;
		days++;
		if(i==6 || i == 0) {
			continue;
		}
		total++;
	}
	cout<<total*250;
	return 0;
}
