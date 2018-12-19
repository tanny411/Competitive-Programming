#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("out.txt","w",stdout);
    int ara[100003];
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        printf("Case %d:\n",cas++);
        int n,q;
        scanf("%d %d",&n,&q);
        //cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            //cin>>ara[i];
            scanf("%d",&ara[i]);
        }
        int a,b;
        while(q--)
        {
            int no=0;
            //cin>>a>>b;
            scanf("%d %d",&a,&b);
            int start=0,last=n-1,mid;
            while(start<=last)
            {
                mid=(start+last)/2;
                if(ara[mid]==a)
                {
                    no=1;
                    last=mid;
                    break;
                }
                else if(ara[mid]<a) start=mid+1;
                else last=mid-1;
            }

        a=last;
        if(a<0) {a=0;no++;}
        //cout<<a<<endl;
        start=0;
        last=n-1;
        while(start<=last)
            {
                mid=(start+last)/2;
                if(ara[mid]==b)
                {
                    last=mid;
                    break;
                }
                else if(ara[mid]<b) start=mid+1;
                else last=mid-1;
            }
        b=last;
        if(b>=n) {b=n-1;}
        //cout<<b<<endl;
        no+=b-a;
        printf("%d\n",no);
        }
    }
    return 0;
}
