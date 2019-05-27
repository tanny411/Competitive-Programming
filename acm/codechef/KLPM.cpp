#include <bits/stdc++.h>
#define fs first
#define sc second
#define ll long long
#define pb push_back
using namespace std;

string str;
int ln;
vector<ll> mp[1005],rmp[1005];
vector<int>lps;
  
void countSort(vector<ll> &arr)  
{  
    vector<ll>output(arr.size());
   
    int RANGE=ln;
    int count[RANGE + 1], i;  
    memset(count, 0, sizeof(count));  
  
    for(i = 0; i<arr.size() ; ++i)  
        ++count[arr[i]];  
   
    for (i = 1; i <= RANGE; ++i)  
        count[i] += count[i-1];  
  
    for (i = 0; i<arr.size(); ++i)  
    {  
        output[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  

    for (i = 0; i<arr.size(); ++i)  
        arr[i] = output[i];  
}  

void expand(int low, int high)
{
	while (low >= 0 && high < ln && str[low] == str[high])
	{
        if( low==0 && high==(ln-1) );
        else mp[low].pb(high),rmp[high].pb(low);
		low--, high++;
	}
}

void allPalindromicSubstrings()
{
	for (int i = 0; i < ln; i++)
	{
		expand(i, i);
		expand(i, i + 1);
	}
    for(int i=0;i<ln;i++) {
        countSort(mp[i]);
        countSort(rmp[i]);
    }
    return;
}

int f(int st,int en){
    int in=lower_bound(mp[st].begin(),mp[st].end(),en)-mp[st].begin();
    return in;
}
int b(int st,int en){
    int in=lower_bound(rmp[en].begin(),rmp[en].end(),st+1)-rmp[en].begin()-1;
    return rmp[en].size()-in-1;
}

void computeLPS(string pat,int m)
{
    lps=vector<int>(m);
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i]) lps[i]=++len,i++;
        else if(len!=0) len=lps[len-1];
        else lps[i]=0,i++;
    }
}
int main()
{
    /*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
    */
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>str;
    ln=str.length();

    // cout<<"length = "<<ln<<endl;

    ll ans=0;

    int diff=0;
    for(int i=1;i<ln;i++) if(str[i]!=str[i-1]) {diff=1;break;} 
    if(diff==0){
        ll Ans=0;
        for(ll i=1,r=ln-1;i<ln;i++,r--){
            Ans+=i*(r*(r+1)/2ll);
        }
        cout<<Ans<<endl;
        // return 0;
    }

	allPalindromicSubstrings();

    for(int st=0;st<ln;st++)
    {
        int pans=ans;

        string ss=str.substr(st,ln);
        string rss=ss;
        reverse(rss.begin(),rss.end());
        ss=ss+"#"+rss;
        int sl=ln-st;
        int slen=2*sl+1;
        
        computeLPS(ss,slen);
        for(int i=sl+1,in=sl-1;i<slen;i++,in--){
            int pans=ans;
            int j=i;
            while(j>=0 && lps[j]){
                if(in>lps[j]-1)
                {   
                    int s=lps[j]-1;
                    ans+=1;
                    if(s+1<in) ans+=f(s+st+1,in+st)+b(s+st,in+st-1);
                }
                j=lps[j]-1;
            }
            // cout<<in<<" "<<ans-pans<<endl;
        }

        // cout<<st<<" "<<pans<<" "<<ans<<endl;

        /*for(int i=st , r=ln-1 ; i<ln && i<r ; r--){
            int j=i;
            int rj=r;
            while(j<rj && str[j]==str[rj]) {
                ans+=1;
                if(j+1<rj) ans+=f(j+1,rj)+b(j,rj-1);
                j++;
                rj--;
            }
        }*/
    }

    cout<<ans<<"\n";
	
    return 0;
}