class Solution {
  public:
    int minNumberInRotateArray(vector<int> v) {
              if(v.empty())
                            return 0;
                      int left=0;
                              int right=v.size()-1;
                                      int mid=0;
                                              while(v[left]>=v[right])
                                              {
                                                            if(right-left==1)
                                                            {
                                                                              mid=right;
                                                                                              break;
                                                                                                          
                                                            }
                                                                    mid=(left+right)>>1;
                                                                                if(v[left]==v[right]&&v[mid]==v[left])
                                                                                {
                                                                                                  int result=v[left];
                                                                                                                  for(int i=left+1;i<right;i++)
                                                                                                                  {
                                                                                                                                        if(result>v[i])
                                                                                                                                        {
                                                                                                                                                                  result=v[i];
                                                                                                                                                                                      
                                                                                                                                        }
                                                                                                                                                        
                                                                                                                  }
                                                                                                                                  return result;
                                                                                                                                              
                                                                                }
                                                                                            if(v[mid]>=v[left])
                                                                                            {
                                                                                                              left=mid;
                                                                                                                          
                                                                                            }
                                                                                            else{
                                                                                                              right=mid;
                                                                                                                          
                                                                                            }
                                                                                                    
                                              }
                                                      return v[mid];
                                                          
    }

};
