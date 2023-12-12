import collections
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        # 使用defaultdict生成一个特殊的字典
        # 在每次访问该字典不存在的键时，对该键的值生成一个列表list
        d = collections.defaultdict(list)

        for word in strs:
            # 对于列表中的每个词，由于我们需要的是含有相同字母的词，所以词中字母的顺序可以改变
            # 排列字符串中的字母，作为键
            key = ''.join(sorted(word))

            # 对于每个键的值列表，插入对应的词
            d[key].append(word)
        # 返回的字典的所有值就是所需答案
        return d.values()
