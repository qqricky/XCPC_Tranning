#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#define count 600
struct Workerdef
{
	char num[10];//编号
	char name[20];//姓名
	double baspay;//基本工资
	double pospay;//岗位工资
	double perpay;//绩效工资
	double reward;//奖励金额
	double housepay;//住房补贴
	double publish;//迟到早退罚款
	double tax;//扣税
	double duepay;//应发工资
	double realpay;//实发工资
	struct Workerdef *next;
};
struct Departmentdef
{
	char depnum[10];//部门编号
	char depname[20];//部门名称
	int workernum;//部门员工人数
	struct Workerdef worker[30];//部门员工信息
}  department [20];
struct Workerdef *CreateList()
{
    struct Workerdef *pointer,*head,*q;
    struct Workerdef temp;
    FILE *fp;
    pointer=(struct Workerdef *)malloc(sizeof(struct Workerdef ));
    head = pointer;
    q = pointer;
    q->next = NULL;
    fp=fopen("Datalibrary.txt","rb");
    while(fread(&temp,sizeof(struct Workerdef),1,fp)!=0)
    {
		pointer=(struct Workerdef*)malloc(sizeof(struct Workerdef));
    	pointer->baspay=temp.baspay;
    	pointer->pospay=temp.pospay;
    	pointer->perpay=temp.perpay;
    	pointer->reward=temp.reward;
    	pointer->housepay=temp.publish;
    	pointer->tax=temp.tax;
    	pointer->duepay=temp.duepay;
    	pointer->realpay=temp.realpay;
    	q->next=pointer;
    	q=q->next;
    }
    q->next=NULL;//标志链表的结束
    fclose(fp);
    return head;
};
void Workerenter(int a)//ok
{
	int depnumber=a;
	int enternumber;
	char ch[20];
	enternumber=Countoutput(department[depnumber].depname);
	char workernum[10];
	printf("请输入想要录入员工的编号：");
	scanf("%s",workernum);
	for(int j=0;j<=enternumber;j++)
	{
		if(strcmp(department[depnumber].worker[j].num,workernum)==0)
		{
			printf("此编号已经存在，请勿重复录入\n");
			return;
		}
	}
	strcpy(department[depnumber].worker[enternumber].num,workernum);
	printf("请输入员工的姓名：");
	scanf("%s",department[depnumber].worker[enternumber].name);
	printf("请输入员工的基本工资：");
	scanf("%lf",&department[depnumber].worker[enternumber].baspay);
	printf("请输入员工的岗位工资：");
	scanf("%lf",&department[depnumber].worker[enternumber].pospay);
	printf("请输入员工的绩效工资：");
	scanf("%lf",&department[depnumber].worker[enternumber].perpay);
	printf("请输入员工的奖励金额：");
	scanf("%lf",&department[depnumber].worker[enternumber].reward);
	printf("请输入员工的住房补贴：");
	scanf("%lf",&department[depnumber].worker[enternumber].housepay);
	printf("请输入员工的罚款：");
	scanf("%lf",&department[depnumber].worker[enternumber].publish);

	department[depnumber].worker[enternumber].duepay=
	Duepay(department[depnumber].worker[enternumber].baspay,
	department[depnumber].worker[enternumber].pospay
	,department[depnumber].worker[enternumber].perpay
	,department[depnumber].worker[enternumber].reward
	,department[depnumber].worker[enternumber].housepay
	,department[depnumber].worker[enternumber].publish);

	department[depnumber].worker[enternumber].tax=Tax(
	department[depnumber].worker[enternumber].baspay,
	department[depnumber].worker[enternumber].pospay
	,department[depnumber].worker[enternumber].perpay
	,department[depnumber].worker[enternumber].reward
	,department[depnumber].worker[enternumber].housepay
	,department[depnumber].worker[enternumber].publish);

	department[depnumber].worker[enternumber].realpay=Realpay(
	department[depnumber].worker[enternumber].baspay,
	department[depnumber].worker[enternumber].pospay
	,department[depnumber].worker[enternumber].perpay
	,department[depnumber].worker[enternumber].reward
	,department[depnumber].worker[enternumber].housepay
	,department[depnumber].worker[enternumber].publish
	);
	printf("录入成功");
	enternumber+=1;
	Countinput(department[depnumber].depname,enternumber);
	Dataenter();
}
void printt(struct Workerdef *head)
{
	struct Workerdef* pointer;
	pointer=head->next;
	while(pointer!=NULL)
	{
	printf("%lf",department[depnumber].worker[enternumber].baspay);
	printf("%lf",department[depnumber].worker[enternumber].pospay);
	printf("%lf",department[depnumber].worker[enternumber].perpay);
	printf("%lf",department[depnumber].worker[enternumber].housepay);
	printf("%lf",department[depnumber].worker[enternumber].reward);
	printf("%lf",department[depnumber].worker[enternumber].tax);
	printf("%lf",department[depnumber].worker[enternumber].publish);
	printf("%lf",department[depnumber].worker[enternumber].duepay);
	printf("%lf",department[depnumber].worker[enternumber].realpay);
	printf("lf",pointer->baspay);
	printf("lf",pointer->pospay);
	printf("lf",pointer->perpay);
	printf("lf",pointer->housepay);
	printf("lf",pointer->reward);
	printf("lf",pointer->tax);
	printf("lf",pointer->publish);
	printf("lf",pointer->duepay);
	printf("lf",pointer->realpay);
	}
}
void printt(struct Workerdef *pointer)
{
	printf("lf",pointer->baspay);
	printf("lf",pointer->pospay);
	printf("lf",pointer->perpay);
	printf("lf",pointer->housepay);
	printf("lf",pointer->reward);
	printf("lf",pointer->tax);
	printf("lf",pointer->publish);
	printf("lf",pointer->duepay);
	printf("lf",pointer->realpay);
}
void f1()//部门
{
	int numberdep,i;
	char depname[20] ;
	printf("请输入你想要查找的部门：");
	scanf("%s",depname);
	for(i=0;i<=19;i++)
	{
		if(strcmp(department[i].depname,depname)==0)
		{
			numberdep=i;
			break;
		}
		if(i==19)
		{
			printf("没有此部门的信息");
			return;
		}
	}
}
void f2()//编号
{
	int depnumber;
	int enternumber,i;
	char ch[20];
	enternumber=Countoutput(department[depnumber].depname);
	char workernum[10];
	printf("请输入编号：");
	scanf("%s",workernum);
	for(i=0;i<=enternumber;i++)
	{
		if(strcmp(department[depnumber].worker[i].num,workernum)==1)
		{
			printf("%s",department[depnumber]);
		}
	}
}
void f3()//基本工资
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].baspay>=min&&department[i].worker[i].baspay<=max)
		{
			struct Workerdef * pt=&department[i].worker[i];
			printt(pt);
		}
	}
}
void f4()//岗位工资
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].pospay>=min&&department[i].worker[i].pospay<=max)
		{
			printf("%d",&department[i].worker[i].pospay);
		}
	}
}
void f5()//绩效工资
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].perpay>=min&&department[i].worker[i].perpay<=max)
		{
			printt(Workerdef.next);
		}
	}
}
void f6()//奖金
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].reward>=min&&department[i].worker[i].reward<=max)
		{
			printt(Workerdef.next);
		}
	}
}
void f7()//住房补贴
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].housepay>=min&&department[i].worker[i].housepay<=max)
		{
			printt(Workerdef.next);
		}
	}
}
void f8()//应发工资
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].duepay>=min&&department[i].worker[i].duepay<=max)
		{
			printt(Workerdef.next);
		}
	}
}
void f9()//实发工资
{
	int min,max,i;
	scanf("%d%d",&min,&max);
	for(i=1;i<count;i++)
	{
		if(department[i].worker[i].realpay>=min&&department[i].worker[i].realpay<=max)
		{
			printt(Workerdef.next);
		}
	}
}
void datasearch()
{
	int i,num,nf;
	printf("\n       欢迎使用工资信息查询系统\n");
    printf("\n----------------------------------------------\n");
    printf("\n          1.按编号查询\n");
    printf("\n          2.按部门查询\n");
    printf("\n          3.按基本工资查询\n");
    printf("\n          4.按岗位工资查询\n");
    printf("\n          5.按绩效工资查询");
    printf("\n          6.按奖金查询");
    printf("\n          7.按住房补贴查询");
    printf("\n          8.按应发工资查询");
    printf("\n          9.按实发工资查询");
    printf("\n          0.退出查询\n");
    printf("\n----------------------------------------------\n");
    scanf("%d",num);
	switch(num)
	{
		for(i=1;i<=num;i++)
		{
			scanf("%d",&nf);
			switch (nf)
			case 1:
				f1();
			case 2:
				f2();
			case 3:
				f3();
			case 4:
				f4();
			case 5:
				f5();
			case 6:
				f6();
			case 7:
				f7();
			case 8:
				f8();
			case 9:
				f9();
		}
	}
}
