#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int findSum(int n)
{
	int i, j, k;
	int three_for = 0, five_for = 0, three_total = 0, five_total = 0, fifteen_for = 0, Common_Multiple_Total = 0;
	int result;
	
	printf("3�� ����� �ش�Ǵ� ���� { ");
	for (i=1; i <= (n/3); i++)
	{
		three_for = i * 3;
		three_total += three_for;
		printf("%d, ", three_for);
	}
	printf(" } �Դϴ�.\n");
	
	printf("5�� ����� �ش�Ǵ� ���� { ");
	for (j=1; j <= (n/5); j++)
	{
		five_for = j * 5;
		five_total += five_for;
		printf("%d, ", five_for);
	}
	printf(" } �Դϴ�.\n");

	// 3�� ����� 5�� ����� ������� 15��� ����. ���� 15��� ������ ���� 1���� ���Ѵ�.
	// �Ʒ� if ������ n�� 15 �̻��� ���, 15���� count 1���� 15�� ���ؼ� ������ ���ϴ� ��.
	if (n >= 15)
	{
		printf("3�� ����� 5�� ����� �ߺ���(�����)�� �ֽ��ϴ�. �ش�Ǵ� ���� { ");
		for (k=1; k <= (n/15); k++)
		{
			fifteen_for = k * 15;
			Common_Multiple_Total += fifteen_for;
			printf("%d, ", fifteen_for);
			result = three_total + five_total - Common_Multiple_Total;
		}
		printf(" } �Դϴ�.\n");
	}
	
	else
	{
		result = three_total + five_total;
	}

	printf("���� ����� %d �Դϴ�.\n", result);
	return result;
}

void main()
{
	int n;

	printf("findSum����. ���ڸ� �Է��ϼ���.\n");
	scanf("%d", &n);
	findSum(n);

	system("pause");
}