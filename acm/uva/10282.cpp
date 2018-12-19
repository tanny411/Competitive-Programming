#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    map<string,string>dic;
    string eng,oth;
    char sen[30];
    stringstream s;
    while(gets(sen) && strlen(sen))
    {
        s<<sen;
        s>>eng;
        s>>oth;
        dic[oth]=eng;
        s.clear();
    }
    while(cin>>oth)
    {
        if(dic.count(oth)==1) cout<<dic[oth]<<endl;
        else cout<<"eh"<<endl;
    }

}
