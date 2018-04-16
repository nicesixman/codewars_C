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

	printf("2-steps primes를 구합니다.\n");
	printf("-----------------------------------------------------\n");
	printf("찾으려는 prime step(2 이상)을 기입하세요.\n");
	scanf("%d", &g);
	printf("범위의 시작 수를 기입하세요.\n");
	scanf("%d", &m);
	printf("범위의 마지막 수를 기입하세요.\n");
	scanf("%d", &n);
	printf("-----------------------------------------------------\n");
	step(g, m, n);
	printf("\n");
	system("pause");

	return 0;
}