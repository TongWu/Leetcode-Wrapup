/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int start_x = 0, start_y = 0; //定义二维数组指针起始位置，默认0,0
        int loop = n/2; //定义这个二维数组除去最中间的数值外有几层
        int mid = n/2; //定义二维数组最中间的数值的坐标(mid,mid)
        int offset = 1, count = 1; //定义每一条边的长度负补偿，和每一条边中的当前坐标
        int i, j;
        while (loop--)
        {
            i = start_x;
            j = start_y;

            // 第一条横边
            for ( j=start_y; j<(n-offset); j++ ) {
                res[start_x][j] = count++;
            }

            // 第一条竖边
            for ( i=start_x; i<(n-offset); i++) {
                res[i][j] = count++;
            }

            // 第二条横边
            for ( ; j>start_y; j--) {
                res[i][j] = count++;
            }

            // 第二条竖边
            for ( ; i>start_x; i-- ) {
                res[i][j] = count++;
            }

            //至此完成一层的赋值，赋值指针在下一个循环开始后挪到第二层的开始坐标，在此之前，在此循环的末尾需要更新起始坐标
            start_x++;
            start_y++;

            // 同时需要更新新的一层中的每条边的长度负补偿
            offset += 1;
        }

        // 在把所有层填满数值后，如果n为奇数，则会存在中间的单个数值，这时需要单独赋值
        if (n%2) {
            res[mid][mid] = n*n;
        }

        return res;
        
    }
};
// @lc code=end

