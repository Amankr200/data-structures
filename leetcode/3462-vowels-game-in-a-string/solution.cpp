class Solution {
public:
    bool doesAliceWin(string s) {
        string vowels ="aeiou";
        int count =0;
        for(auto it : s){
        if (vowels.find(it) != string::npos){ 
            count++;
        }
        }
        if(count == 0){
            return false;
      
        }else{
            return true;
        }
    }
};
