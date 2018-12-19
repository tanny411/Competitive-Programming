#include<cstdio>
#include<string>
#include<vector>
#include<iostream>

using namespace std;


vector <int> ara[30],temp;
int cur[30];

void getrid(int no,int element)
{
    int b;
    while(ara[no].back()!=element)
    {
        b=ara[no].back();

        ara[b].push_back(b);
        cur[b]=b;
        ara[no].pop_back();
    }
}

void pile(int pos,int a,int b)
{
    int c;
    while((c=ara[pos].back())!=a)
    {
        temp.push_back(c);
        ara[pos].pop_back();
        cur[c]=cur[b];
    }
    temp.push_back(c);
    ara[pos].pop_back();
    cur[c]=cur[b];

    while(!temp.empty())
    {
        ara[cur[b]].push_back(temp.back());
        temp.pop_back();
    }
}

void move_onto(int a,int b)
{
    getrid(cur[a],a);
    getrid(cur[b],b);

    ara[cur[b]].push_back(a);
    ara[cur[a]].pop_back();//

    cur[a]=cur[b];
}
void move_over(int a,int b)
{
    getrid(cur[a],a);

    ara[cur[b]].push_back(a);
    ara[cur[a]].pop_back();//

    cur[a]=cur[b];
}
void pile_onto(int a,int b)
{
    getrid(cur[b],b);

    pile(cur[a],a,b);
}
void pile_over(int a,int b)
{
    pile(cur[a],a,b);
}

void print_shit(int n)
{
    int i,j,s;
    for(i=0;i<n;i++)
    {
        printf("%d:",i);
        s=ara[i].size();
        for(j=0;j<s;j++)
        {
            printf(" %d",ara[i][j]);
        }

        printf("\n");
    }
}


int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,i,a,b;
    string m="move",p="pile",on="onto",ov="over",q="quit",str1,str2;

    for(i=0;i<30;i++)
    {
        ara[i].push_back(i);
        cur[i]=i;
    }

    scanf("%d",&n);

    while(cin>>str1 && str1!=q)
    {
        cin>>a>>str2>>b;

        if(cur[a]==cur[b]) continue;

        if(str1==m)///move
        {
            //printf("moved");
            if(str2==on)///move_onto
            {
                move_onto(a,b);
            }
            else///move_over
            {
                move_over(a,b);
            }
        }
        else///pile
        {
            if(str2==on)///pile_onto
            {
                pile_onto(a,b);
            }
            else///pile_over
            {
                pile_over(a,b);
            }
        }
       // if(str1==q) print_shit(n);
    }

    print_shit(n);

    return 0;
}

/**

10
move 9 over 1
move 8 over 1
move 7 over 1
move 6 over 1
pile 8 over 1
pile 8 over 5
pile 2 over 1
move 4 over 9
quit

**/
