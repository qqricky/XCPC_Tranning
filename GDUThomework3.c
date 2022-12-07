#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ll long long
#define MaxStudent 100
#define MaxMajor 10
#define MaxClass 10
#define MaxGrade 4
const int N=1e5+10;
//总成绩和绩点，绩点=学业成绩*0.7+课外表现分*0.3
struct student
{
    char name[10];
    int major;//专业，用专业编号表示
    int clas;//班级
    int grade;//年级
    int id;//学号
    int cur1;//课程1成绩
    int cur2;//课程2成绩
    int cur3;//课程3成绩
    int curtot;//三门课程总成绩
    int curout;//课外课程成绩
    double gpa;//平均绩点=学业成绩*0.7+课外表现分*0.3  curtot*0.7+curout*0.3
};
#define student struct student
student stu[N];
int tot=0;
int cmpClassGpa(const void* aa,const void * bb){
    student* a=(student*)aa;
    student* b=(student*)bb;
    if(a->clas==b->clas)return a->gpa<b->gpa;
    return a->clas<b->clas;
}
int cmpGPA(const void* aa,const void * bb){
    student* a=(student*)aa;
    student* b=(student*)bb;
    return a->gpa<b->gpa;
}
void outputStu(int pos){
    printf("******************\n");
    printf("name: %s\n",&stu[pos].name);
    printf("major: %d clas: %d grade: %d\n",stu[pos].major,stu[pos].clas,stu[pos].grade);
    printf("ID: %d\n",stu[pos].id);
    printf("scholastic attainment:\n");
    printf("cur1 :%d cur2 :%d cur3 :%d curout :%d\n",stu[pos].cur1,stu[pos].cur2,stu[pos].cur3,stu[pos].curout);
    printf("gpa:%.4f\n",stu[pos].gpa);
    printf("******************\n\n");
}
//2显示所有学生信息
void outputAllStu(){
    for(int i=1;i<=tot;i++){
        outputStu(i);
    }
}
//3-1
int findStuByClass(int clas){
    int flag=0;
    for(int i=1;i<=tot;i++){
        if(stu[i].clas==clas){
            if(!flag){
                printf("succsesfully find the student\n");
                flag=1;
            }
            outputStu(i);
        }
    }
    if(flag)return 1;
    printf("can't find such student\n");
    return 0;
}
//3-2
int findStuByGrade(int grade){
    int flag=0;
    for(int i=1;i<=tot;i++){
        if(stu[i].grade==grade){
            if(!flag){
                printf("succsesfully find the student\n");
                flag=1;
            }
            outputStu(i);
        }
    }
    if(flag)return 1;
    printf("can't find such student\n");
    return 0;
}
//3-3
int findStuById(int id){
    int flag=0;
    for(int i=1;i<=tot;i++){
        if(stu[i].id==id){
            if(!flag){
                printf("succsesfully find the student\n");
                flag=i;
            }
            outputStu(i);
        }
    }
    if(flag)return 1;
    printf("can't find such student\n");
    return 0;
}
//3-4
int findStuByName(char name[]){
    int flag=0;
    for(int i=1;i<=tot;i++){
        if(!strcmp(stu[i].name,name)){
            if(!flag){
                printf("succsesfully find the student\n");
                flag=1;
            }
            outputStu(i);
        }
    }
    if(flag)return 1;
    printf("can't find such student\n");
    return 0;
}
//3-5
int findStuByMultyParameter(int clas,int grade){
    int flag=0;
    for(int i=1;i<=tot;i++){
        if(stu[i].clas==clas&&stu[i].grade==grade){
            if(!flag){
                printf("succsesfully find the student\n");
                flag=1;
            }
            outputStu(i);
        }
    }
    if(flag)return 1;
    printf("can't find such student\n");
    return 0;
}
//查找学生
void findstu(){
    printf("*************************************\n");
    printf("请输入需要的查找方式：\n");
    printf("1:By class\n2:By Grade\n3:By ID\n4:ByName\n5:By class&grade\n");
    printf("*************************************\n");
    int var;
    scanf("%d",&var);
    int x;
    switch (var)
    {
    case 1:
        printf("enter class\n");
        scanf("%d",&x);
        findStuByClass(x);
        break;
    case 2:
        printf("enter grade\n");
        scanf("%d",&x);
        findStuByGrade(x);
        break;
    case 3:
        printf("enter id\n");
        scanf("%d",&x);
        findStuById(x);
        break;
    case 4:
        printf("enter name\n");
        char s[10];
        scanf("%s",&s);
        findStuByName(s);
        break;
    case 5:
        printf("enter class grade\n");
        int y;
        scanf("%d",&x,&y);
        findStuByMultyParameter(x,y);
        break;
    default:
        break;
    }
}
int modifyStu(int id){
    printf("the student's informations are as follow\n");
    id=findStuById(id);
    if(!id)return 0;
    printf("请重新输入该学生的全部信息\n");
    printf("请输入学生信息，格式：姓名 年级 班级 学号 专业编号\n成绩1 成绩2 成绩3 课外成绩\n");
    scanf("%s %d %d %d %d",&stu[id].name,&stu[id].grade,&stu[id].clas,&stu[id].id,&stu[id].major);
    scanf("%d %d %d %d",&stu[id].cur1,&stu[id].cur2,&stu[id].cur3,&stu[id].curout);
    stu[id].curtot=stu[id].cur1+stu[id].cur2+stu[id].cur3;
    stu[id].gpa=stu[id].curtot*0.7+stu[id].curout*0.3;
    return 1;
}
//6-1 按专业统计绩点
void countByMajor(){
    double cnt[MaxMajor+1]={};
    int num[MaxMajor+1]={};
    for(int i=1;i<=tot;i++){
        cnt[stu[i].major]+=stu[i].gpa;
        num[stu[i].major]++;
    }
    for(int i=1;i<=MaxMajor;i++){
        if(num[i]==0){
            printf("major%d has no student\n",i);
            continue;
        }
        cnt[i]/=num[i];
        printf("major%d's average GPA:%.3f\n",i,cnt[i]);
    }
}
//6-2 按班统计绩点
void countByClass(){
    double cnt[MaxClass+1]={};
    int num[MaxClass+1]={};
    for(int i=1;i<=tot;i++){
        cnt[stu[i].clas]+=stu[i].gpa;
        num[stu[i].clas]++;
    }
    for(int i=1;i<=MaxClass;i++){
        if(num[i]==0){
            printf("clas%d has no student\n",i);
            continue;
        }
        cnt[i]/=num[i];
        printf("class%d's average GPA is:%.3f\n",i,cnt[i]);
    }
}
//6-3 按区间统计绩点情况
void countByRange(){
    int cntt[5]={};//100- 100-150 150-200 200+
    for(int i=1;i<=tot;i++){
        //printf("%.5f\n",stu[i].gpa);
        if(stu[i].gpa>=200.0){
            cntt[1]++;
        }
        else if(stu[i].gpa>=150.0){
            cntt[2]++;
        }
        else if(stu[i].gpa>=100.0){
            cntt[3]++;
        }
        else{
            cntt[4]++;
        }
    }
    printf("There are %d students in range [200,inf)\n",cntt[1]);
    printf("There are %d students in range [150,200)\n",cntt[2]);
    printf("There are %d students in range [100,150)\n",cntt[3]);
    printf("There are %d students in range [0,100)\n",cntt[4]);
}
//5学生信息统计
void countStu(){
    printf("*************************************\n");
    printf("请输入需要的学生信息统计方式\n");
    printf("1:By major\n2:By class\n3:By range\n");
    printf("*************************************\n");
    int var;
    scanf("%d",&var);
    int x;
    switch (var)
    {
    case 1:
        countByMajor();
        break;
    case 2:
        countByClass();
        break;
    case 3:
        countByRange();
        break;
    default:
        break;
    }
}
void del(int pos){
    for(int i=pos;i<tot;i++){
        stu[i]=stu[i+1];
    }
    tot--;
}
//4/7 学生信息修改	：指定学生记录，实现按条件批量删除记录
void changeStu(){
    int var;
    printf("*************************************\n");
    printf("Please enter the delete type\n");
    printf("1: class\n2:name\n3:gap<=60\n");
    printf("*************************************\n");
    scanf("%d",&var);
    switch (var)
    {
    case 1:
        int cls;
        printf("please enter the clase number\n");
        scanf("%d",&cls);
        for(int i=1;i<=tot;i++){
            if(stu[i].clas==cls){
                del(i);
                i--;
            }
        }
        break;
    case 2:
        char na[10];
        printf("please enter name");
        scanf("%s",&na);
        for(int i=1;i<=tot;i++){
            if(!strcmp(na,stu[i].name)){
                del(i);
                i--;
            }
        }
        break;
    case 3:
        for(int i=1;i<=tot;i++){
            if(stu[i].gpa<=60){
                del(i);
                i--;
            }
        }
        break;
    default:
        printf("invalid input!\n");
        break;
    }
    printf("删除成功！\n");
}
//8 备份文件：将 stu.txt 内容复制到备份文件 backup.txt 中。
void backup(){
    FILE *fp=fopen("backup.txt","w");
    for(int i=1;i<=tot;i++){
        fprintf(fp,"%s %d %d %d %d\n",stu[i].name,stu[i].grade,stu[i].clas,stu[i].id,stu[i].major);
        fprintf(fp,"%d %d %d %d\n",stu[i].cur1,stu[i].cur2,stu[i].cur3,stu[i].curout);
    }
    fclose(fp);
    printf("备份成功！\n");
}
//从student.txt中读入信息，完成对系统的初始化。
void init(){
    FILE *fp=fopen("student.txt","r");
    int m;
    if(fp==NULL){
        exit(0);
    }
    fscanf(fp,"%d",&m);
    for(;++tot<=m;){
        fscanf(fp,"%s %d %d %d %d",&stu[tot].name,&stu[tot].grade,&stu[tot].clas,&stu[tot].id,&stu[tot].major);
        fscanf(fp,"%d %d %d %d",&stu[tot].cur1,&stu[tot].cur2,&stu[tot].cur3,&stu[tot].curout);
        stu[tot].curtot=stu[tot].cur1+stu[tot].cur2+stu[tot].cur3;
        stu[tot].gpa=stu[tot].curtot*0.7+stu[tot].curout*0.3;
    }
    tot--;
    printf("初始化了%d个学生\n",tot);
}
//5 追加学生信息：在stu.txt中追加新的记录
void addStu(){
    tot++;
    printf("请输入学生信息，格式：姓名 年级 班级 学号 专业编号\n成绩1 成绩2 成绩3 课外成绩\n");
    scanf("%s %d %d %d %d",&stu[tot].name,&stu[tot].grade,&stu[tot].clas,&stu[tot].id,&stu[tot].major);
    scanf("%d %d %d %d",&stu[tot].cur1,&stu[tot].cur2,&stu[tot].cur3,&stu[tot].curout);
    stu[tot].curtot=stu[tot].cur1+stu[tot].cur2+stu[tot].cur3;
    stu[tot].gpa=stu[tot].curtot*0.7+stu[tot].curout*0.3;
    FILE *fp=fopen("backup.txt","w");
    int i=tot;
    fprintf(fp,"%s %d %d %d %d\n",stu[i].name,stu[i].grade,stu[i].clas,stu[i].id,stu[i].major);
    fprintf(fp,"%d %d %d %d\n",stu[i].cur1,stu[i].cur2,stu[i].cur3,stu[i].curout);
    fclose(fp);
}
//9 奖学金：将每个班的学生绩点排序，前十位可以获得奖学金。
void getRank(){
    qsort(stu+1,tot,sizeof(stu[0]),cmpClassGpa);
    int num[MaxClass+1]={};
    printf("Scholarship Information:\n");
    for(int i=1;i<=tot;i++){
        if(stu[i].clas!=stu[i-1].clas){
            printf("****************\n");
            printf("\n******");
            printf("class%d \n:",stu[i].clas);
        }
        if(num[stu[i].clas]<10){
            num[stu[i].clas]++;
            printf("%s\n",&stu[i].name);
        }
    }
}
// void read_text(const char* file_name)
// {
// 	char line[1024]={0};
// 	FILE *file = fopen(file_name,"rt");
// 	if(!file)
// 		return;
// 	while(1)
// 	{
// 		//文件读取结束
// 		if(EOF == fscanf(file,"%s",line))
// 			break;
// 		printf("%s\n",line);
// 	}
// 	fclose(file);
 
// }
int main()
{
    //freopen("TestCase.in","r",stdin);
    // freopen("TestCase.out","w",stdout);
    //解决windows终端中文乱码问题
    #if defined(_WIN16) || defined(_WIN32) || defined(_WIN64)
        // change code page，use utf-8
        system("chcp 65001");
    #endif
    init();
    while(1){
        printf("*************************************\n");
        puts("Please enter the number below to intend what you are going to do\n");
        printf("1: 显示全部学生信息\n");
        printf("2：查询学生信息\n");
        printf("3: 删除学生信息\n");
        printf("4: 追加学生信息\n");
        printf("5: 学生信息统计\n");
        printf("6: 学生信息修改\n");
        printf("7: 奖学金统计\n");
        printf("8: 备份文件\n");
        printf("9: 退出系统\n");
        printf("*************************************\n");
        int var;
        scanf("%d",&var);
        switch (var)
        {
        case 1:
            outputAllStu();
            break;
        case 2:
            findstu();
            break;
        case 3:
            changeStu();
            break;
        case 4:
            addStu();
            break;
        case 5:
            countStu();
            break;
        case 6:
            modifyStu(1);
            break;
        case 7:
            getRank();
            break;
        case 8:
            backup();
            break;
        case 9:
            goto end;
        default:
            printf("invalid input!\n");
            break;
        }
    }
    end:;
    system("pause");
    return 0;
}
/*demand
（1）建立文件，把学生信息保存到文件stu.txt中，输入学生基本信息、课外表现分和各科成绩信息，计算总成绩和绩点，绩点=学业成绩*0.7+课外表现分*0.3
专业	班级	姓名	高数	英语	语文	学业总成绩	课外表现分	绩点
网络	21-1	张三	100	33	90		90	
	
（2） 显示全部学生信息
（3）查询学生信息
按单字段条件查询，例如：按班级查询
按多字段查询，例如：按班级和姓名查询
（4）学生信息删除	：删除指定学生记录，实现按条件批量删除记录
（5）追加学生信息：在stu.txt中追加新的记录
（6） 学生信息统计:
按专业统计绩点
按班统计绩点
按区间统计绩点情况，区间值自己设定，例如：60分-69分共10人，70分-79分共8人……	
（7）学生信息修改	：指定学生记录，实现按条件批量删除记录
（8）备份文件：将 stu.txt 内容复制到备份文件 backup.txt 中。

2)奖学金
（1）绩点排序
（2）显示获奖名单：每班绩点前10名可获得奖学金

3)不同的模块都要有出错处理，并能给出出错提示。如输入数据错误，文件操作错误等等。 
4)以上各个功能均要编写为子函数形式，程序有良好的注释说明，由主函数调用实现。 
5)界面设计：应提供一个界面来调用各个功能,调用界面和各个功能的操作界面应尽可能清晰美观。 例如：设置主菜单，调用各个功能
*/