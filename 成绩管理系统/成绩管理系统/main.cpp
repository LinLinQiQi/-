//
//  main.cpp
//  成绩管理系统
//
//  Created by 苏苏波波 on 16/5/22.
//  Copyright © 2016年 苏苏波波. All rights reserved.
//

#include <iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

typedef  struct Student
{
    int number;
    string name;
    int Mathscore;
    int Englishscore;
    int Cscore;
    int Physicscore;
    //struct Student *next;
}Student;

struct Degrad
{
    float Excellent=0;//>=90
    float good=0;//>=80
    float medium=0;//>=70
    float pass=0;//>=60
    float fail=0;//<60
}Class[4];

struct AvergeGrade
{
    float Aver=0;
    string name;
}lesson[4];


vector<Student> list;

bool cmp1(Student a,Student b)
{
    return a.number<b.number;
}

bool cmp2(Student a,Student b)
{
    float suma=(a).Mathscore+(a).Englishscore+(a).Cscore+(a).Physicscore;
    float sumb=(b).Mathscore+(b).Englishscore+(b).Cscore+(b).Physicscore;
    return sumb<suma;
}

bool cmp3(Student a,Student b)
{
    return a.name<b.name;
}

bool cmp4(AvergeGrade a,AvergeGrade b)
{
    return a.Aver>b.Aver;
}
int Menu()
{	int itemSelected;
    printf("1.录入每个学生的学号、姓名和各科考试成绩\n");
    printf("2.计算每门课程的平均分\n");
    printf("3.计算每个学生的平均分并输出\n");
    printf("4.按每个学生平均分从高到低排出名次表（学生排名）\n");
    printf("5.按每门课程平均分从高到低排出名次表（课程排名）\n");
    printf("6.按学号从小到大排出成绩表\n");
    printf("7.按姓名的字典顺序排出成绩表\n");
    printf("8.按学号查询学生排名及其考试成绩\n");
    printf("9.按姓名的字典顺序排出成绩表\n");
    printf("10.按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别的人数一级所占的百分比\n");
    printf("11.输出每个学生的学号、姓名、各科考试成绩\n");
    printf("0.Exit\n");
    printf("Please input your choice:\n");
    scanf("%d",&itemSelected);  //读入用户输入
    return itemSelected;
}
void AppendRecord()
{
    Student example;
    cout<<"请分别输入你的学号，名字，数学分数，英语分数，c语言分数，物理分数"<<endl;
    cin>>example.number>>example.name>>example.Mathscore>>example.Englishscore>>example.Cscore>>example.Physicscore;
    list.push_back(example);
}

void SortByAverge()
{
    sort(list.begin(),list.end(),cmp2);
}

void SortByNumber()
{
    sort(list.begin(),list.end(),cmp1);
}

void SortByName()
{
    sort(list.begin(),list.end(),cmp3);
}

void PrintScore()
{
    for(vector<Student>::iterator it=list.begin();it!=list.end();++it)
    {
        cout<<"学生学号："<<(*it).number<<endl;
        cout<<"学生姓名："<<(*it).name<<endl;
        cout<<"学生数学成绩"<<(*it).Mathscore<<endl;
        cout<<"学生英语成绩"<<(*it).Englishscore<<endl;
        cout<<"学生C语言成绩"<<(*it).Cscore<<endl;
        cout<<"学生物理成绩"<<(*it).Physicscore<<endl;
    }
}

void AverSumofScore()
{
    float MathSum;
    float EnglishSum;
    float CSum;
    float PhysicsSum;
    int cnt=0;
    for(vector<Student>::iterator it=list.begin();it!=list.end();++it)
    {
        cnt++;
        MathSum+=(*it).Mathscore;
        EnglishSum+=(*it).Englishscore;
        CSum+=(*it).Cscore;
        PhysicsSum+=(*it).Physicscore;
    }
    lesson[0].name="每个学生的数学平均分为：";
    lesson[0].Aver=MathSum/cnt;
    lesson[1].name="每个学生的英语平均分为：";
    lesson[1].Aver=EnglishSum/cnt;
    lesson[2].name="每个学生的C语言平均分为：";
    lesson[2].Aver=CSum/cnt;
    lesson[3].name="每个学生的物理平均分为：";
    lesson[3].Aver=PhysicsSum/cnt;
    cout<<"每个学生的数学平均分为："<<MathSum/cnt<<endl;
    cout<<"每个学生的英语平均分为："<<EnglishSum/cnt<<endl;
    cout<<"每个学生的C语言平均分为："<<CSum/cnt<<endl;
    cout<<"每个学生的物理平均分为："<<PhysicsSum/cnt<<endl;
}


void AverSumofScore1()
{
    sort(lesson,lesson+4,cmp4);
    for (int i=0; i<4; i++) {
        cout<<lesson[i].name<<lesson[i].Aver<<endl;
    }
}

void AverScoreOfperStudents()
{
    for(vector<Student>::iterator it=list.begin();it!=list.end();++it)
    {
        float sum=(*it).Mathscore+(*it).Englishscore+(*it).Cscore+(*it).Physicscore;
        cout<<"学生学号："<<(*it).number<<endl;
        cout<<"学生姓名："<<(*it).name<<endl;
        cout<<"学生数学英语C语言物理四门课的平均分为："<<sum/4<<endl;
        
    }
}

void SearchbyNum()
{
    int Num,cnt=0;
    cout<<"输入你想要查询的学生的学号"<<endl;
    cin>>Num;
    SortByAverge();
    for(vector<Student>::iterator it=list.begin();it!=list.end();++it)
    {
        cnt++;
        if((*it).number==Num)
        {
            cout<<"学生学号："<<(*it).number<<endl;
            cout<<"学生姓名："<<(*it).name<<endl;
            cout<<"学生数学成绩"<<(*it).Mathscore<<endl;
            cout<<"学生英语成绩"<<(*it).Englishscore<<endl;
            cout<<"学生C语言成绩"<<(*it).Cscore<<endl;
            cout<<"学生物理成绩"<<(*it).Physicscore<<endl;
            cout<<"该学生的排名为"<<cnt<<endl;
        }
    }
    
}

void SearchbyName()
{
    string Name;
    int cnt=0;
    cout<<"输入你想要查询的学生的姓名"<<endl;
    cin>>Name;
    for(vector<Student>::iterator it=list.begin();it!=list.end();++it)
    {
        cnt++;
       if((*it).name==Name)
       {
           cout<<"学生学号："<<(*it).number<<endl;
           cout<<"学生姓名："<<(*it).name<<endl;
           cout<<"学生数学成绩"<<(*it).Mathscore<<endl;
           cout<<"学生英语成绩"<<(*it).Englishscore<<endl;
           cout<<"学生C语言成绩"<<(*it).Cscore<<endl;
           cout<<"学生物理成绩"<<(*it).Physicscore<<endl;
           cout<<"该学生的排名为"<<cnt<<endl;
       }
    }
}

void StatisticAnalysis()
{
    int cnt=0;
    for(vector<Student>::iterator it=list.begin();it!=list.end();++it)
    {
        cnt++;
        if ((*it).Mathscore>=90) {
            Class[0].Excellent++;
        }else if((*it).Mathscore>=80)
            Class[0].good++;
        else if((*it).Mathscore>=70)
            Class[0].medium++;
        else if((*it).Mathscore>=60)
            Class[0].pass++;
        else if((*it).Mathscore>=0)
            Class[0].fail++;
        if ((*it).Englishscore>=90) {
            Class[1].Excellent++;
        }else if((*it).Englishscore>=80)
            Class[1].good++;
        else if((*it).Englishscore>=70)
            Class[1].medium++;
        else if((*it).Englishscore>=60)
            Class[1].pass++;
        else if((*it).Englishscore>=0)
            Class[1].fail++;
        if ((*it).Cscore>=90) {
            Class[2].Excellent++;
        }else if((*it).Cscore>=80)
            Class[2].good++;
        else if((*it).Cscore>=70)
            Class[2].medium++;
        else if((*it).Cscore>=60)
            Class[2].pass++;
        else if((*it).Cscore>=0)
            Class[2].fail++;
        if ((*it).Physicscore>=90) {
            Class[3].Excellent++;
        }else if((*it).Physicscore>=80)
            Class[3].good++;
        else if((*it).Physicscore>=70)
            Class[3].medium++;
        else if((*it).Physicscore>=60)
            Class[3].pass++;
        else if((*it).Physicscore>=0)
            Class[3].fail++;
    }
    cout<<"对于数学这门学科"<<endl;
    cout<<"优秀的人的百分比为："<<Class[0].Excellent/cnt*100<<"％"<<endl;
    cout<<"良好的人的百分比为："<<Class[0].good/cnt*100<<"％"<<endl;
    cout<<"中等的人的百分比为："<<Class[0].medium/cnt*100<<"％"<<endl;
    cout<<"及格的人的百分比为："<<Class[0].pass/cnt*100<<"％"<<endl;
    cout<<"不及格的人的百分比为："<<Class[0].fail/cnt*100<<"％"<<endl;
    cout<<"对于英语这门学科"<<endl;
    cout<<"优秀的人的百分比为："<<Class[1].Excellent/cnt*100<<"％"<<endl;
    cout<<"良好的人的百分比为："<<Class[1].good/cnt*100<<"％"<<endl;
    cout<<"中等的人的百分比为："<<Class[1].medium/cnt*100<<"％"<<endl;
    cout<<"及格的人的百分比为："<<Class[1].pass/cnt*100<<"％"<<endl;
    cout<<"不及格的人的百分比为："<<Class[1].fail/cnt*100<<"％"<<endl;
    cout<<"对于c语言这门学科"<<endl;
    cout<<"优秀的人的百分比为："<<Class[2].Excellent/cnt*100<<"％"<<endl;
    cout<<"良好的人的百分比为："<<Class[2].good/cnt*100<<"％"<<endl;
    cout<<"中等的人的百分比为："<<Class[2].medium/cnt*100<<"％"<<endl;
    cout<<"及格的人的百分比为："<<Class[2].pass/cnt*100<<"％"<<endl;
    cout<<"不及格的人的百分比为："<<Class[2].fail/cnt*100<<"％"<<endl;
    cout<<"对于物理这门学科"<<endl;
    cout<<"优秀的人的百分比为："<<Class[3].Excellent/cnt*100<<"％"<<endl;
    cout<<"良好的人的百分比为："<<Class[3].good/cnt*100<<"％"<<endl;
    cout<<"中等的人的百分比为："<<Class[3].medium/cnt*100<<"％"<<endl;
    cout<<"及格的人的百分比为："<<Class[3].pass/cnt*100<<"％"<<endl;
    cout<<"不及格的人的百分比为："<<Class[3].fail/cnt*100<<"％"<<endl;
    
}
int main(int argc, const char * argv[]) {
    int itemSelected;
    while((itemSelected=Menu())!=0)
    {
    switch(itemSelected)
        {	case 1: AppendRecord() ; break;                       //录入每个学生的学号、姓名和各科考试成绩
            case 2: AverSumofScore() ; break;                     //计算每门课程的平均分
            case 3: AverScoreOfperStudents() ; break;             //计算每个学生的平均分并输出
            case 4: SortByAverge();    break;                     //按每个学生平均分从高到低排出名次表（学生排名）
            case 5: AverSumofScore1();  break;                    //按每门课程平均分从高到低排出名次表（课程排名）
            case 6: SortByNumber();   break;                      //按学号从小到大排出成绩表
            case 7: SortByName();    break;                       //按姓名的字典顺序排出成绩表
            case 8: SearchbyNum();   break;                       //按学号查询学生排名及其考试成绩
            case 9: SearchbyName();    break;                  //按姓名查询学生排名及其考试成绩
            case 10:StatisticAnalysis();  break;               //按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别的人数一级所占的百分比
            case 11:PrintScore();      break;                  //输出每个学生的学号、姓名、各科考试成绩
            case 0:  ;                                      //退出系统
            default:  ;                                     //出错提示
        }
        cout<<"修改测试"<<endl;
    }
    return 0;
}
