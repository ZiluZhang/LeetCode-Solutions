class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        l = s.split(' ')
        tmp = []
        for i in xrange(len(l)):
            if l[-1-i] != '':
                tmp.append(l[-1-i])
        return ' '.join(tmp)