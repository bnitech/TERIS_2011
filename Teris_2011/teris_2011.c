// 주석 test

#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int Map[20][11];
int Block[4][4];
int combo = 0, sw = 0, x, y, B_kind = 0, H = 0, B_hold = 0, N_B_kind = 0, N_N_B_kind = 0;
long All_score = 0;
void print();
void Block_select();
void Next_view();
void Hold_view();
void R();
void G();
void G_r();
void Z();
void Z_r();
void T();
void L();
void Block_clear();
void Block_print();
void Line();
void Hold();
void Gameover();

void start()
{
	int su;

	printf("                                                                               \n");
	printf("                                                        제작회사 : ㈜BNItech   \n");
	printf("                                                        제 작 자 : 임동빈      \n");
	printf("                                                                               \n");
	printf("    ┏━━━━━━━┓         ┏━━━━━┓            ┏━━━━━━━┓    \n");
	printf("    ┃              ┃         ┃          ┃            ┃              ┃    \n");
	printf("    ┗━━┓  ┏━━┛         ┃  ┏━┓  ┃            ┗┓  ┏━━━━┛    \n");
	printf("          ┃  ┃   ┏━━━━┓┃  ┃  ┃  ┃┏━━━━━┓┃   ┓             \n");
	printf("          ┃  ┃   ┃        ┃┃  ┗━┛  ┃┃          ┃┃     ┓           \n");
	printf("          ┃  ┃   ┃  ┏━━┛┃          ┃┗━┓  ┏━┛ ┗      ┓         \n");
	printf("          ┃  ┃   ┃  ┃      ┃  ┏┓    ┛    ┃  ┃       ┗      ┓       \n");
	printf("          ┃  ┃   ┃  ┗━━┓┃  ┃ ┗   ┓    ┃  ┃         ┗     ┃      \n");
	printf("          ┃  ┃   ┃        ┃┃  ┃  ┗    ┓  ┃  ┃┏━━━━━┛  ┃      \n");
	printf("          ┃  ┃   ┃  ┏━━┛┃  ┃   ┗     ┓┃  ┃┃              ┃      \n");
	printf("          ┃  ┃   ┃  ┃      ┃  ┃    ┗━━┛┃  ┃┗━━━━━━━┛      \n");
	printf("          ┗━┛   ┃  ┗━━┓┗━┛        ┏━┛  ┗━┓                    \n");
	printf("                   ┃        ┃              ┃          ┃                    \n");
	printf("                   ┗━━━━┛              ┗━━━━━┛                    \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("        시작 하려면 아무키나누르세요....");
	su = _getch();
}

void main()
{
	int i, j;

	start();

	H = 5;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 11; j++)
		{
			Map[i][j] = 0;
		}
	}
	while (1)
	{
		system("cls");

		srand(time(NULL));	 // 난수 발생	
		if (B_kind == 0) 	// 랜덤수 추출
		{
			B_kind = rand() % 7 + 1;
			N_B_kind = rand() % 7 + 1;
			N_N_B_kind = rand() % 7 + 1;
		}
		else
		{
			B_kind = N_B_kind;
			N_B_kind = rand() % 7 + 1;
		}

		Block_select();
	}
}

void Block_select()
{
	switch (B_kind)
	{
	case 1: R(); break;
	case 2: G(); break;
	case 3: G_r(); break;
	case 4: Z(); break;
	case 5: Z_r(); break;
	case 6: T(); break;
	case 7: L(); break;
	default: break;
	}
}
void Next_view()
{
	printf("\nNEXT  ━> \t\t", H);
	if (N_B_kind == 1)
		printf("   □□□□□\n\t\t\t   □■■□□\n\t\t\t   □■■□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (N_B_kind == 2)
		printf("   □□□□□\n\t\t\t   □■■■□\n\t\t\t   □□□■□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (N_B_kind == 3)
		printf("   □□□□□\n\t\t\t   □■■■□\n\t\t\t   □■□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (N_B_kind == 4)
		printf("   □□□□□\n\t\t\t   □■■□□\n\t\t\t   □□■■□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (N_B_kind == 5)
		printf("   □□□□□\n\t\t\t   □□■■□\n\t\t\t   □■■□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (N_B_kind == 6)
		printf("   □□□□□\n\t\t\t   □■■■□\n\t\t\t   □□■□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (N_B_kind == 7)
		printf("   □□□□□\n\t\t\t   □■□□□\n\t\t\t   □■□□□\n\t\t\t   □■□□□\n\t\t\t   □■□□□\n\t\t\t   □□□□□\n");
	else
		printf("   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
}


void Hold_view()
{
	printf("\n홀드 :  %d (개) ━> \t", H);
	if (B_hold == 1)
		printf("   □□□□□\n\t\t\t   □■■□□\n\t\t\t   □■■□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (B_hold == 2)
		printf("   □□□□□\n\t\t\t   □■■■□\n\t\t\t   □□□■□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (B_hold == 3)
		printf("   □□□□□\n\t\t\t   □■■■□\n\t\t\t   □■□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (B_hold == 4)
		printf("   □□□□□\n\t\t\t   □■■□□\n\t\t\t   □□■■□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (B_hold == 5)
		printf("   □□□□□\n\t\t\t   □□■■□\n\t\t\t   □■■□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (B_hold == 6)
		printf("   □□□□□\n\t\t\t   □■■■□\n\t\t\t   □□■□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
	else if (B_hold == 7)
		printf("   □□□□□\n\t\t\t   □■□□□\n\t\t\t   □■□□□\n\t\t\t   □■□□□\n\t\t\t   □■□□□\n\t\t\t   □□□□□\n");
	else
		printf("   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n\t\t\t   □□□□□\n");
}
void R() // 네모
{
	int i, j;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 4;
	Block[0][0] = 1;
	Block[0][1] = 1;
	Block[1][0] = 1;
	Block[1][1] = 1;

	while (1)
	{
		if (sw == 1)
		{
			Line();
			sw = 0;
			return;
		}

		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();

		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 32) // 고속 하강 (스페이스바)
		{
			Map[y][x] = 0;
			Map[y][x + 1] = 0;
			Map[y + 1][x] = 0;
			Map[y + 1][x + 1] = 0;

			while (1)
			{
				y++;
				if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3)
				{
					y--;
					break;
				}
			}

			for (i = 0; i < 4; i++) // Block_heap()
			{
				for (j = 0; j < 4; j++)
				{
					if (Block[i][j] == 1)
					{
						Map[y + i][x + j] = 3;
					}
				}
			}
			sw = 1;
			continue;
		}

		if (keyin == 72)			// Up
		{
		}
		else if (keyin == 75)	// Left
		{
			x--;
			if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3)
			{
				x++;
				continue;
			}
			Map[y][x + 2] = 0;
			Map[y + 1][x + 2] = 0;
		}
		else if (keyin == 77)	// Right
		{
			x++;
			if (x + 1 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 1] == 3)
			{
				x--;
				continue;
			}
			Map[y][x - 1] = 0;
			Map[y + 1][x - 1] = 0;
		}
		else if (keyin == 80)	// Down
		{
			y++;
			if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3)
			{
				y--;
				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			Map[y - 1][x] = 0;
			Map[y - 1][x + 1] = 0;
		}
		else if (keyin == 13 && H>0) // 엔터(홀드)
		{
			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if (Block[i][j] == 1)
					{
						Map[y + i][x + j] = 0;
					}
				}
			}
			Hold();
			if (H == 1)
				return;
			else
			{
				Block_select();
				return;
			}
		}
	}
}

void G()  // 기역자
{
	int i, j, R = 0;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 3;
	Block[0][0] = 1;
	Block[0][1] = 1;
	Block[0][2] = 1;
	Block[1][2] = 1;

	while (1)
	{
		if (sw == 1)
		{
			sw = 0;
			Line();
			return;
		}
		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();
		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 72)			// Up
		{
			if (R == 0) // ┘으로 회전
			{
				if (y < 18 && Map[y + 1][x + 1] != 3 && Map[y + 2][x] != 3 && Map[y + 2][x + 1] != 3)
				{
					Map[y][x] = 0;
					Map[y][x + 2] = 0;
					Map[y + 1][x + 2] = 0;

					Block_clear();
					Block[0][1] = 1;
					Block[1][1] = 1;
					Block[2][0] = 1;
					Block[2][1] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 1) // └ 으로 회전
			{
				if (x < 9 && Map[y][x] != 3 && Map[y + 1][x] != 3 && Map[y + 1][x + 2] != 3)
				{
					Map[y][x + 1] = 0;
					Map[y + 2][x] = 0;
					Map[y + 2][x + 1] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;
					Block[1][2] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 2) // ┌ 으로 회전
			{
				if (y < 18 && (Map[y][x + 1] != 3 && Map[y + 2][x] != 3))
				{
					Map[y + 1][x + 1] = 0;
					Map[y + 1][x + 2] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[1][0] = 1;
					Block[2][0] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 3) // ┐ 으로 회전
			{
				if (x < 9 && (Map[y][x + 2] != 3 && Map[y + 1][x + 2] != 3))
				{
					Map[y + 1][x] = 0;
					Map[y + 2][x] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[0][2] = 1;
					Block[1][2] = 1;

					Block_print();
					R = 0;
				}
			}
			continue;
		}

		if (R == 0)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y][x + 2] = 0;
				Map[y + 1][x + 2] = 0;

				while (1)
				{
					y++;
					if (y + 1 == 20 || Map[y][x] == 3 || Map[y][x + 1] == 3 || Map[y + 1][x + 2] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x + 2] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 3] = 0;
				Map[y + 1][x + 3] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 2 == 11 || Map[y + 1][x + 2] == 3 || Map[y + 1][x + 2] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x + 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 1 == 20 || Map[y][x] == 3 || Map[y][x + 1] == 3 || Map[y + 1][x + 2] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y - 1][x + 1] = 0;
				Map[y - 1][x + 2] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}

		else if (R == 1)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x + 1] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x] = 0;
				Map[y + 2][x + 1] = 0;

				while (1)
				{
					y++;
					if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 2][x + 1] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x + 1] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 2] = 0;
				Map[y + 1][x + 2] = 0;
				Map[y + 2][x + 2] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 1 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x + 1] == 3)
				{
					x--;
					continue;
				}
				Map[y][x] = 0;
				Map[y + 1][x] = 0;
				Map[y + 2][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 2][x + 1] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x + 1] = 0;
				Map[y + 1][x] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}

		else if (R == 2)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y + 1][x] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 1][x + 2] = 0;

				while (1)
				{
					y++;
					if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 1] = 0;
				Map[y + 1][x + 3] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 2 == 11 || Map[y][x] == 3 || Map[y + 1][x + 2] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y][x + 1] = 0;
				Map[y][x + 2] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
		else if (R == 3)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y + 1][x] = 0;
				Map[y + 2][x] = 0;

				while (1)
				{
					y++;
					if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y][x + 1] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 2] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x + 1] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 1 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x - 1] = 0;
				Map[y + 2][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y][x + 1] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y - 1][x + 1] = 0;
			}

			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
	}
}

void G_r() // 역 기역자
{
	int i, j, R = 0;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 3;
	Block[0][0] = 1;
	Block[1][0] = 1;
	Block[0][1] = 1;
	Block[0][2] = 1;

	while (1)
	{
		if (sw == 1)
		{
			Line();
			sw = 0;
			return;
		}
		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();
		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 72)			// Up
		{
			if (R == 0) // ┐으로 회전
			{
				if (y < 18 && Map[y + 1][x + 1] != 3 && Map[y + 2][x + 1] != 3)
				{
					Map[y][x + 2] = 0;
					Map[y + 1][x] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[1][1] = 1;
					Block[2][1] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 1) // ┘ 으로 회전
			{
				if (x < 9 && Map[y + 1][x] != 3 && Map[y][x + 2] != 3 && Map[y + 1][x + 2] != 3)
				{
					Map[y][x] = 0;
					Map[y][x + 1] = 0;
					Map[y + 2][x + 1] = 0;

					Block_clear();
					Block[0][2] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;
					Block[1][2] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 2) // └ 으로 회전
			{
				if (y < 18 && Map[y][x] != 3 && Map[y + 2][x] != 3 && Map[y + 2][x + 1] != 3)
				{
					Map[y][x + 2] = 0;
					Map[y + 1][x + 1] = 0;
					Map[y + 1][x + 2] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[1][0] = 1;
					Block[2][0] = 1;
					Block[2][1] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 3) // ┌ 으로 회전
			{
				if (x < 9 && Map[y][x + 1] != 3 && Map[y][x + 2] != 3)
				{
					Map[y + 2][x] = 0;
					Map[y + 2][x + 1] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[0][2] = 1;
					Block[1][0] = 1;

					Block_print();
					R = 0;
				}
			}
			continue;
		}

		if (R == 0)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y][x + 2] = 0;
				Map[y + 1][x] = 0;

				while (1)
				{
					y++;
					if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y][x + 1] == 3 || Map[y][x + 2] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 3] = 0;
				Map[y + 1][x + 1] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 2 == 11 || Map[y + 1][x] == 3 || Map[y][x + 2] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y][x + 1] == 3 || Map[y][x + 2] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y - 1][x + 1] = 0;
				Map[y - 1][x + 2] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}

		else if (R == 1)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x + 1] = 0;

				while (1)
				{
					y++;
					if (y + 2 == 20 || Map[y][x] == 3 || Map[y + 2][x + 1] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x + 1] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 2] = 0;
				Map[y + 1][x + 2] = 0;
				Map[y + 2][x + 2] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 1 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x + 1] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x] = 0;
				Map[y + 2][x] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 2 == 20 || Map[y][x] == 3 || Map[y + 2][x + 1] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y - 1][x + 1] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}

		else if (R == 2)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x + 2] = 0;
				Map[y + 1][x] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 1][x + 2] = 0;

				while (1)
				{
					y++;
					if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y + 1][x] == 3 || Map[y][x + 2] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 3] = 0;
				Map[y + 1][x + 3] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 2 == 11 || Map[y][x + 2] == 3 || Map[y + 1][x + 2] == 3)
				{
					x--;
					continue;
				}
				Map[y][x + 1] = 0;
				Map[y + 1][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y - 1][x + 2] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
		else if (R == 3)
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y + 1][x] = 0;
				Map[y + 2][x] = 0;
				Map[y + 2][x + 1] = 0;

				while (1)
				{
					y++;
					if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 2][x + 1] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}

			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 1] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x + 2] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 1 == 11 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x - 1] = 0;
				Map[y + 2][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 2][x + 1] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y + 1][x + 1] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
	}
}

void Z()
{
	int i, j;
	int R = 0;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 3;
	Block_clear();
	Block[0][0] = 1;
	Block[0][1] = 1;
	Block[1][1] = 1;
	Block[1][2] = 1;

	while (1)
	{
		if (sw == 1)
		{
			Line();
			sw = 0;
			return;
		}
		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();
		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 72)	// Up
		{
			if (R == 0)	 // 역 Z로 바꾸기
			{
				if (y < 18 && Map[y + 1][x] != 3 && Map[y + 2][x] != 3)
				{
					Map[y][x] = 0;
					Map[y + 1][x + 2] = 0;

					Block_clear();
					Block[0][1] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;
					Block[2][0] = 1;
					Block_print();
					R = 1;
				}
			}
			else		// Z로 바꾸기
			{
				if (x < 9 && Map[y][x] != 3 && Map[y + 1][x + 2] != 3)
				{
					Map[y + 1][x] = 0;
					Map[y + 2][x] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[1][1] = 1;
					Block[1][2] = 1;

					Block_print();
					R = 0;
				}
			}
			continue;
		}
		if (R == 0)		// 회전 하지 않은 상태
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 1][x + 2] = 0;

				while (1)
				{
					y++;
					if (y + 1 == 20 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 2] = 0;
				Map[y + 1][x + 3] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 2 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 2] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 1 == 20 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y - 1][x + 1] = 0;
				Map[y][x + 2] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
		else		// 회전 상태
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x + 1] = 0;
				Map[y + 1][x] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x] = 0;

				while (1)
				{
					y++;
					if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 1][x + 1] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x + 1] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 2] = 0;
				Map[y + 1][x + 2] = 0;
				Map[y + 2][x + 1] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 1 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x] == 3)
				{
					x--;
					continue;
				}
				Map[y][x] = 0;
				Map[y + 1][x - 1] = 0;
				Map[y + 2][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 1][x + 1] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) //Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y][x] = 0;
				Map[y - 1][x + 1] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
	}
}

void Z_r()
{
	int i, j;
	int R = 0;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 3;
	Block_clear();
	Block[0][1] = 1;
	Block[0][2] = 1;
	Block[1][0] = 1;
	Block[1][1] = 1;

	while (1)
	{
		if (sw == 1)
		{
			Line();
			sw = 0;
			return;
		}
		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();
		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 72)	// Up
		{
			if (R == 0)	 // 역 Z_r로 바꾸기
			{
				if (y < 18 && Map[y][x] != 3 && Map[y + 2][x + 1] != 3)
				{
					Map[y][x + 1] = 0;
					Map[y][x + 2] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;
					Block[2][1] = 1;
					Block_print();
					R = 1;
				}
			}
			else		// Z_r로 바꾸기
			{
				if (x < 9 && Map[y][x + 1] != 3 && Map[y][x + 2] != 3)
				{
					Map[y][x] = 0;
					Map[y + 2][x + 1] = 0;

					Block_clear();
					Block[0][1] = 1;
					Block[0][2] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;

					Block_print();
					R = 0;
				}
			}
			continue;
		}
		if (R == 0)		// Z_r
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x + 1] = 0;
				Map[y][x + 2] = 0;
				Map[y + 1][x] = 0;
				Map[y + 1][x + 1] = 0;

				while (1)
				{
					y++;
					if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y][x + 2] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x + 1] == 3 || Map[y + 1][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 3] = 0;
				Map[y + 1][x + 2] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 2 == 11 || Map[y][x + 2] == 3 || Map[y + 1][x + 1] == 3)
				{
					x--;
					continue;
				}
				Map[y][x] = 0;
				Map[y + 1][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y][x + 2] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x + 1] = 0;
				Map[y - 1][x + 2] = 0;
				Map[y][x] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
		else		// 역 Z_r
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y + 1][x] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x + 1] = 0;

				while (1)
				{
					y++;
					if (y + 2 == 20 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 1] = 0;
				Map[y + 1][x + 2] = 0;
				Map[y + 2][x + 2] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 1 == 11 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x + 1] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x - 1] = 0;
				Map[y + 2][x] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 2 == 20 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) //Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y][x + 1] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
	}
}

void T() // 티 자
{
	int i, j, R = 0;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 3;
	Block[0][0] = 1;
	Block[0][1] = 1;
	Block[0][2] = 1;
	Block[1][1] = 1;

	while (1)
	{
		if (sw == 1)
		{
			Line();
			sw = 0;
			return;
		}
		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();
		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 72)			// Up
		{
			if (R == 0) // ㅓ으로 회전
			{
				if (y < 18 && Map[y + 1][x] != 3 && Map[y + 2][x + 1] != 3)
				{

					Map[y][x] = 0;
					Map[y][x + 2] = 0;

					Block_clear();
					Block[0][1] = 1;
					Block[1][1] = 1;
					Block[1][0] = 1;
					Block[2][1] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 1) // ㅗ 으로 회전
			{
				if (x < 9 && Map[y + 1][x + 2] != 3)
				{
					Map[y + 2][x + 1] = 0;

					Block_clear();
					Block[0][1] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;
					Block[1][2] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 2) // ㅏ 으로 회전
			{
				if (y < 18 && Map[y][x] != 3 && Map[y + 2][x] != 3)
				{
					Map[y][x + 1] = 0;
					Map[y + 1][x + 2] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[1][0] = 1;
					Block[1][1] = 1;
					Block[2][0] = 1;

					Block_print();
					R++;
				}
			}
			else if (R == 3) // ㅜ 으로 회전
			{
				if (x < 9 && Map[y][x + 1] != 3 && Map[y][x + 2] != 3)
				{
					Map[y + 1][x] = 0;
					Map[y + 2][x] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[1][1] = 1;
					Block[0][2] = 1;

					Block_print();
					R = 0;
				}
			}
			continue;
		}
		else
		{
			if (R == 0)
			{
				if (keyin == 32) // 고속 하강 (스페이스바)
				{
					Map[y][x] = 0;
					Map[y][x + 1] = 0;
					Map[y][x + 2] = 0;
					Map[y + 1][x + 1] = 0;

					while (1)
					{
						y++;
						if (y + 1 == 20 || Map[y + 1][x + 1] == 3 || Map[y][x] == 3 || Map[y][x + 2] == 3)
						{
							y--;
							break;
						}
					}

					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}

				if (keyin == 75)	// Left
				{
					x--;
					if (x == -1 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3)
					{
						x++;
						continue;
					}
					Map[y][x + 3] = 0;
					Map[y + 1][x + 2] = 0;
				}
				else if (keyin == 77)	// Right
				{
					x++;
					if (x + 2 == 11 || Map[y + 1][x + 1] == 3 || Map[y][x + 2] == 3)
					{
						x--;
						continue;
					}
					Map[y][x - 1] = 0;
					Map[y + 1][x] = 0;
				}
				else if (keyin == 80)	// Down
				{
					y++;
					if (y + 1 == 20 || Map[y + 1][x + 1] == 3 || Map[y][x] == 3 || Map[y][x + 2] == 3)
					{
						y--;
						for (i = 0; i < 4; i++) // Block_heap()
						{
							for (j = 0; j < 4; j++)
							{
								if (Block[i][j] == 1)
								{
									Map[y + i][x + j] = 3;
								}
							}
						}
						sw = 1;
						continue;
					}
					Map[y - 1][x] = 0;
					Map[y - 1][x + 1] = 0;
					Map[y - 1][x + 2] = 0;
				}
				else if (keyin == 13 && H>0) // 엔터(홀드)
				{
					for (i = 0; i < 4; i++)
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 0;
							}
						}
					}
					Hold();
					if (H == 1)
						return;
					else
					{
						Block_select();
						return;
					}
				}
			}
			else if (R == 1)
			{
				if (keyin == 32) // 고속 하강 (스페이스바)
				{
					Map[y][x + 1] = 0;
					Map[y + 1][x] = 0;
					Map[y + 1][x + 1] = 0;
					Map[y + 2][x + 1] = 0;

					while (1)
					{
						y++;
						if (y + 2 == 20 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
						{
							y--;
							break;
						}
					}

					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				if (keyin == 75)	// Left
				{
					x--;
					if (x == -1 || Map[y][x + 1] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
					{
						x++;
						continue;
					}
					Map[y][x + 2] = 0;
					Map[y + 1][x + 2] = 0;
					Map[y + 2][x + 2] = 0;
				}
				else if (keyin == 77)	// Right
				{
					x++;
					if (x + 1 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x + 1] == 3)
					{
						x--;
						continue;
					}
					Map[y][x] = 0;
					Map[y + 1][x - 1] = 0;
					Map[y + 2][x] = 0;
				}
				else if (keyin == 80)	// Down
				{
					y++;
					if (y + 2 == 20 || Map[y + 1][x] == 3 || Map[y + 2][x + 1] == 3)
					{
						y--;
						for (i = 0; i < 4; i++) // Block_heap()
						{
							for (j = 0; j < 4; j++)
							{
								if (Block[i][j] == 1)
								{
									Map[y + i][x + j] = 3;
								}
							}
						}
						sw = 1;
						continue;
					}
					Map[y][x] = 0;
					Map[y - 1][x + 1] = 0;
				}
				else if (keyin == 13 && H>0) // 엔터(홀드)
				{
					for (i = 0; i < 4; i++)
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 0;
							}
						}
					}
					Hold();
					if (H == 1)
						return;
					else
					{
						Block_select();
						return;
					}
				}
			}
			else if (R == 2)
			{
				if (keyin == 32) // 고속 하강 (스페이스바)
				{
					Map[y][x + 1] = 0;
					Map[y + 1][x] = 0;
					Map[y + 1][x + 1] = 0;
					Map[y + 1][x + 2] = 0;

					while (1)
					{
						y++;
						if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
						{
							y--;
							break;
						}
					}

					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				if (keyin == 75)	// Left
				{
					x--;
					if (x == -1 || Map[y][x + 1] == 3 || Map[y + 1][x] == 3)
					{
						x++;
						continue;
					}
					Map[y][x + 2] = 0;
					Map[y + 1][x + 3] = 0;
				}
				else if (keyin == 77)	// Right
				{
					x++;
					if (x + 2 == 11 || Map[y][x + 1] == 3 || Map[y + 1][x + 2] == 3)
					{
						x--;
						continue;
					}
					Map[y][x] = 0;
					Map[y + 1][x - 1] = 0;
				}
				else if (keyin == 80)	// Down
				{
					y++;
					if (y + 1 == 20 || Map[y + 1][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 1][x + 2] == 3)
					{
						y--;
						for (i = 0; i < 4; i++) // Block_heap()
						{
							for (j = 0; j < 4; j++)
							{
								if (Block[i][j] == 1)
								{
									Map[y + i][x + j] = 3;
								}
							}
						}
						sw = 1;
						continue;
					}
					Map[y][x] = 0;
					Map[y - 1][x + 1] = 0;
					Map[y][x + 2] = 0;
				}
				else if (keyin == 13 && H>0) // 엔터(홀드)
				{
					for (i = 0; i < 4; i++)
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 0;
							}
						}
					}
					Hold();
					if (H == 1)
						return;
					else
					{
						Block_select();
						return;
					}
				}
			}
			else if (R == 3)
			{
				if (keyin == 32) // 고속 하강 (스페이스바)
				{
					Map[y][x] = 0;
					Map[y + 1][x] = 0;
					Map[y + 1][x + 1] = 0;
					Map[y + 2][x] = 0;

					while (1)
					{
						y++;
						if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 1][x + 1] == 3)
						{
							y--;
							break;
						}
					}

					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				if (keyin == 75)	// Left
				{
					x--;
					if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3)
					{
						x++;
						continue;
					}
					Map[y][x + 1] = 0;
					Map[y + 1][x + 2] = 0;
					Map[y + 2][x + 1] = 0;
				}
				else if (keyin == 77)	// Right
				{
					x++;
					if (x == 10 || Map[y][x] == 3 || Map[y + 1][x + 1] == 3 || Map[y + 2][x] == 3)
					{
						x--;
						continue;
					}
					Map[y][x - 1] = 0;
					Map[y + 1][x - 1] = 0;
					Map[y + 2][x - 1] = 0;
				}
				else if (keyin == 80)	// Down
				{
					y++;
					if (y + 2 == 20 || Map[y + 2][x] == 3 || Map[y + 1][x + 1] == 3)
					{
						y--;
						for (i = 0; i < 4; i++) // Block_heap()
						{
							for (j = 0; j < 4; j++)
							{
								if (Block[i][j] == 1)
								{
									Map[y + i][x + j] = 3;
								}
							}
						}
						sw = 1;
						continue;
					}
					Map[y - 1][x] = 0;
					Map[y][x + 1] = 0;
				}
				else if (keyin == 13 && H>0) // 엔터(홀드)
				{
					for (i = 0; i < 4; i++)
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 0;
							}
						}
					}
					Hold();
					if (H == 1)
						return;
					else
					{
						Block_select();
						return;
					}
				}
			}
		}
	}
}


void L() // 일자
{
	int i, j;
	int R = 0;
	char keyin;

	system("cls");
	Block_clear();
	print();

	y = 0;
	x = 4;
	Block_clear();
	Block[0][0] = 1;
	Block[1][0] = 1;
	Block[2][0] = 1;
	Block[3][0] = 1;

	while (1)
	{
		if (sw == 1)
		{
			Line();
			sw = 0;
			return;
		}
		system("cls");
		Next_view();
		Hold_view();
		printf("\n 홀드 추가 구입 :  1 -> 5개(100점)   2 -> 15개(200점)    3 -> 50개(400점)\n\n");
		printf("\n  SCORE :  %ld     COMBO  :  %d \n\n", All_score, combo);

		Block_print();
		print();
		keyin = _getche();

		if (keyin == 49)
		{
			if (All_score - 100 >= 0)
			{
				All_score = All_score - 100;
				H = H + 5;
			}
			continue;
		}
		if (keyin == 50)
		{
			if (All_score - 200 >= 0)
			{
				All_score = All_score - 200;
				H = H + 15;
			}
			continue;
		}
		if (keyin == 51)
		{
			if (All_score - 400 >= 0)
			{
				All_score = All_score - 400;
				H = H + 50;
			}
			continue;
		}

		if (keyin == 72)	// Up
		{
			if (R == 0)		 // 역 일자로 바꾸기
			{
				if (x < 8 && Map[y][x + 1] != 3 && Map[y][x + 2] != 3 && Map[y][x + 3] != 3)
				{
					Map[y + 1][x] = 0;
					Map[y + 2][x] = 0;
					Map[y + 3][x] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[0][1] = 1;
					Block[0][2] = 1;
					Block[0][3] = 1;

					Block_print();
					R = 1;
				}

			}
			else		// 일자로 바꾸기
			{
				if (y < 17 && Map[y + 1][x] != 3 && Map[y + 2][x] != 3 && Map[y + 3][x] != 3)
				{
					Map[y][x + 1] = 0;
					Map[y][x + 2] = 0;
					Map[y][x + 3] = 0;

					Block_clear();
					Block[0][0] = 1;
					Block[1][0] = 1;
					Block[2][0] = 1;
					Block[3][0] = 1;
					Block_print();
					R = 0;
				}
			}
			continue;
		}

		if (R == 0)		// 회전 하지 않은 상태
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y + 1][x] = 0;
				Map[y + 2][x] = 0;
				Map[y + 3][x] = 0;

				while (1)
				{
					y++;
					if (y + 3 == 20 || Map[y + 3][x] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3 || Map[y + 3][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 1] = 0;
				Map[y + 1][x + 1] = 0;
				Map[y + 2][x + 1] = 0;
				Map[y + 3][x + 1] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x == 11 || Map[y][x] == 3 || Map[y + 1][x] == 3 || Map[y + 2][x] == 3 || Map[y + 3][x] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
				Map[y + 1][x - 1] = 0;
				Map[y + 2][x - 1] = 0;
				Map[y + 3][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y + 3 == 20 || Map[y + 3][x] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) // Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
		else		// 회전 상태
		{
			if (keyin == 32) // 고속 하강 (스페이스바)
			{
				Map[y][x] = 0;
				Map[y][x + 1] = 0;
				Map[y][x + 2] = 0;
				Map[y][x + 3] = 0;

				while (1)
				{
					y++;
					if (y == 20 || Map[y][x] == 3 || Map[y][x + 1] == 3 || Map[y][x + 2] == 3 || Map[y][x + 3] == 3)
					{
						y--;
						break;
					}
				}

				for (i = 0; i < 4; i++) // Block_heap()
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 3;
						}
					}
				}
				sw = 1;
				continue;
			}
			if (keyin == 75)	// Left
			{
				x--;
				if (x == -1 || Map[y][x] == 3)
				{
					x++;
					continue;
				}
				Map[y][x + 4] = 0;
			}
			else if (keyin == 77)	// Right
			{
				x++;
				if (x + 3 == 11 || Map[y + 3][x] == 3)
				{
					x--;
					continue;
				}
				Map[y][x - 1] = 0;
			}
			else if (keyin == 80)	// Down
			{
				y++;
				if (y == 20 || Map[y][x] == 3 || Map[y][x + 1] == 3 || Map[y][x + 2] == 3 || Map[y][x + 3] == 3)
				{
					y--;
					for (i = 0; i < 4; i++) //Block_heap()
					{
						for (j = 0; j < 4; j++)
						{
							if (Block[i][j] == 1)
							{
								Map[y + i][x + j] = 3;
							}
						}
					}
					sw = 1;
					continue;
				}
				Map[y - 1][x] = 0;
				Map[y - 1][x + 1] = 0;
				Map[y - 1][x + 2] = 0;
				Map[y - 1][x + 3] = 0;
			}
			else if (keyin == 13 && H>0) // 엔터(홀드)
			{
				for (i = 0; i < 4; i++)
				{
					for (j = 0; j < 4; j++)
					{
						if (Block[i][j] == 1)
						{
							Map[y + i][x + j] = 0;
						}
					}
				}
				Hold();
				if (H == 1)
					return;
				else
				{
					Block_select();
					return;
				}
			}
		}
	}
}

void print()
{
	int i, j;
	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 11; j++)
		{
			if (Map[i][j] == 0)
			{
				printf("□");
			}
			else if (Map[i][j] == 1)
			{
				printf("■");
			}
			else if (Map[i][j] == 3)
			{
				printf("■");
			}
		}
		printf("\n");
	}
}

void Block_clear()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			Block[i][j] = 0;
		}
	}
}

void Block_print()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if (Block[i][j] == 1)
			{
				Map[y + i][x + j] = 1;
			}

		}
	}
}

void Line()
{
	int j, i, line, y_line, S_cnt = 0;
	for (i = 0; i<20; i++)
	{
		line = 0;
		for (j = 0; j<11; j++)
		{
			if (Map[i][j] == 3)
			{
				if (i == 0)
					Gameover();
				line++;
			}
			if (line == 11)
			{
				S_cnt++;
				y_line = i;
				for (j = 0; j<11; j++)
					Map[y_line][j] = 0;

				for (i = y_line - 1; i >= 0; i--) // Line_clear()
				{
					for (j = 0; j < 11; j++)
					{
						if (Map[i][j] == 0)
							Map[i + 1][j] = 0;

						else if (Map[i][j] == 3)
							Map[i + 1][j] = 3;
					}
				}
				for (j = 0; j < 11; j++)
					Map[0][j] = 0;
			}
		}
	}

	if (S_cnt == 0)
		combo = 0;
	else
	{
		combo++;
		All_score = All_score + (S_cnt * 10)*combo;
	}
}

void Hold()
{
	int B_temp;

	H--;
	B_temp = B_kind;
	if (B_hold != 0)
		B_kind = B_hold;
	else
	{
		B_kind = N_B_kind;
		N_B_kind = N_N_B_kind;
	}
	B_hold = B_temp;
}

void Gameover()
{
	system("cls");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                   GAME OVER                                   \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");
	printf("                                                                               \n");

	exit(0);
}
