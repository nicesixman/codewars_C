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
	int answer_queue = 0, answer_Y = 0, answer = 1, answer_original = 0, samechar_count = 0;
	int answer_highest = 1, exception_count = 1, samechar_Y = 1;
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
		printf(" (%d %d)\n", find_queueX, find_queueY);
		if (devided[find_queueX][find_queueY] != '\0')
		{
			exception_count = 1;
			find_queueY++;
			// for_queueY 번째의 char까지 도달하는동안 모든 문자를 비교.
			for (for_queueY=0; for_queueY<find_queueY; for_queueY++)
			{
				answer_Y++;
				// find_queueY, for_queueY의 위치에 따라 가변적으로 비교.
				// (ex. char 7개 단어 --> 1번째 char는 1 비교, 2번째 char는 1~2 비교, ..., 7번째 char는 1~7 비교.)
				if (devided[find_queueX][for_queueY] == devided[find_queueX][find_queueY - 1])
				{
					answer_queue = 0;
					answer_queue++;
					if (answer_queue == 1)
					{
						answer_original = answer;
						// palindrome(회문)이 있는 경우에는 answer_highest를 구함.
						if (devided[find_queueX][for_queueY] != devided[find_queueX][answer_Y - 1])
						{
							answer = answer_Y + 1;
							// answer와 answer_original을 비교했을 때, 차이가 2보다 크다면 palindrome(회문)이 아님.
							// 이유는 answer_Y가 증감연산자이기 때문에 안쪽 for문을 도는동안 1단위로만 변하기 때문임.
							if (answer - answer_original == 2)
							{
								if (answer > answer_highest)
									answer_highest = answer;
								if (exception_count > answer_highest)
									answer_highest = exception_count;
								result = answer_highest;
								printf(" ★%d %d %d★\n", answer, answer_original, answer_Y);
								printf(" --> palindrome Found!! answer_highest's value: %d\n", answer_highest);
							}
							else
							{
								// 동일 char가 일정 구간동안만 반복될 때를 구함.
								if (devided[find_queueX][for_queueY - samechar_Y] == devided[find_queueX][for_queueY])
								{
									samechar_Y = samechar_Y + 2;
									if (answer > answer_highest)
										answer_highest = answer;
									if (exception_count > answer_highest)
										answer_highest = exception_count;
									result = answer_highest;
									printf(" ★%d %d %d★\n", answer, answer_original, answer_Y);
									printf(" --> same char palindrome Found!! answer_highest's value: %d\n", answer_highest);
								}
								// 최종적으로 회문이 아닌 것으로 판단.
								answer = 1;
								result = answer_highest;
							}
						}
						// 정확한 이유는 모르겠지만 간혹 위 if문에 다 걸리지 않는 경우가 발생한다.
						// 아마도 for_queueY가 증가하면서 동일한 char가 2~3번 이상 걸리는 경우의 별도 예외처리가 필요한 듯 싶다.
						else
						{
							samechar_count++;
							if (find_queueX > 0 && find_queueY == 1)
								samechar_count = 1;
							if (find_queueY != samechar_count)
							{
								exception_count++;
								answer = answer_Y + 1;
								samechar_count = find_queueY;
								if (answer > answer_highest)
									answer_highest = answer;
								if (exception_count > answer_highest)
									answer_highest = exception_count;
								result = answer_highest;
								printf(" ★%d %d %d★\n", find_queueY, for_queueY, samechar_count);
								printf(" --> exception palindrome Found!! answer_highest's value: %d\n", answer_highest);
							}
							// 동일한 char 사이에 다른 char가 존재할 경우, 아직 계산 오류가 나는 상태이므로 해결이 필요하다.
							if (devided[find_queueX][samechar_count - 1] != devided[find_queueX][samechar_count])
								printf(" Hi Another Word %d %d %d\n", find_queueY, for_queueY, samechar_count);
						}
					}
					// 딱 1글자만 입력됐을 때 단순하게 1을 return하는 예외처리.
					if (strlen(s) == 1)
					{
						answer_highest = 1;
						result = answer_highest;
						printf(" --> exception Found!! answer_highest's value: %d\n", answer_highest);
					}
					answer_Y = 0;
				}
			}
			/*
			// 특정 char이 반복되어 나올 때의 예외처리.
			if (answer_highest == 0 && (devided[find_queueX][find_queueY - 1] == devided[find_queueX][find_queueY]))
			{
				exception_count++;
				printf(" --> EX1)exception Found!! exception_highest's value: %d %d\n", exception_count, find_queueY);
				result = exception_count;
			}
			*/
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
	// Random Tests는 아직 Failed를 출력한다. (하단 문장 Expected 57, but Received 7)
	// 내 코드 구조는 공백 단위를 띄어버리는데, 알고보니 공백 관계 없이 찾아야한다..
	char *s = "aabaa";
	printf("The test string is: aabaa\n");
	// printf("The test string is: 7tgq1!0 zjavn829zfc 4qhahw99499whahq4 cfz928nvajz 0!1qgt76xz\n");
	longest_palindrome(s);

	system("pause");
	return 0;
}
