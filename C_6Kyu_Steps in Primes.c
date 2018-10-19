#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int isPrime = 0;
	// int Count의 경우 원래는 long long으로 선언해야 warning C4244가 발생하지 않지만
	// long long으로 선언할 경우에는 실행속도가 2.5배 가까이 느려져버림.
	int Count, reminderCount;
	int betweenCount;
	// 동적 배열로 선언.
	long long* matrix = (long long*)malloc(sizeof(long long) * 100000);
	int matrixCount = 0;
	long long* result = (long long*)malloc(sizeof(long long) * 2);

	// m > n 으로 입력했을 때의 예외처리.
	// ex) (2, 5101, 103) --> 0, 0
	if (m > n)
	{
		result[0] = 0;
		result[1] = 0;
		printf("%lld %lld\n", result[0], result[1]);
		free(matrix);
		return result;
	}
	// step함수는 start of the search(m) ~ end of the search(n)가 있다.
	for (Count = m; Count <= n; Count++)
	{
		isPrime = 0;
		// 나누어줄 변수를 1씩 증가시키면서 반복.
		for (reminderCount = 1; reminderCount < Count; reminderCount++)
		{
			if (Count % reminderCount == 0)
			{
				isPrime++;
				if (isPrime > 1)
					break;
			}
		}

		// 안쪽 for문이 마무리 된 후 isPrime == 1일 때만 배열에 수를 저장하게끔 코드를 짜면 된다.
		if (isPrime == 1)
		{
			matrix[matrixCount] = Count;
			matrixCount = matrixCount + 1;
			// Case 1. 맞닿은 두 소수 차이를 계산.
			// ex) (2, 100, 110) --> 101, 103
			if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				result[0] = matrix[matrixCount - 2];
				result[1] = matrix[matrixCount - 1];
				printf("%lld, %lld\n", result[0], result[1]);
				free(matrix);
				return result;
			}
			// Case 2. 맞닿은 두 소수 차이만 구하는 것이 아니라 prime step(g)를 고려한 또다른 수식을 각각 작성하여야 한다.
			// else if로 재차 구분시켜놓는 이유는, 비효율적으로 for문을 진입하지 않게 하기 위함이다.
			// ex) (6, 100, 110) --> 101, 107
			else if (matrixCount >= 2 && g != (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				for (betweenCount = 3; betweenCount <= g; betweenCount++)
				{
					// matrixCount가 올라가기도 전에 betweenCount가 더 높은 경우의 예외처리.
					if (matrixCount < betweenCount)
						break;
					else if (g == (matrix[matrixCount - 1] - matrix[matrixCount - betweenCount]))
					{
						result[0] = matrix[matrixCount - betweenCount];
						result[1] = matrix[matrixCount - 1];
						printf("%lld, %lld\n", result[0], result[1]);
						free(matrix);
						return result;
					}
				}
				// Case 3. start of the search(m) ~ end of the search(n) 내 소수가 2개 이상이지만 prime step(g)에 걸리지 않을 때.
				// ex) (2, 4900, 4919) --> 0, 0
				if (n == Count)
				{
					result[0] = 0;
					result[1] = 0;
					printf("%lld %lld\n", result[0], result[1]);
					free(matrix);
					return result;
				}
			}
			// Case 4. start of the search(m), end of the search(n) 가 일치하는 수 일 때.
			// ex) (2, 5, 5) --> 0, 0
			else if (n == Count)
			{
				result[0] = 0;
				result[1] = 0;
				printf("%lld %lld\n", result[0], result[1]);
				free(matrix);
				return result;
			}
		}
		else
		{
			// Case 5. start of the search(m) ~ end of the search(n) 내 모든 소수의 차 중 prime step(g)과 일치하는 수가 없을 때.
			// ex) (11, 30000, 100000) --> 0, 0
			if (n == Count)
			{
				result[0] = 0;
				result[1] = 0;
				printf("%lld %lld\n", result[0], result[1]);
				free(matrix);
				return result;
			}
		}
	}
	free(result);
	free(matrix);
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
	system("pause");

	return 0;
}
