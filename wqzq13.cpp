#include<bits/stdc++.h>
using namespace std;      

struct team
{
	char name[31];
	int grade;  //得分 
	int goal_dif; //净胜球
	int goal ; //进球 
};
bool cmp(team x, team y)
{
    if(x.grade==y.grade){
        if(x.goal_dif==y.goal_dif){
            return x.goal<y.goal;
        }
        return x.goal_dif<y.goal_dif;
    }
    return x.grade<y.grade;
}
int main(void)
{
	int n; 
	cin>>n;
	team *p=(team*)malloc(sizeof(team)*n);
	for(int i=0;i<n;i++)
		cin>>p[i].name;
	for(int i=0;i<n;i++)  			//初始化 
	{
		p[i].grade=p[i].goal=p[i].goal_dif=0;
	}
	for(int i=0;i<n*(n-1)/2;i++)
	{
		char team1[31],team2[31],tmp2;
		int goal1,goal2;
		
		int j=-1;					//输入 team1 ，以'-'结束 
		do{
			cin>>team1[++j];
		}while(team1[j]!='-');
		team1[j]='\0';
		
		cin>>team2;
		cin>>goal1>>tmp2>>goal2;
		
		int num1,num2;				//确定 team1,team2在结构体数组中的位置 
		for(int i=0;i<n;i++)
			if(strcmp(p[i].name,team1)==0)
				{num1=i; break;	}
		for(int i=0;i<n;i++)
			if(strcmp(p[i].name,team2)==0)
				{num2=i;break;}
				
		p[num1].goal+=goal1;		//记录加分 
		p[num1].goal_dif+=goal1-goal2;
		p[num2].goal+=goal2;
		p[num2].goal_dif+=goal2-goal1;
		if(goal1>goal2)
		 	p[num1].grade+=3;
		else if(goal2>goal1)
			p[num2].grade+=3;
		else {
			p[num2].grade++;
			p[num1].grade++;}
	}
	
	
    sort(p,p+n,cmp);
	// for(int i=0;i<n-1;i++)			//按得分，净胜球，进球排序 
	// {
	// 	for(int j=i+1;j<n;j++)
	// 	{
	// 		team tmp;
	// 		if(p[i].grade>p[j].grade) continue;
	// 		else if(p[i].grade==p[j].grade)
	// 		{
	// 			if(p[i].goal_dif>p[j].goal_dif) continue;
	// 			else if(p[i].goal_dif==p[j].goal_dif)
	// 			{
	// 				if(p[i].goal>p[j].goal) continue;
	// 			}
	// 		}
	// 		tmp=p[i];
	// 		p[i]=p[j];
	// 		p[j]=tmp;
	// 	}
	// }
	for(int i=0;i<n/2-1;i++)		//对前n/2按字典序排序 
	{
		for(int j=0;j<n/2;j++)
		 	if(strcmp(p[i].name,p[j].name)>0)
		 	{
		 		team tmp;
		 		tmp=p[i];
		 		p[i]=p[j];
		 		p[j]=tmp;
			 }
	}
	for(int i=0;i<n/2;i++)		//输出 
		cout<<p[i].name<<endl;
	free(p);
	return 0;
}