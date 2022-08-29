#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "head.h"
#include "m_time.h"

void find_xs_info(void);

void xs_gui(void)
{
    printf("\033c");
    printf("\n        *******************学生用户管理界面********************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("*                           1.查询个人信息                             *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("*                           2.查询个人成绩                             *\n");
    printf("*----------------------------------------------------------------------*\n"); 

    int xuhao;
    while(1)
    {
        printf("请学生用户选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -1;
        }
        switch(xuhao)
        {
            case 1:
            {
                //查询个人信息
                find_xs_info();
            }
            break;
            case 2:
            {
                //查询个人成绩
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

//学生用户查看信息验证
student_info* find_xs_info_yz(void)
{
    char xsyh_zh[20],xsyh_mm[33];
    student_info* s_i = NULL;
    while(1)
    {
        printf("\033c");
        printf("\n          *******************学生用户修改密码界面*******************\n");
        m_time();
        printf("\n       学生用户名为本人学号,学生用户密码为本人身份证后六位！\n");
        printf("\n------------------------------------------------------------------------\n");
        printf("                            学生用户名:");
        scanf("%s",xsyh_zh);
        printf("*----------------------------------------------------------------------*\n");
        strcpy(xsyh_mm,getpass("                            学生用户密码："));
        s_i = myfind(stu_list,xsyh_zh);
        if(s_i == NULL)
        {
            printf("\n                     抱歉，您的账号暂未创建！登录失败！\n");
            fflush(stdout);
            sleep(2);
            exit(1);
        }
        if(s_i->s_is_cj == 0)
        {
                printf("\n               抱歉，您的账号暂未创建！登录失败！\n");
                fflush(stdout);
                sleep(2);
                exit(1);
        } 
        if(s_i->s_is_cj == 1)
        {
            if(strcmp(s_i->s_pass,xsyh_mm) != 0)
            {
                printf("\n                            密码输入错误！\n");
                fflush(stdout);
                sleep(2);
            }
            if(strcmp(s_i->s_pass,xsyh_mm) == 0)
            {
                printf("\n                      学生用户验证成功。\n");
                break;
            }
        }
    }
    return s_i;
    fflush(stdout);
    sleep(2);
}

//查询个人信息
void find_xs_info(void)
{
    student_info* s_i = NULL;
    s_i = find_xs_info_yz();
    printf("\033c");
    printf("\n      ******************学生用户信息界面******************\n");
    m_time();
    printf("\n  班级            学号      姓名              身份证号             密码       手机号");
    printf("\n-----------------------------------------------------------------------------------------\n");
    printf("%-20s%-10s%-15s%-25s%-10s%-20s\n",s_i->s_class,s_i->s_son,s_i->s_name,s_i->s_idcard,s_i->s_pass,s_i->s_number);

    printf("\n退出系统（0）                                                              返回上一级（-1）\n");
    int xuhao;
    while(1)
    {
        printf("\n请学生用户选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -2;
        }
        switch(xuhao)
        {
            case 0:
            {
                printf("\n                        感谢学生用户使用本系统，欢迎下次使用！\n");
                exit(1);
            }
            break;
            case -1:
            {
                xs_gui();
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


//查询个人成绩
void find_xs_grand(void)
{

}