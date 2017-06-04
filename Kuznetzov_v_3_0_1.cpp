// Kuznetzov.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//


#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <WinUser.h>
#include <ctime>
#include <signal.h>
#include <cmath>

using namespace std;

void show(int ** func, int ** func2, int num, int num2, int n) {

	cout << endl << "âíåøíèõ: " << num << "   âíóòðåííèõ: " << num2 << endl << endl;
	cout << "ìàññèâ âíåøíèõ ôóíêöèé:" ;
	cout << "              ";
	cout << "ìàññèâ âíóòðåííèõ ôóíêöèé:" << endl;

	int n2 = n*n;
	for (int i = 0; i < num2; i++) {

		if (i <= num-1) {
			for (int j = 0; j < n2; j++) {
				cout << func[i][j] << " ";
			}
		}
		else {
			for (int k = 0; k < n2; k++) cout << "  ";
		}
		
		cout << "                             ";

		for (int j = 0; j < n2; j++) {
			cout << func2[i][j] << " ";
		}
		cout << endl;
	}


}

void func_cal(int * funcmain, int * arg1, int * arg2, int * newf, int n) {

	

	for (int i=0;i<(n*n);i++)

		{newf[i]=funcmain[arg1[i]*n+arg2[i]]}

}

void add(int ** func, int * newf, int & num, int n) {
	bool flag = 0;

	for (int k = 0; k < num; k++) {

		for (int i = 0; i < n*n; i++) {
			if (newf[i] == func[k][i]) 	flag = 1;
			else { flag = 0; break; }
		}
		if (flag == 1) break;
	}

	if (flag == 0) {

		for (int i = 0; i < n*n; i++) {
			func[num][i] = newf[i];
		}
		num++;
	}
}

bool newf7(int ** func, int * newf, int num, int n) {
	bool flag = 0;

	for (int k = 0; k < num; k++) {

		for (int i = 0; i < n*n; i++) {
			if (newf[i] == func[k][i]) 	flag = 1;
			else { flag = 0; break; }
		}
		if (flag == 1) break;
	}

	if (flag == 0) 
		return 1;
	else return 0;
}

void check(int ** func, int ** func2, int & num, int & num2, bool NOT, bool showcalc, int n) {

	int * arg1 = new int[n*n];
	int * arg2 = new int[n*n];
	int * newf = new int[n*n];
	int * funcmain = new int[n*n];

	int end = 0; 
	int times = 1;

	while (end < 500) {
		end++;

		for (int i = 0; i < num2; i++) {
			for (int m = 0; m < num2; m++) {
				for (int q = 0; q < num; q++) {

					for (int j = 0; j < n*n; j++) {
						arg1[j] = func2[i][j];
						arg2[j] = func2[m][j];
						funcmain[j] = func[q][j];

					}

					func_cal(funcmain, arg1, arg2, newf, n);

					if (showcalc) {
						bool newfunc = newf7(func, newf, num, n);
						//newfunc = 1;
						if (newfunc) {
							cout << endl << times << ")///////////////////////////////////////////////////////////////////////" << endl;
							show(func, func2, num, num2 , n);
							times++;

							cout << "âíóòðåííÿÿ ôóíêöèÿ 1:" << endl;
							for (int f = 0; f < n*n; f++) cout << arg1[f] << " ";

							cout << endl << "âíóòðåííÿÿ ôóíêöèÿ 2:" << endl;
							for (int f = 0; f < n*n; f++) cout << arg2[f] << " ";

							cout << endl << "ïîäñòàâëÿåì âî âíåøíþþ ôóíêöèþ 3:" << endl;
							for (int f = 0; f < n*n; f++) cout << funcmain[f] << " ";

							cout << endl << "ïîëó÷àåì íîâóþ (" << num + 1 << ")" << endl;
							for (int f = 0; f < n*n; f++) cout << newf[f] << " ";
							cout << endl << endl;
						}

					}
					
					add(func, newf, num,n);
					add(func2, newf, num2, n);

					if (num == pow(n, pow(n,n)) ) goto next;

				}
			}
		}
	}

next:

	delete[] arg1;
	delete[] arg2;
	delete[] newf;
	delete[] funcmain;

}

int main()
{
	system("title Kuznetzov_v.3.0.1");
	setlocale(LC_ALL, "russian");

	cout << "ââåäèòå ðàçðÿäíîñòü ëîãèêè (2-...)" << endl;
	int n = 2;
	cin >> n;

	if (n < 2) n = 2;
	int n2 = pow(n, (n *n));
	if (n > 3) n2 = 100000;

	int ** func = new int*[n2];
		for (int i = 0; i < n2; i++) {
			func[i] = new int[n*n];
		}

	int ** func2 = new int*[n2];// ìàññèâ âíóòðåííèõ ô öèé
		for (int i = 0.; i < n2; i++) {
			func2[i] = new int[n*n];
		}

	int num=0;
	int num2=0;

	int * arg1 = new int[n*n]; 
	int * arg2 = new int[n*n]; 
	int * newf = new int[n*n];
	int * funcmain = new int[n*n];


	//cout << "use NOT?" << endl;
	bool NOT = 0;
	//cin >> NOT;

	//cout << "add selector in func2? " << endl;
	bool sel = 1;
	//cin >> sel;

	if (sel == 1) {
		int k = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				func2[0][k] = i;
				func2[1][k] = j;
				k++;
			}
		}
	}


		cout << "ââåäèòå êîëè÷åñòâî íà÷àëüíûõ ôóíêöèé" << endl;

		cin >> num;
		if (sel == 1) num2 =2;

		cout << "begin typing functions" << endl;
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < n*n; j++) {
				cin >> func[i][j];//â îáà ìíîæåñòâà

				arg2[j] = func[i][j];
			}

			add(func2, arg2, num2, n);

		}
	

	cout << endl << endl;
	bool showcalc = 1; //show all calculations

	check(func, func2, num, num2, NOT, showcalc , n);

	show(func, func2, num, num2, n );

	for (int i = 0; i < n2; i++)
		delete[] func[i];
	delete[] func;

	for (int i = 0; i < n2; i++)
		delete[] func2[i];
	delete[] func2;

	delete[] arg1;
	delete[] arg2;
	delete[] newf;
	delete[] funcmain;

	system("pause");

	return 0;
}

