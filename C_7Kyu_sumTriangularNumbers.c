#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sumTriangularNumbers(int n)
{
	int i, j;
	int next = 0;
	int sum = 0;

	for (i=0; i<n; i++)
	{
		for (j=0; j<=i; j++)
		{
			// 행방향 (→)
			next++;
			printf("%d ", next);	// 수가 너무 커지면 주석처리.
		}
		// 열방향 (↓)
		printf(" << \n");
		sum += next;				// 수가 너무 커지면 주석처리.
	}

	printf("최종 합은 %d 입니다.\n", sum);

	return sum;
}

int main()
{
	int n;

	printf("Triangular Numbers 수의 합을 구합니다. 숫자를 입력하세요.\n");
	scanf("%d", &n);
	printf("---------------------------------------------------------\n");
	sumTriangularNumbers(n);

	system("pause");
}
