#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	printf("%d", g);
	printf("%d", m);
	printf("%d", n);
	
	return 0;
}

int main()
{
	int g;
	long long m, n;

	printf("2-steps primes�� ���մϴ�.\n");
	printf("-----------------------------------------------------\n");
	printf("ã������ prime step(2 �̻�)�� �����ϼ���.\n");
	scanf("%d", &g);
	printf("������ ���� ���� �����ϼ���.\n");
	scanf("%d", &m);
	printf("������ ������ ���� �����ϼ���.\n");
	scanf("%d", &n);
	printf("-----------------------------------------------------\n");
	step(g, m, n);
	printf("\n");
	system("pause");

	return 0;
}