class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if(n == 0 || k == 0)
            return res;
        string l = "123456789";
        int fac = 1;
        int tmp = n;
        while(tmp)
        {
            fac *= tmp;
            tmp--;
        }
        k --;
        while(n)
        {
            fac /= n;
            res += l[k / fac];
            l.erase(l.begin() + k/fac);
            k %= fac;
            n--;
        }
        return res;
    }
};

// string getPermutation(int n, int k) {
// string re;
// if(n==0||k==0)
// return re;
// string list="123456789";
// int jiecheng=1;
// int temp=n;
// while(temp)
// {
// jiecheng*=temp--;
// }
// k-=1;
// while(n)
// {
// jiecheng/=n;
// re+=list[k/jiecheng];
// list.erase(list.begin()+k/jiecheng);
// k%=jiecheng;
// --n;
// }
// return re;
// }