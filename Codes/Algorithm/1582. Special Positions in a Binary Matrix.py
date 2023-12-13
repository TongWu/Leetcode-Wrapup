class Solution(object):
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        results = 0
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1 and sum(mat[i]) == 1 and sum(row[j] for row in mat) == 1:
                    results += 1
        return results
