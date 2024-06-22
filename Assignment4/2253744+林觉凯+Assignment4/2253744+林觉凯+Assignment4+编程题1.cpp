#include <iostream>
#include <vector>
using namespace std;
/*本题思路：
* 本题需要我们判断在给定的花坛下能否种植好给定数目的花朵，所以我们可以将该花坛还可以种植的花朵数量与需要种植的花朵数量进行比较即可；
* 运用贪心算法，对每一个位置都进行判断，只要是可以种植花朵就尽量种植，这样就可以算出可以再种植的最大花朵数量；
* 对每一个位置都进行判断，可以种植的条件是该位置为空(0)而且两边都没有花朵(1)；
* 主要还是一些边界条件的判断，即如果是第0个位置只要保证该位置的右边没有花朵即可；如果是最后一个位置只要保证该位置的左边没有花朵即可；
* 最后当这个位置种植好花朵之后，记得将这个位置的标志置为1即可。
*/
/***************************************************************************
  函数名称：canPlaceFlowers(vector<int>& flowerbed, int n)
  功    能：通过遍历计算来判断是否在花坛中可以种植n朵花
  输入参数：花坛数组flowerbed和要种植的花数n
  返 回 值：true/false
  说    明：注意判断边界条件即可
***************************************************************************/
bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
	int sumFlowers = 0;
	for (unsigned int i = 0; i < flowerbed.size(); i++)
	{
		if (flowerbed[i] == 0)
		{
			if ((i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
			{
				sumFlowers++;
				flowerbed[i] = 1;
			}
		}
	}
	return (sumFlowers >= n);
}
/***************************************************************************
  函数名称：主函数
  功    能：完成花坛数组flowerbed和花朵数n的输入和输出最后结果
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
	int n = 0;
	int element;
	vector<int> flowerbed;
	cout << "请输入花坛的具体值：";
	while (1)
	{
		cin >> element;
		flowerbed.push_back(element);
		if (cin.get() == '\n')
			break;
	}
	cout << "请输入想要种的花数：";
	cin >> n;
	bool result = canPlaceFlowers(flowerbed, n);
	cout << "结果是：" << boolalpha << result << endl;
	return 0;
}