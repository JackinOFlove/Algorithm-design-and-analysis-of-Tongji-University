#include <iostream>
#include <vector>
using namespace std;
/*����˼·��
��������ʹ�����ֲ�ͬʱ�临�Ӷȵ��㷨��������������
1.ʱ�临�Ӷ�ΪO(mlogn)�Ķ��ֲ���
���ڶ�ά�����ÿһ�У��������Matrix[row][0] <= target && Matrix[row][N - 1] >= target��
��˵��Ҫ���ҵ�Ŀ��ֵtarget�Ĵ�Сλ��ÿһ����С��ֵ������ֵ�м䣬
���ͬʱ����ά�����ÿһ������Ӵ�С�Ĺ������У��������������������
���ʱ�����ǾͿ��Զ�ÿһ�ж��ֲ���ͨ�����ֲ��ҵķ�ʽ���������Ƿ����target���Ԫ�أ�
2.ʱ�临�Ӷ�ΪO(m+n)��Z���β���
���ڶ�ά����ÿһ����˵�Ǵ������������У�ÿһ����˵���ϵ����������У�
���ǿ��Է������Ͻǵ���һ��Ԫ���Ǹ������ģ�������С�ģ��������Ǵ����Ͻǵ��Ǹ�Ԫ�ؿ�ʼ������
���targetС�����Ͻǵ����Ԫ�أ�˵��target������ֵĸ�Ԫ�������������Ԫ���У��ʶ�N--��������ʡȥ��
���target�������Ͻǵ����Ԫ�أ�˵��target������ֵĸ�Ԫ����������ߵ�Ԫ���У��ʶ�row++��������ʡȥ��
���target�������Ͻǵ����Ԫ�أ�˵���ҵ���Ԫ�أ�����true�������������û���ҵ�������false��
*/
/***************************************************************************
  �������ƣ�SearchTarget_BS(vector<vector<int>>matrix, int target, int M, int N)
  ��    �ܣ�ʹ��ʱ�临�Ӷ�ΪO(mlogn)�Ķ��ֲ��ҽ�������
  �����������άvectormatrix��Ŀ��ֵtarget������M������N
  �� �� ֵ��true/false
  ˵    �����÷�����ʱ�临�Ӷ�ΪO(mlogn)
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
  �������ƣ�SearchTarget_Z(vector<vector<int>>matrix, int target, int M, int N)
  ��    �ܣ�ʹ��ʱ�临�Ӷ�ΪO(m+n)��Z���ν��в���
  �����������άvectormatrix��Ŀ��ֵtarget������M������N
  �� �� ֵ��true/false
  ˵    �����÷�����ʱ�临�Ӷ�ΪO(m+n)
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
  �������ƣ�������
  ��    �ܣ�����Matrix��target�����ݣ����ú�����������
  �����������
  �� �� ֵ��0
  ˵    ������
***************************************************************************/
int main()
{
	int M, N, target;
	cout << "����������������������" << endl;
	cin >> M >> N;
	vector<vector<int>>matrix;
	vector<int>temp;
	cout << "�������������ݣ�" << endl;
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
	cout << "������Ŀ��ֵ��";
	cin >> target;
	bool result_BS = SearchTarget_BS(matrix, target, M, N);
	bool result_Z = SearchTarget_Z(matrix, target, M, N);
	cout << "ʹ��ʱ�临�Ӷ�ΪO(mlogn)�Ķ��ֲ��ҵĽ���ǣ�" << boolalpha << result_BS << endl;
	cout << "ʹ��ʱ�临�Ӷ�ΪO(m+n)��Z���β��ҵĽ���ǣ�" << boolalpha << result_Z << endl; 
	return 0;
}