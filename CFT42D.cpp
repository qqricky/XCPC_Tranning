#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int dp[4002][4002][2];
int main(void)
{
	string str1,str2;
	cin>>str1>>str2;
	int ling1=0;
	int ling2=0;
	int i;
	for(i=0;i<str1.size();i++)if(str1[i]=='0')ling1++;
	for(i=0;i<str2.size();i++)if(str2[i]=='0')ling2++;
	int ans1=min(ling1,str1.size()-ling1);
	ans1=max(ling2,str2.size()-ling2);
	int ans2=1;
	for(i=1;i<str1.size();i++)
	{
		if(str1[i]!=str[i-1])ans2++;
	}
	int ans3=1;
	for(i=1;i<str2.size();i++)
	{
		if(str2[i]!=str2[i-1])ans3++;
	}
	ans2=min(ans2,ans3)+1;
	if(ans1<ans2)
	{
		if(ans1==ling1||ans1==ling2)
		{
			int i;
			for(i=1;i<=ans1;i++)printf("0");
		}
		else
		{
			int i;
			for(i=1;i<=ans1;i++)printf("1");
		}
	}
	else
	{
		if(ans2==ans3+1)
		{
			if(str2[0]=='0')
			{
				int i;
				for(i=1;i<=ans2;i++)
				{
					if(i%2==1)printf("0");
					else printf("1");
				}
			}
			else
			{
				int i;
				for(i=1;i<=ans2;i++)
				{
					if(i%2==1)printf("1");
					else printf("0");
				}
			}
		}
		else
		{
			if(str1[0]=='0')
			{
				int i;
				for(i=1;i<=ans2;i++)
				{
					if(i%2==1)printf("0");
					else printf("1");
				}
			}
			else
			{
				int i;
				for(i=1;i<=ans2;i++)
				{
					if(i%2==1)printf("1");
					else printf("0");
				}
			}
		}
	}
    system("pause");
}
