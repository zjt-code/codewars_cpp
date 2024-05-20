#include<stdio.h>
#include<string.h>

char *human_readable_time (unsigned seconds, char *time_string)
{
    unsigned sec,min,hour;
    sec = seconds%60;
    min = (seconds/60)%60;
    hour = seconds/3600;
    sprintf(time_string,"%02d:%02d:%02d",hour,min,sec);

    return time_string;
}
int main()
{


    char timestring[20]={0};

    printf("%s\r\n",human_readable_time(99999,timestring));

    return 0;
}