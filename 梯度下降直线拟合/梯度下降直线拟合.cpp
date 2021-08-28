﻿// 梯度下降直线拟合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	//1. 定义训练数据, 学习速率
	double Train_set_x[17] = { 1.1, 2.4, 2.4, 3.1, 2.2, 4.42, 5.43, 4.5, 5.28, 7.35, 10, 8.27, 12.6, 12.8, 9.69, 15.0, 13.69 };
	double Train_set_y[17] = { 2.5, 1.7, 3, 4.0, 5.2, 6.53, 7.33, 8.7, 4.2, 5.8, 6.05, 8.05, 7.41, 8.89, 10.12, 9.72, 10.83 };
	double m = 17.00;  //共有17个点
	double alpha = 0.0001;

	//2. 定义好过程中需要的变量
	double temp_1 = 0;  //更新x1, x2的值
	double temp_2 = 0;
	double sum_1, sum_2;  //所有点累加
	double x1 = 0;
	double x2 = 0;

	//3. 进行梯度下降
	int epoch = 100;
	for (int i = 1; i < epoch; i++) {
		sum_1 = 0;
		sum_2 = 0;
		for (int j = 0; j < m; j++) {
			sum_1 += (x2 + x1 * Train_set_x[j] - Train_set_y[j]) * Train_set_x[j];
		}
		for (int k = 0; k < m; k++) {
			sum_2 += x2 + x1 * Train_set_x[k] - Train_set_y[k];
		}

		temp_1 = x1 - alpha * (1 / m)*sum_1;
		temp_2 = x2 - alpha * (1 / m)*sum_2;

		//4. 检验是否为最优解
		//若x1, x2都不再改变, 即已经收敛到了最优处, 就可以退出循环, 得到最优解
		//注意这里是一个完整的训练集一更新temp, 训练样本是确定的, 可以得到精确地相等
		if ((temp_1 == x1) && (temp_2 == x2)) {
			break;
		}
		//5. 若未达到最优解的条件, 则更新x1, x2的值, 进行下一次循环
		else {
			x1 = temp_1;
			x2 = temp_2;
		}

		std::cout << "拟合的结果为: y=" << x1 << "x+" << x2 << endl;
	}










    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
