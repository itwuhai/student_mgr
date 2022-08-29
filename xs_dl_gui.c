#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "head.h"
#include "m_time.h"

void xs_xgpass_gui(void);

void xs_dl_gui(void)
{
    printf("\033c");
    printf("\n         *******************学生用户管理界面*******************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("*                           1.修改用户密码                             *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("*                           2.学生用户操作界面                         *\n");
    printf("*----------------------------------------------------------------------*\n"); 

    int xuhao;
    while(1)
    {
        printf("\n请学生用户选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n')
            xuhao  = -1;
        }
        switch(xuhao)
        {
            case 1:
            {
                //修改用户密码
                xs_xgpass_gui();
                save_data();
                dl_gui();
            }
            break;
            case 2:
            {
                //学生用户操作界面
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

//学生用户登录验证
void xs_zhmm_dlyz(void)
{
    char xsyh_zh[20],xsyh_mm[33];
    while(1)
    {
        printf("\033c");
        printf("\n          *******************学生用户登录界面*******************\n");
        m_time();
        printf("\n       学生用户名为本人学号,学生用户密码为本人身份证后六位！\n");
        printf("\n------------------------------------------------------------------------\n");
        printf("                            学生用户名:");
        scanf("%s",xsyh_zh);
        printf("*----------------------------------------------------------------------*\n");
        strcpy(xsyh_mm,getpass("                            学生用户密码："));
        FILE* fp = NULL;
        fp = fopen("stu_info","rb");
        if(fp == NULL)
        {
            printf("               抱歉，您的账号暂未创建！登录失败！\n");
            exit(1);
        }
        fclose(fp);
        student_info* s_i = NULL;
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
                printf("\n                  恭喜学生用户登录成功。欢迎您的使用！");
                break;
            }
        }
    }
    fflush(stdout);
    sleep(2);
    xs_dl_gui();
}


//修改学生用户密码
void xs_xgpass_gui(void)
{
    char xsyh_zh[20],xsyh_mm[33],xsyh_new_mm[33];
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
                printf("\n                        密码输入错误！\n");
                fflush(stdout);
                sleep(2);
            }
            if(strcmp(s_i->s_pass,xsyh_mm) == 0)
            {
                printf("\n                  学生用户验证成功。重新修改新密码！\n");
                break;
            }
        }
    }
    fflush(stdout);
    sleep(2);
    while(1)
    {
        printf("*----------------------------------------------------------------------*\n");
        strcpy(xsyh_mm,getpass("                            学生用户新密码："));
        printf("*----------------------------------------------------------------------*\n");
        strcpy(xsyh_new_mm,getpass("                           再次输入学生用户新密码："));
        if(strcmp(xsyh_mm,xsyh_new_mm) == 0) break;
        printf("\n                 两次输入的密码不一致，请重新输入!\n");
    }
    strcpy(s_i->s_pass,xsyh_mm);
    printf("\n                 修改学生用户密码成功，请学生用户重新登录!\n");
    fflush(stdout);
    sleep(2);
}