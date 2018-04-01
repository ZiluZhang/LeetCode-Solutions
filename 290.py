class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split(' ')
        if len(pattern) != len(words):
            return False
        dic = {}
        for i in range(len(pattern)):
            if pattern[i] not in dic.keys():
                if words[i] in dic.values():
                    return False
                dic[pattern[i]] = words[i]
            else:
                if dic[pattern[i]] != words[i]:
                    return False
        return True