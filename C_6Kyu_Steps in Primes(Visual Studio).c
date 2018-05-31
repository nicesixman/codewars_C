#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int isPrime = 0;
	int Count, reminderCount;
	int matrix[100000], result[2], matrixCount = 0;
	// 동적 배열은 C++ 사용할 때 시도하고, 현재(C)는 코드 구조를 쉽게 읽기 위해 정적 배열로 선언.
	int betweenCount;

	// m > n 으로 입력했을 때의 예외처리.
	// ex) (2, 5101, 103) --> 0, 0
	if (m > n)
	{
		int* result[2] = { 0, 0 };
		printf("%d %d\n", result[0], result[1]);
		return result;
	}
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
			// Normal case. 맞닿은 두 소수 차이를 계산.
			// ex) (2, 100, 110) --> 101, 103
			if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				int* result[2] = { matrix[matrixCount - 2], matrix[matrixCount - 1] };
				printf("%d, %d\n", matrix[matrixCount - 2], matrix[matrixCount - 1]);
				return result;
				matrixCount = 0;
			}
			// ex1) (6, 100, 110) --> 101, 107
			// ex2) (3, 2, 5) --> 2, 5
			// 맞닿은 두 소수 차이만 구하는 것이 아니라 prime step(g)를 고려한 또다른 수식을 작성하여야 한다.
			// else if로 재차 구분시켜놓는 이유는, 비효율적으로 for문을 진입하지 않게 하기 위함이다.
			// ★codewars에서는 왜인지 이 부분에서 (3, 2, 5) --> 0, 3으로 인식한다.
			// 원인은 gcc 문법과 VS 문법의 차이점에서 비롯하는 것.
			else if (matrixCount >= 2 && g != (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				for (betweenCount = 3; betweenCount <= g; betweenCount++)
				{
					if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - betweenCount]))
					{
						int* result[2] = { matrix[matrixCount - betweenCount], matrix[matrixCount - 1] };
						printf("%d, %d\n", matrix[matrixCount - betweenCount], matrix[matrixCount - 1]);
						return result;
						matrixCount = 0;
					}
				}
				// start of the search(m) ~ end of the search(n) 내 소수가 2개 이상이지만 prime step(g)에 걸리지 않을 때.
				// ex) (2, 4900, 4919) --> 0, 0
				if (n == Count)
				{
					int* result[2] = { 0, 0 };
					printf("%d %d\n", result[0], result[1]);
					return result;
					matrixCount = 0;
				}
			}
			// start of the search(m), end of the search(n) 가 일치하는 수 일 때.
			// ex) (2, 5, 5) --> 0, 0
			else if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d\n", result[0], result[1]);
				return result;
				matrixCount = 0;
			}
		}
		else
		{
			// start of the search(m) ~ end of the search(n) 내 모든 소수의 차 중 prime step(g)과 일치하는 수가 없을 때.
			// ex) (11, 30000, 100000) --> 0, 0
			if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d\n", result[0], result[1]);
				return result;
				matrixCount = 0;
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
	system("pause");

	return 0;
}
