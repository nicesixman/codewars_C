#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int i, j, steps, x;
	int sumYaksu = 0;
	long long number1, number2;

	int Count, reminderCount;
	int isPrime = 0;


	// 우리가 필요한건 약수가 아니라 소수였다. [Prime = 소수]였음..
	// 1은 소수가 아니므로 2부터 시작.
	for (Count=2; Count<=m; Count++)
	{
		// 나누어줄 변수를 1씩 증가시키면서 반복.
		for (reminderCount=2; reminderCount<=Count; reminderCount++)
		{
			// 자기 자신과 1만으로 나누어지므로 for문을 도는동안 0이 두 번만 나오면 그건 소수이다.
			// 허나 아래 수식 하나만으로는 나머지가 0이되는 모든 경우가 계산된다.
			if (Count % reminderCount == 0)
			{
				isPrime = isPrime + 1;

				// 따라서 키포인트는, 아래 조건문이 2번 이상 걸리는 경우에는 출력하지 않는 것이다.
				if (isPrime == 1)
				{
					printf("%d ", Count);
					isPrime = 0;
				}
			}
			else
				isPrime = 0;
		}
	}

	// 이럴 경우 2부터의 모든 수를 출력한다.
	// 소수 = 자신과 1만으로 나누어지는 수. (2, 3, 5, 7, 11, ...)
	// 일단은 위와같이 수식을 짤 경우 소수는 1회만 출력, 소수가 아닌 수는 여러번 출력된다.
	// 수식을 조금만 더 다듬으면 될듯함.

	/*
	// number1(앞 수)을 구한다.
	for (i=1; i<=m; i++)
	{
		if (m%i != 0)
		{
			number1 = i;
		}
		else
		{
			number1 = m;
		}
	}

	// number2(뒷 수)를 구한다.
	for (j=m; j<=n; j++)
	{
		if (n%j != 0)
		{
			number2 = j;
		}
		else
		{
			number2 = n;
		}
	}

	printf("%lld", number1);
	printf("%lld", number2);
	*/
	
	return 0;
}

int main()
{
	int g;
	long long m, n;

	printf("2-steps primes를 구합니다.\n");
	printf("-----------------------------------------------------\n");
	printf("찾으려는 prime step(2 이상)을 기입하세요.\n");
	scanf("%d", &g);
	printf("범위의 시작 수(2 이상)를 기입하세요.\n");
	scanf("%lld", &m);
	printf("범위의 마지막 수(시작 수 이상)를 기입하세요.\n");
	scanf("%lld", &n);
	printf("-----------------------------------------------------\n");
	step(g, m, n);
	printf("\n");
	system("pause");

	return 0;
}
