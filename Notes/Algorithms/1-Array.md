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



### 思路



### 过程



### 代码

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

