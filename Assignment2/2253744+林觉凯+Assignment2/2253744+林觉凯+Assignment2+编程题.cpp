#include <iostream>
#include <vector>
using namespace std;
/*本题思路：
本题我们使用两种不同时间复杂度的算法来进行问题的求解
1.时间复杂度为O(mlogn)的二分查找
对于二维矩阵的每一行，如果满足Matrix[row][0] <= target && Matrix[row][N - 1] >= target，
即说明要查找的目标值target的大小位于每一行最小的值和最大的值中间，
与此同时，二维矩阵的每一行满足从大到小的规律排列，满足二分搜索的条件，
这个时候我们就可以对每一行二分查找通过二分查找的方式进行搜索是否存在target这个元素；
2.时间复杂度为O(m+n)的Z字形查找
对于二维矩阵每一行来说是从左到右升序排列，每一列来说从上到下升序排列，
我们可以发现左上角的那一个元素是该行最大的，该列最小的，所以我们从左上角的那个元素开始搜索：
如果target小于左上角的这个元素，说明target不会出现的该元素所在列下面的元素中，故而N--，将此列省去；
如果target大于左上角的这个元素，说明target不会出现的该元素所在行左边的元素中，故而row++，将此行省去；
如果target等于左上角的这个元素，说明找到该元素，返回true，如果在搜索后还没有找到，返回false。
*/
/***************************************************************************
  函数名称：SearchTarget_BS(vector<vector<int>>matrix, int target, int M, int N)
  功    能：使用时间复杂度为O(mlogn)的二分查找进行搜索
  输入参数：二维vectormatrix，目标值target，行数M，列数N
  返 回 值：true/false
  说    明：该方法的时间复杂度为O(mlogn)
***************************************************************************/
bool SearchTarget_BS(vector<vector<int>>matrix, int target, int M, int N)
{
	for (int row = 0; row < M; row++)
	{
		if (matrix[row][0] <= target && matrix[row][N - 1] >= target)
		{
			int left = 0;
			int right = N - 1;
			while (left <= right)
			{
				int middle = left + (right - left) / 2;
				if (matrix[row][middle] < target)
					left = middle + 1;
				else if (matrix[row][middle] > target)
					right = middle - 1;
				else
					return true;
			}
		}
	}
	return false;
}
/***************************************************************************
  函数名称：SearchTarget_Z(vector<vector<int>>matrix, int target, int M, int N)
  功    能：使用时间复杂度为O(m+n)的Z字形进行查找
  输入参数：二维vectormatrix，目标值target，行数M，列数N
  返 回 值：true/false
  说    明：该方法的时间复杂度为O(m+n)
***************************************************************************/
bool SearchTarget_Z(vector<vector<int>>matrix, int target, int M, int N)
{
	int row = 0;
	while (M > row && N > 0)
	{
		if (matrix[row][N - 1] > target)
			N--;
		else if (matrix[row][N - 1] < target)
			row++;
		else
			return true;
	}
	return false;
}
/***************************************************************************
  函数名称：主函数
  功    能：输入Matrix和target的内容，调用函数，输出结果
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
	int M, N, target;
	cout << "请输入矩阵的行数和列数：" << endl;
	cin >> M >> N;
	vector<vector<int>>matrix;
	vector<int>temp;
	cout << "请输入矩阵的内容：" << endl;
	for (int i = 0; i < M; i++)
	{
		temp.clear();
		for (int j = 0; j < N; j++)
		{
			int element;
			cin >> element;
			temp.push_back(element);
		}
		matrix.push_back(temp);
	}
	cout << "请输入目标值：";
	cin >> target;
	bool result_BS = SearchTarget_BS(matrix, target, M, N);
	bool result_Z = SearchTarget_Z(matrix, target, M, N);
	cout << "使用时间复杂度为O(mlogn)的二分查找的结果是：" << boolalpha << result_BS << endl;
	cout << "使用时间复杂度为O(m+n)的Z字形查找的结果是：" << boolalpha << result_Z << endl; 
	return 0;
}