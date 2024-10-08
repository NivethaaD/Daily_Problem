class Solution {
public:
    int minSwaps(string s) {
       int res=0;
       for(auto it:s){
         if(it=='[')res++;
         else if(res>0)res--;
       }
       return (res+1)/2;
    }
};
