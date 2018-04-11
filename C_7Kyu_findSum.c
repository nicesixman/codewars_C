#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int findSum(int n)
{
	int i, j, k;
	int three_for = 0, five_for = 0, three_total = 0, five_total = 0, fifteen_for = 0, Common_Multiple_Total = 0;
	int result;
	
	printf("3의 배수에 해당되는 수는 { ");
	for (i=1; i <= (n/3); i++)
	{
		three_for = i * 3;
		three_total += three_for;
		printf("%d, ", three_for);
	}
	printf(" } 입니다.\n");
	
	printf("5의 배수에 해당되는 수는 { ");
	for (j=1; j <= (n/5); j++)
	{
		five_for = j * 5;
		five_total += five_for;
		printf("%d, ", five_for);
	}
	printf(" } 입니다.\n");

	// 3의 배수와 5의 배수의 공배수는 15배수 단위. 따라서 15배수 단위의 수는 1번만 더한다.
	// 아래 if 구문은 n이 15 이상일 경우, 15부터 count 1마다 15씩 더해서 총합을 구하는 것.
	if (n >= 15)
	{
		printf("3의 배수와 5의 배수에 중복값(공배수)이 있습니다. 해당되는 수는 { ");
		for (k=1; k <= (n/15); k++)
		{
			fifteen_for = k * 15;
			Common_Multiple_Total += fifteen_for;
			printf("%d, ", fifteen_for);
			result = three_total + five_total - Common_Multiple_Total;
		}
		printf(" } 입니다.\n");
	}
	
	else
	{
		result = three_total + five_total;
	}

	printf("최종 결과는 %d 입니다.\n", result);
	return result;
}

void main()
{
	int n;

	printf("findSum실행. 숫자를 입력하세요.\n");
	scanf("%d", &n);
	findSum(n);

	system("pause");
}
