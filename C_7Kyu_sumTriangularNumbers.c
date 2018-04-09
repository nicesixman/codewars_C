#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int sumTriangularNumbers(int n)
{
	int i, j=1;

	for (i=0; i<5; i++)
	{
		for (j=0; j<i; j++)
		{
			// 행방향 (→)
			printf("%d", i);
		}
		// 열방향 (↓)
		printf("\n");
	}
}

int main()
{
	int n;

	printf("Triangular Numbers 수의 합을 구합니다. 숫자를 입력하세요.\n");
	scanf("%d", &n);
	sumTriangularNumbers(n);

	system("pause");
}
