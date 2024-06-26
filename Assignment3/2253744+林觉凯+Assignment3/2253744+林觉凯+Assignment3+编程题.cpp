#include <iostream>
#include <vector>
using namespace std;
/*本题思路：
* 机器人从(0,0)点出发，走到(m - 1,n - 1)终点，并且只能向右和向下移动;
* 由于机器人移动的规律性，我们就可以发现，到达每一个位置只能从两个方向：即从上方或者从左方移动一格;
* 所以我们采用动态规划的思想，首先确定dp[i][j]的含义：从(0,0)到(i,j)点所有的不同路径的条数;
* 动态规划的递推公式，本题中，到达(i,j)的方法有两种：从上方向下移动一格或从左方向右移动一格;
* 所以可以确定状态转移方程： dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
* 接着进行dp数组的初始化，发现第一行和第一列的位置只能有一种到达方式：即一直向右走或一直向下走，故dp[i][0] = dp[0][j] = 1;
* 这样我们就确定的本题动态规划的大致流程，通过遍历得出最后的答案。
*/
/***************************************************************************
  函数名称：uniquePaths(int m, int n)
  功    能：通过动态规划的方法求解不同路径的总数
  输入参数：网格的层数m和n
  返 回 值：从左上角到右下角不同路径的总数
  说    明：dp[i][j]表示从左上角到(i,j)位置不同路径的总数
***************************************************************************/
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        dp[i][0] = 1;
    for (int j = 0; j < n; j++)
        dp[0][j] = 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m - 1][n - 1];
}
/***************************************************************************
  函数名称：主函数
  功    能：输入网格的层数m,n并且对其进行健壮性检验，输出结果
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
    int m, n;
    cout << "请依次输入m,n(空格进行分隔):";
    while (1) 
    {
        cin >> m >> n;
        if (cin.good() == 0)
        {
            cout << "输入错误，请重新输入:";
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        break;
    }
    int ways = uniquePaths(m, n);
    cout << "共有不同路径的条数为:\t" << ways << endl;
    return 0;
}