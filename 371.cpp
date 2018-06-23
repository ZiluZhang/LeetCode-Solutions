class Solution {
public:
    int getSum(int a, int b) {
        if(a < 0)
            return -getSum(-a, -b);
        int mask = 1;
        while(a)
        {
            if(a & 1)
            {
                int tmp = mask;
                while(b & tmp)
                {
                    b ^= tmp;
                    tmp <<= 1;
                }
                b ^= tmp;
            }
            a >>= 1;
            mask <<= 1;
        }
        return b;
//         int sig_bit = 1;
        
//         while(a){
//             if(a & 1){
//                 int m = sig_bit;
                
//                 while(b & m){
//                     b ^= m;
//                     m <<= 1;
//                 }
//                 b ^= m;
//             }
            
//             a >>= 1;
//             sig_bit <<= 1;
//         }
        
//         return b;
            
    }
};