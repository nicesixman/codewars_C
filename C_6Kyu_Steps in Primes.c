#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int i, j, steps, x;
	int yaksu = 0;
	long long number1, number2;


	// 단순 약수를 먼저 구해보자.
	for (x=1; x<=m; x++)
	{
		if (m%x == 0)
		{
			yaksu = x;
			printf("%d", yaksu);
		}
	}

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
	printf("%d", yaksu);
	
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
