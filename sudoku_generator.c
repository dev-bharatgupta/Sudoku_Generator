#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<string.h>


struct sm {
	int r, c, v;
	struct sm *link;

}*start = NULL;

void menu(int gboard[10][10]);
void s_print(int a[10][10]);
void q_print(int b[10][10], int a[10][10]);
void genrate(int gboard[10][10]);
void play(int gboard[10][10]);
void fgenrate(int b[10][10]);
int check(int gboard[10][10], int row, int col, int m);
int empty(int gboard[10][10], int *i, int *j);
int fill(int gboard[10][10]);
int comparison(int a[10][10], int b[10][10]);



int main()

{
	system("COLOR 0");

	srand(time(NULL));

	int  gboard[10][10] = { 0 };

	menu(gboard);

	system("pause");

	return 0;
}

void menu(int gboard[10][10])
{
	char s[10];
	do
	{
		system("cls");
		printf("				MENU\n");
		printf("	1) PLAY\n");
		printf("	2) GENRATE\n");//F
		printf("	3) SOLVE\n");//u or f
		printf("	4) EXIT\n");
		gets(s);
		switch (s[0])
		{
		case '1':
		{
			genrate(gboard);
			fill(gboard);
			play(gboard);
		}
		break;
		case '2':
		{	char se[10];
		do
		{
			system("cls");
			printf("	Type exit to return , anything else to genrate\n");
			gets(se);
			genrate(gboard);
			fill(gboard);
			fgenrate(gboard);
			system("pause");
		} while (strcmp(se, "exit"));
		}
		break;
		case '3':
		{	char str[10];
		system("cls");
		printf("				MENU\t\t\t\t\t\ttype exit for previous\n");
		printf("	1) CONSOLE INPUT\n");
		printf("	2) FILE INPUT\n");
		gets(str);

		if (!strcmp(str, "exit"))
		{
		}
		else
		{
			int temp[10][10] = { 0 };
			switch (str[0])
			{

				system("cls");
			case '1':
			{
				printf("enter 9 digits seprated by space in each row.enter 9 rows.for empty places type 0\n");
				printf("0 1 4 0 3 0 0 0 8\n");

				int i, j;
				for (i = 1; i < 10; i++)
				{
					scanf("%d %d %d %d %d %d %d %d %d", &temp[i][1], &temp[i][2], &temp[i][3], &temp[i][4], &temp[i][5], &temp[i][6], &temp[i][7], &temp[i][8], &temp[i][9]);

				}


				for (i = 1; i < 10; i++)
				{
					for (j = 1; j < 10; j++)
					{
						struct sm *cur = start;
						struct sm *abc;
						abc = (struct sm*)malloc(sizeof(struct sm));

						if (temp[i][j] != 0)
						{
							abc->r = i;
							abc->c = j;
							abc->v = temp[i][j];
							abc->link = NULL;


							if (start == NULL)
							{
								start = abc;

							}
							else
							{
								while (cur->link != NULL)
								{
									cur = cur->link;
								}
								cur->link = abc;
							}
						}
					}
				}
				/*
				struct sm *cur1 = start;
				for (i = 1; i < 10; i++)
				{
					for (j = 1; j < 10; j++)
					{
						if (cur1->r == i && cur1->c == j && cur1 != NULL)
						{
							temp[i][j] = cur1->v;
							cur1 = cur1->link;
						}
						else
							temp[i][j] = 0;

					}
				}

				*/

			}break;

			case '2':
			{
				FILE* fp1;
				fp1 = fopen("ques.txt", "r");
				int i, j;

				for (i = 1; i < 10; i++)
				{
					fscanf(fp1, "%d %d %d %d %d %d %d %d %d\n", &temp[i][1], &temp[i][2], &temp[i][3], &temp[i][4], &temp[i][5], &temp[i][6], &temp[i][7], &temp[i][8], &temp[i][9]);

				}



			}
			break;
			default: {}
			}
			int i, j;
			system("cls");
			for (i = 1; i < 10; i++)
			{
				for (j = 1; j < 10; j++)

					printf("%d ", temp[i][j]);
				printf("\n");
			}
			printf("\n");
			fill(temp);
			s_print(temp);
			system("pause");
		}
		}


		default: {}
		}
	} while (s[0] != '4');

}

void s_print(int a[10][10])
{
	int i;
	for (i = 1; i < 10; i++)
	{
		if (i == 1)
			printf("       A   B   C   D   E   F   G   H   I\n");
		if (i == 1 || i == 4 || i == 7)
			printf("     \x1b[31m+---+---+---+---+---+---+---+---+---+\x1b[0m\n");
		else
			printf("     \x1b[31m+\x1b[0m---+---+---\x1b[31m+\x1b[0m---+---+---\x1b[31m+\x1b[0m---+---+---\x1b[31m+\x1b[0m\n");

		int j;
		for (j = 1; j < 10; j++)
		{
			if (j == 1)
				printf("  %d  ", i);

			if (j == 1 || j == 4 || j == 7)
				printf("\x1b[31m|\x1b[0m %d ", a[i][j]);
			else
				printf("| %d ", a[i][j]);

		}
		printf("\x1b[31m|\x1b[0m\n");




	}
	printf("     \x1b[31m+---+---+---+---+---+---+---+---+---+\x1b[0m\n");
}

void q_print(int b[10][10], int a[10][10])
{
	system("cls");
	int i;
	for (i = 1; i < 10; i++)
	{
		if (i == 1)
			printf("       A   B   C   D   E   F   G   H   I\n");
		if (i == 1 || i == 4 || i == 7)
			printf("     \x1b[31m+---+---+---+---+---+---+---+---+---+\x1b[0m\n");
		else
			printf("     \x1b[31m+\x1b[0m---+---+---\x1b[31m+\x1b[0m---+---+---\x1b[31m+\x1b[0m---+---+---\x1b[31m+\x1b[0m\n");

		int j;
		for (j = 1; j < 10; j++)
		{
			if (j == 1)
				printf("  %d  ", i);
			if (a[i][j] == 1)
			{
				if (j == 1 || j == 4 || j == 7)
					printf("\x1b[31m| \x1b[33m%d\x1b[0m ", b[i][j]);
				else
					printf("| \x1b[33m%d\x1b[0m ", b[i][j]);
			}

			else if (a[i][j] == 2)
			{
				if (j == 1 || j == 4 || j == 7)
					printf("\x1b[31m| \x1b[0m%d ", b[i][j]);
				else
					printf("| %d ", b[i][j]);
			}

			else
			{
				if (j == 1 || j == 4 || j == 7)
					printf("\x1b[31m|\x1b[0m   ");
				else
					printf("|   ");

			}
		}
		printf("\x1b[31m|\x1b[0m\n");




	}
	printf("     \x1b[31m+---+---+---+---+---+---+---+---+---+\x1b[0m\n");
}

void fgenrate(int b[10][10])
{
	int temp[10][10] = { 0 };
	int a[10][10] = { 0 }, i, j, f;
	for (f = 0; f < 17; f++)
	{
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;
		if (a[i][j] == 1 || ((i >= 4 && i <= 6) && (j >= 4 && j <= 6)))
			f--;
		else
		{
			a[i][j] = 1;
			temp[i][j] = b[i][j];
		}
	}

	FILE *fp;
	fp = fopen("q.txt", "a");
	int k;
	for (k = 1; k < 10; k++)
	{

		fprintf(fp, "+---+---+---+---+---+---+---+---+---+\n");

		int l;
		for (l = 1; l < 10; l++)
		{
			if (a[k][l] == 1)
			{
				fprintf(fp, "| %d ", b[k][l]);
			}

			else
			{
				fprintf(fp, "|   ");
			}
		}
		fprintf(fp, "|\n");




	}
	fprintf(fp, "+---+---+---+---+---+---+---+---+---+\n\n");
	fclose(fp);
}

//Filling the three diagonal grids with elements(genrate incomplete sudoku
void genrate(int gboard[10][10])
{
	int l = 0;
	for (l = 0; l < 7; l = l + 3)
	{
		int m = 1, a[4][4] = { 0 };

		while (m < 10)
		{
			int i = (rand() % 3) + 1 + l;
			int j = (rand() % 3) + 1 + l;
			if (a[i - l][j - l] == 0)
			{
				gboard[i][j] = m;
				a[i - l][j - l] = m;
				m++;
			}

		}

	}
}

//filling Rule check
int check(int gboard[10][10], int row, int col, int m)
{
	int i, j, flag = 1;
	for (i = 1; i < 10; i++)
	{
		if (gboard[i][col] == m)
			flag = 0;

	}
	for (j = 1; j < 10; j++)
	{
		if (gboard[row][j] == m)
			flag = 0;
	}

	for (i = row - ((row - 1) % 3); i < 3 + row - ((row - 1) % 3); i++)
	{
		for (j = col - ((col - 1) % 3); j < 3 + col - ((col - 1) % 3); j++)
		{
			if (gboard[i][j] == m)
				flag = 0;
		}

	}
	return flag;
}

//look for empty slot in sudoku
int empty(int gboard[10][10], int *i, int *j)
{
	for (*i = 1; *i < 10; (*i)++)
	{
		for (*j = 1; *j < 10; (*j)++)
		{
			if (gboard[*i][*j] == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

//filling incomplete sudoku
int fill(int gboard[10][10])
{
	int m, i = 1, j = 1;

	if (!empty(gboard, &i, &j))
		return 1;

	for (m = 1; m < 10; m++)
	{
		if (check(gboard, i, j, m))
		{
			gboard[i][j] = m;
			if (fill(gboard))
			{
				return 1;
			}
			gboard[i][j] = 0;


		}
	}
	return 0;

}


void play(int gboard[10][10])
{
	int op;
	int temp[10][10] = { 0 };
	int a[10][10] = { 0 }, i, j, f, dif = 17;
	system("cls");
	printf("				Difficulty\t\t\t\t\t\ttype exit for previous\n");
	printf("	1) Easy\n");
	printf("	2) Medium\n");
	printf("	3) Difficult\n");
	printf("	4) Exit\n");
	scanf("%d", &op);
	switch (op)
	{
	case 1: dif = 26;
		break;
	case 2:  dif = 23;
		break;
	case 3: dif = 20;
		break;
	case 4: return;
		break;
	default:printf("\nWrong input\n");
	}
	system("cls");
	// dif = 80;
	for (f = 0; f < dif; f++)
	{
		i = rand() % 9 + 1;
		j = rand() % 9 + 1;
		if (a[i][j] == 1 || ((i >= 4 && i <= 6) && (j >= 4 && j <= 6)))
			f--;
		else
		{
			a[i][j] = 1;
			temp[i][j] = gboard[i][j];
		}
	}
	char t;
	int r, c, n;

	q_print(temp, a);
	while (empty(temp, &i, &j))
	{
		printf("Sample input: A1 5\n");
		char s[5];
		gets(s);

		c = (int)toupper(s[0]) - 64;
		r = (int)s[1] - 48;
		n = (int)s[3] - 48;
		if (a[r][c] != 1 && strlen(s) == 4 && s[2] == ' ')
		{
			a[r][c] = 2;
			temp[r][c] = n;
			q_print(temp, a);
		}

		else if (!strcmp(s, "exit"))
		{


			return;
		}

		else
		{
			if (a[r][c] == 1)
			{
				printf("Cannot change Question values\n");
				system("pause");
			}
			else
			{

				printf("Wrong Input\n");
				system("pause");
			}
			q_print(temp, a);
		}
	}


	if (comparison(gboard, temp))
	{
		printf("\n\t\t\t You Win\t\t\n");
	}
	else
		printf("\n\t\t\t You Loose\t\t\n");

	system("pause");

}

int comparison(int a[10][10], int b[10][10])
{
	int i, j;
	for (i = 1; i < 10; i++)
		for (j = 1; j < 10; j++)
		{
			if (a[i][j] != b[i][j])
				return 0;
		}
	return 1;

}




