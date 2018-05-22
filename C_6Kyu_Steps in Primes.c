#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int isPrime = 0;
	int Count, reminderCount;
	int matrix[10000], matrixCount = 0;
	// 동적 배열은 C++ 사용할 때 시도하고, 현재(C)는 코드 구조를 쉽게 읽기 위해 정적 배열로 선언.
	int arraySize = 0;								// ★ for debug

	// step함수는 start of the search(m) ~ end of the search(n)가 있다.
	for (Count=m; Count<=n; Count++)
	{
		// 나누어줄 변수를 1씩 증가시키면서 반복.
		for (reminderCount=1; reminderCount<=Count; reminderCount++)
		{
			// 자기 자신과 1만으로 나누어지므로 for문을 도는동안 0이 두 번만 나오면 그건 소수이다.
			// (즉, isPrime == 2일 경우, 그건 소수이다.)
			// 허나 아래 조건식 하나만으로는 나머지가 0이되는 모든 경우가 계산된다.
			if (Count % reminderCount == 0)
				isPrime = isPrime + 1;

			arraySize = arraySize + 1;				// ★ for debug
		}

		// 모든 경우가 계산되는 것의 해결 방법으로써
		// 안쪽 for문이 마무리 된 후 isPrime == 2일 때만 배열에 수를 저장하게끔 코드를 짜면 된다.
		if (isPrime == 2)
		{
			// printf("%d ", Count);		// 배열 미사용시 소수 전체출력.
			matrix[matrixCount] = Count;
			matrixCount = matrixCount + 1;
			if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				printf("%d, %d", matrix[matrixCount - 2], matrix[matrixCount - 1]);

				// 계산한 값 return을 위함.
				int* result[2] = { matrix[matrixCount - 2], matrix[matrixCount - 1] };
				printf("\n연산 Count: %d", arraySize); // ★ for debug
				return result;
			}
			else if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d", result[0], result[1]);
				printf("\n연산 Count: %d", arraySize); // ★ for debug
				return result;
			}
		}
		// 두 약수의 차가 prime step(g)과 일치하는 수가 없을 때.
		else
		{
			if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d", result[0], result[1]);
				printf("\n연산 Count: %d", arraySize); // ★ for debug
				return result;
			}
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
	step(g, m, n);		// 함수 실행
	printf("\n");
	system("pause");

	return 0;
}
