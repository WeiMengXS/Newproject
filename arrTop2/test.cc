#include<unordered_map>
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.empty())
            return ;
        unordered_map<int, int> map;
        for(auto& e:data)
        {
            map[e]++;
        }
        bool flog=false;
        
        for(auto& m: map)
        {
            if(m.second==1)
            {
                if(flog==false){
                     *num1=m.first;
                    flog=true;
                }
                else{
                     *num2=m.first;

                }
            }
            
        }
    }
};
