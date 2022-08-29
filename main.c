#include <stdio.h>
#include "head.h"

node* stu_list = NULL;

void load_stu_data(void);

int main()
{
    stu_list = creat();
    load_stu_data();
    dl_gui();
}

//加载所有学生信息
void load_stu_data(void)
{
    FILE* fp = NULL;
    student_info s_i;
    fp = fopen("stu_info","rb");
    if(fp == NULL) return; 
    while(fread(&s_i,sizeof(s_i),1,fp))
    {
        push_back(stu_list,s_i);
    }
    fclose(fp);
}