#include<bits/stdc++.h>
#define pb push_back
using namespace std;

///Max number of states = sum of length of patterns n*|p|
#define MAXS 500
///Max characters
#define MAXC 26

///list of output strings in each node
///use int if u wanna keep indices of patterns in out
vector<string>out[MAXS];

///failure nodes
int f[MAXS];

int trie[MAXS][MAXC];

int buildTrie(vector<string>pat, int n)
{
    /** Building Trie */

    for(int i=0;i<MAXS;i++) out[i].clear();
    memset(trie,-1,sizeof trie);

    ///ROOT is 0
    int states=1;

    for(int i=0;i<n;i++)
    {
        string str=pat[i];
        int node=0;

        for(int j=0;j<str.length();j++)
        {
            int ch=str[j]-'a';

            if(trie[node][ch]==-1) trie[node][ch]=states++;

            node=trie[node][ch];
        }

        out[node].pb(str);
    }

    /** Failure Function Building */

    ///adding a track back to root, for those children of root that dont exist
    for(int i=0;i<MAXC;i++) if(trie[0][i]==-1) trie[0][i]=0;

    memset(f, -1, sizeof f);

    queue<int>q;

    ///All children of root fail to root.
    for(int i=0;i<MAXC;i++) if(trie[0][i]!=0) f[trie[0][i]]=0,q.push(trie[0][i]);

    while(!q.empty())
    {
        int node=q.front();
        q.pop();


        for(int i=0;i<MAXC;i++)
        {
            if(trie[node][i]!=-1)
            {
                int failure=f[node];

                while(trie[failure][i]==-1)
                {
                    failure=f[failure];
                }

                failure=trie[failure][i];
                f[trie[node][i]]=failure;

                for(int k=0;k<out[failure].size();k++)
                {
                    out[trie[node][i]].pb(out[failure][k]);
                }

                q.push(trie[node][i]);
            }
        }
    }
    return states;
    ///no. of states in trie
}

void AhoCorasick(vector<string>pat, int n, string text)
{
    ///builds trie, failure and stores outputs
    buildTrie(pat,n);

    int curState=0;

    for(int i=0;i<text.size();i++)
    {
        int ch=text[i]-'a';

        while(trie[curState][ch]==-1)
        {
            curState=f[curState];
        }
        curState=trie[curState][ch];

        for(int j=0;j<out[curState].size();j++)
        {
            //if same word is in dictionary multiple times, will be printed multiple times
            //also if word in text multiple times, also printed multiple times
            //these are to be handled according to the problem
            cout<<out[curState][j]<< " appears in text from "<<i-out[curState][j].size()+1<<"\n";
        }
    }
}


int main()
{
    int n;
    cin>>n;
    vector<string>pat(n);
    for(int i=0;i<n;i++) cin>>pat[i];
    string text;
    cin>>text;
    AhoCorasick(pat,n,text);
    return 0;
}
/*
4
he she hers his
ahishers
*/
/**
I stored in out all the strings that end at a specific node
I could also: use bitset to mark those positions (index of strings) which are output at that position //bitset<MAXS>out[MAXS];
*/
