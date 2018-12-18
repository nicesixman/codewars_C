#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int longest_palindrome(const char *s)
{
	// 포인터 매개변수는 함수 내부/외부에서 모두 사용 가능.
	const char *copied = s;
	char devided[1000][1000] = { '\0' };
	int devided_queueX = 0, devided_queueY = 0;
	int find_queueX = 0, find_queueY = 0;
	int for_queueY = 1;
	int answer_queue = 0, answer_Y = 0, exception_answer_Y = 0, answer = 1, answer_original = 0;
	int answer_highest = 0, exception_count = 1;
	int result = 0;

	printf("-----------------------------------\n");
	// C언어는 string을 지원 안하므로 2차원 배열을 이용하여 char별로 저장.
	// 공백 개수를 포함한 char 개수만큼 for문 반복.
	for (int slen=0; slen<(int)strlen(s); slen++)
	{
		devided[devided_queueX][devided_queueY] = *copied++;
		if (devided[devided_queueX][devided_queueY] == ' ')
		{
			devided_queueX++;
			devided_queueY = 0;
			devided[devided_queueX][devided_queueY] = *copied++;		// x,0 공백 제거하며 저장
		}
		devided_queueY++;
	}

	// 실질적으로 palindrome(회문)을 찾는 부분.
	// 단어간 공백을 만나면 다음 2차 행렬로 넘어가고, null을 만나면 프로그램을 종료함.
	for (int slen=0; slen<(int)strlen(s); slen++)
	{
		printf("%c", devided[find_queueX][find_queueY]);
		if (devided[find_queueX][find_queueY] != '\0')
		{
			find_queueY++;
			// for_queueY 번째의 char까지 도달하는동안 모든 문자를 비교.
			for (for_queueY=0; for_queueY<find_queueY; for_queueY++)
			{
				answer_Y++;
				// for_queueY의 위치에 따라 가변적으로 비교.
				// (ex. char 7개 단어 --> 1번째 char는 1~7 비교, 2번째 char는 2~7 비교, ..., 7번째 char는 7~7 비교.)
				if (devided[find_queueX][for_queueY] == devided[find_queueX][find_queueY - 1])
				{
					answer_queue = 0;
					answer_queue++;
					// (char >= 1 이며) palindrome(회문)이 없는 경우에는 answer_highest == 1;
					if (answer_queue == 1)
					{
						printf(" (%d %d %d)\n", answer, answer_original, answer_Y);
						answer_original = answer;
						// palindrome(회문)이 있는 경우에는 answer_highest를 구함.
						if (devided[find_queueX][for_queueY] != devided[find_queueX][answer_Y - 1])
						{
							printf(" ((%d %d %d))\n", answer, answer_original, answer_Y);
							answer = answer_Y + 1;
							// answer와 answer_original을 비교했을 때, 2보다 크게면 palindrome(회문)이 아님.
							// 이유는 answer_Y가 증감연산자이기 때문에 1단위로만 변하기 때문임.
							if (answer - answer_original == 2)
							{
								if (answer > answer_highest)
									answer_highest = answer;
								result = answer_highest;
								printf(" ★%d %d %d★\n", answer, answer_original, answer_Y);
								printf(" --> palindrome Found!! answer_highest's value: %d\n", answer_highest);
							}
							else
							{
								answer = 1;
								printf(" ♥%d %d %d♥\n", answer, answer_original, answer_Y);
								printf("this is not palindrome\n");
							}
						}
					}
					// 딱 1글자만 입력됐을 때 단순하게 1을 return하는 예외처리.
					if (strlen(s) == 1)
					{
						answer_highest = 1;
						result = answer_highest;
						printf(" --> exception Found!! answer_highest's value: %d\n", answer_highest);
					}
					exception_answer_Y = answer_Y;
					answer_Y = 0;
				}
			}
			// 특정 char이 반복되어 나올 때의 예외처리.
			if (answer_highest == 0 && (devided[find_queueX][slen] == devided[find_queueX][slen + 1]))
			{
				exception_count++;
				printf(" ■%d %d %d■\n", answer, answer_original, exception_answer_Y);
				printf(" --> EX1)exception Found!! exception_highest's value: %d %d\n", exception_count, answer);
				result = exception_count;
			}
			if (devided[find_queueX][find_queueY] == ' ')
			{
				find_queueX++;
				find_queueY = 0;
			}
			else if (devided[find_queueX][find_queueY] == '\0')
				break;
		}
		else
			return 0;
	}
	printf("★★ >>>>> %d <<<<< ★★", result);
	return result;
}

int main()
{
	// 현재 simple test 미통과 사항은 2개 남음: baabcd, baablkj12345432133d
	// 123454321 로만 돌리면 잘 되는 것을 보아, baab 부분에 뭔가 문제가 있는듯 싶다.
	char *s = "I like racecars that go fast";
	printf("The test string is: I like racecars that go fast\n");
	longest_palindrome(s);

	system("pause");
	return 0;
}
