#include <stdio.h>
#include <time.h>
#include "m_time.h"

int main()
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

    
}