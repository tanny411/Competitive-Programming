///code not runnable, only for reference
int dir[][]={{-1}};
int dp[][]={{-1}};
int func(int i,int w) //i নম্বর আইটেম নিয়ে চেষ্টা করা হচ্ছে,w ওজনের জিনিস নেয়া হয়েছে
{
    .........
    //BASE CASE
    .........

     if(w+weight[i]<=CAP) //i নম্বর জিনিসটি নিবো
         profit1=cost[i]+func(i+1,w+weight[i])
     else
         profit1=0;
     profit2=func(i+1,w) // i নম্বর জিনিসটি নিবো না
     if(profit1>profit2){dir[i][w]=1; return dp[i][w]=profit1;}
     else {dir[i][w]=2; return dp[i][w]=profit2;}
}

/**

*/
