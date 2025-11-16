class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int counta=0,countb=0;
        for(char ch : s){
            if(ch== 'a'){
                counta++;
            }else if (ch=='b'){
                countb++;
            }
        }
        return abs(counta- countb);
    }
};
