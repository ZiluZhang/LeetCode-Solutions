class Solution(object):
    def customSortString(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: str
        """
        tmp = []
        for i in S:
            tmp.append(i * T.count(i))
        for i in T:
            if i not in S:
                tmp.append(i)
        return ''.join(tmp)