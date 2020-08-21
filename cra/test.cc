class Solution {
public:
    int cutRope(int number) {
        if(number<2)
            return 0;
        if(number==2)
            return 1;
        if(number==3)
            return 2;
        int *dp=new int[number+1];
        
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        int max=0;
        for(int i=4;i<=number;i++)
        {
            max=0;
            for(int j=1;j<=i/2;j++)
            {
                int num=dp[j]*dp[i-j];
                if(max<num)
                {
                    max=num;
                }
                dp[i]=max;
            }
        }
        max=dp[number];
        delete[] dp;
        return max;
    }
};
