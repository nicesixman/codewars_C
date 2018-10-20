#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)
#define MAXvalue 1000000

// ★ 에라토스테네스의 체를 활용하여 연산을 대폭 줄여본다.
/*
step1) 2는 소수라고 판단이 된다. --> 2의 배수는 모두 소수임.
step2) 3은 소수라고 판단이 된다. --> 3의 배수는 모두 소수임.
step3) 4는 2의 배수이므로 바로 skip
step4) 5는 소수라고 판단이 된다. --> 5의 배수는 모두 소수임.
step5) 6는 2의 배수이므로 바로 skip
즉, ESFlag == 0(소수가 아니면) 일 때는 2중 중첩 for문을 계산하며
ESFlag == 1(소수라면) 2중 중첩 for문으로 진입하지 않게 함으로써 Dynamic Programming 구현.
*/

// 어차피 0 아니면 1만 저장되므로 char로 선언하여 할당 가능 공간 추가 확보
static char ESArr[MAXvalue + 1] = { 0 };

// inline 함수를 통해 함수 호출을 줄임으로써 속도 낭비를 방지.
static int __inline isEratosthenesSieve(unsigned int Count)
{
	int i, j;
	static int ESArrFlag = 0;

	if (ESArrFlag == 0)
	{
		// i를 2부터 MAXvalue까지 설정 후 모든 숫자를 연산.
		for (i=2; i<MAXvalue; i++)
		{
			if (ESArr[i] == 0)
			{
				// 위 for문에서 i의 배수는 모두 소수가 아닌 것으로 세팅.
				for (j=i+i; j<=MAXvalue; j+=i)
				{
					ESArr[j] = 1;
				}
			}
		}
		ESArrFlag = 1;
	}
	// for문 종료 후 Count가 MAXvalue 이내이며, 배열의 값이 소수인지 아닌지 판별.
	if (Count < MAXvalue && ESArr[Count] == 0)
		return 1;	// 소수.
	else
		return 0;	// 소수 아님.
}

long long* step(int g, long long m, long long n)
{
	int isNotPrime = 0;
	// int Count의 경우 원래는 long long으로 선언해야 warning C4244가 발생하지 않지만 실행속도가 2.5배 가까이 느려져버림.
	int Count = 0;
	int ESCount = 0, betweenCount;
	// 동적 배열은 느려서 알고리즘 문제풀이에 적합하지 않다. 정적 배열로 선언.
	int matrix[MAXvalue], matrixCount = 0;
	long long* result = (long long*)malloc(sizeof(long long) * 1);
	int i;

	// 문제에서 주어진 조건의 사전 예외처리.
	// ex) (2, 5, 5) --> 0, 0
	if (g > n - m)
	{
		result[0] = 0;
		result[1] = 0;
		printf("%lld %lld\n", result[0], result[1]);
		return result;
	}

	// step함수는 start of the search(m) ~ end of the search(n)가 있다.
	// 단, m~n사이의 소수만 검색하면 되므로 m이 범위 안에 있더라도 n이 범위를 넘어서면 구하지 않아도 된다.
	// 따라서 원래는 end of the search(n)까지 모두 찾는 것이 아니라, n-g까지만 검색해도 된다.
	for (Count=m; Count<=n; Count++)
	{
		isNotPrime = 0;
		// Count가 소수가 아니라면 추가 연산 없이 for문으로 되돌아간다.
		if (isEratosthenesSieve(Count) == 0)
			continue;
		// Count가 소수라면 아래 조건문으로 진입시켜준다.
		if (isEratosthenesSieve(Count) == 1)
		{
			isNotPrime++;
			matrix[matrixCount] = Count;
		}
		// isNotPrime == 1일 때(소수일 때) matrix 배열 위치를 +1씩 변경해서 저장해준다.
		if (isNotPrime == 1)
		{
			matrixCount++;
			continue;
		}
	}
	// matrixCount가 2 이상으로 올라간다면 소수가 아닌 수가 2개 이상 존재한다는 의미.

	// Case 1. 맞닿은 두 소수 차이를 계산.
	// ex) (2, 100, 110) --> 101, 103
	// matrix[matrixCount]: start of the search(m)보다 큰 수 중 처음 소수가 아닌 수가 저장되어 있음.
	for (i=0; i<matrixCount; i++)
	{
		if (matrixCount >= 2 && g == (matrix[i+1] - matrix[i]))
		{
			result[0] = matrix[i];
			result[1] = matrix[i+1];
			printf("%lld, %lld\n", result[0], result[1]);
			return result;
			break;
		}
		// Case 2. 맞닿은 두 소수 차이만 구하는 것이 아니라 prime step(g)를 고려한 또다른 수식을 각각 작성하여야 한다.
		// else if로 재차 구분시켜놓는 이유는, 비효율적으로 for문을 진입하지 않게 하기 위함이다.
		// ex) (6, 100, 110) --> 101, 107
		else if (matrixCount >= 2 && g != (matrix[i+1] - matrix[i]))
		{
			for (betweenCount=2; betweenCount<g; betweenCount++)
			{
				if (g == (matrix[i+betweenCount] - matrix[i]))
				{
					result[0] = matrix[i];
					result[1] = matrix[i + betweenCount];
					printf("%lld, %lld\n", result[0], result[1]);
					return result;
				}
			}
		}
	}
	// Case 3. prime step(g)를 고려해도 matrix 배열 안에 해당되는 소수가 없을 때.
	// ex) (2, 4900, 4919)--> 0, 0
	if (matrixCount >= 2)
	{
		result[0] = 0;
		result[1] = 0;
		printf("%lld %lld\n", result[0], result[1]);
		return result;
	}
	free(result);
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
