class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N = -N;
        }
            return powers(x,N);
    }    
        double powers(double x,long long N){
            if(N == 0) return 1;

            double halfpow = powers(x,N/2);
            double halfpowsq = halfpow*halfpow;

            if(N%2 != 0) return x*halfpowsq;
            return halfpowsq;
        }
    };