
#include<stdio.h>
#include<string.h>

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char qwerty[]={"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?"};
    char dvorak[]={"`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\""};
    char ara[1010];
    int i,j;
    while(gets(ara)){
        for(i=0;ara[i];i++){
        if(ara[i]==' ') printf(" ");
        else{
        for(j=0;ara[i]!=qwerty[j];j++){}
        printf("%c",dvorak[j]);
        }
        }
        printf("\n");
    }
    return 0;
}
