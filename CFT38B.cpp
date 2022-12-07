#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb(x) push_back(x);
int main(void)
{
	string str;
	cin>>str;
	int i;int ans=0;
	for(i=0;i<str.size()-4;i++)
	{
		string now;
		int j;
		for(j=0;j<5;j++)
		{
			now.pb(str[i+j]);
		}
		if(now=="edgnb")ans++;
	}
	printf("%d\n",ans);
    //system("pause");
	return 0;
}