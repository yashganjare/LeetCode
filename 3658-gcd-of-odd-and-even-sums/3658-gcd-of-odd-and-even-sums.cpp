class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long oddSum=n*n;
        long long evenSum=n*(n-1);
        return int(gcd(oddSum,evenSum));
    }
};