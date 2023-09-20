# Algorithm Explanation - Array

## 704. 二分查找

### 题目

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

> 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

**Example 1:**

```
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**

```
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

```
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
```

**Example 2:**

```
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



### 思路



### 过程



### 代码

## 209. 长度最小的子数组

### 题目



### 思路



### 过程



### 代码
## 59. 螺旋矩阵

### 题目



### 思路





### 过程



### 代码
## 总结

