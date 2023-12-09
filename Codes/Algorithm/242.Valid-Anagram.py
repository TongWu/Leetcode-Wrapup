class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        array = [0 for _ in range(26)]
        # Create hash function
        def hash(char):
            return ord(char) % 97

        # Check each string's char
        for char in s:
            array[hash(char)] += 1
        for char in t:
            if array[hash(char)] >= 1:
                array[hash(char)] -= 1
            else:
                return False
        # Check the array is empty
        for i in array:
            if i != 0:
                return False
        return True