#include <stdio.h>
#include <time.h>
#include "m_time.h"

void m_time()
{
    time_t t;
    time(&t);
    struct tm* now_time = localtime(&t);
    const char* weekday[] = {"日","一","二","三","四","五","六"};
    printf("                系统时间：%d年%d月%d日 %d：%02d：%02d 星期%s\n",now_time->tm_year+1900,now_time->tm_mon+1,now_time->tm_mday,now_time->tm_hour,now_time->tm_min,now_time->tm_sec,weekday[now_time->tm_wday]);
}