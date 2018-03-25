class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int i = 0;
        int lastone = -1;
        while(i < len)
        {
            if(bits[i] == 1)
            {
                lastone = 2;
                i += 2;
            }
            else
            {
                lastone = 1;
                i += 1;
            }
        }
        return lastone == 1;
    }
};