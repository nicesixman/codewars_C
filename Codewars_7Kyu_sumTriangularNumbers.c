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
			// ����� (��)
			printf("%d", i);
		}
		// ������ (��)
		printf("\n");
	}
}

int main()
{
	int n;

	printf("Triangular Numbers ���� ���� ���մϴ�. ���ڸ� �Է��ϼ���.\n");
	scanf("%d", &n);
	sumTriangularNumbers(n);

	system("pause");
}