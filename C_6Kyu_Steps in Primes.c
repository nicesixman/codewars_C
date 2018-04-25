#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int i, j, steps, x;
	int sumYaksu = 0;
	long long number1, number2;

	int Count, reminderCount;

	/*
	// 단순 약수를 먼저 구해보자. 이건 입력값에 대한 약수. (o(N))
	for (x=1; x<=m; x++)
	{
		if (m%x == 0)
		{
			sumYaksu += x;
			printf("%d", x);
		}
	}
	*/

	// 하지만 우리가 필요한건 약수가 아니라 소수였다. [Prime = 소수]였음..
	for (Count=2; Count<=m; Count++)			// 1은 소수가 아니므로 2부터 시작.
	{
		for (reminderCount=2; reminderCount<=Count; reminderCount++)
		{
			printf("%d ", Count);
		}
	}

	// 이럴 경우 모든 수를 출력한다.
	// 소수 = 자신과 1만으로 나누어지는 수. (2, 3, 5, 7, 11, ...)
	// 일단은 2 / 3 3 / 4 4 4 / 5 5 5 5 ... 형식으로 카운트되고 있다. 수식만 만들어서 적용하면 될듯함.



	// 약수 구현 완료. 이제 여기서 나열되는 숫자를 뽑아서 문제를 해결하는 방식으로 풀어보자.



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
