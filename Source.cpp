#include<iostream>
#include<conio.h>
#include"help.h"
#include<fstream>
#include<windows.h>
using namespace std;

void print(char board[8][8])
{
	system("cls");
	int x1 = 400, x2 = 440, y1 = 40, y2 = 80;
	for (int i = 0; i < 8; i++)
	{
		
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] == '1')
			{
				myRect(x1, y1, x2, y2 , 0, 255, 0, 0, 255, 0);
				myEllipse(x1, y1, x2, y2, 0, 0, 0, 255, 255, 255);
			}
			if (board[i][j] == '2')
			{
				myRect(x1, y1, x2, y2, 0, 255, 0, 0, 255, 0);
				myEllipse(x1, y1, x2, y2, 255, 255, 255, 0, 0, 0);
			}
			if (board[i][j] == '*')
			{
				myRect(x1, y1, x2, y2, 0, 255, 0, 0, 255, 0);
			}
			x1 = x1 + 50;
			x2 = x2 + 50;
		}
		y1 = y1 + 50;
		y2 = y2 + 50;
		x1 = 400;
		x2 = 440;
	}
}

struct coordinates
{
	int x;
	int y;
};

bool checkvalidindex(char arr[8][8], int x, int y, int turn)
{
	int decision = 0;
	int temp1 = x;
	int temp2 = y;
	if (turn == 1)
	{
		if (arr[x - 1][y] == '2')
		{
			x = x - 1;
			while (arr[x][y] == '2')
			{
				x = x - 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x + 1][y] == '2')
		{
			x = x + 1;
			while (arr[x][y] == '2')
			{
				x = x + 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x][y - 1] == '2')
		{
			y = y - 1;
			while (arr[x][y] == '2')
			{
				y = y - 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x][y + 1] == '2')
		{

			y = y + 1;
			while (arr[x][y] == '2')
			{
				y = y + 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x + 1][y + 1] == '2')
		{
			y = y + 1;
			x = x + 1;
			while (arr[x][y] == '2')
			{
				y = y + 1;
				x = x + 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x - 1][y - 1] == '2')
		{
			y = y - 1;
			x = x - 1;
			while (arr[x][y] == '2')
			{
				y = y - 1;
				x = x - 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x - 1][y + 1] == '2')
		{

			y = y + 1;
			x = x - 1;
			while (arr[x][y] == '2')
			{

				y = y + 1;
				x = x - 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x + 1][y - 1] == '2')
		{
			y = y - 1;
			x = x + 1;
			while (arr[x][y] == '2')
			{
				y = y - 1;
				x = x + 1;
				if (arr[x][y] == '1')
				{
					decision = 1;
					break;
				}
			}
		}
		if (decision == 1)
		{
			return true;
		}
	}
	
	if (turn == 2)
	{
		if (arr[x - 1][y] == '1')
		{
			x = x - 1;
			while (arr[x][y] == '1')
			{
				x = x - 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x + 1][y] == '1')
		{
			x = x + 1;
			while (arr[x][y] == '1')
			{
				x = x + 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x][y - 1] == '1')
		{
			y = y - 1;
			while (arr[x][y] == '1')
			{
				y = y - 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x][y + 1] == '1')
		{

			y = y + 1;
			while (arr[x][y] == '1')
			{
				y = y + 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x + 1][y + 1] == '1')
		{
			y = y + 1;
			x = x + 1;
			while (arr[x][y] == '1')
			{
				y = y + 1;
				x = x + 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x - 1][y - 1] == '1')
		{
			y = y - 1;
			x = x - 1;
			while (arr[x][y] == '1')
			{
				y = y - 1;
				x = x - 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x - 1][y + 1] == '1')
		{

			y = y + 1;
			x = x - 1;
			while (arr[x][y] == '1')
			{

				y = y + 1;
				x = x - 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		x = temp1;
		y = temp2;
		if (arr[x + 1][y - 1] == '1')
		{
			y = y - 1;
			x = x + 1;
			while (arr[x][y] == '1')
			{
				y = y - 1;
				x = x + 1;
				if (arr[x][y] == '2')
				{
					decision = 1;
					break;
				}
			}
		}
		if (decision == 1)
		{
			return true;
		}
	}

	return false;
		
}

coordinates checkbestmove(char arr[8][8], coordinates*temp,int count)
{
	int max = 0;
	int counter = 0;
	int prevcount = 0;
	coordinates a;
	a=temp[0];
	coordinates b;
	for (int i = 0; i < count; i++)
	{
		b = temp[i];
		int x=temp[i].x;
		int y= temp[i].y;
		counter = 0;
		if (arr[temp[i].x - 1][temp[i].y] == '1')
		{
			temp[i].x = temp[i].x - 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].x = temp[i].x - 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x + 1][temp[i].y] == '1')
		{
			temp[i].x = temp[i].x + 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].x = temp[i].x + 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x][temp[i].y-1] == '1')
		{
			temp[i].y = temp[i].y - 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].y = temp[i].y - 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x][temp[i].y + 1] == '1')
		{
			temp[i].y = temp[i].y + 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].y = temp[i].y + 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x + 1][temp[i].y + 1] == '1')
		{
			temp[i].y = temp[i].y + 1;
			temp[i].x = temp[i].x + 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].y = temp[i].y + 1;
				temp[i].x = temp[i].x + 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x - 1][temp[i].y - 1] == '1')
		{
			temp[i].y = temp[i].y - 1;
			temp[i].x = temp[i].x - 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].y = temp[i].y - 1;
				temp[i].x = temp[i].x - 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x - 1][temp[i].y + 1] == '1')
		{
			temp[i].y = temp[i].y + 1;
			temp[i].x = temp[i].x - 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].y = temp[i].y + 1;
				temp[i].x = temp[i].x - 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		else if (arr[temp[i].x + 1][temp[i].y - 1] == '1')
		{
			temp[i].y = temp[i].y + 1;
			temp[i].x = temp[i].x - 1;
			while (arr[temp[i].x][temp[i].y] == '1')
			{
				temp[i].y = temp[i].y + 1;
				temp[i].x = temp[i].x - 1;
				counter++;
				if (arr[temp[i].x][temp[i].y] == '2')
				{
					break;
				}
			}
		}
		temp[i].x = x;
		temp[i].y = y;
		if (counter > prevcount)
		{
			a = temp[i];
			prevcount = counter;
		}
	}
	return a;
}

void update_game_max(char arr[8][8], int x_coord, int y_coord)
{
	int temp1 = x_coord;
	int temp2 = y_coord;

	int checktrue = 0;
	if ((x_coord - 1 > 0) && arr[x_coord - 1][y_coord] == '1')
	{
		arr[x_coord][y_coord] = '2';
		x_coord = x_coord - 1;
		while ((x_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord - 1][y_coord] == '2')
			{
				checktrue = 1;
				break;
			}
			x_coord = x_coord - 1;
		}
		x_coord = temp1 - 1;
		if (checktrue == 1)
		{
			while ((x_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				x_coord = x_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if (x_coord + 1 < 7 && arr[x_coord + 1][y_coord] == '1')
	{
		arr[x_coord][y_coord] = '2';
		x_coord = x_coord + 1;
		while (x_coord + 1 < 7 && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord + 1][y_coord] == '2')
			{
				checktrue = 1;
				break;
			}
			x_coord = x_coord + 1;
		}
		x_coord = temp1 + 1;
		if (checktrue == 1)
		{
			while (x_coord + 1 < 7 && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				x_coord = x_coord + 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((y_coord - 1 > 0) && arr[x_coord][y_coord - 1] == '1')
	{
		arr[x_coord][y_coord] = '2';
		y_coord = y_coord - 1;
		while (y_coord - 1 > 0 && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord][y_coord - 1] == '2')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord - 1;
		}
		y_coord = temp2 - 1;
		x_coord = temp1;
		if (checktrue == 1)
		{
			while ((y_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				y_coord = y_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((y_coord + 1 < 7) && arr[x_coord][y_coord + 1] == '1')
	{
		arr[x_coord][y_coord] = '2';
		y_coord = y_coord + 1;
		while (y_coord + 1 < 7 && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord][y_coord + 1] == '2')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord + 1;
		}
		y_coord = temp2 + 1;
		if (checktrue == 1)
		{
			while ((y_coord + 1 < 7) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				y_coord = y_coord + 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord + 1 < 7 && y_coord + 1 < 7) && arr[x_coord + 1][y_coord + 1] == '1')
	{
		arr[x_coord][y_coord] = '2';
		y_coord = y_coord + 1;
		x_coord = x_coord + 1;
		while ((x_coord + 1 < 7 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord + 1][y_coord + 1] == '2')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord + 1;
			x_coord = x_coord + 1;
		}
		y_coord = temp2 + 1;
		x_coord = temp1 + 1;
		if (checktrue == 1)
		{
			while ((x_coord + 1 < 7 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				y_coord = y_coord + 1;
				x_coord = x_coord + 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord - 1 > 0 && y_coord - 1 > 0) && arr[x_coord - 1][y_coord - 1] == '1')
	{
		arr[x_coord][y_coord] = '2';
		y_coord = y_coord - 1;
		x_coord = x_coord - 1;
		while ((x_coord - 1 > 0 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord - 1][y_coord - 1] == '2')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord - 1;
			x_coord = x_coord - 1;
		}
		y_coord = temp2 - 1;
		x_coord = temp1 - 1;
		if (checktrue == 1)
		{
			while ((x_coord - 1 > 0 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				y_coord = y_coord - 1;
				x_coord = x_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord - 1 > 0 && y_coord + 1 < 7) && arr[x_coord - 1][y_coord + 1] == '1')
	{
		arr[x_coord][y_coord] = '2';
		y_coord = y_coord + 1;
		x_coord = x_coord - 1;
		while ((x_coord - 1 > 0 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord - 1][y_coord + 1] == '2')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord + 1;
			x_coord = x_coord - 1;
		}
		y_coord = temp2 + 1;
		x_coord = temp1 - 1;
		if (checktrue == 1)
		{
			while ((x_coord - 1 > 0 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				y_coord = y_coord + 1;
				x_coord = x_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord + 1 < 7 && y_coord - 1 > 0) && arr[x_coord + 1][y_coord - 1] == '1')
	{
		arr[x_coord][y_coord] = '2';
		y_coord = y_coord - 1;
		x_coord = x_coord + 1;
		while ((x_coord + 1 < 7 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
		{
			if (arr[x_coord + 1][y_coord - 1] == '2')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord - 1;
			x_coord = x_coord + 1;
		}
		y_coord = temp2 - 1;
		x_coord = temp1 + 1;
		if (checktrue == 1)
		{
			while ((x_coord + 1 < 7 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '1')
			{
				arr[x_coord][y_coord] = '2';
				y_coord = y_coord - 1;
				x_coord = x_coord + 1;
			}
		}
	}
}

void update_game_min(char arr[8][8], int x_coord, int y_coord)
{
	int temp1 = x_coord;
	int temp2 = y_coord;

	int checktrue = 0;
	if ((x_coord - 1 > 0) && arr[x_coord - 1][y_coord] == '2')
	{
		arr[x_coord][y_coord] = '1';
		x_coord = x_coord - 1;
		while ((x_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord - 1][y_coord] == '1')
			{
				checktrue = 1;
				break;
			}
			x_coord = x_coord - 1;
		}
		x_coord = temp1 - 1;
		if (checktrue == 1)
		{
			while ((x_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				x_coord = x_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if (x_coord + 1 < 7 && arr[x_coord + 1][y_coord] == '2')
	{
		arr[x_coord][y_coord] = '1';
		x_coord = x_coord + 1;
		while (x_coord + 1 < 7 && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord + 1][y_coord] == '1')
			{
				checktrue = 1;
				break;
			}
			x_coord = x_coord + 1;
		}
		x_coord = temp1 + 1;
		if (checktrue == 1)
		{
			while (x_coord + 1 < 7 && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				x_coord = x_coord + 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((y_coord - 1 > 0) && arr[x_coord][y_coord - 1] == '2')
	{
		arr[x_coord][y_coord] = '1';
		y_coord = y_coord - 1;
		while (y_coord - 1 > 0 && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord][y_coord - 1] == '1')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord - 1;
		}
		y_coord = temp2 - 1;
		//x_coord = temp1;
		if (checktrue == 1)
		{
			while ((y_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				y_coord = y_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((y_coord + 1 < 7) && arr[x_coord][y_coord + 1] == '2')
	{
		arr[x_coord][y_coord] = '1';
		y_coord = y_coord + 1;
		while (y_coord + 1 < 7 && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord][y_coord + 1] == '1')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord + 1;
		}
		y_coord = temp2 + 1;
		if (checktrue == 1)
		{
			while ((y_coord + 1 < 7) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				y_coord = y_coord + 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord + 1 < 7 && y_coord + 1 < 7) && arr[x_coord + 1][y_coord + 1] == '2')
	{
		arr[x_coord][y_coord] = '1';
		y_coord = y_coord + 1;
		x_coord = x_coord + 1;
		while ((x_coord + 1 < 7 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord + 1][y_coord + 1] == '1')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord + 1;
			x_coord = x_coord + 1;
		}
		y_coord = temp2 + 1;
		x_coord = temp1 + 1;
		if (checktrue == 1)
		{
			while ((x_coord + 1 < 7 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				y_coord = y_coord + 1;
				x_coord = x_coord + 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord - 1 > 0 && y_coord - 1 > 0) && arr[x_coord - 1][y_coord - 1] == '2')
	{
		arr[x_coord][y_coord] = '1';
		y_coord = y_coord - 1;
		x_coord = x_coord - 1;
		while ((x_coord - 1 > 0 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord - 1][y_coord - 1] == '1')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord - 1;
			x_coord = x_coord - 1;
		}
		y_coord = temp2 - 1;
		x_coord = temp1 - 1;
		if (checktrue == 1)
		{
			while ((x_coord - 1 > 0 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				y_coord = y_coord - 1;
				x_coord = x_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord - 1 > 0 && y_coord + 1 < 7) && arr[x_coord - 1][y_coord + 1] == '2')
	{
		arr[x_coord][y_coord] = '1';
		y_coord = y_coord + 1;
		x_coord = x_coord - 1;
		while ((x_coord - 1 > 0 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord - 1][y_coord + 1] == '1')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord + 1;
			x_coord = x_coord - 1;
		}
		y_coord = temp2 + 1;
		x_coord = temp1 - 1;
		if (checktrue == 1)
		{
			while ((x_coord - 1 > 0 && y_coord + 1 < 7) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				y_coord = y_coord + 1;
				x_coord = x_coord - 1;
			}
		}
	}
	x_coord = temp1;
	y_coord = temp2;
	checktrue = 0;
	if ((x_coord + 1 < 7 && y_coord - 1 > 0) && arr[x_coord + 1][y_coord - 1] == '2')
	{
		arr[x_coord][y_coord] = '1';
		y_coord = y_coord - 1;
		x_coord = x_coord + 1;
		while ((x_coord + 1 < 7 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
		{
			if (arr[x_coord + 1][y_coord - 1] == '1')
			{
				checktrue = 1;
				break;
			}
			y_coord = y_coord - 1;
			x_coord = x_coord + 1;
		}
		y_coord = temp2 - 1;
		x_coord = temp1 + 1;
		if (checktrue == 1)
		{
			while ((x_coord + 1 < 7 && y_coord - 1 > 0) && arr[x_coord][y_coord] == '2')
			{
				arr[x_coord][y_coord] = '1';
				y_coord = y_coord - 1;
				x_coord = x_coord + 1;
			}
		}
	}
}

void minmax(char arr[8][8])    //level 1
{
	coordinates*temp = new coordinates[64];
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == '*')
			{
				bool a = checkvalidindex(arr, i, j, 2);
				if (a == true)
				{
					coordinates a;
					a.x = i;
					a.y = j;
					temp[count] = a;
					count++;
				}
			}
		}
	}

	coordinates a = checkbestmove(arr, temp, count);
	
	int x_coord = a.x;
	int y_coord = a.y;
	update_game_max(arr, x_coord, y_coord);
}

int evaluationfunction(char arr[8][8])
{
	int b_count = 0, w_count=0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j]=='2')
			{
				b_count++;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (arr[i][j] == '1')
			{
				w_count++;
			}
		}
	}
	return b_count - w_count;
}

int minmax2(char arr[8][8],int level,coordinates &T,bool ismax)
{
	if (level == 0)
	{
		return evaluationfunction(arr);
	} 
	if(ismax)
	{
		coordinates*temp = new coordinates[64];
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == '*')
				{
					bool a = checkvalidindex(arr, i, j, 2);
					if (a == true)
					{
						coordinates a;
						a.x = i;
						a.y = j;
						temp[count] = a;
						count++;
					}
				}
			}
		}
		int evaluation = 0;
		int max = -999999;
		char temporary_arr[8][8];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				temporary_arr[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < count; i++)
		{
			update_game_max(arr, temp[i].x, temp[i].y);
			minmax2(arr, level-1,T,!ismax);  

			evaluation = evaluationfunction(arr);
			if (evaluation > max)
			{
				max = evaluation;
				T.x = temp[i].x;
				T.y = temp[i].y;
			}
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					arr[i][j]=temporary_arr[i][j];
				}
			}
		}
		return max;
	}
	if (!ismax)
	{
		coordinates T;
		int evaluation = 0;
		int min = 99999;
		coordinates*temp = new coordinates[64];
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == '*')
				{
					bool a = checkvalidindex(arr, i, j, 1);
					if (a == true)
					{
						coordinates a;
						a.x = i;
						a.y = j;
						temp[count] = a;
						count++;
					}
				}
			}
		}
		char temporary_arr[8][8];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				temporary_arr[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < count; i++)
		{
			update_game_min(arr, temp[i].x, temp[i].y);
			minmax2(arr, level - 1,T,ismax);

			evaluation = evaluationfunction(arr);
			if (evaluation < min)
			{
				min = evaluation;
				T.x = temp[i].x;
				T.y=temp[i].y;
			}
			for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					arr[i][j] = temporary_arr[i][j];
				}
			}
		}
		return min;
	}
}

int main()
{
	char arr[8][8];
	ifstream fin;
	fin.open("array.txt");
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			fin >> arr[i][j];
		}
	}
	int B_score = 2, W_score = 2;
	int x_coord;
	int y_coord;
	
	int difficulty;
	cout << "Enter Difficulty, 1 for easy , 2 for hard : " << endl;
	cin >> difficulty;
	system("cls");
	while (B_score + W_score < 64)
	{
		coordinates*temp = new coordinates[64];
		print(arr);
		int count = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == '*')
				{
					bool a = checkvalidindex(arr, i, j, 1);
					if (a == true)
					{
						coordinates a;
						a.x = i;
						a.y = j;
						temp[count] = a;
						count++;
					}
				}
			}
		}
		cout << "White score = " << W_score << endl;
		cout << "Black score = " << B_score << endl;
		for (int i = 0; i < count; i++)
		{
			cout<< "x : " << temp[i].x << "    y : " << temp[i].y << endl;
		}
		cin >> x_coord;
		cin >> y_coord;
		int check = 0;
		for (int i = 0; i < count; i++)
		{
			if (x_coord == temp[i].x && y_coord == temp[i].y)
			{
				check = 1;
				break;
			}
		}
		if (check == 1)
		{
			update_game_min(arr, x_coord, y_coord);
		}
		if(check==0)
		{
			cout << "not a valid move, Try again" << endl;
			Sleep(2000);
		}
		
		system("cls");
		print(arr);
		if (difficulty == 1 && check==1)
		{
			minmax(arr);
		}
		if (difficulty == 2 && check==1)
		{
			coordinates T;
			int a = minmax2(arr, 3, T, true);
			update_game_max(arr, T.x, T.y);
		}
		Sleep(500);
		B_score = 0;
		W_score = 0;
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (arr[i][j] == '2')
				{
					B_score++;
				}
				if (arr[i][j] == '1')
				{
					W_score++;
				}
			}
		}
		system("cls");
	}
	if (B_score > W_score)
	{
		cout << endl << "Black wins" << endl;
	}
	if (B_score < W_score)
	{
		cout << endl << "White wins" << endl;
	}
	if (B_score == W_score)
	{
		cout << endl << "Draw!" << endl;
	}
	_getch();
}