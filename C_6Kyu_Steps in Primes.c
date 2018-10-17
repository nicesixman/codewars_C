#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

// 전역변수를 사용하는 이유는 배열값을 return받기 위함.
// int로 선언할 시 prime step(g)가 start of the search(m) 보다 큰 경우 마지막 소수를 제대로 구하지 못한다.
// 아마 컴파일러 내 형변환 과정에서 VS는 잘 변환시켜주는 반면, gcc는 버그가 발생하는 듯 함. (추측)
long long result[2];

long long* step(int g, long long m, long long n)
{
	int isPrime = 0;
	int Count, reminderCount;
	// 동적 배열은 C++ 사용할 때 시도하고, 현재(C)는 코드 구조를 쉽게 읽기 위해 정적 배열로 선언.
	int matrix[100000], matrixCount = 0;
	int betweenCount;

	// m > n 으로 입력했을 때의 예외처리.
	// ex) (2, 5101, 103) --> 0, 0
	if (m > n)
	{
		result[0] = 0;
		result[1] = 0;
		printf("%lld %lld\n", result[0], result[1]);
		return result;
	}
	// step함수는 start of the search(m) ~ end of the search(n)가 있다.
	for (Count = m; Count <= n; Count++)
	{
		// isPrime = 0으로 초기화.
		isPrime = 0;
		// 나누어줄 변수를 1씩 증가시키면서 반복.
		for (reminderCount = 1; reminderCount <= Count; reminderCount++)
		{
			// 자기 자신과 1만으로 나누어지므로 for문을 도는동안 0이 두 번만 나오면 그건 소수이다.
			// (즉, isPrime == 2일 경우, 그건 소수이다.)
			// 허나 아래 조건식 하나만으로는 나머지가 0이되는 모든 경우가 계산된다.
			if (Count % reminderCount == 0)
			{
				isPrime = isPrime + 1;
				if (isPrime > 2)
					break;
			}

			/* 개선 아이디어: 자기 자신과 1만으로 나누어지므로 나머지가 0이 두 번만 나오는 수가 소수이다.
			하지만 % 연산을 1번만 거치게 하기 위해 reminderCount = 2; 부터 시작한다. (최적화)
			(즉, isPrime == 1일 경우, 그건 소수이다.) */

		}

		// 모든 경우가 계산되는 것의 해결 방법으로써
		// 안쪽 for문이 마무리 된 후 isPrime == 2일 때만 배열에 수를 저장하게끔 코드를 짜면 된다.
		if (isPrime == 2)
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
				return result;
			}
			// Case 2. 맞닿은 두 소수 차이만 구하는 것이 아니라 prime step(g)를 고려한 또다른 수식을 각각 작성하여야 한다.
			// else if로 재차 구분시켜놓는 이유는, 비효율적으로 for문을 진입하지 않게 하기 위함이다.
			// ex) (6, 100, 110) --> 101, 107
			else if (matrixCount >= 2 && g != (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				for (betweenCount = 3; betweenCount <= g; betweenCount++)
				{
					if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - betweenCount]))
					{
						result[0] = matrix[matrixCount - betweenCount];
						result[1] = matrix[matrixCount - 1];
						printf("%lld, %lld\n", result[0], result[1]);
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
				return result;
			}
		}
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
