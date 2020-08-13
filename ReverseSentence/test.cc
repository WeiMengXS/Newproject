class Solution {
public:
    void Reverse(string& s,int start,int end)
    {
        while(start<end)
        {
            char tmp=s[end];
            s[end]=s[start];
            s[start]=tmp;
            start++;
            end--;
        }
    }
    string ReverseSentence(string str) {
        if(str.empty())
            return str;
        int i=0;
        int j=0;
        int end=str.size();
        while(i<end)
        {
            while(i<end&&!isspace(str[i]))
                i++;
            Reverse(str,j,i-1);
               while(i<end&&isspace(str[i]))
                    i++;
                     j=i;

        }
        Reverse(str,j,i-1);
        Reverse(str,0,i-1);
        return str;
    }
};
