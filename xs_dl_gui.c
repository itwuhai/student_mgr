#include <stdio.h>
#include "head.h"
#include "m_time.h"

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
}