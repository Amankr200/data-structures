class Solution {
public:
    long long sumAndMultiply(int n) {
        string nonzerodig="";
        string st = to_string(n);
        for (char c:st){
        if (c!='0'){
            nonzerodig +=c;
        }
    }
    long long x ;
    if(nonzerodig.empty()){
    x=0;
    }else{
    x=stoll(nonzerodig);
    }
long long sum =0;
for(char c: nonzerodig){
    sum+=c-'0';
}
return x*sum;
}
};
