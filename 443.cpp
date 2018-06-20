class Solution {
public:
    int compress(vector<char>& chars) {
        int cnt = 0;
        int l = 0;
        char prev;
        
        int len = chars.size();
        for(int i = 0; i < len; i++)
        {
            if(i == 0 || chars[i] == prev)
                cnt++;
            else
            {
                chars[l] = prev;
                l++;
                if(cnt > 1)
                {
                    string tmp = to_string(cnt);
                    int tmplen = tmp.length();
                    for(int k = 0; k < tmplen; k++)
                    {
                        chars[l] = tmp[k];
                        l++;
                    }
                }
                // prev = chars[i];
                cnt = 1;
            }
            prev = chars[i];
        }
        chars[l] = prev;
        l++;
        if(cnt > 1)
        {
            string tmp = to_string(cnt);
            int tmplen = tmp.length();
            for(int k = 0; k < tmplen; k++)
            {
                chars[l] = tmp[k];
                l++;
            }
        }
        return l;
    }
};
// int count = 0, len = 0;
//     char prev = 0;
   
//     for (auto ch:chars)
//     {
//         if (prev==0 or ch==prev)  
//             ++count;
//         else
//         {
//             chars[len++] = prev;
//             if(count>1)
//                 for (auto c_count:to_string(count))
//                     chars[len++] = c_count;
//             count = 1;
//         }
//         prev = ch;
//     }
  
//     // The last element
//      chars[len++] = prev;
//      if(count>1)
//         for(auto c_count:to_string(count))
//             chars[len++] = c_count;

//     return len;