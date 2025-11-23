class Solution {
    private: 
    const long long MOD = 1e9 + 7;
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<long long >psum(n,0);
        vector<int> pcnt(n,0);
        vector<long long >px(n,0);
        vector <long long > powten(n+1 , 1);
        for(int i =1 ; i<=n;++i){
            powten[i]=(powten[i-1]*10)%MOD;
        }if(n>0){
            int digit =s[0]-'0';
            if(digit !=0 ){
                psum[0]=digit;
                pcnt[0]=1;
                px[0]=digit;
            }
        }
        for(int i =1; i<n;++i){
            psum[i]=psum[i-1];
            pcnt[i]=pcnt[i-1];
            px[i]=px[i-1];
            int digit =s[i]-'0';
            if(digit !=0){
                psum[i]+=digit; 
               
                pcnt[i]++;
                px[i]=(px[i-1]*10)%MOD;
                px[i]=(px[i]+digit)%MOD;
            }
        }
            vector<int> result;
            for(const auto& query: queries){
                int l =query[0];
                int r= query[1];
                long long rsum = psum[r];
                long long rx =px[r];
                int rcnt = pcnt[r];
                long long lsum =(l>0)?psum[l-1]:0;
                long long lx= (l>0)?px[l-1]:0;
                int lcnt =(l>0)? pcnt[l-1]:0;
                long long cursum=rsum-lsum;
                long long curx;
                int k =rcnt - lcnt ;
                if(k==0){
                    curx=0;
                }else{
                    long long lxshift =(lx * powten[k])%MOD;
                    curx=(rx -lxshift +MOD)%MOD;
                    
                }
                long long finans=(curx * cursum )%MOD;
                result.push_back((int)finans);
            }
            return result;
    }
    
};
