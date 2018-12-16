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
	int answer_queue = 0, answer_Y = 0, answer = 0;
	int answer_highest = 0, exception_highest = 0;

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
				// (ex. char 7개 단어--> 1번째 char는 1~7 비교, 2번째 char는 2~7 비교, ..., 7번째 char는 7~7 비교.)
				if (devided[find_queueX][for_queueY] == devided[find_queueX][find_queueY - 1])
				{
					answer_queue = 0;
					answer_queue++;
					// (char >= 1 이며) palindrome(회문)이 없는 경우에는 answer_highest == 1;
					if (answer_queue == 1)
					{
						answer = 1;
						if (answer > answer_highest)
							answer_highest = answer;
						// palindrome(회문)이 있는 경우에는 answer_highest를 구함.
						if (devided[find_queueX][for_queueY] != devided[find_queueX][answer_Y - 1])
						{
							// printf(" (%d %d %d)★%d★\n", for_queueY, find_queueY - 1, answer_queue, answer_Y);
							answer = answer_Y + 1;
							if (answer > answer_highest)
								answer_highest = answer;
							printf(" --> palindrome Found!! answer_highest's value: %d\n", answer_highest);
						}
					}
					answer_Y = 0;
				}
			}
			// 특정 char이 반복되어 나올 때의 예외처리.
			// 1) 시작점부터 char이 반복될 때. (aaaaab)
			if (devided[find_queueX][slen] == devided[find_queueX][slen + 1])
			{
				exception_highest = find_queueY + 1;
				printf(" --> EX1)exception Found!! answer_highest's value: %d\n", exception_highest);
			}
			/*
			// 2) n번째 부터 char이 반복될 때. (baaaaa)
			if (devided[find_queueX][slen] == devided[find_queueX][slen - 1])
			{
				exception_highest = find_queueY - 1;
				printf(" --> EX2)exception Found!! answer_highest's value: %d\n", exception_highest);
			}
			*/
			// 딱 1글자만 입력됐을 때 단순하게 1을 return하는 예외처리.
			if (strlen(s) == 1)
			{
				answer_highest = 1;
				printf(" --> exception Found!! answer_highest's value: %d\n", answer_highest);
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
	return answer_highest;
}

int main()
{
	char *s = "aaaaab";
	printf("The test string is: I like racecars that go fast\n");
	longest_palindrome(s);

	system("pause");
	return 0;
}
