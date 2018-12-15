////空格加入计算
////3.3-4s
////fputs 将数独装换成一个长的字符串

#include"generator.h"
static int num = 0;
static int settle_flag = 0;
//void sudoku_generate(int n)
//{
//	//char str[30];
//	char line[9] = { '5','1','2','3','4','6','7','8','9' };
//	char line1[19] = { '5',' ','1', ' ' ,'2', ' ','3',' ','4', ' ','6',' ','7',' ','8',' ','9','\n','\0' };
//	int shift[9] = { 0,6,12,2,8,14,4,10,16 };
//
//	int pos1[6][3] = { { 3,4,5 },{ 3,5,4 },{ 4,5,3 },{ 4,3,5 },{ 5,4,3 },{ 5,3,4 } };
//	int pos2[6][3] = { { 6,7,8 },{ 6,8,7 },{ 7,6,8 },{ 7,8,6 },{ 8,6,7 },{ 8,7,6 } };
//
//
//	char final[10][19];
//	int i, j, k;
//	int flag = 0;
//	char str[200];
//
//	for (int i = 0; i < 9; i++)//初始值置空格和\0
//	{
//		for (int j = 0; j < 17; j++)
//		{
//			final[i][j] = ' ';
//		}
//		final[i][17] = '\n';
//		final[i][18] = '\0';
//	}
//	final[9][0] = '\n';//第10行只有一个空行
//	final[9][1] = '\0';
//
//
//	//freopen(SUDOKUPATH, "w", stdout);
//	FILE *fp = fopen(GENERATEPATH, "w");
//
//	do//生成第一行
//	{
//		for (int i = 0; i < 9; i++)
//		{
//			line1[2 * i] = line[i];
//		}
//		memcpy(final[0], line1, sizeof(line1));
//		for (i = 1; i < 9; i++)//以第一行为基础，生成一个终局
//		{
//			for (j = 0; j < 18; j += 2)
//			{
//				final[i][j] = line1[(j + shift[i]) % 18];
//			}
//		}
//
//		//在一个终局的基础上改变4-6,7-9行的输出顺序即可
//		for (i = 0; i < 6; i++)
//		{
//			for (j = 0; j < 6; j++)
//			{
//				str[0] = '\0';
//				flag++;
//				for (k = 0; k < 3; k++)//前三行
//				{
//					//fputs(final[k], fp);
//					strcat(str, final[k]);
//				}
//
//				for (k = 0; k < 3; k++)//3 4 5行
//				{
//					//fputs(final[pos1[i][k]], fp);
//					strcat(str, final[pos1[i][k]]);
//				}
//				//if (n > 1)
//				//{
//				for (k = 0; k < 3; k++)
//				{
//					//fputs(final[pos2[j][k]], fp);
//					strcat(str, final[pos2[j][k]]);
//				}
//				//fputs(final[9], fp);//输出回车
//				strcat(str, final[9]);
//				if (n == 1)str[161] = '\0';
//				fputs(str, fp);
//				n--;
//				if (!n) { fclose(fp); return; }
//			}
//		}
//
//	} while (next_permutation(line + 1, line + 9));
//}


//void ques_genetate(int ques_num)
//{
//
//	FILE *fpQues1;
//	FILE *fpBase1;
//	char str[200];
//	
//	fpBase1 = fopen(BASEPATH,"r");
//	fpQues1 = fopen(QUESPATH, "w");
//	ques_board[9][0] = '\n';
//	ques_board[9][1] = '\0';
//	while (ques_num--)
//	{
//		str[0] = '\0';
//		for (int i = 0; i < 9; i++)
//		{
//			fgets(ques_board[i], 20, fpBase1);
//		}fgetc(fpBase1);
//
//		//int base[9] = { 0,3,6,27,30,33,54,57,60 };
//		int base[9] = { 0,6,12,54,60,66,108,114,120 };
//		//int plus[9] = { 0,1,2,9,10,11,18,19,20 };
//		int plus[9] = { 0,2,4,18,20,22,36,38,40 };
//
//		for (int k = 0; k < 9; k++)//每个3*3随机掏空2个
//		{
//
//			int i, j,
//				hole[2];//3*3里面掏的位置
//			hole[0] = rand() % 9;
//			//hole[1] *= 2;
//			hole[1] = rand() % 9;
//			//hole[2] *= 2;
//			while (hole[0] == hole[1])//防止重复
//			{
//				hole[1] = rand() % 9;
//			}
//			for (int t = 0; t < 2; t++)
//			{
//				int dot;
//				dot = base[k] + plus[hole[t]];
//				i = dot / 18;
//				j = dot % 18;
//				ques_board[i][j] = '0';
//			}
//		}
//
//		//已经掏空了18个
//		int others;
//		others = 12 + rand() % 31;//再掏12-41个就可以了
//		while (others--)
//		{
//			int k = rand() % 81;
//			int i = k / 9;
//			int j = k % 9;
//			
//			j *= 2;
//			if (ques_board[i][j] != '0')ques_board[i][j] = '0';
//			else others++;
//		}
//
//		//freopen(QUESPATH, "w", stdout);
//		for (int i = 0; i < 10; i++)
//		{
//			strcat(str, ques_board[i]);
//		}if (!ques_num) str[161] = '\0';
//		fputs(str, fpQues1);
//	}
//	fclose(fpBase1);
//	fclose(fpQues1);
//}

int check(int m, int n)
{
	int i, j, k;
	i = m;
	j = n;
	for (k = 0; k < 18; k+=2)
	{
		if (k != j)//判断行是否满足
		{
			if (ques_board[i][j] == ques_board[i][k])return 0;
		}
		if (k != i)//判断列是否满足
		{
			if (ques_board[i][j] == ques_board[k][j])return 0;
		}
	}
	if (m / 6 == 0)i = 0;
	else if (m / 6 == 1)i = 6;
	else i = 12;

	if (n / 6 == 0)j = 0;
	else if (n / 6 == 1)j = 6;
	else j = 12;

	//int sum = 0;
	for (int c = i; c<i + 6; c+=2)
		for (int d = j; d < j + 6; d+=2)
		{
			if (c != m && d != n && ques_board[m][n] == ques_board[c][d])return 0;
		}
	return 1;
}

void prune(int i, int j, bool point[10])
{
	for (int k = 0; k < 18; k+=2)//行排除
	{
		if (ques_board[i][k] != '0'&&k != j)point[ques_board[i][k] - '0'] = true;
	}
	for (int k = 0; k < 9; k++)//列排除
	{
		if (ques_board[k][j] != '0'&&k != i)point[ques_board[k][j] - '0'] = true;
	}
	int m, n;
	if (i / 3 == 0)m = 0;
	else if (i / 3 == 1)m = 3;
	else if (i / 3 == 2)m = 6;

	if (j / 6 == 0)n = 0;
	else if (j / 6 == 1)n = 6;
	else if (j / 6 == 2)n = 12;

	for (int c = m; c < m + 3; c++)
	{
		for (int d = n; d < n + 6; d+=2)
		{
			if(c!=i&&d!=j&&ques_board[c][d]!='0')point[ques_board[c][d] - '0'] = true;
		}
	}
}


void settle(int pos)
{
	if (pos == 162)
	{
		settle_flag = 1;
		return;
	}
	int i, j, k;
	i = pos / 18;
	j = pos % 18;

	bool point[10] = { false };

	if (ques_board[i][j] == '0')
	{
		prune(i, j, point);

		for (k = 1; k <= 9; k++)
		{
			if (point[k])continue;
			ques_board[i][j] = k + '0';
			//if (check(i, j))
			{
				settle(pos + 2);
			}
			if (settle_flag) { return; }
			ques_board[i][j] = '0';//??
		}
	}
	else
	{
		settle(pos + 2);
	}

	if (settle_flag) { return; }
}


int total=0;
void settle_ques()
{
	
	int begin=0, end = 0;
	FILE *fpQues, *fpSolution;
	char strSolution[200];
	int n = 0;
	fpQues = fopen(QUESPATH, "r");
	fpSolution = fopen(SUDOKUPATH, "w");
	int flag = 0;
	while (1)
	{
		n = 0;
		flag = 0;
		for (int i = 0; i < 9; i++)
		{
			fgets(ques_board[i], 20, fpQues);

		}
		flag = fgetc(fpQues);//读取中间的空行，判断是否文件尾
		
		begin = clock();
		settle_flag = 0;
		settle(0);
		end = clock();
		total += end - begin;
		//freopen(SOLUTIONPATH, "w", stdout);
		strSolution[0] = '\0';
		for (int i = 0; i < 9; i++)
		{
			strcat(strSolution, ques_board[i]);
		}
		if (flag == -1)strSolution[161] = '\0';
		else
		{
			strSolution[161] = '\n';
			strSolution[162] = '\n';
			strSolution[163] = '\0';
		}
		fputs(strSolution, fpSolution);
		if (flag == -1) break;
	}
	fclose(fpQues);
	fclose(fpSolution);
}

int main(int argc, char** argv)
{
	int num=1000;
	int begintime, endtime;
	//scanf("%d", &num);

	begintime = clock();
	//sudoku_generate(num);
	settle_ques();
	//ques_genetate(num);
	endtime = clock();	//计时结束
	//freopen("CON", "w", stdout);
	printf("total time: %d\n",total);
	printf("\nRunning Time：%dms\n", endtime - begintime);

	system("pause");
	return 0;
}






//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//#include<iostream>
//using namespace std;
//
//int main()
//{
//	
//	int k = 0;
//	FILE *fp;
//	char str[10];
//	char str2[10];
//	fp = fopen("test.txt", "r");
//	//fgets(str,10,fp);
//	while (fgetc(fp))
//		;
//	system("pause");
//	return 0;
//}