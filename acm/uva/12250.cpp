#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    string hello[]={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
    string language[]={"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN"};
    string var;
    int i,j,flag;
    for(i=1;;i++){
        flag=1;
        cin >> var ;///this string doesnt take spaces
        if(var=="#") break;
        cout << "Case " << i << ": ";
        for(j=0;j<6;j++){
            if(var==hello[j]){
                cout << language[j] << endl;
                flag=0;
                break;
            }
        }
        if(flag){
            cout << "UNKNOWN" << endl;
        }
    }

    return 0;
}
