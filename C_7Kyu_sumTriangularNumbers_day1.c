#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sumTriangularNumbers(int n)
{
	int i, j;
	int next = 0;

	for (i=1; i<n; i++)
	{
		for (j=1; j<=i; j++)
		{
			// 행방향 (→)
			next++;
			printf("%d ", next);
		}
		// 열방향 (↓)
		printf(" << \n");
	}

	return 0;
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
