#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ///candidates(1 to n) company preference(n+1 to 2n)
        vector< map<int,int> >candidate(n+2);
        int company[n+2][n+2];
        //cout<<"KI HOISE"<<endl;
        for(int i=1;i<=n;i++){
            //cout<<i<<endl;
            for(int j=1;j<=n;j++){
                int x;
                cin>>x;
                candidate[i][x]=j;
                //cout<<" "<<x<<endl;
            }
        }
        //cout<<"NILAM"<<endl;
        ///companys candidiate preference
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>company[i][j];
            }
        }
        int preference[n+2];///[candidate] - company preference list
        int taken[n+2]; ///is company taken?
        int next[n+2];
        for(int i=0;i<=n;i++){
            preference[i]=-1;
            taken[i]=0;
            next[i]=1;
        }
        int f=1;
        int iteration=1;
        while(f)
        {
            //cout<<"kita?"<<endl;
            f=0;
            for(int j=1;j<=n;j++){///company
                //cout<<"loop "<<j<<endl;
                if(taken[j]) continue;
                f=1;
                int i=next[j];
                next[j]++;
                //cout<<"ekhon? "<<i<<endl;
                if(preference[company[j][i]]==-1){
                    //cout<<"aiso?"<<endl;
                    preference[company[j][i]]=j+n;
                    taken[j]=1;
                }
                else{
                    int can=company[j][i];
                    if(candidate[can][preference[can]]>candidate[can][j+n]){
                        taken[preference[can]-n]=0;
                        preference[can]=j+n;
                        taken[j]=1;
                    }
                }
            }
            //cout<<"iteration: "<<iteration<<endl;
//            for(int i=1;i<=n;i++){
//                cout<<i<<" "<<(taken[i]?"taken":"no")<<endl;
//            }
        }
        cout<<"Case "<<test++<<":";
        for(int i=1;i<=n;i++){
            cout<<" ("<<i<<" "<<preference[i]<<")";
        }
        cout<<endl;
    }
    return 0;
}
/**
1
4
6 8 7 5
8 6 5 7
6 7 8 5
7 5 8 6
1 3 4 2
2 4 1 3
4 2 1 3
2 1 4 3

one possible output
Case 1: (3 5) (1 6) (4 7) (2 8)
**/
