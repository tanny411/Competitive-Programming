/*
    Author       :  Jan
    Problem Name :
    Algorithm    :
    Complexity   :
*/

#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

const int NN = 1000005;
const int MM = 505;

int cases, caseno, n, res[MM];
char T[NN], A[MM][MM];

struct node {
    node *next[27];
    vector <int> out;
    node() {
        for( int i = 0; i < 27; i++ ) next[i] = NULL;
        out.clear();
    }
};
queue <node *> Q;

node* buildTrieWithFailure( char A[MM][MM], int n ) {
    node *root = new node;
    for( int i = 0; i < n; i++ ) {
        node *p = root;
        for( int j = 0; A[i][j]; j++ ) {
            int c = A[i][j] - 96;
            if( !p->next[c] ) p->next[c] = new node;
            p = p->next[c];
        }
        p->out.push_back(i);
    }
    for( int i = 1; i < 27; i++ ) {
        if( !root->next[i] ) root->next[i] = root;
        else {
            Q.push( root->next[i] );
            root->next[i]->next[0] = root;
        }
    }
    while( !Q.empty() ) {
        node *u = Q.front(); Q.pop();
        for( int i = 1; i < 27; i++ ) if( u->next[i] ) {
            node *v = u->next[i];
            node *w = u->next[0];
            while( !w->next[i] ) w = w->next[0];
            v->next[0] = w = w->next[i];
            for( int j = 0; j < w->out.size(); j++ ) v->out.push_back( w->out[j] );
            Q.push(v);
        }
    }
    return root;
}

void AhoCorasick( node *p, char *T ) {
    for( int i = 0; T[i]; i++ ) {
        int c = T[i] - 96;
        while( !p->next[c] ) p = p->next[0];
        p = p->next[c];
        for( int j = 0; j < p->out.size(); j++ ) res[ p->out[j] ]++;
    }
}

void deleteTrie( node *p ) {
    for( int i = 1; i < 27; i++ ) if( p->next[i] && p->next[i] != p ) deleteTrie( p->next[i] );
    delete p;
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a2.ans", "w", stdout);

    double cl = clock();

    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %s", &n, T);
        assert( 1 <= n && n <= 500 );
        for( int i = 0; i < n; i++ ) {
            scanf("%s", A[i]);
            assert( strlen( A[i] ) <= 500 );
            res[i] = 0;
        }
        node *root = buildTrieWithFailure( A, n );
        AhoCorasick( root, T );

        printf("Case %d:\n", ++caseno);
        for( int i = 0; i < n; i++ ) printf("%d\n", res[i]);

        cerr << cases << endl;
        deleteTrie( root );
    }

    cl = clock() - cl;
    fprintf(stderr, "Total Execution Time = %lf seconds\n", cl / CLOCKS_PER_SEC);

    return 0;
}
