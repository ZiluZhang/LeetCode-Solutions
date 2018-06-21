class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        s = 1
        if numerator * denominator < 0:
            s = -1
            numerator = abs(numerator)
            denominator = abs(denominator)
        
        repeating = {}
        quotient, remainder = divmod(numerator, denominator)
        res = [str(quotient)]
        cnt = 1
        
        while remainder != 0:
            repeating[remainder] = cnt
            cur_quotient, remainder = divmod(remainder * 10, denominator)
            res.append(str(cur_quotient))
            if remainder in repeating:
                res.insert(repeating[remainder], "(")
                res.append(")")
                break
            cnt += 1
            
        if len(res) > 1:
            res.insert(1, ".")
        
        if s == 1:
            return "".join(res)
        else:
            return "-"+"".join(res)
        
        
        
#         sign = 1
#         if numerator * denominator < 0: 
#             sign = -1
#             numerator, denominator = abs(numerator), abs(denominator)
#         seenRem = {}
#         initVal, remainder = divmod (numerator, denominator)
#         res = [str(initVal)]
#         count = 1
#         while remainder != 0:
#             #print (seenRem, res)
#             seenRem[remainder] = count
#             next, remainder = divmod (remainder * 10, denominator)
#             res.append (str(next))
#             if remainder in seenRem:
#                 res.insert (seenRem[remainder], "(")
#                 res.append (")")
#                 break
#             count += 1
        
#         if len(res) > 1:
#             res.insert(1, ".")
            
#         if sign == 1:
#             return "".join(res)
#         else:
#             return "-"+"".join(res)