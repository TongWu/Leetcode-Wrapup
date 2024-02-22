class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        lword = s[s.rfind(' ') + 1:]
        return len(lword)
