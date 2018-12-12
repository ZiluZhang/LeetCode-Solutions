/*

Description
A palindrome is a word, phrase, number, or other sequence of characters which reads the same backward or forward.

Given a string, find the "minimum" number of characters to be inserted or removed to convert it to palindrome.

Please try to balance the result, meaning the returned value size and characters should be close to the original and, the total count should be close to 0. (every time you insert a character, that counts as +1 and when you remove, -1)

Template
def minPalindromeRemoveOrAdd(str):
or
String minPalindromeRemoveOrAdd(String str) {}

Examples
AEBCBDA => AEBCBEA (remove D and insert E, count = 0)

FINISH => FINIF (remove S, H and insert F, count = -1)

AAABAA => AABAA (remove A) or AAABAAA (insert A) ==> both are right answer


*/
/*
AEBCBDA
left, right
curStep
result
if(left >= right) {
    update result
    if curStep is better than result, result = curStep
}
str[left] == str[right] keep on checking for next positions
    left++; right--;
str[left] != str[right] try to remove one of them / insert one new character
    remove one
    remove left, curStep --
    remove right, curStep --
    insert
    insert in left position, with a character == str[right], curStep++
    insert in right position, with a character == str[left], curStep++
*/

string findBestPalindrome(string str) {
    int len = str.length();
    if(len <=1) return str;
    int left = 0, right = len-1;
    int result = INT_MAX;
    string resStr = "";
    DFS(str, left, right, 0, result, resStr);
    return resStr;
}

two way of converting str into palindrome
    1. 1 insert, 1 remove
    2. 1 insert

void DFS(string curStr, int left, int right, int curStep, int& result, string& resStr) {
    if(left >= right) {
        // curStr is a palindrome, check if this result is better than resStr
        if(abs(curStep) < abs(result)) {
            result = curStep;
            resStr = curStr;
        }
        return;
    }
    // left < right
    if(curStr[left] == curStr[right]) {
        // we don't need to remove / insert
        left++;
        right--;
        DFS(curStr, left, right, curStep, result, resStr)
    } else {
        // remove one of them
        // remove left character
        // 012345 remove char on index 2, 01 + 345
        
        // ABC   null + BC
        // substr(int startPos, int len);
        // substr(int startPos); get substr[startPos:end]
        string tmp = curStr.substr(0, left) + curStr.substr(left+1);
        DFS(tmp, left, right-1, curStep-1, result, resStr);
        // remove right character
        tmp = curStr.substr(0, right) + curStr.substr(right+1);
        DFS(tmp, left, right-1, curStep-1, result, resStr);
        
        // insert a new character
        // insert in left position
        // ABCDEFG left = 2, right = 4
        // add a char in left
        // AB E CDEFG left = 3, right = 4
        tmp = curStr.substr(0, left) + curStr[right] + curStr.substr(left);
        DFS(tmp, left+1, right, curStep+1, result, resStr);
        // insert in right position
        tmp = curStr.substr(0, right) + curstr[left] + curStr.substr(right);
        DFS(tmp, left+1, right-1, curStep+1, result, resStr);
    }
    return;
}

AEBCBDA
AEBCBDA, left = 0, right = 6, curStep = 0
    left: A, right: A
    left = left+1 = 1
    right = right - 1 = 5, curStep = 0

AEBCBDA, left = 1, right = 5, curStep = 0
    left: E, right: D
    ABCBDA left = 1, right = 4, curStep = 1
        left: B, right: D
        ...
        
        finally end when ADA, curStep = 4
        
        try to remove D
        ABCBA curStep = 2, update result

AEBCBEA

FINISH => FINIF (remove S, H and insert F, count = -1)

FINISH
|    |
    replace F with H, FINISF
    remove F, INISH
    remove H, FINIS
    insert H, HFINISH
    insert F, FINISHF
FINISHF

ABCDDA
ABCDBA
  ||
      replace C with D
      ABDDBA 
 |  |
    replace B with D
    remove B curStep--
    insert D curStep++
    curStep stays the same
