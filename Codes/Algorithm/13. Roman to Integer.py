class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roam_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000, 'IV': 4, 'IX': 9, 'XL': 40,
                    'XC': 90, 'CD': 400, 'CM': 900}
        result = 0
        n = len(s)
        i = 0
        while i < n - 1:
            if s[i] in ('I', 'X', 'C'):
                # Read next string value
                combined = s[i] + s[i + 1]
                if combined in roam_map:
                    result += roam_map[combined]
                    i += 2
                else:
                    result += roam_map[s[i]]
                    i += 1
            else:
                result += roam_map[s[i]]
                i += 1
            print(result)
        if i == len(s):
            return result
        else:
            return result + roam_map[s[-1]]

