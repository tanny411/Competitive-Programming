#include<stdio.h>
#include<math.h>
#include<ctype.h>


void merge(int ara[],int L[],int R[],int n,int l,int r)//function to merge two arrays L,R to one ara[] thru sorting
{
    int i,j,k;
    for(i=0,j=0,k=0;i<l && j<r;k++){
        if(L[i]<R[j]){
            ara[k]=L[i];
            i++;
        }
        else {
            ara[k]=R[j];
            j++;
        }
    }
    for(;i<l;i++,k++)
        ara[k]=L[i];
    for(;j<r;j++,k++)
        ara[k]=R[j];
}

int merge_sort(int ara[],int n)
{
    int a,b,c;
    if(n<2) return 0;
    int mid=n/2;
    int L[mid],R[n-mid];
    for(a=0,c=0;a<mid;a++,c++)
        L[a]=ara[c];
    for(b=0;b<n-mid;b++,c++)
        R[b]=ara[c];
    merge_sort(L,mid);
    merge_sort(R,n-mid);
    merge(ara,L,R,n,mid,n-mid);
    return 0;
}



int main()
{
    //printf("uuu");
    //freopen("int.txt","r",stdin);
    //freopen("outt.txt","w",stdout);
    long n,i;
    int ages[2000001];
    while(scanf("%d",&n)==1){//ages of n peoples will be inputted
        if(n==0) break;
        for(i=0;i<n;i++){
            scanf("%d",&ages[i]);
        }
        merge_sort(ages,n);
        for(i=0;i<n-1;i++)
        printf("%d ",ages[i]);
        printf("%d",ages[n-1]);
        printf("\n");
    }
    return 0;
}

