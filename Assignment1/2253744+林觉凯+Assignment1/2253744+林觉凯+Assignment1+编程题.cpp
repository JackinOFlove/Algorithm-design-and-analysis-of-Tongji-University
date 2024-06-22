#include <iostream>
#include <vector>
using namespace std;
/*����˼·��
1.���������Ҫ�Ƚ�����������յ÷ֵĴ�С���������ǿ��ԱȽ�������ҵ÷ֵĲ�ֵ���У�
����վ�����1���ӽǣ���������1�ķ�����ȥ���2�ķ��������ڵ���0�����1��ʤ����֮���2��ʤ��
2.ÿ���غ����ȡ����Ҫô��ͷҪô��βȡ���ʶ�ʣ������������ԭ�������һ�������飬
�ʶ��������ֵ�һ��Ԫ���±�����һ��Ԫ���±꣬�ֱ���Ϊstart��end��
��start=endʱ��������ֻʣ�����һ���������ֻ��ѡ���������
��start<endʱ������ѡ���������е�numbers[start]��numbers[end]��
ѡ��֮�����ֶԷ����ѡ����������һ���ݹ�Ĺ��̡�
3.��ÿ��ѡȡ���ֵ�ʱ����ҿ϶���ѡ���Ǹ����Լ�������󻯵����֣�
������ÿ��ѡ���ʱ��Ҫ�Ƚ�start��end�������֣���ѡ����һ�������Լ��������
*/
/***************************************************************************
  �������ƣ�Get_maxdifferent(vector<int>& numbers, int start, int end)
  ��    �ܣ��������1�����2������ֵ����ֵ
  �������������numbers��������ĵ�һ��start������������һ��end
  �� �� ֵ����numbers�������������1�����2�����Ĳ�ֵ��ֵ
  ˵    ������
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
  �������ƣ�Get_result(vector<int>& numbers)
  ��    �ܣ��жϷ���ֵʱtrue����false
  �������������numbers
  �� �� ֵ��true/false
  ˵    ������
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
  �������ƣ�������
  ��    �ܣ���������Ԫ�أ����ú�����������
  �����������
  �� �� ֵ��0
  ˵    ������
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