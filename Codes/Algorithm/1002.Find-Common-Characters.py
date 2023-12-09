class Solution(object):
    def commonChars(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        # Maintain a hashmap for store the min word frequency
        first_word = [0 for _ in range(26)]
        # Maintain an array to store the result
        results = []

        def hash(input):
            return ord(input) % ord("a")

        # Initialise the first word frequency hashmap
        for char in words[0]:
            first_word[hash(char)] += 1

        # For each following word
        for i in range(1, len(words)):
            other_words = [0 for _ in range(26)]
            # Maintain a temp hashmap
            for j in range(len(words[i])):
                other_words[hash(words[i][j])] += 1
            # Update the first_word hashmap with the min value of two hashmap
            for i in range(26):
                first_word[i] = min(first_word[i], other_words[i])
        for i in range(26):
            while first_word[i] != 0:
                # Update the result array
                results.append(chr(i + ord("a")))
                first_word[i] -= 1
        return results
