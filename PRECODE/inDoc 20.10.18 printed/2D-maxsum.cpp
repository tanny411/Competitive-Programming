#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

using namespace std;

int kadane(vector<int>v, int* start, int* finish)///address of start and finish
{
    int sum=0,maxsum=-1<<30,s;
    *finish=-1;

    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        if(sum<0)
        {
            sum=0;
            s=i+1;
        }
        else if(sum>maxsum)
        {
            *start=s;
            *finish=i;
            maxsum=sum;
        }
    }
    if(*finish!=-1) return maxsum;

    for(int i=0;i<v.size();i++)
    {
        if(maxsum<v[i])
        {
            maxsum=v[i];
            *start=*finish=i;
        }
    }
    return maxsum;
}

int kadane_2D(vector< vector<int> >v , int* top,int* left,int* right, int* bottom)
{
    int MX=-1<<30;
    ///select two columns by n^2
    ///for each row in the range of the selected column find cummulative sum
    ///run kadane in that cummulative sum array to find the rows of either sides
    int n=v.size();///row
    int m=v[0].size();///column
    ///start and end column
    for(int stcol=0;stcol<m;stcol++)
    {
        vector<int>temp(n);

        for(int encol=stcol;encol<m;encol++)
        {
            for(int i=0;i<n;i++) temp[i]+=v[i][encol];

            int start,finish;
            int mx=kadane(temp,&start,&finish);
            if(mx>MX)
            {
                MX=mx;
                *left=stcol;
                *right=encol;
                *top=start;
                *bottom=finish;
            }
        }
    }
    return MX;
}

int main()
{
/*int M[4][5] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };*/
    //int M[4][5]={ -10,-20,-3,-4,-5,-10,-20,-38,-74,-85,-107,-20,-37,-48,-500,-100,-200,-30,-40,-50};

    vector< vector<int> >v(4,vector<int>(5));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            v[i][j]=M[i][j];
        }
    }
    int t,l,r,b;
    cout<<kadane_2D(v,&t,&l,&r,&b)<<endl;
    cout<<"top "<<t<<endl;
    cout<<"left "<<l<<endl;
    cout<<"right "<<r<<endl;
    cout<<"bottom "<<b<<endl;
    return 0;
}

