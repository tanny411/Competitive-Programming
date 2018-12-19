#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<string.h>

using namespace std;

struct data{
int x,y,z;
};

struct data X[210000];
int l;

int gcdr ( int a, int b )
{
  if ( a==0 ) return b;
  return gcdr ( b%a, a );
}

void denerate_triples()
{
    l=0;
    int r,s,max=1000;
    for(s=1;s<max;s++)
    {
        for(r=s+1;r<max;r+=2)///r,s one shud be even other should be odd//r>s//
        {
            if(gcdr(r,s)==1)
            {
                X[l].z= r*r + s*s;
                X[l].x= r*r - s*s;
                X[l].y=2*r*s;
                l++;
            }
        }
    }
}

bool comp(struct data a,struct data b)
{
    return a.z<b.z;
}

int mbin(int n)  ///modified_binary search
{
    int starti=0,endi=l-1;///l is the size of the X array
    int midi=l/2;
    while(starti<=endi)
    {
        if(X[midi].z==n) {while(X[midi+1].z==n) midi++;  return midi;}///did the loop becoz more than 1 z value can be same! I want the highest!!
        else if(X[midi].z<n) {if(X[midi+1].z>n) { while(X[midi+1].z==n) midi++;  return midi; }  starti=midi+1;}
        else if(X[midi].z>n) {if(X[midi-1].z<n) { return midi-1; } endi=midi-1;}
        midi=(starti+endi)/2;
    }

}

int main()
{
    denerate_triples();
    sort(X,X+l,comp);
    char ulala[1000005];
    int p,notincluded,i,j,n,x1,y1,z1;
    while(scanf("%d",&n)==1)
    {
        memset(ulala,0,sizeof(ulala));
        p=mbin(n);
        printf("%d",p+1);
        notincluded= n;
        for(i=0;i<=p;i++)
        {
            if(ulala[X[i].x]!=1){
                        notincluded--;
                        ulala[X[i].x]=1;
                    }
            if(ulala[X[i].y]!=1){
                        notincluded--;
                        ulala[X[i].y]=1;
                    }
            if(ulala[X[i].z]!=1){
                        notincluded--;
                        ulala[X[i].z]=1;
                    }
            for(j=2 ; ; j++)
            {
                z1=j*X[i].z;
                if(z1<=n)
                {
                    x1=j*X[i].x;
                    y1=j*X[i].y;
                    if(ulala[x1]!=1){
                        notincluded--;
                        ulala[x1]=1;
                    }
                    if(ulala[y1]!=1){
                        notincluded--;
                        ulala[y1]=1;
                    }
                    if(ulala[z1]!=1){
                        notincluded--;
                        ulala[z1]=1;
                    }
                }
                else break;
            }
        }
        printf(" %d\n",notincluded);
    }
    return 0;
}
