#include<cstdio>

int main()
{
    char time[20];
    double min,sec,hour,speed,h=0,s=0,m=0,distance=0,lspeed=0;
    int n;
    while(gets(time)){
        n=sscanf(time,"%lf:%lf:%lf %lf",&hour,&min,&sec,&speed);
//printf("abc%lfabc%lfabc%lfabc%lfspeed",sec,min,hour,speed);
        distance+=lspeed*(sec-s+(min-m)*60+(hour-h)*3600)/3600;
        m=min;
        h=hour;
        s=sec;
        if(n==3) printf("%s %.2lf km\n",time,distance);
        else lspeed=speed;
    }
    return 0;
}
