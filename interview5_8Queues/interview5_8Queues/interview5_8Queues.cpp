// interview5_8Queues.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>

using namespace std;

/* 八皇后问题
   在 8 X 8 的网格中，放入八个皇后（棋子），满足的条件是，
   任意两个皇后（棋子）都不能处于同一行、同一列或同一斜线上，
   问有多少种摆放方式？
*/
//row表示行，column表示列，n表示技术满足条件的多少种
int n = 0;
/* isOkCulumn判断当前列填入皇后，是否合理，即是否满足斜线及上列没有元素
   入参：res对应数组，row表示行，col待判断列
   输出：true或false
*/
const bool isOkCulumn(int *res, int row, int col)
{
	//设置左上角
	int leftcolumn = col - 1;
	//设置右上角
	int rightcolumn = col + 1;

	for (int i = row - 1; i >= 0; i--)
	{
		//判断当前格子正上方是否有重复
		if (res[i] == col)
		{
			return false;
		}
		//判断当前格子左上角是否有重复
		if (leftcolumn >= 0)
		{
			if (res[i] == leftcolumn)
			{
				return false;
			}
		}
		//判断当前格子右上角是否有重复
		if (rightcolumn < 8)
		{
			if (res[i] == rightcolumn)
			{
				return false;
			}
		}
		//继续遍历
		leftcolumn--;
		rightcolumn++;
	}
	return true;
}
/* 遍历打印所有情况 */
void showWays(int *result)
{
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 8;j++)
		{
			if (result[i] == j)
			{
				cout << "Q" << " ";
			}
			else
			{
				cout << "*" << " ";
			}
		}
		cout << endl;
	}

	cout << "================" << endl;
}
const void cal8Queens(int *result, int row)
{
	//终止条件
	if (row == 8)
	{
		//输出这个摆法
		showWays(result);
		n++;
		return;
	}
	//每一列的判断
	for (int column = 0;column < 8;column++)
	{
		//判断当前列队位置是否合适
		if (isOkCulumn(result, row, column))
		{
			//保存皇后的位置
			result[row] = column;
			//对下一列寻找数据
			cal8Queens(result, row + 1);
		}
		// 此循环结束后,继续遍历下一种情况,就会形成一种枚举所有可能性
	}
}


void testCal8Queens()
{
	//result为数组，下标为行，数组中存储的是每一行中皇后的存储的列的位置
	int result[8] = {};
	//row表示行，column表示列，n表示技术满足条件的多少种
	int row = 0;
	cal8Queens(result, row);
	cout << "共有" << n << "种排列方法" << endl;
}

int main()
{
	testCal8Queens();
	cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
