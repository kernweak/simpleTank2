// simpleTank3.cpp : �������̨Ӧ�ó������ڵ㡣
//


#include "stdafx.h"
#include "tank.h"
#include "unit.h"
#include<stdio.h>
#include<stdlib.h>


int main()
{
	setsometing();
	ShowCursor();
	SetWindowSize("̹�˴�ս", 150, 50);
	char f5[30] = "��ӭ����̹�˴�ս\n";
	char f8[30] = "�ù�����δ�������\n";
	PrintCHar(24, 20, f5, 7);
	char f6[30] = "���ߣ������\n";
	PrintCHar(30, 22, f6, 7);
	char f7[30] = "��Դ��15PB\n";
	PrintCHar(30, 23, f7, 7);
	getchar();
	system("cls");
	int fina = 0;
	int temp = 0;
	while (1) {
		int nNum = -1;
		system("cls");
		PrintCHar(24, 20, "*******************************", 7);
		PrintCHar(24, 21, "*1.��ͼ�༭                   *", 7);
		PrintCHar(24, 22, "*2.��ʼ��Ϸ                   *", 7);
		PrintCHar(24, 23, "*3.������Ϸ                   *", 7);
		PrintCHar(24, 24, "*4.�˳���Ϸ                   *", 7);
		PrintCHar(24, 25, "*******************************", 7);
		scanf_s("%d", &nNum);
		if (nNum == 4)
			return 0;
		switch (nNum)
		{
		case 1:
			system("cls");
			initMap();
			DrawMap();
			MessageLoop();
			temp = 1;
			break;
		case 2:
			system("cls");
			if(temp==0)initMap();
			DrawMap();
			printMap();
			pGameIntroduce();
			allTank *aTank = NULL;
			allBullet* aBullet = NULL;
			initTank(&aTank);
			initPlayerTank(aTank, 18, 47, 6, 2, 2);
			initCompuTank(aTank, 1, 5, 4);
			initBullet(&aBullet);
			printAllpTank(aTank);
			fina = run(aTank, aBullet);
			system("cls");
			if (fina == 6)
			{
				char f[30] = "ʧ�ܣ����ϼ�ը��\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			if (fina == 5)
			{
				char f[30] = "���ʤ��\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			if (fina == 4)
			{
				char f[30] = "��Һ͵��˶����ݻ٣���Ϸ����\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			if (fina == 3)
			{
				char f[30] = "��ұ��ݻ٣���Ϸʧ��\n";
				PrintCHar(24, 20, f, 7);
				getchar();
				getchar();
			}
			break;
		}
	}
	getchar();
	return 0;
}


