#include <stdio.h>
#include <windows.h>
#pragma warning(disable:4996)

long long* step(int g, long long m, long long n)
{
	int isPrime = 0;
	int Count, reminderCount;
	int matrix[100000], result[2], matrixCount = 0;
	// ���� �迭�� C++ ����� �� �õ��ϰ�, ����(C)�� �ڵ� ������ ���� �б� ���� ���� �迭�� ����.
	int betweenCount;

	// m > n ���� �Է����� ���� ����ó��.
	// ex) (2, 5101, 103) --> 0, 0
	if (m > n)
	{
		int* result[2] = { 0, 0 };
		printf("%d %d\n", result[0], result[1]);
		return result;
	}
	// step�Լ��� start of the search(m) ~ end of the search(n)�� �ִ�.
	for (Count = m; Count <= n; Count++)
	{
		// �������� ������ 1�� ������Ű�鼭 �ݺ�.
		for (reminderCount = 1; reminderCount <= Count; reminderCount++)
		{
			// �ڱ� �ڽŰ� 1������ ���������Ƿ� for���� ���µ��� 0�� �� ���� ������ �װ� �Ҽ��̴�.
			// (��, isPrime == 2�� ���, �װ� �Ҽ��̴�.)
			// �㳪 �Ʒ� ���ǽ� �ϳ������δ� �������� 0�̵Ǵ� ��� ��찡 ���ȴ�.
			if (Count % reminderCount == 0)
				isPrime = isPrime + 1;

			// ����ӵ� ����� ���� ����ó��.
			if (isPrime > 2)
				break;
		}

		// ��� ��찡 ���Ǵ� ���� �ذ� ������ν�
		// ���� for���� ������ �� �� isPrime == 2�� ���� �迭�� ���� �����ϰԲ� �ڵ带 ¥�� �ȴ�.
		if (isPrime == 2)
		{
			matrix[matrixCount] = Count;
			matrixCount = matrixCount + 1;
			// Normal case. �´��� �� �Ҽ� ���̸� ���.
			// ex) (2, 100, 110) --> 101, 103
			if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				int* result[2] = { matrix[matrixCount - 2], matrix[matrixCount - 1] };
				printf("%d, %d\n", matrix[matrixCount - 2], matrix[matrixCount - 1]);
				return result;
				matrixCount = 0;
			}
			// ex1) (6, 100, 110) --> 101, 107
			// ex2) (3, 2, 5) --> 2, 5
			// �´��� �� �Ҽ� ���̸� ���ϴ� ���� �ƴ϶� prime step(g)�� ����� �Ǵٸ� ������ �ۼ��Ͽ��� �Ѵ�.
			// else if�� ���� ���н��ѳ��� ������, ��ȿ�������� for���� �������� �ʰ� �ϱ� �����̴�.
			// ��codewars������ ������ �� �κп��� (3, 2, 5) --> 0, 3���� �ν��Ѵ�.
			// ������ gcc ������ VS ������ ���������� ����ϴ� ��.
			else if (matrixCount >= 2 && g != (matrix[matrixCount - 1] - matrix[matrixCount - 2]))
			{
				for (betweenCount = 3; betweenCount <= g; betweenCount++)
				{
					if (matrixCount >= 2 && g == (matrix[matrixCount - 1] - matrix[matrixCount - betweenCount]))
					{
						int* result[2] = { matrix[matrixCount - betweenCount], matrix[matrixCount - 1] };
						printf("%d, %d\n", matrix[matrixCount - betweenCount], matrix[matrixCount - 1]);
						return result;
						matrixCount = 0;
					}
				}
				// start of the search(m) ~ end of the search(n) �� �Ҽ��� 2�� �̻������� prime step(g)�� �ɸ��� ���� ��.
				// ex) (2, 4900, 4919) --> 0, 0
				if (n == Count)
				{
					int* result[2] = { 0, 0 };
					printf("%d %d\n", result[0], result[1]);
					return result;
					matrixCount = 0;
				}
			}
			// start of the search(m), end of the search(n) �� ��ġ�ϴ� �� �� ��.
			// ex) (2, 5, 5) --> 0, 0
			else if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d\n", result[0], result[1]);
				return result;
				matrixCount = 0;
			}
		}
		else
		{
			// start of the search(m) ~ end of the search(n) �� ��� �Ҽ��� �� �� prime step(g)�� ��ġ�ϴ� ���� ���� ��.
			// ex) (11, 30000, 100000) --> 0, 0
			if (n == Count)
			{
				int* result[2] = { 0, 0 };
				printf("%d %d\n", result[0], result[1]);
				return result;
				matrixCount = 0;
			}
		}
		// isPrime = 0���� �ٽ� �ʱ�ȭ.
		isPrime = 0;
	}
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
	printf("������ ���� ��(2 �̻�)�� �����ϼ���.\n");
	scanf("%lld", &m);
	printf("������ ������ ��(���� �� �̻�)�� �����ϼ���.\n");
	scanf("%lld", &n);
	printf("-----------------------------------------------------\n");
	step(g, m, n);		// �Լ� ����
	system("pause");

	return 0;
}