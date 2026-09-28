class Solution {
public:
    double power(double x,long long N){
        if(N == 0) return 1;

        double halfpow = power(x,N/2);
        double halfpowsq = halfpow*halfpow;

        if(N%2 != 0) return x*halfpowsq;
        return halfpowsq;
    }
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            N = -N;
            x = 1/x;
        }
        return power(x,N);
    }
};