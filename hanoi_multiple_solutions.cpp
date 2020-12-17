#include<iostream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include"hanoi.h"
#include"cmd_console_tools.h"
using namespace std;

/* -----------------------------------------

	 本文件功能：
	1、放被 hanoi_main.cpp/hanoi_menu.cpp 中的各函数调用的菜单各项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */

int cnt = 1;
int a[20] = { 0 };
int b[20] = { 0 };
int c[20] = { 0 };
int apointer = 0;
int	bpointer = 0;
int	cpointer = 0;


void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

void printPattern(int apointer, int bpointer, int cpointer, int n, HANDLE hout, int cmd) {
	if (cmd != 8 && cmd != 9) {
		gotoxy(hout, 2, 0);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "         =========================" << endl;
		cout << "           A         B         C" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i <= 10; i++) {
			if (a[i] != 10) {
				gotoxy(hout, 11, 12 - i);
			}
			else {
				gotoxy(hout, 10, 12 - i);
			}
			if (i <= apointer - 1) {
				cout << a[i];
			}
			else {
				gotoxy(hout, 10, 12 - i);
				cout << "  ";
			}
		}
		for (int i = 0; i <= 10; i++) {
			if (b[i] != 10) {
				gotoxy(hout, 21, 12 - i);
			}
			else {
				gotoxy(hout, 20, 12 - i);
			}
			if (i <= bpointer - 1) {
				cout << b[i];
			}
			else {
				gotoxy(hout, 20, 12 - i);
				cout << "  ";
			}
		}
		for (int i = 0; i <= 10; i++) {
			if (c[i] != 10) {
				gotoxy(hout, 31, 12 - i);
			}
			else {
				gotoxy(hout, 30, 12 - i);
			}
			if (i <= cpointer - 1) {
				cout << c[i];
			}
			else {
				gotoxy(hout, 30, 12 - i);
				cout << "  ";
			}
		}
	}
	else {
		gotoxy(hout, 0, 27);
		cct_setcolor(0, 15);
		cout << "         =========================" << endl;
		cout << "           A         B         C" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		for (int i = 0; i <= 10; i++) {
			if (a[i] != 10) {
				gotoxy(hout, 11, 26 - i);
			}
			else {
				gotoxy(hout, 10, 26 - i);
			}
			if (i <= apointer - 1) {
				cout << a[i];
			}
			else {
				gotoxy(hout, 10, 26 - i);
				cout << "  ";
			}
		}
		for (int i = 0; i <= 10; i++) {
			if (b[i] != 10) {
				gotoxy(hout, 21, 26 - i);
			}
			else {
				gotoxy(hout, 20, 26 - i);
			}
			if (i <= bpointer - 1) {
				cout << b[i];
			}
			else {
				gotoxy(hout, 20, 26 - i);
				cout << "  ";
			}
		}
		for (int i = 0; i <= 10; i++) {
			if (c[i] != 10) {
				gotoxy(hout, 31, 26 - i);
			}
			else {
				gotoxy(hout, 30, 26 - i);
			}
			if (i <= cpointer - 1) {
				cout << c[i];
			}
			else {
				gotoxy(hout, 30, 26 - i);
				cout << "  ";
			}
		}
	}
}

void choose(int cmd)
{
	if (cmd == 5) {
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		cls(hout);
		printtower(hout);
		gotoxy(hout, 0, 30);
		cct_setcolor(0, 15);
		cout << "按回车键继续";
		char c;
		while (1) {
			c = _getch();
			if (c != 13) {
				continue;
			}
			else {
				break;
			}
		}
		cls(hout);
		cnt = 1;
		return;
	}
	if (cmd == 6) {
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		int n;
		while (1) {
			cin >> n;
			if (n < 1 || n>10) {
				cout << "请输入汉诺塔的层数(1-10)：" << endl;
				cin.clear();
				cin.ignore(2147483647, '\n');
				continue;
			}
			else {
				break;
			}
		}
		cin.clear();
		cin.ignore(2147483647, '\n');
		char s1, s2;
		cout << "请输入起始柱(A-C)：" << endl;
		while (cin >> s1) {
			if (s1 == 'A' || s1 == 'a') {
				s1 = 'A';
				break;
			}
			else if (s1 == 'B' || s1 == 'b') {
				s1 = 'B';
				break;
			}
			else if (s1 == 'C' || s1 == 'c') {
				s1 = 'C';
				break;
			}
			else {
				cin.clear();
				cin.ignore(2147483647, '\n');
				cout << "请输入起始柱(A-C)：" << endl;
				continue;
			}
		}
		cin.clear();
		cin.ignore(2147483647, '\n');
		cout << "请输入目标柱(A-C)：" << endl;
		while (cin >> s2) {
			if (s2 == 'A' || s2 == 'a') {
				s2 = 'A';
			}
			else if (s2 == 'B' || s2 == 'b') {
				s2 = 'B';
			}
			else if (s2 == 'C' || s2 == 'c') {
				s2 = 'C';
			}
			else {
				cin.clear();
				cin.ignore(2147483647, '\n');
				cout << "请输入目标柱(A-C)：" << endl;
				continue;
			}
			if (s2 == s1) {
				cout << "目标柱(" << s2 << ")不能与起始柱(" << s1 << ")相同" << endl;
				cout << "请输入目标柱(A-C)：" << endl;
				cin.clear();
				cin.ignore(2147483647, '\n');
				continue;
			}
			else break;
		}
		cls(hout);
		cout << "从 " << s1 << " 移动到 " << s2 << ", 共 " << n << " 层";
		printplate(hout, n, s1, s2);
		gotoxy(hout, 0, 30);
		cct_setcolor(0, 15);
		cout << "按回车键继续";
		char s;
		while (1) {
			s = _getch();
			if (s != 13) {
				continue;
			}
			else {
				break;
			}
		}
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cls(hout);
		cnt = 1;
		return;
	}
	cout << "请输入汉诺塔的层数(1-10)：" << endl;
	int n;
	while (1) {
		cin >> n;
		if (n < 1 || n>10) {
			cout << "请输入汉诺塔的层数(1-10)：" << endl;
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			break;
		}
	}
	cin.clear();
	cin.ignore(2147483647, '\n');
	char s1, s2;
	cout << "请输入起始柱(A-C)：" << endl;
	while (cin >> s1) {
		if (s1 == 'A' || s1 == 'a') {
			s1 = 'A';
			break;
		}
		else if (s1 == 'B' || s1 == 'b') {
			s1 = 'B';
			break;
		}
		else if (s1 == 'C' || s1 == 'c') {
			s1 = 'C';
			break;
		}
		else {
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "请输入起始柱(A-C)：" << endl;
			continue;
		}
	}
	cin.clear();
	cin.ignore(2147483647, '\n');
	cout << "请输入目标柱(A-C)：" << endl;
	while (cin >> s2) {
		if (s2 == 'A' || s2 == 'a') {
			s2 = 'A';
		}
		else if (s2 == 'B' || s2 == 'b') {
			s2 = 'B';
		}
		else if (s2 == 'C' || s2 == 'c') {
			s2 = 'C';
		}
		else {
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "请输入目标柱(A-C)：" << endl;
			continue;
		}
		if (s2 == s1) {
			cout << "目标柱(" << s2 << ")不能与起始柱(" << s1 << ")相同" << endl;
			cout << "请输入目标柱(A-C)：" << endl;
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else break;

	}
	char s3 = ' ';
	if (s1 == 'A' && s2 == 'B') {
		s3 = 'C';
	}
	else if (s1 == 'A' && s2 == 'C') {
		s3 = 'B';
	}
	else if (s1 == 'B' && s2 == 'C') {
		s3 = 'A';
	}
	else if (s1 == 'B' && s2 == 'A') {
		s3 = 'C';
	}
	else if (s1 == 'C' && s2 == 'A') {
		s3 = 'B';
	}
	else if (s1 == 'C' && s2 == 'B') {
		s3 = 'A';
	}
	int temp = n;
	if (s1 == 'A') {
		for (int i = 0; ; i++) {
			a[i] = temp;
			temp--;
			if (temp == 0) {
				apointer = n;
				break;
			}
		}
	}
	if (s1 == 'B') {
		for (int i = 0; ; i++) {
			b[i] = temp;
			temp--;
			if (temp == 0) {
				bpointer = n;
				break;
			}
		}
	}
	if (s1 == 'C') {
		for (int i = 0; ; i++) {
			c[i] = temp;
			temp--;
			if (temp == 0) {
				cpointer = n;
				break;
			}
		}
	}
	choice(cmd, n, s1, s3, s2);
}

void choice(int cmd, int n, char src, char tmp, char dst)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int delay = 0;
	if (cmd == 1) {
		cnt = 1;
		hanoi(1, n, src, tmp, dst, delay, hout);
		cout << endl;
		cout << "按回车键继续";
		char s;
		while (1) {
			s = _getch();
			if (s != 13) {
				continue;
			}
			else {
				break;
			}
		}
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		cls(hout);
		return;
	}
	if (cmd == 2) {
		cnt = 1;
		hanoi(2, n, src, tmp, dst, delay, hout);
		cout << endl;
		cout << "按回车键继续";
		char s;
		while (1) {
			s = _getch();
			if (s != 13) {
				continue;
			}
			else {
				break;
			}
		}
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		cls(hout);
		return;
	}
	if (cmd == 3) {
		cnt = 1;
		hanoi(3, n, src, tmp, dst, delay, hout);
		cout << endl;
		cout << "按回车键继续";
		char s;
		while (1) {
			s = _getch();
			if (s != 13) {
				continue;
			}
			else {
				break;
			}
		}
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		cls(hout);
		return;
	}
	if (cmd == 4) {
		cnt = 1;
		cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		while (1) {
			cin >> delay;
			if (delay >= 0 && delay <= 5) {
				break;
			}
			else {
				cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)：" << endl;
				continue;
			}
		}
		cls(hout);
		gotoxy(hout, 0, 16);
		cout << "初始:";
		cout << setw(17) << "A:";
		for (int i = 0; i < 10; i++) {
			if (i <= apointer - 1) {
				cout << setw(2) << a[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i <= bpointer - 1) {
				cout << setw(2) << b[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " C:";
		for (int i = 0; i < 10; i++) {
			if (i <= cpointer - 1) {
				cout << setw(2) << c[i];
			}
			else {
				cout << "  ";
			}
		}
		if (delay == 0) {
			char cmd = 'a';
			while (1) {
				cmd = _getch();
				if (cmd == 13) {
					break;
				}
			}
			gotoxy(hout, 2, 0);
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "         =========================" << endl;
			cout << "           A         B         C" << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			printPattern(apointer, bpointer, cpointer, n, hout, cmd);
		}

		Sleep(500);
		hanoi(cmd, n, src, tmp, dst, delay, hout);
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		gotoxy(hout, 0, 30);
		cct_setcolor(0, 15);
		cout << "按回车键继续";
		char c;
		while (1) {
			c = _getch();
			if (c != 13) {
				continue;
			}
			else {
				break;
			}
		}
		cls(hout);
		return;
	}
	else if (cmd == 7) {
		moveplate(7, hout, n, src, dst, 4);
		gotoxy(hout, 0, 30);
		cct_setcolor(0, 15);
		cout << "按回车键继续";
		char s;
		while (1) {
			s = _getch();
			if (s != 13) {
				continue;
			}
			else {
				break;
			}
		}
		cls(hout);
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		return;
	}

	else if (cmd == 8) {
		int delay;
		cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
		while (1) {
			cin >> delay;
			if (delay >= 0 && delay <= 5) {
				break;
			}
			else {
				cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)：" << endl;
				continue;
			}
		}
		cls(hout);
		cout << "从 " << src << " 移动到 " << dst << " , 共 " << n << " 层， 延时设置为 " << delay;
		printplate(hout, n, src, dst);
		printPattern(apointer, bpointer, cpointer, n, hout, cmd);
		gotoxy(hout, 0, 33);
		cout << "初始:  ";
		cout << "A:";
		for (int i = 0; i < 10; i++) {
			if (i <= apointer - 1) {
				cout << setw(2) << a[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i <= bpointer - 1) {
				cout << setw(2) << b[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " C:";
		for (int i = 0; i < 10; i++) {
			if (i <= cpointer - 1) {
				cout << setw(2) << c[i];
			}
			else {
				cout << "  ";
			}
		}
		hanoi(8, n, src, tmp, dst, delay, hout);
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		gotoxy(hout, 0, 38);
		cct_setcolor(0, 15);
		cout << "按回车键继续";
		char c;
		while (1) {
			c = _getch();
			if (c != 13) {
				continue;
			}
			else {
				break;
			}
		}
		cls(hout);
		return;
	}
	else if (cmd == 9) {
		cls(hout);
		printplate(hout, n, src, dst);
		printPattern(apointer, bpointer, cpointer, n, hout, cmd);
		gotoxy(hout, 0, 33);
		cout << "初始:  ";
		cout << "A:";
		for (int i = 0; i < 10; i++) {
			if (i <= apointer - 1) {
				cout << setw(2) << a[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i <= bpointer - 1) {
				cout << setw(2) << b[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " C:";
		for (int i = 0; i < 10; i++) {
			if (i <= cpointer - 1) {
				cout << setw(2) << c[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
		playmode(hout, delay, n, dst);
		cout << endl;
		cout << endl;
		cout << endl;
		char s;
		cct_setcolor(0, 15);
		cout << "按回车键继续";
		while (1) {
			s = _getch();
			if (s != 13) {
				continue;
			}
			else {
				break;
			}
		}
		apointer = 0;
		bpointer = 0;
		cpointer = 0;
		for (int i = 0; i < 20; i++) {
			a[i] = 0;
			b[i] = 0;
			c[i] = 0;
		}
		cnt = 1;
		cls(hout);
		return;
	}
}

void hanoi(int cmd, int n, char src, char tmp, char dst, int delay, HANDLE hout) {
	if (n == 1) {
		print(cmd, n, src, dst, delay, hout);
		cnt++;
	}
	else {
		hanoi(cmd, n - 1, src, dst, tmp, delay, hout);
		print(cmd, n, src, dst, delay, hout);
		cnt++;
		hanoi(cmd, n - 1, tmp, src, dst, delay, hout);
	}
}

void printline(char src, char dst, int n) {
	cout << "第" << setw(4) << cnt << "步" << "(" << n << "#: " << src << "-->" << dst << ")  " << ": ";
	cout << ' ' << "A:";
	for (int i = 0; i < 10; i++) {
		if (i <= apointer - 1) {
			cout << setw(2) << a[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (i <= bpointer - 1) {
			cout << setw(2) << b[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (i <= cpointer - 1) {
			cout << setw(2) << c[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << endl;
}

void print(int cmd, int n, char src, char dst, int delay, HANDLE hout)
{
	if (cmd == 1) {
		cout << n << "# " << src << "-->" << dst << endl;
	}
	else if (cmd == 2) {
		cout << "第" << setw(4) << cnt << " 步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
	}
	else if (cmd == 3) {
		cout << "第" << setw(4) << cnt << "步" << "(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
		if (src == 'A' && dst == 'B') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		else if (src == 'A' && dst == 'C') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (src == 'B' && dst == 'C') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (src == 'B' && dst == 'A') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (src == 'C' && dst == 'A') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (src == 'C' && dst == 'B') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		cout << ' ' << "A:";
		for (int i = 0; i < 10; i++) {
			if (i <= apointer - 1) {
				cout << setw(2) << a[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " B:";
		for (int i = 0; i < 10; i++) {
			if (i <= bpointer - 1) {
				cout << setw(2) << b[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << " C:";
		for (int i = 0; i < 10; i++) {
			if (i <= cpointer - 1) {
				cout << setw(2) << c[i];
			}
			else {
				cout << "  ";
			}
		}
		cout << endl;
	}
	else if (cmd == 4) {
		if (src == 'A' && dst == 'B') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		else if (src == 'A' && dst == 'C') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (src == 'B' && dst == 'C') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (src == 'B' && dst == 'A') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (src == 'C' && dst == 'A') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (src == 'C' && dst == 'B') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		while (1) {
			if (delay == 0) {
				char cmd;
				cmd = _getch();
				if (cmd == 13) {
					break;
				}
			}
			else break;
		}
		gotoxy(hout, 0, 16);
		printline(src, dst, n);
		while (1) {
			if (delay == 0) {
				char cmd;
				cmd = _getch();
				if (cmd == 13) {
					break;
				}
			}
			else break;
		}
		printPattern(apointer, bpointer, cpointer, n, hout, cmd);
		switch (delay) {
		case 1:
			Sleep(700);
			break;
		case 2:
			Sleep(600);
			break;
		case 3:
			Sleep(400);
			break;
		case 4:
			Sleep(200);
			break;
		case 5:
			Sleep(30);
			break;
		}
	}
	else if (cmd == 8) {
		while (1) {
			if (delay == 0) {
				char cmd;
				cmd = _getch();
				if (cmd == 13) {
					break;
				}
			}
			else break;
		}
		moveplate(8, hout, n, src, dst, delay);
		if (src == 'A' && dst == 'B') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		else if (src == 'A' && dst == 'C') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (src == 'B' && dst == 'C') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (src == 'B' && dst == 'A') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (src == 'C' && dst == 'A') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (src == 'C' && dst == 'B') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		printPattern(apointer, bpointer, cpointer, n, hout, 8);
		gotoxy(hout, 0, 33);
		printline(src, dst, n);
		movesleep(delay);
	}
}

void printtower(HANDLE hout) {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 88; j++) {
			if (i == 0) {
				if (j < 1 || (j >= 24 && j <= 32) || (j >= 56 && j <= 64)) {
					cct_showch(j, 15 - i, ' ', 0, 0, 1);
				}
				else {
					cct_showch(j, 15 - i, ' ', 14, 14, 1);
					Sleep(5);
				}
			}
			else {
				if (j == 12 || j == 44 || j == 76) {
					cct_showch(j, 15 - i, ' ', 14, 14, 1);
					Sleep(30);
				}
				else cct_showch(j, 15 - i, ' ', 0, 0, 1);
			}
		}
	}
}

void printplate(HANDLE hout, int n, char s1, char s2) {
	char s3 = ' ';
	if (s1 == 'A' && s2 == 'B') {
		s3 = 'C';
	}
	else if (s1 == 'A' && s2 == 'C') {
		s3 = 'B';
	}
	else if (s1 == 'B' && s2 == 'C') {
		s3 = 'A';
	}
	else if (s1 == 'B' && s2 == 'A') {
		s3 = 'C';
	}
	else if (s1 == 'C' && s2 == 'A') {
		s3 = 'B';
	}
	else if (s1 == 'C' && s2 == 'B') {
		s3 = 'A';
	}
	int temp = n;
	if (s1 == 'A') {
		for (int i = 0; ; i++) {
			a[i] = temp;
			temp--;
			if (temp == 0) {
				apointer = n;
				break;
			}
		}
	}
	if (s1 == 'B') {
		for (int i = 0; ; i++) {
			b[i] = temp;
			temp--;
			if (temp == 0) {
				bpointer = n;
				break;
			}
		}
	}
	if (s1 == 'C') {
		for (int i = 0; ; i++) {
			c[i] = temp;
			temp--;
			if (temp == 0) {
				cpointer = n;
				break;
			}
		}
	}
	printtower(hout);
	if (apointer != 0) {
		for (int i = 0; i < apointer; i++) {
			cct_showch(12 - a[i], 14 - i, ' ', a[i], 0, 2 * a[i] + 1);
			Sleep(20);
		}
	}
	else if (bpointer != 0) {
		for (int i = 0; i < bpointer; i++) {
			cct_showch(44 - b[i], 14 - i, ' ', b[i], 0, 2 * b[i] + 1);
			Sleep(20);
		}
	}
	else if (cpointer != 0) {
		for (int i = 0; i < cpointer; i++) {
			cct_showch(76 - c[i], 14 - i, ' ', c[i], 0, 2 * c[i] + 1);
			Sleep(20);
		}
	}
	cct_setcolor(0, 15);
}

void moveplate(int cmd, HANDLE hout, int n, char s1, char s2, int delay) {
	if (cmd == 7) {
		char s3 = ' ';
		if (s1 == 'A' && s2 == 'B') {
			s3 = 'C';
		}
		else if (s1 == 'A' && s2 == 'C') {
			s3 = 'B';
		}
		else if (s1 == 'B' && s2 == 'C') {
			s3 = 'A';
		}
		else if (s1 == 'B' && s2 == 'A') {
			s3 = 'C';
		}
		else if (s1 == 'C' && s2 == 'A') {
			s3 = 'B';
		}
		else if (s1 == 'C' && s2 == 'B') {
			s3 = 'A';
		}
		cls(hout);
		cout << "从 " << s1 << " 移动到 " << s2 << ",共" << setw(2) << n << " 层";
		printplate(hout, n, s1, s2);
		if (n % 2 != 0) {
			int x = getstartx(s1);
			int y = getstarty(s1);
			int x1 = getfinalx(s2, s1);
			int y1 = getfinaly(s2);
			moveup(x, y, s1, delay);
			hellmove(x, x1, s1, delay);
			movedown(x1, y1, s1, s2, delay);
			cct_setcolor(0, 15);
		}
		else {
			int x = getstartx(s1);
			int y = getstarty(s1);
			int x1 = getfinalx(s3, s1);
			int y1 = getfinaly(s3);
			moveup(x, y, s1, delay);
			hellmove(x, x1, s1, delay);
			movedown(x1, y1, s1, s3, delay);
			cct_setcolor(0, 15);
		}

		return;
	}


	else if (cmd == 8) {
		int x = getstartx(s1);
		int y = getstarty(s1);
		int x1 = getfinalx(s2, s1);
		int y1 = getfinaly(s2);

		moveup(x, y, s1, delay);
		hellmove(x, x1, s1, delay);
		movedown(x1, y1, s1, s2, delay);
	}
}

int getstartx(char s1) {
	if (s1 == 'A') {
		int i = 13;
		return(i - a[apointer - 1] - 1);
	}
	else if (s1 == 'B') {
		int i = 45;
		return(i - b[bpointer - 1] - 1);
	}
	else {
		int i = 77;
		return(i - c[cpointer - 1] - 1);
	}
}

int getstarty(char s1) {
	if (s1 == 'A') {
		return (15 - apointer);
	}
	else if (s1 == 'B') {
		return (15 - bpointer);
	}
	else {
		return (15 - cpointer);
	}
}

int getfinalx(char s3, char s1) {
	if (s3 == 'A') {
		if (s1 == 'B') {
			int i = 13;
			return(i - b[bpointer - 1] - 1);
		}
		else {
			int i = 13;
			return(i - c[cpointer - 1] - 1);
		}
	}
	else if (s3 == 'B') {
		if (s1 == 'A') {
			int i = 45;
			return(i - a[apointer - 1] - 1);
		}
		else if (s1 == 'C') {
			int i = 45;
			return(i - c[cpointer - 1] - 1);
		}
	}
	else {
		if (s1 == 'A') {
			int i = 77;
			return(i - a[apointer - 1] - 1);
		}
		else {
			int i = 77;
			return(i - b[bpointer - 1] - 1);
		}
	}
}

int getfinaly(char s3) {
	if (s3 == 'A') {
		return (14 - apointer);
	}
	else if (s3 == 'B') {
		return (14 - bpointer);
	}
	else {
		return (14 - cpointer);
	}
}

void moveup(int x, int y, char s1, int delay) {
	if (s1 == 'A') {
		for (int i = y; i > 1; i--) {
			cct_showch(x, i, ' ', 0, 0, a[apointer - 1]);
			if (i != 2) {
				cct_showch(12, i, ' ', 14, 14, 1);
			}
			else {
				cct_showch(12, i, ' ', 0, 0, 1);
			}
			cct_showch(13, i, ' ', 0, 0, a[apointer - 1]);
			cct_showch(x, i - 1, ' ', a[apointer - 1], 0, 2 * a[apointer - 1] + 1);
			movesleep(delay);
		}
	}
	else if (s1 == 'B') {
		for (int i = y; i > 1; i--) {
			cct_showch(x, i, ' ', 0, 0, b[bpointer - 1]);
			if (i != 2) {
				cct_showch(44, i, ' ', 14, 14, 1);
			}
			else {
				cct_showch(44, i, ' ', 0, 0, 1);
			}
			cct_showch(45, i, ' ', 0, 0, b[bpointer - 1]);
			cct_showch(x, i - 1, ' ', b[bpointer - 1], 0, 2 * b[bpointer - 1] + 1);
			movesleep(delay);
		}
	}
	else if (s1 == 'C') {
		for (int i = y; i > 1; i--) {
			cct_showch(x, i, ' ', 0, 0, c[cpointer - 1]);
			if (i != 2) {
				cct_showch(76, i, ' ', 14, 14, 1);
			}
			else {
				cct_showch(76, i, ' ', 0, 0, 1);
			}
			cct_showch(77, i, ' ', 0, 0, c[cpointer - 1]);
			cct_showch(x, i - 1, ' ', c[cpointer - 1], 0, 2 * c[cpointer - 1] + 1);
			movesleep(delay);
		}
	}
}

void hellmove(int x, int x1, char s1, int delay) {
	if (s1 == 'A') {
		int y = 1;
		for (int i = x; i <= x1; i++) {
			cct_showch(i - 1, y, ' ', 0, 0, 2 * a[apointer - 1] + 1);
			cct_showch(i, y, ' ', a[apointer - 1], 0, 2 * a[apointer - 1] + 1);
			movesleep(delay);
		}
	}
	else if (s1 == 'B') {
		int y = 1;
		if (x - x1 < 0) {
			for (int i = x; i <= x1; i++) {
				cct_showch(i - 1, y, ' ', 0, 0, 2 * b[bpointer - 1] + 1);
				cct_showch(i, y, ' ', b[bpointer - 1], 0, 2 * b[bpointer - 1] + 1);
				movesleep(delay);
			}
		}
		else {
			for (int i = x; i > x1; i--) {
				cct_showch(i, y, ' ', 0, 0, 2 * b[bpointer - 1] + 1);
				cct_showch(i - 1, y, ' ', b[bpointer - 1], 0, 2 * b[bpointer - 1] + 1);
				movesleep(delay);
			}
		}
	}
	else if (s1 == 'C') {
		int y = 1;
		for (int i = x; i > x1; i--) {
			cct_showch(i, y, ' ', 0, 0, 2 * c[cpointer - 1] + 1);
			cct_showch(i - 1, y, ' ', c[cpointer - 1], 0, 2 * c[cpointer - 1] + 1);
			movesleep(delay);
		}
	}
}

void movedown(int x1, int y1, char s1, char s2, int delay) {
	if (s2 == 'A') {
		if (s1 == 'B') {
			for (int i = 1; i < y1; i++) {
				cct_showch(x1, i, ' ', 0, 0, b[bpointer - 1]);
				if (i > 2) {
					cct_showch(12, i, ' ', 14, 14, 1);
				}
				else {
					cct_showch(12, i, ' ', 0, 0, 1);
				}
				cct_showch(13, i, ' ', 0, 0, b[bpointer - 1]);
				cct_showch(x1, i + 1, ' ', b[bpointer - 1], 0, 2 * b[bpointer - 1] + 1);
				movesleep(delay);
			}
		}
		else if (s1 == 'C') {
			for (int i = 1; i < y1; i++) {
				cct_showch(x1, i, ' ', 0, 0, c[cpointer - 1]);
				if (i > 2) {
					cct_showch(12, i, ' ', 14, 14, 1);
				}
				else {
					cct_showch(12, i, ' ', 0, 0, 1);
				}
				cct_showch(13, i, ' ', 0, 0, c[cpointer - 1]);
				cct_showch(x1, i + 1, ' ', c[cpointer - 1], 0, 2 * c[cpointer - 1] + 1);
				movesleep(delay);
			}
		}
	}
	else if (s2 == 'B') {
		if (s1 == 'A') {
			for (int i = 1; i < y1; i++) {
				cct_showch(x1, i, ' ', 0, 0, a[apointer - 1]);
				if (i > 2) {
					cct_showch(44, i, ' ', 14, 14, 1);
				}
				else {
					cct_showch(44, i, ' ', 0, 0, 1);
				}
				cct_showch(45, i, ' ', 0, 0, a[apointer - 1]);
				cct_showch(x1, i + 1, ' ', a[apointer - 1], 0, 2 * a[apointer - 1] + 1);
				movesleep(delay);
			}
		}
		else if (s1 == 'C') {
			for (int i = 1; i < y1; i++) {
				cct_showch(x1, i, ' ', 0, 0, c[cpointer - 1]);
				if (i > 2) {
					cct_showch(44, i, ' ', 14, 14, 1);
				}
				else {
					cct_showch(44, i, ' ', 0, 0, 1);
				}
				cct_showch(45, i, ' ', 0, 0, c[cpointer - 1]);
				cct_showch(x1, i + 1, ' ', c[cpointer - 1], 0, 2 * c[cpointer - 1] + 1);
				movesleep(delay);
			}
		}
	}
	else if (s2 == 'C') {
		if (s1 == 'A') {
			for (int i = 1; i < y1; i++) {
				cct_showch(x1, i, ' ', 0, 0, a[apointer - 1]);
				if (i > 2) {
					cct_showch(76, i, ' ', 14, 14, 1);
				}
				else {
					cct_showch(76, i, ' ', 0, 0, 1);
				}
				cct_showch(77, i, ' ', 0, 0, a[apointer - 1]);
				cct_showch(x1, i + 1, ' ', a[apointer - 1], 0, 2 * a[apointer - 1] + 1);
				movesleep(delay);
			}
		}
		else if (s1 == 'B') {
			for (int i = 1; i < y1; i++) {
				cct_showch(x1, i, ' ', 0, 0, b[bpointer - 1]);
				if (i > 2) {
					cct_showch(76, i, ' ', 14, 14, 1);
				}
				else {
					cct_showch(76, i, ' ', 0, 0, 1);
				}
				cct_showch(77, i, ' ', 0, 0, b[bpointer - 1]);
				cct_showch(x1, i + 1, ' ', b[bpointer - 1], 0, 2 * b[bpointer - 1] + 1);
				movesleep(delay);
			}
		}
	}
}

void movesleep(int delay) {
	switch (delay) {
	case 1:
		Sleep(200);
	case 2:
		Sleep(100);
	case 3:
		Sleep(50);
	case 4:
		Sleep(10);
	case 5:
		Sleep(0);
	}
}

void playmode(HANDLE hout, int delay, int n, char dst) {
	while (1) {
		cout << endl;
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
		cct_showch(60, 35, ' ', 0, 15, 100);
		gotoxy(hout, 60, 35);
		char s[2];
		char tmp;
		int i = 0;
		bool flag = 1;
		bool halt = 1;
		while (1) {
			tmp = _getch();
			if (tmp == 13) {
				if (i == 2) {
					if (flag == 1) {
						if (s[0] == s[1]) {
							s[0] = ' ';
							s[1] = ' ';
							i = 0;
							cct_showch(60, 35, ' ', 0, 15, 100);
							gotoxy(hout, 60, 35);
							continue;
						}
						else if (s[0] != s[1]) {
							if (s[0] == 'a' || s[0] == 'A') {
								if (apointer == 0) {
									cout << endl;
									cout << "源柱为空";
									Sleep(500);
									s[0] = ' ';
									s[1] = ' ';
									i = 0;
									cct_showch(60, 35, ' ', 0, 15, 100);
									gotoxy(hout, 60, 35);
									continue;
								}
								else {
									if (s[1] == 'b' || s[1] == 'B') {
										if (a[apointer - 1] > b[bpointer - 1] && b[bpointer - 1] != 0) {
											cout << endl;
											cout << "大盘压小盘，非法移动！";
											Sleep(500);
											s[0] = ' ';
											s[1] = ' ';
											i = 0;
											cct_showch(60, 35, ' ', 0, 15, 100);
											gotoxy(hout, 60, 35);
											continue;
										}
										else break;
									}

									if (s[1] == 'c' || s[1] == 'C') {
										if (a[apointer - 1] > c[cpointer - 1] && c[cpointer - 1] != 0) {
											cout << endl;
											cout << "大盘压小盘，非法移动！";
											Sleep(500);
											s[0] = ' ';
											s[1] = ' ';
											i = 0;
											cct_showch(60, 35, ' ', 0, 15, 100);
											gotoxy(hout, 60, 35);
											continue;
										}
										else break;
									}
								}
							}
							else if (s[0] == 'b' || s[0] == 'B') {
								if (bpointer == 0) {
									cout << endl;
									cout << "源柱为空";
									Sleep(500);
									s[0] = ' ';
									s[1] = ' ';
									i = 0;
									cct_showch(60, 35, ' ', 0, 15, 100);
									gotoxy(hout, 60, 35);
									continue;
								}
								else {
									if (s[1] == 'a' || s[1] == 'A') {
										if (b[bpointer - 1] > a[apointer - 1] && a[apointer - 1] != 0) {
											cout << endl;
											cout << "大盘压小盘，非法移动！";
											Sleep(500);
											s[0] = ' ';
											s[1] = ' ';
											i = 0;
											cct_showch(60, 35, ' ', 0, 15, 100);
											gotoxy(hout, 60, 35);
											continue;
										}
										else break;
									}

									if (s[1] == 'c' || s[1] == 'C') {
										if (b[bpointer - 1] > c[cpointer - 1] && c[cpointer - 1] != 0) {
											cout << endl;
											cout << "大盘压小盘，非法移动！";
											Sleep(500);
											s[0] = ' ';
											s[1] = ' ';
											i = 0;
											cct_showch(60, 35, ' ', 0, 15, 100);
											gotoxy(hout, 60, 35);
											continue;
										}
										else break;
									}
								}

							}
							else if (s[0] == 'c' || s[0] == 'C') {
								if (cpointer == 0) {
									cout << endl;
									cout << "源柱为空";
									Sleep(500);
									s[0] = ' ';
									s[1] = ' ';
									i = 0;
									cct_showch(60, 35, ' ', 0, 15, 100);
									gotoxy(hout, 60, 35);
									continue;
								}
								else {
									if (s[1] == 'b' || s[1] == 'B') {
										if (c[cpointer - 1] > b[bpointer - 1] && b[bpointer - 1] != 0) {
											cout << endl;
											cout << "大盘压小盘，非法移动！";
											Sleep(500);
											s[0] = ' ';
											s[1] = ' ';
											i = 0;
											cct_showch(60, 35, ' ', 0, 15, 100);
											gotoxy(hout, 60, 35);
											continue;
										}
										else break;
									}

									if (s[1] == 'a' || s[1] == 'A') {
										if (c[cpointer - 1] > a[apointer - 1] && a[apointer - 1] != 0) {
											cout << endl;
											cout << "大盘压小盘，非法移动！";
											Sleep(500);
											s[0] = ' ';
											s[1] = ' ';
											i = 0;
											cct_showch(60, 35, ' ', 0, 15, 100);
											gotoxy(hout, 60, 35);
											continue;
										}
										else break;
									}
								}
							}
						}
					}
					else {
						s[0] = ' ';
						s[1] = ' ';
						i = 0;
						cct_showch(60, 35, ' ', 0, 15, 100);
						gotoxy(hout, 60, 35);
						continue;
					}
				}
				if (halt == 0) {
					break;
				}
				else {
					s[0] = ' ';
					s[1] = ' ';
					i = 0;
					cct_showch(60, 35, ' ', 0, 15, 100);
					gotoxy(hout, 60, 35);
					continue;
				}
			}
			if (tmp == '\b') {
				continue;
			}
			cout << tmp;

			if (tmp == 'A' || tmp == 'a' || tmp == 'b' || tmp == 'B' || tmp == 'c' || tmp == 'C') {
				s[i] = tmp;
				i++;
			}
			else if (tmp == 'Q' || tmp == 'q') {
				halt = 0;
			}
			else {
				flag = 0;
			}

		}

		if (halt == 0) {
			cout << endl;
			cout << "游戏中止!!!!!";
			return;
		}

		for (int i = 0; i < 2; i++) {
			if (s[i] == 'a' || s[i] == 'A')s[i] = 'A';
			if (s[i] == 'b' || s[i] == 'B')s[i] = 'B';
			if (s[i] == 'c' || s[i] == 'C')s[i] = 'C';
		}


		int x = getstartx(s[0]);
		int y = getstarty(s[0]);
		int x1 = getfinalx(s[1], s[0]);
		int y1 = getfinaly(s[1]);
		moveup(x, y, s[0], delay);
		hellmove(x, x1, s[0], delay);
		movedown(x1, y1, s[0], s[1], delay);
		cct_setcolor(0, 15);

		if (s[0] == 'A' && s[1] == 'B') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		else if (s[0] == 'A' && s[1] == 'C') {
			int temp = a[apointer - 1];
			a[apointer - 1] = 0;
			apointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (s[0] == 'B' && s[1] == 'C') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			c[cpointer] = temp;
			cpointer++;
		}
		else if (s[0] == 'B' && s[1] == 'A') {
			int temp = b[bpointer - 1];
			b[bpointer - 1] = 0;
			bpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (s[0] == 'C' && s[1] == 'A') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			a[apointer] = temp;
			apointer++;
		}
		else if (s[0] == 'C' && s[1] == 'B') {
			int temp = c[cpointer - 1];
			c[cpointer - 1] = 0;
			cpointer--;
			b[bpointer] = temp;
			bpointer++;
		}
		printPattern(apointer, bpointer, cpointer, n, hout, 8);
		gotoxy(hout, 0, 33);
		printline(s[0], s[1], n);
		

		if (dst == 'A') {
			if (apointer == n)break;
			else continue;
		}
		if (dst == 'B') {
			if (bpointer == n)break;
			else continue;
		}
		if (dst == 'C') {
			if (cpointer == n)break;
			else continue;
		}
	}
	cout << endl;
	cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
	cct_showch(60, 35, ' ', 0, 15, 100);
	gotoxy(hout, 60, 35);
	cout << endl;
	cout << "游戏结束!!!!!";



}
