#include<stdio.h>
#include<map>
#include<string>
using namespace std;
int main()
{
    map<string,int>month,day;

    month["JAN"]=31;month["FEB"]=28;month["MAR"]=31;month["APR"]=30;
    month["MAY"]=31;month["JUN"]=30;month["JUL"]=31;month["AUG"]=31;
    month["SEP"]=30;month["OCT"]=31;month["NOV"]=30;month["DEC"]=31;
    day["SUN"]=0;day["MON"]=1;day["TUE"]=2;day["WED"]=3;day["THU"]=4;
    day["FRI"]=5;day["SAT"]=6;

    char m[13],d[8];
    int test,a,date,sat,fri;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%s %s", m, d);
        a=day[d];date=1,sat=fri=0;
        if(a==6) sat++;
        while(a!=5){
            a=(a+1)%7;
            date++;
        }
        while(date<=month[m])
        {
            fri++;
            if((date+1)<=month[m]) sat++;
            date+=7;
        }
        printf("%d\n",fri+sat);
    }
    return 0;
}
