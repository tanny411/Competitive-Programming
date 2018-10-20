#include<bits/stdc++.h>

///ios_base::sync_with_stdio(false);

using namespace std;

#define mx 1000
///no. of nodes=number of strings*max string size
struct trietree
{
    int tr[mx][26];
    int leaf[mx];
    int nodenumber;
    int root=0;
    trietree()
    {
        memset(tr,-1,sizeof tr);
        memset(leaf,0,sizeof leaf);
        nodenumber=0;
    }
    void insert_string(string s)
    {
        int node=root;
        for(int i=0;i<s.length();i++)
        {
            if(tr[node][s[i]-'a']==-1)
            {
                tr[node][s[i]-'a']=++nodenumber;
            }
            node=tr[node][s[i]-'a'];
        }
        leaf[node]++;
    }
    int look(string s)
    {
        int node=root;
        for(int i=0;i<s.length();i++)
        {
            if(tr[node][s[i]-'a']==-1) return 0;
            node=tr[node][s[i]-'a'];
        }
        if(leaf[node]>0) return 1;
    }
};

int main()
{
    trietree lala;
    string keys[] = {"hi", "hello", "you", "ekta", "me"};

	for (int i = 0; i < 5; ++i)
		lala.insert_string (keys[i]);

	cout << lala.look("hipls") << endl;
	cout << lala.look("m") << endl;
    return 0;
}

