#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int isPrime = 0;
	int Count, reminderCount;
	int matrix[10000], matrixCount = 0;
	// 동적 배열은 C++ 사용할 때 시도하고, 현재(C)는 코드 구조를 쉽게 읽기 위해 정적 배열로 선언.
	int betweenCount;

	// step함수는 start of the search(m) ~ end of the search(n)가 있다.
	for (Count = m; Count <= n; Count++)
	{
		// 나누어줄 변수를 1씩 증가시키면서 반복.
		for (reminderCount = 1; reminderCount <= Count; reminderCount++)
		{
			// 자기 자신과 1만으로 나누어지므로 for문을 도는동안 0이 두 번만 나오면 그건 소수이다.
			// (즉, isPrime == 2일 경우, 그건 소수이다.)
			// 허나 아래 조건식 하나만으로는 나머지가 0이되는 모든 경우가 계산된다.
			if (Count % reminderCount == 0)
				isPrime = isPrime + 1;

			// 연산속도 향상을 위한 예외처리.
			if (isPrime > 2)
				break;
		}

		// 모든 경우가 계산되는 것의 해결 방법으로써
		// 안쪽 for문이 마무리 된 후 isPrime == 2일 때만 배열에 수를 저장하게끔 코드를 짜면 된다.
		if (isPrime == 2)
		{
			matrix[matrixCount] = Count;
			matrixCount = matrixCount + 1;
			if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				// 계산한 값 return.
				int* result[2] = { matrix[matrixCount - 2], matrix[matrixCount - 1] };
				printf("%d, %d", matrix[matrixCount - 2], matrix[matrixCount - 1]);
				return result;
				matrixCount = 0;
			}
			// (6, 100, 110) --> 101, 107이나 (3, 2, 5) --> 2, 5 등 처럼.
			// 맞닿은 두 소수 차이만 구하는 것이 아니라 prime step(g)를 고려한 또다른 수식을 작성하여야 한다.
			// else if로 재차 구분시켜놓는 이유는, 비효율적으로 for문을 진입하지 않게 하기 위함이다.
			else if (matrixCount >= 2 && g != (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				for (betweenCount = 3; betweenCount <= g; betweenCount++)
				{
					if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - betweenCount]))
					{
						int* result[2] = { matrix[matrixCount - betweenCount], matrix[matrixCount - 1] };
						printf("%d, %d", matrix[matrixCount - betweenCount], matrix[matrixCount - 1]);
						return result;
						matrixCount = 0;
					}
				}
			}
			// prime step(g)가 끝까지 도달했으나 일치하는 소수를 찾지 못한 경우.
			else if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d", result[0], result[1]);
				return result;
				matrixCount = 0;
			}
		}
		// 두 약수의 차가 prime step(g)과 일치하는 수가 없을 때.
		else
		{
			if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d", result[0], result[1]);
				return result;
				matrixCount = 0;
			}
		}
		// ★ 다른건 다 되는데 왜 2, 4900, 4919는 위 수식에 걸리지 않는걸까? 정말로 마지막 미해결 과제.
		// 한 가지 알아낸 사실: end of the search(n)이 소수이면 prime step(g)에 걸리지 않을 때, 출력되지 않음.

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
