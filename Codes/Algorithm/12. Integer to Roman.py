class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        roman_list = [1000, 500, 100, 50, 10, 5, 1]
        integer_map = {1000: 'M', 500: 'D', 100: 'C', 50: 'L', 10: 'X', 5: 'V', 1: 'I'}
        i = 0
        result = ''
        while num > 0:
            cur = roman_list[i]
            if num // cur > 0:
                product = num // cur
                num %= cur
                result += integer_map[cur] * product
            i += 1
        result = result.replace('DCCCC', 'CM')
        result = result.replace('LXXXX', 'XC')
        result = result.replace('IIII', 'IV')
        result = result.replace('VIV', 'IX')
        result = result.replace('XXXX', 'XL')
        result = result.replace('CCCC', 'CD')
        return result

