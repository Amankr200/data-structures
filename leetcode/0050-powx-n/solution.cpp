class Solution {
public:
    double myPow(double x, int n) {
        double y = pow(x,n);
        return y;
    }
    int main(){
        int x;
        int n;
        double z = myPow(x,n);
        cout<<z;
        return 0;
    }
};
