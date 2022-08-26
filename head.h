#ifndef _HEAD_H_
#define _HEAD_H_

#include <time.h>

//创建用户名和密码结构体
typedef struct
{
    char gl_name[31];
    char gl_pass[33];
}name_pass;

//创建课程信息结构体
typedef struct g_cno
{
    char chinese[10];
    char math[10];
    char english[10];
}g_c;

//创建课程考试时间结构体
typedef struct g_time
{
    char chinese_time[20];
    char math_time[20];
    char english[20];
}g_t;

//创建课程考试成绩结构体
typedef struct g_grade
{
    int chinese_grade;
    int math_grade;
    int english_grade;
}g_g;

//创建考试成绩信息结构体
typedef struct student_g
{
    g_c g_cno;;
    g_t g_time;
    g_g g_grade;
}student_grade;

//创建学生用户信息结构体
typedef struct student_i
{
    char s_class[30];
    char s_son[20];
    char s_name[31];
    char s_pass[33];
    char s_number[20];
    char s_idcard[30];
    student_grade student_g;
}student_info;

typedef student_info elem_type;

//创建链表
typedef struct node_t
{
    elem_type data;
    struct node_t* next;
}node;

extern node* stu_list;
extern name_pass n_p;


void dl_gui(void);
void gly_dl_gui(void);
void gly_gui(void);
void xs_dl_gui(void);
void xs_gui(void);
void gly_cz(void);
node* creat(void);
void push_back(node* l,elem_type data);
void show(node* l);

#endif