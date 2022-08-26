#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "m_time.h"
#include "head.h"

void clear_hcq(void);
void tjxsyhxx(void);
void save_data(void);

void gly_gui(void)
{
    printf("\033c");
    printf("\n        *********************管理员操作界面*********************\n");
    m_time();
    printf("\n---------------------------------------------------------------------\n");
    printf("*      1.添加学生用户信息          |      2.删除学生用户信息        *\n");
    printf("*-------------------------------------------------------------------*\n");
    printf("*      3.修改学生用户信息          |      4.查询学生用户信息        *\n");
    printf("*-------------------------------------------------------------------*\n");
    printf("*      5.查询学生成绩信息          |      6.录入学生考试成绩        *\n");
    printf("*-------------------------------------------------------------------*\n");
    printf("*      7.修改学生考试成绩          |      8.删除学生考试成绩        *\n");
    printf("*-------------------------------------------------------------------*\n");

    int xuhao;
    while(1)
    {
        printf("请管理员选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -1;
        }
        switch(xuhao)
        {
            case 1:
            {
                //添加学生用户信息
                tjxsyhxx();
            }
            break;
            case 2:
            {
                //删除学生用户信息
            }
            break;
            case 3:
            {
                //修改学生用户信息
            }
            break;
            case 4:
            {
                //查询学生用户信息
                show(stu_list);
            }
            break;
            case 5:
            {
                //查询学生成绩信息
            }
            break;
            case 6:
            {
                //录入学生考试成绩
            }
            break;
            case 7:
            {
                //修改学生考试成绩
            }
            break;
            case 8:
            {
                //删除学生考试成绩
            }
            break;
            default:
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
            break;
        }
    }
}

//添加学生用户信息
void tjxsyhxx(void)
{
    student_info s_i;
    printf("\033c");
    printf("\n      ******************管理员添加学生用户信息界面******************\n");
    m_time();
    printf("\n                   请管理员按照以下提示添加学生用户信息！");
    printf("\n--------------------------------------------------------------------------\n");
    printf("                            班级：");
    scanf("%s",s_i.s_class);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    printf("                            学号：");
    scanf("%s",s_i.s_son);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    printf("                            姓名：");
    scanf("%s",s_i.s_name);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    while(1)
    {
        printf("                            身份证号：");
        scanf("%s",s_i.s_idcard);
        clear_hcq();
        if(strlen(s_i.s_idcard) == 18)
        {
            printf("----------------------------------------------------------------------------\n");
            memcpy(s_i.s_pass,s_i.s_idcard+12,6);
            printf("                            密码：%s",s_i.s_pass);
            break;
        }
        printf("           %s身份证号输入错误，无法获取正确初始密码！请重新输入：\n",s_i.s_name);
    }
    printf("\n----------------------------------------------------------------------------\n");
    printf("                            手机号：");
    scanf("%s",s_i.s_number);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    push_back(stu_list,s_i);
    save_data();
    gly_gui();
}

//清空缓存区
void clear_hcq(void)
{
    while(getchar() != '\n');
}

//创建空链表
node* creat(void)
{
    node* n = (node*)malloc(sizeof(node));
    n->next = NULL;
    return n;
}

//存储信息
void save_data(void)
{
    FILE *fp = fopen("stu_info","wb");
    if(fp == NULL)
    {
        perror("fopen fail");
    }

    //遍历链表所有节点
    node* l = stu_list->next;
    while(l != NULL)
    {
        fwrite(&(l->data),sizeof(student_info),1,fp);
        l = l->next;
    }
    fclose(fp);
}

//在链表尾部插入节点
void push_back(node* l,elem_type data)
{
    //创建一个节点
    node* n = (node*)malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    //找到链表的尾节点
    while(l->next != NULL)
        l = l->next;
    //在尾部插入新节点
    l->next = n;
}

//打印链表中所有节点数据
void show(node* l)
{
    l = l->next;
    printf("\033c");
    printf("\n      ******************学生用户信息界面******************\n");
    m_time();
    printf("\n班级          学号       姓名             身份证号             密码         手机号");
    while(l != NULL)
    {
        printf("\n------------------------------------------------------------------------------------------\n");
        printf("%s      %s       %s        %s       %s      %s",l->data.s_class,l->data.s_son,l->data.s_name,l->data.s_idcard,l->data.s_pass,l->data.s_number);
        l = l->next;
    }
}