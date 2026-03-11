class Solution {
public:
long long get_gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    int nthMagicalNumber(int n, int a, int b) {
       long long MOD = 1e9 + 7;
        long long gcd = get_gcd(a, b);
        long long lcm = (long long)a / gcd * b;

        long long range = lcm/a + lcm/b - 1;

        //range jitne numbers honge lcm tak

        int rem = n % range;

        //number from complete cycle

        long long cc = n / range; // like kitni baar vo cycle complete kr rha ahi
        long long numCC = ((cc % MOD) * (lcm % MOD)) % MOD;
       
       if (rem == 0) return (int)numCC;

       long long next_a = a;
        long long next_b = b;
        long long additional = 0;

        for (int i = 0; i < rem; ++i) {
            if (next_a < next_b) {
                additional = next_a;
                next_a += a;
            } else {
                additional = next_b;
                next_b += b;
            }
        }

        return (int)((numCC + additional) % MOD);
       
       
    }
};
