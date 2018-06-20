class Solution {
public:
    bool erased = false;
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else if(!erased)
            {
                erased = true;
                string s1 = s, s2 = s;
                s1.erase(i,1);
                s2.erase(j,1);
                return validPalindrome(s1) || validPalindrome(s2);
            }
            else
                return false;
            // i++;
            // j--;
            // cout << i << j << endl;
        }
        return true;
    }
};

// int flag=0;
//     bool validPalindrome(string s) {
//         for(int i=0,j=s.size()-1;i<=j;i++,j--)
//         {
//             if(s[i]==s[j]) continue;
//             else if(s[i]!=s[j] && flag==0)
//             {
//                 flag=1;
//                 string s1=s,s2=s;
//                 s1.erase(i,1);
//                 s2.erase(j,1);
//                 return (validPalindrome(s1) || validPalindrome(s2));
//             }
//             else return false;
//         }
//         return true;
//     }