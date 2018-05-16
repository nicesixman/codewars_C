#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	// ★ 진척상황
	/*
	1. int g / long long m / long long n은 모두 작동한다.
	2. 단, 현재는 위 작동점을 기준으로 모든 소수를 출력한다.
	3. 따라서 앞으로 해야할 작업은 (마지막 소수 - 마지막 전 소수 = g)인 케이스를 구별하는 것.
	4. 위 작업들이 끝나면 마지막으로 else if (steps > g)의 케이스(null 경우)도 추가해줘야 한다.
	*/


	int isPrime = 0;
	int Count, reminderCount, holdCount;


	// 우리가 필요한건 약수가 아니라 소수였다. [Prime = 소수]였음..
	// 1은 소수가 아니므로 2부터 시작하여야하지만, step함수는 start of the search 수(m)가 있다.
	for (Count=m; Count<=n; Count++)
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
			// ...를 하고 싶었으나 아래 수식을 추가하면 계산식이 안맞는다. 일단 skip.
			/*
			else
				break;
			*/
		}

		// 모든 경우가 계산되는 것의 해결 방법으로써
		// for문이 마무리 된 후 isPrime == 2일 때만 출력하게끔 전환하면 된다.
		if (isPrime == 2)
			printf("%d ", Count);
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
	step(g, m, n);		// 함수 실행
	printf("\n");
	system("pause");

	return 0;
}
