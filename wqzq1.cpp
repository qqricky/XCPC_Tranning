#include <bits/stdc++.h>
using namespace std;

int main()
{
	char c[20];
	int i=0;
	cout<<"\\\\";
	int cnt=0;
	while(i<19)
	{
		c[i++]=getchar();
		cout<<++cnt<<"\n";
	}
	c[19]='\n';
	puts(c);
    system("pause");
	return 0;
 }
