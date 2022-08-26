#include <stdio.h>
#include "m_time.h"
#include "head.h"

void dl_gui(void)
{
    printf("\033c");
    printf("\n    *******************学生成绩与信息管理系统*******************\n");
    m_time();
    printf("\n----------------------------------------------------------------------\n");
    printf("*                         1.管理员用户登录                           *\n");
    printf("*--------------------------------------------------------------------*\n");
    printf("*                         2. 学生用户登录                            *\n");
    printf("*--------------------------------------------------------------------*\n"); 

    int xuhao;
    while(1)
    {
        printf("\n请选择用户登录界面：");
        if(1 != scanf("%d",&xuhao))
        {
            //如果输失败，就清空缓存区
            while(getchar() != '\n');
            xuhao = -1;
        }
        switch(xuhao)
        {
            case 1:
            {
                //管理员用户登录
                gly_cz();
            }
            break;
            case 2:
            {
                //学生用户登录
                xs_dl_gui();
            }
            break;
            default:
            {
                //输入错误
                printf("\n输入错误，请重新输入！\n");
            }
            break;
        }
    }
}