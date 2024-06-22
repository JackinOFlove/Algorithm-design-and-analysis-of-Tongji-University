#include<iostream>
#include <vector>
using namespace std;
/*本题思路：
* 本题要求解路径的最大得分，由于有两个数组，使用我们将以nums1为终点的得分为sum1，以nums2为终点的得分为sum2；
* 我们需要判断从哪一个为起点的最后得分高，使用我们要计算从每一个起点开始各自的最高得分；
* 此时我们使用两个指针，一个为i，另一个为j，前者指向nums1的下标，后者指向nums2的下标；
* 再不断遍历的过程中(双下标各自不超过各自的数组长度)，如果两个下标所指向各自数组的值不相等，则哪一个指针向右移，同时该数组的计数总和加上前面的部分；
* 如果两个下标所指向各自数组的值相等，此时两个指针都要右移动，这时还要注意，更新sum1和sum2和当前的两者最大值！
* 这一点非常重要！因为在两个数字相同时可以跑到另一条路径上！相当于前面的得分可以一样(取最大的)！
* 当退出循环后，如果两个数组的长度不同，肯定会存在另一条路径后面还有剩余的情况，此时将后面的部分再加上即可；
* 最后比较两种情况，取最高得分并且对10^9 +7取余后返回，即为最后的结果。
*/
/***************************************************************************
  函数名称：maxSum(vector<int>& nums1, vector<int>& nums2)
  功    能：通过双指针计算比较得出最大得分数
  输入参数：两个数组nums1和nums2
  返 回 值：最后计算的最大得分数
  说    明：由于答案可能很大，将答案对10^9 +7取余后返回。
***************************************************************************/
int maxSum(vector<int>& nums1, vector<int>& nums2)
{
    int i = 0;
    int j = 0;
    long sum1 = 0;
    long sum2 = 0;
    int length1 = nums1.size();
    int length2 = nums2.size();
    while (i < length1 && j < length2)
    {
        if (nums1[i] < nums2[j])
        {
            sum1 += nums1[i];
            i++;
        }
        else if (nums1[i] > nums2[j])
        {
            sum2 += nums2[j];
            j++;
        }
        else
        {
            sum1 += nums1[i];
            sum2 += nums2[j];
            long tempMax = max(sum1, sum2);
            sum1 = sum2 = tempMax;
            i++;
            j++;
        }
    }
    while (i < length1)
        sum1 += nums1[i++];
    while (j < length2)
        sum2 += nums2[j++];
    return (max(sum1, sum2) % 1000000007);
}
/***************************************************************************
  函数名称：主函数
  功    能：完成两个数组nums1和nums2的输入和输出最后结果
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
    int element;
    vector<int> nums1;
    vector<int> nums2;
    cout << "请输入nums1中的内容：";
    while (1)
    {
        cin >> element;
        nums1.push_back(element);
        if (cin.get() == '\n')
            break;
    }
    cout << "请输入nums2中的内容：";
    while (1)
    {
        cin >> element;
        nums2.push_back(element);
        if (cin.get() == '\n')
            break;
    }
    cout << "最大得分为：" << maxSum(nums1, nums2) << endl;
    return 0;
}