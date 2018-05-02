#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int i, j, steps, x;
	int sumYaksu = 0;
	long long number1, number2;

	int Count, reminderCount;
	int isPrime = 0, isPrimeCount = 0;


	// 우리가 필요한건 약수가 아니라 소수였다. [Prime = 소수]였음..
	// 1은 소수가 아니므로 2부터 시작.
	for (Count=2; Count<=m; Count++)
	{
		// 나누어줄 변수를 1씩 증가시키면서 반복.
		for (reminderCount=1; reminderCount<=Count; reminderCount++)
		{
			// 자기 자신과 1만으로 나누어지므로 for문을 도는동안 0이 두 번만 나오면 그건 소수이다.
			// (즉, isPrime == 2일 경우, 그건 소수이다.)
			// 허나 아래 조건문 수식 하나만으로는 나머지가 0이되는 모든 경우가 계산된다.
			if (Count % reminderCount == 0)
				isPrime = isPrime + 1;
			// 예외처리를 하여 연산속도 증가.
			else
				break;
		}

		// 해결 방법으로써는, for문이 마무리 된 후 isPrime == 2일 때만 출력하게끔 전환하면 된다.
		if (isPrime == 2)
		{
			printf("%d ", Count);
		}
		// isPrime = 0으로 다시 초기화.
		isPrime = 0;
	}
	
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
