class Solution {
public:
    string lexSmallest(string s) {
        int n =s.size();
        string answer =s;
        for (int j =1; j<=n; j++){
            string k1 =s;
            string k2=s;
             reverse(k1.begin(),k1.begin()+j);
            answer=min(answer ,k1);
            reverse (k2.end()-j,k2.end());
            answer =min (answer,k2);
        }
        return answer;
        }
 

};
