#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "m_time.h"
#include "head.h"
#include "md5.h"

name_pass n_p;

int is_first();
int gly_cz_check(const char* gl_name,const char* gl_pass);
void gly_revise_n_p(void);

void gly_dl_gui(void)
{
    printf("\033c");
    printf("\n          *******************管理员管理界面*******************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("*                          1.修改用户名和密码                          *\n");
    printf("*----------------------------------------------------------------------*\n");
    printf("*                          2.创建学生用户账号及密码                    *\n");
    printf("*----------------------------------------------------------------------*\n"); 
    printf("*                          3.管理员操作界面                            *\n");
    printf("*----------------------------------------------------------------------*\n"); 

    int xuhao;
    while(1)
    {
        printf("\n请管理员选择对应的操作：");
        if(!scanf("%d",&xuhao))
        {
            while(getchar() != '\n');
            xuhao = -1;
        }
        switch(xuhao)
        {
            case 1:
            {
                gly_revise_n_p();
                gly_cz();
            }
            break;
            case 2:
            {

            }
            break;
            case 3:
            {
                gly_gui();
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

void gly_cz(void)
{

    char gl_name[31], gl_pass[33],gl_pass_check[33];
    printf("\033c");
    printf("\n          *******************管理员登录界面*******************\n");
    m_time();
    printf("\n------------------------------------------------------------------------\n");
    printf("                            管理员用户名:");
    scanf("%s",gl_name);
    printf("*----------------------------------------------------------------------*\n");
    strcpy(gl_pass,getpass("                            管理员密码："));
    
    if(is_first())
    {
        if(strcmp(gl_name,"root") != 0 ||strcmp(gl_pass,"666666") != 0)
        {
            printf("\n管理员用户名或密码错误，登录失败!\n");
            exit(1);
        }

        //首次登陆成功
        printf("\033c");
        printf("\n     *******************管理员首次登录信息重置界面*******************\n");
        while(1)
        {
            printf("           为了保证您的账号安全，请重新设置管理员用户名和密码！          \n");
            m_time();
            printf("\n------------------------------------------------------------------------\n");
            printf("                          管理员新用户名:");
            scanf("%s",gl_name);
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass,getpass("                          管理员新密码："));
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass_check,getpass("                          再次输入管理员新密码："));
            if(strcmp(gl_pass,gl_pass_check) == 0) break;
            printf("\n                 两次输入的密码不一致，请重新输入!\n");
        }
        strcpy(n_p.gl_name,gl_name);
        md5_encode(gl_pass,strlen(gl_pass),n_p.gl_pass);

        FILE *fp =fopen("gly_data","wb");
        if(fp == NULL)
        {
            perror("open gly_data fail");
        }
        fwrite(&n_p,sizeof(n_p),1,fp);
        fclose(fp);
    }
    else
    {
        //重置信息后登录
        if(!gly_cz_check(gl_name,gl_pass))
        {
            printf("\n管理员用户名或密码输入错误，登录失败！\n");
            exit(1);
        }
    }
    gly_dl_gui();
}

//第一次登录验证
int is_first()
{
    FILE *fp = fopen("gly_data","rb");
    if(fp == NULL) return 1;
    fclose(fp);
    return 0;
}

//更改新密码后登录验证
int gly_cz_check(const char* gl_name,const char* gl_pass)
{
    FILE *fp = NULL;
    name_pass gly_np;
    char gly_pass_md5[33];
    int check_success = 0;

    fp = fopen("gly_data","rb");
    if(fp == NULL) return 0;

    md5_encode(gl_pass,strlen(gl_pass),gly_pass_md5);

    while(fread(&gly_np,sizeof(gly_np),1,fp) == 1)
    {
        if(strcmp(gl_name,gly_np.gl_name) == 0 && strcmp(gly_pass_md5,gly_np.gl_pass) == 0)
        {
            n_p = gly_np;
            check_success = 1;
            break;
        }
    }
    fclose(fp);
    return check_success;
}


//管理员修改用户名及密码界面
void gly_revise_n_p(void)
{
    char gl_name[31], gl_pass[33],gl_pass_check[33];
    printf("\033c");
    printf("\n     *******************管理员修改用户名和密码界面*******************\n");
        while(1)
        {
            m_time();
            printf("\n------------------------------------------------------------------------\n");
            printf("                          管理员新用户名:");
            scanf("%s",gl_name);
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass,getpass("                          管理员新密码："));
            printf("*----------------------------------------------------------------------*\n");
            strcpy(gl_pass_check,getpass("                          再次输入管理员新密码："));
            if(strcmp(gl_pass,gl_pass_check) == 0) break;
            printf("\n                 两次输入的密码不一致，请重新输入!\n");
        }
        strcpy(n_p.gl_name,gl_name);
        md5_encode(gl_pass,strlen(gl_pass),n_p.gl_pass);

        FILE *fp =fopen("gly_data","wb");
        if(fp == NULL)
        {
            perror("open gly_data fail");
        }
        fwrite(&n_p,sizeof(n_p),1,fp);
        fclose(fp);
}