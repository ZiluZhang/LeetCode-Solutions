class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        int i = 0;
        int j = len-1;
        while(i < j)
        {
            while(i < j && !isalnum(s[i]))
                i++;
            while(i < j && !isalnum(s[j]))
                j--;
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};

// int j = s.length() - 1;
//         for (int i = 0; i <= j; i++, j--)
//         {
           
//                     while (isalnum(s.at(i)) == false)
// 		    {
// 			if (++i > j)
// 			  return true;
// 		    }
			
// 		    while (isalnum(s.at(j)) == false)
// 		    {
// 		    	if (--j < i)
// 			  return true;
// 		    }

//             if ( tolower(s.at(i)) != tolower(s.at(j)) )
//                 return false;
//         }
//         return true;