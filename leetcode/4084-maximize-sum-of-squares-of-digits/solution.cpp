class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum<0 || sum>9*num){
            return "";
        }
        string result(num,'0');
         int remain =sum;
        
        for (int i =0 ; i<num  && remain >0 ; i++){
            int digit = min(9,remain);
            result[i]='0'+digit;
            remain-=digit;
        }
        return result;
    }
};
