# Algorithm Explanation - Array

## 704. 二分查找

### 题目

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

> 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

**Example 1:**

```python
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**

```python
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

**Constraints:**

- `1 <= nums.length <= 104`
- `-104 < nums[i], target < 104`
- All the integers in `nums` are **unique**.
- `nums` is sorted in ascending order.

### 思路

- 二分查找是一种在无重复元素的有序数组中查找特定元素的搜索算法。工作原理为不断地将数组分为两部分并对目标数值进行比较，从而确定目标在左侧或是右侧。
  - 1. 找到数组的中间元素
       - 如果中间元素正好是我们需要的值，那么搜索结束
    2. 如果中间元素小于我们要查找的值，则判断目标值在数组的右侧，在右半部分继续查找
    3. 如果中间元素大于我们要查找的值，则判断目标值在数组的左侧，在左半部分继续查找
    4. 重复以上的步骤，直到找到目标数值或搜索范围为空
- 在每一次分割左半和右半部分的时候，需要确定区间是左闭右闭还是左闭右开
  - 左闭右闭指包含最左侧和最右侧的数值
  - 左闭右开指包含最左侧的数值，但不包含最右侧的数值
  - 这里我们使用左闭右闭

![704.二分查找](https://images.wu.engineer/images/2023/08/28/68747470733a2f2f636f64652d7468696e6b696e672d313235333835353039332e66696c652e6d7971636c6f75642e636f6d2f706963732f32303231303331313135333035353732332e6a7067.jpeg)

### 过程

1. 定义所需的变量（左侧指针和右侧指针）
   - 左侧指针一般为`0`，即数组的第一个数值
   - 右侧指针一般为`array.size()-1`，即最后一个数值
2. 只要左侧指针小于右侧指针，就继续执行以下代码
   - 在这个题目中，我们将根据判断的条件逐渐将右侧指针左移或者将左侧指针右移到中位值。
3. 定义当前数组的中位数坐标
4. 如果目标数值小于中位数坐标，这说明目标数值在数组的右半部分，则将左侧指针挪到中位数坐标右侧`left=middle+1`
   - 因为我们已经证明目标数值比中位数大，所以不必包含中位数坐标在右侧数组中
5. 如果目标数值大于中位数坐标，这说明目标数值在数组的左半部分，则将右侧指针挪到中位数坐标左侧`right=middle-1`
6. 如果目标数值等于中位数坐标，则输出坐标

### 代码

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left + right) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle - 1;
            } else {
                return middle;
            }
        }

        return -1;
    }
};
```

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        left = 0
        right = len(nums) - 1
        while(left<=right):
        	# Declare a pointer in the middle of the array
        	mid = (right + left) // 2
        	if nums[mid] == target:
            	return mid
        	elif nums[mid] > target:
            	right = mid - 1
        	else:
            	left = mid + 1

        return -1
```

> 相关题目：
>
> 35. 搜索插入位置
>
> 34. 在排序数组中查找元素的第一个和最后一个位置
>
> 69. x的平方根
>
> 367. 有效的完全平方数

## 27. 移除元素

### 题目

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm). The order of the elements may be changed. Then return *the number of elements in* `nums` *which are not equal to* `val`.

Consider the number of elements in `nums` which are not equal to `val` be `k`, to get accepted, you need to do the following things:

- Change the array `nums` such that the first `k` elements of `nums` contain the elements which are not equal to `val`. The remaining elements of `nums` are not important as well as the size of `nums`.
- Return `k`.

**Example 1:**

```python
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```python
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
Note that the five elements can be returned in any order.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

### 思路

> 给定一个list，移除其中所有等于val的元素。最后输出移除后list中的数字数量。

- 由于list的内存地址是连续的（在C++中），所以我们不能直接删除list中的某一个元素，而是需要将后面的元素覆写上来。
- 根据这个思路，我们需要两个指针，一个指向需要被覆写的元素，另一个指向准备覆写的元素
- 这种方法叫做双指针。一般来说分为fast和slow两个指针，fast在每次循环中都指向下一个元素，而slow指针根据特殊的需求设定移动的节奏

![27.移除元素-双指针法](https://camo.githubusercontent.com/8c49666f4d541dd22e7e221964cc0ac7997d4bc98272d54ea6569c51bc2640d6/68747470733a2f2f636f64652d7468696e6b696e672e63646e2e626365626f732e636f6d2f676966732f32372e2545372541372542422545392539392541342545352538352538332545372542342541302d2545352538462538432545362538432538372545392539322538382545362542332539352e676966)

### 过程

1. 定义两个指针`slow`, `fast`。`fast`指针在每个循环中都向前进一个元素，而`slow`则根据特定的要求向前进
2. 设定循环，遍历list中的每一个元素。停止条件为`fast`指针到达list的最后一个元素为止
3. 在每个循环中，判断`fast`指针指向的元素值是否和val匹配。如果不匹配，说明这个值是可以覆写到`slow`指针中的，覆写到`slow`指针的元素。
   - 由于`fast`指针肯定比`slow`指针快或相等。如果在相等的位置则覆写不会改变值。如果`fast`指针比`slow`指针快，则说明`slow`指针卡在了需要覆写的元素上，所以覆写是安全的。
4. 循环结束后输出`slow`指针的数字（即数组内有多少有效的元素）

### 代码

```c++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow_pointer = 0;
        for(int fast_pointer=0; fast_pointer < nums.size(); fast_pointer++) {
            if (nums[fast_pointer] != val) {
                nums[slow_pointer++] = nums[fast_pointer]; 
            }
        }
        return slow_pointer;
    }
};
```

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        
        '''
        Dual pointer:
        Two pointer fast and slow, for each elements, if the element 
        not equal to the target, the element of slow pointer is re-writted
        by the fast pointer element. Then slow pointer move forward. 
        Whatever the element is, fast pointer always move forward.
        '''
        fast = 0
        slow = 0
        while fast < len(nums):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow
```

## 977. 有序数组的平方

### 题目

Given an integer array `nums` sorted in **non-decreasing** order, return *an array of **the squares of each number** sorted in non-decreasing order*.

**Example 1:**

```python
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
```

**Example 2:**

```python
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
```

### 思路

> 将list中的每个元素平方之后重新排列

- 使用双指针，一个指向第一个元素，一个指向最后一个元素。新建一个list，多一个指针指向list的最后一位元素

### 过程

- 创建循环，将每个元素平方后做对比，如果前面的元素平方后大于后面的元素的平方，则将前面的元素的平方放到新建list的末尾。前面的指针向后移，新建list的指针向前移。反之亦然
- 前后两个指针相遇时循环结束

### 代码

```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int result_pointer = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for (int i=0, j=nums.size()-1; i<=j; result_pointer--){
            if (nums[i]*nums[i] >= nums[j]*nums[j]) {
                result[result_pointer] = nums[i] * nums[i++];
            } else if (nums[i]*nums[i] < nums[j]*nums[j]) {
                result[result_pointer] = nums[j] * nums[j--];
            }
        }
        return result;
    }
};
```

```python
class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        '''
        Dual pointer:
        '''
        cur1 = 0
        cur2 = len(nums) - 1
        nums1 = [0] * len(nums)
        cur3 = len(nums) - 1
        while cur1 <= cur2:
            if nums[cur1]**2 >= nums[cur2]**2:
                nums1[cur3] = nums[cur1]**2
                cur1 += 1
            else:
                nums1[cur3] = nums[cur2]**2
                cur2 -= 1
            cur3 -= 1
        return nums1
```



## 209. 长度最小的子数组

### 题目

Given an array of positive integers `nums` and a positive integer `target`, return *the **minimal length** of a* 

*subarray*

Whose sum is *greater than or equal to* `target`. If there is no such subarray, return `0` instead.

**Example 1:**

```
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
```

**Example 2:**

```
Input: target = 4, nums = [1,4,4]
Output: 1
```

**Example 3:**

```
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
```

### 思路

> Sliding window is a window that sliding form the start of the array to the end

滑动窗口是**不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果**。

在暴力解法中，是一个for循环滑动窗口的起始位置，一个for循环为滑动窗口的终止位置，用两个for循环 完成了一个不断搜索区间的过程。

那么滑动窗口如何用一个for循环来完成这个操作呢。

首先要思考 如果用一个for循环，那么应该表示 滑动窗口的起始位置，还是终止位置。

如果只用一个for循环来表示 滑动窗口的起始位置，那么如何遍历剩下的终止位置？

此时难免再次陷入 暴力解法的怪圈。

所以 只用一个for循环，那么这个循环的索引，一定是表示 滑动窗口的终止位置。

那么问题来了， 滑动窗口的起始位置如何移动呢？

这里还是以题目中的示例来举例，s=7， 数组是 2，3，1，2，4，3，来看一下查找的过程：

![209.长度最小的子数组](https://camo.githubusercontent.com/dd84aee84237ebb78cf7ffde58803dc03350a4071d0981b8add65d9c59199ac4/68747470733a2f2f636f64652d7468696e6b696e672e63646e2e626365626f732e636f6d2f676966732f3230392e2545392539352542462545352542412541362545362539432538302545352542302538462545372539412538342545352541442539302545362539352542302545372542422538342e676966)

最后找到 4，3 是最短距离。

其实从动画中可以发现滑动窗口也可以理解为双指针法的一种！只不过这种解法更像是一个窗口的移动，所以叫做滑动窗口更适合一些。

在本题中实现滑动窗口，主要确定如下三点：

- 窗口内是什么？
- 如何移动窗口的起始位置？
- 如何移动窗口的结束位置？

窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。

窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。

窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。

![leetcode_209](https://camo.githubusercontent.com/6728c7e466955f2c15c6d37077d3f00274065bfadd9b855e48ff6540335b8c18/68747470733a2f2f636f64652d7468696e6b696e672d313235333835353039332e66696c652e6d7971636c6f75642e636f6d2f706963732f32303231303331323136303434313934322e706e67)

### 过程

- The initial window size is one, which the left pointer and right pointer are both zero
- Before shifting, the variable `sum` is added by the right pointer's element value
  - Since the initial element for right pointer is zero, so the variable `sum` contains the sliding window's elements sum
- **While** the sum is greater or equal to the target value, calculate the minimum length `min_len`
  - Which is one of the previous or the current window size
  - Shift the sliding window, by shifting the **left pointer**
  - Do not forget to subtract the left element value from sum
- Then, the sliding window will default increase its size by shifting right pointer
- Finally, return the `min_len`, if the value of `min_len` is infinite, then return 0

### 代码

```c++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        /*
        滑动窗口法：

        该方法使用两个指针（与双指针法极其类似）确定起始位置和终止位置。
        在brute-force中，我们同样使用了滑动窗口法。在初始状态，起始位置在0，通过第一个for loop不断后调终止位置，
        再通过第二个for loop在起始位置到数组末尾后调整起始位置到下一个。这种方法使用了两个for loop，时间复杂度
        为n^2。
        
        但是在滑动窗口法中，我们可以改变起始位置的变动策略。在初始状态，起始位置在0，通过第一个for loop不断后调
        终止位置。但是一旦滑动窗口中的数字和大于等于目标值后，起始位置即+1。这样我们只需要一个for loop便能解决
        问题。
        */ 

       int result = INT32_MAX;
       int sublen = 0;
       int j = 0; //起始位置
       int sum = 0;

       for (int i=0 /*终点位置*/; i<nums.size(); i++) 
       {
            sum += nums[i];
            /*
            使用while的原因：
            考虑到即使滑动起始位置后，剩下的数组仍能满足条件，所以需要不断验证
            */
            while (sum >= target)
            {
                sublen = i - j + 1;
                result = result < sublen ? result : sublen;
                /*
                滑动起始位置后，将sum中滑出起始位置的数值减掉，同时让起始位置j加一
                */
                sum -= nums[j++];
            }
       }
       return result == INT32_MAX ? 0 : result;
    }
};
```

```python
class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """

        # Sliding window:
        '''
        - Sliding window is a window that sliding form the start of the array to the end
        - The initial window size is one, which the left pointer and right pointer are both zero
        - Before shifting, the variable `sum` is added by the right pointer's element value
            - Since the initial element for right pointer is zero, so the variable `sum` contains the sliding window's elements sum
        - **While** the sum is greater or equal to the target value, calculate the minimum length `min_len`
            - Which is one of the previous or the current window size
            - Shift the sliding window, by shifting the **left pointer**
            - Do not forget to subtract the left element value from sum
        - Then, the sliding window will default increase its size by shifting right pointer
        - Finally, return the `min_len`, if the value of `min_len` is infinite, then return 0
        '''

        l = len(nums)
        left = 0
        right = 0
        min_len = float('inf')
        sum = 0
        
        while right < l:
            sum += nums[right]
            while sum >= target:
                min_len = min(min_len, right-left+1)
                sum -= nums[left]
                left += 1
            
            right += 1

        return min_len if min_len != float('inf') else 0
```

## 59. 螺旋矩阵

### 题目



### 思路





### 过程



### 代码
## 总结

