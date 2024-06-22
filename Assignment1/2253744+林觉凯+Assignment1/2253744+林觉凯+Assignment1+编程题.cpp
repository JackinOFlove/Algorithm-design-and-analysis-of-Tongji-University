#include <iostream>
#include <vector>
using namespace std;
/*本题思路：
1.最后我们是要比较两个玩家最终得分的大小，所以我们可以比较两个玩家得分的差值就行，
我们站在玩家1的视角，最后用玩家1的分数减去玩家2的分数，大于等于0则玩家1获胜，反之玩家2获胜。
2.每个回合玩家取数字要么从头要么从尾取，故而剩下来的数组是原来数组的一个字数组，
故而子数组又第一个元素下标和最后一个元素下标，分别设为start和end。
当start=end时，子数组只剩下最后一个数，玩家只能选择这个数；
当start<end时，可以选择子数组中的numbers[start]或numbers[end]。
选完之后再又对方玩家选择，所以这是一个递归的过程。
3.当每次选取数字的时候，玩家肯定会选择那个人自己分数最大化的数字，
所以在每次选择的时候，要比较start和end处的数字，看选择哪一个能让自己分数最大
*/
/***************************************************************************
  函数名称：Get_maxdifferent(vector<int>& numbers, int start, int end)
  功    能：计算玩家1和玩家2分数差值最大的值
  输入参数：数组numbers，子数组的第一个start，子数组的最后一个end
  返 回 值：在numbers数组中能让玩家1和玩家2有最大的差值的值
  说    明：无
***************************************************************************/
int Get_maxdifferent(vector<int>& numbers, int start, int end)
{
	if (start == end)
		return numbers[start];
	int select_start = numbers[start] - Get_maxdifferent(numbers, start + 1, end);
	int select_end = numbers[end] - Get_maxdifferent(numbers, start, end - 1);
	return max(select_start, select_end);
}
/***************************************************************************
  函数名称：Get_result(vector<int>& numbers)
  功    能：判断返回值时true还是false
  输入参数：数组numbers
  返 回 值：true/false
  说    明：无
***************************************************************************/
bool Get_result(vector<int>& numbers)
{
	int Maxdifferent = Get_maxdifferent(numbers, 0, numbers.size() - 1);
	if (Maxdifferent >= 0)
		return true;
	else
		return false;
}
/***************************************************************************
  函数名称：主函数
  功    能：输入数组元素，调用函数，输出结果
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
	int element;
	vector <int> numbers;
	cout << "Please enter a string of numbers:" << endl;
	while (1)
	{
		cin >> element;
		numbers.push_back(element);
		if(cin.get()=='\n')
			break; 
	}
	bool flag = Get_result(numbers);
	cout << "The answer is:" << endl << boolalpha << flag << endl;
	return 0;
}