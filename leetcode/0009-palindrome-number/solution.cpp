class Solution {
public:
   bool isPalindrome(int x) {
        if(x<0)
        {
            return 0;
        }
        long int num=0;
        int n=x;
        while(x!=0)
        {
            num=num*10+x%10;
            x=x/10;
        }
        if(n==num)
        {
            return 1;
        }
        return 0;


        
    }
};
