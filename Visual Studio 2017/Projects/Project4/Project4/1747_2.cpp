#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int len, mid, input;
char str[7];


void Is_palinedrome();
int Is_prime(int num);


int main()
{
	scanf("%d", &input);


	Is_palinedrome();

	while (Is_prime(atoi(str)))
	{
		input++;
		Is_palinedrome();
	}

	printf("%s", str);
	return 0;
}


void Is_palinedrome()
{
	int i, mid_L;

	sprintf(str, "%d", input);
	len = strlen(str);
	mid = len / 2;


	if (len % 2 == 1)        //  odd
	{
		for (i = 1; i <= mid; i++)
		{
			if (str[mid - i] < str[mid + i])
			{
				input += (int)pow(10.0, (double)mid);
				sprintf(str, "%d", input);
				len = strlen(str);
				mid = len / 2;
				break;
			}
		}

		for (i = 1; i <= mid; i++)
		{
			str[mid + i] = str[mid - i];
		}
	}

	else                //  even
	{
		mid_L = mid - 1;    //  middle numer from the left

		for (i = 0; i < mid; i++)
		{
			if (str[mid_L - i] < str[mid + i])
			{
				input += (int)pow(10.0, (double)mid);
				sprintf(str, "%d", input);
				len = strlen(str);
				mid = len / 2;
				mid_L = mid - 1;
				break;
			}
		}

		for (i = 0; i < mid; i++)
		{
			str[mid + i] = str[mid_L - i];
		}
	}

	return;
}


int Is_prime(int num)
{
	if (num == 1)
		return 1;
	int root = (int)sqrt((double)num);

	for (int i = 2; i <= root; i++)
	{
		if (num % i == 0)
		{
			return 1;		//	not a prime number
		}
	}

	return 0;			//	a prime number
}
