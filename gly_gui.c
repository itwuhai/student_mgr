#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "m_time.h"
#include "head.h"

void clear_hcq(void);
void tjxsyhxx(void);
void save_data(void);
void delete_xs_info(void);

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
                delete_xs_info();
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
    s_i.s_is_cj = 0;
    printf("\n----------------------------------------------------------------------------\n");
    printf("                            手机号：");
    scanf("%s",s_i.s_number);
    clear_hcq();
    printf("----------------------------------------------------------------------------\n");
    push_back(stu_list,s_i);
    save_data();
    gly_gui();
}

//用学号删除学生信息
void delete_xs_info(void)
{
    while(1)
    {
        show(stu_list);
        printf("\n\n退出系统（0）                  继续删除学生用户信息（1）                  返回上一级（-1）\n");
        char sno[20];
        printf("\n请管理员输入需要删除学生的学号：");
        scanf("%s",sno);
        if(my_remove(stu_list,sno))
        {
            printf("\n                             删除学生用户信息成功！\n");
            fflush(stdout);
            sleep(2);
            show(stu_list);
            printf("\n\n退出系统（0）                  继续删除学生用户信息（1）                  返回上一级（-1）\n");
        }
        else
        {
            printf("\n                         学生用户信息不存在，删除失败！\n");
        }
        int xuhao;
        while(1)
        {
            printf("\n请管理员选择对应的操作：");
            if(!scanf("%d",&xuhao))
            {
                while(getchar() != '\n');
                xuhao = -2;
            }
            if(xuhao == -1)
            {
                gly_gui();
            }
            if(xuhao == 0)
            {
                printf("\n                        感谢学生用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            if(xuhao == 1)
            {
                break;
            }
            if((xuhao != -1) && (xuhao != 0) && (xuhao != 1))
            {
                printf("输入操作序号错误，请重新输入！\n");
            }
        }
    }
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

//删除链表某个节点
int my_remove(node* l,char sno[20])
{
    node* p = NULL;
    //找到待删除节点的前驱节点
    //节点存在，返回节点的前驱节点指针
    while(l->next != NULL && (strcmp(l->next->data.s_son,sno) != 0))
        l = l->next;
    //节点不存在返回0
    if(l->next == NULL) return 0;
    
    //连接断开的链表
    p = l->next;
    l->next = p->next;
    free(p);
    //删除成功返回1
    return 1;
}

//打印链表中所有节点数据
void show(node* l)
{
    l = l->next;
    printf("\033c");
    printf("\n      ******************学生用户信息界面******************\n");
    m_time();
    printf("\n  班级            学号      姓名              身份证号             密码       手机号");
    while(l != NULL)
    {
        printf("\n-----------------------------------------------------------------------------------------\n");
        printf("%-20s%-10s%-15s%-25s%-10s%-20s%d",l->data.s_class,l->data.s_son,l->data.s_name,l->data.s_idcard,l->data.s_pass,l->data.s_number,l->data.s_is_cj);
        l = l->next;
    }
}