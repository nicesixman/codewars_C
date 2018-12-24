#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int longest_palindrome(const char *s)
{
	// 포인터 매개변수는 함수 내부/외부에서 모두 사용 가능.
	const char *copied = s;
	char devided[1000][1000] = { '\0' }, nospace[10000] = { '\0' }, nospace_realtime[10000] = { '\0' }, space_pos[1000] = { '\0' };
	int devided_queueX = 0, devided_queueY = 0;
	int nospace_last_char = 0, nospace_first_pos = 0, nospace_char_total = 0;
	int space_count = 0, perfect_palindrome = 0, is_pal_count = 0;
	int find_queueX = 0, find_queueY = 0, find_space = 1;
	int for_queueY = 1;
	int answer_queue = 0, answer_Y = 0, answer = 1, answer_original = 0, samechar_count = 0;
	int answer_highest = 1, exception_count = 1, samechar_Y = 1;
	int result = 0;

	printf("-----------------------------------\n");
	// C언어는 string을 지원 안하므로 2차원 배열을 이용하여 char별로 저장.
	// 공백 개수를 포함한 char 개수만큼 for문 반복.
	for (int slen = 0; slen<(int)strlen(s); slen++)
	{
		devided[devided_queueX][devided_queueY] = *copied++;
		if (devided[devided_queueX][devided_queueY] == ' ')
		{
			space_count++;
			space_pos[devided_queueX] = slen;
			devided_queueX++;
			devided_queueY = 0;
			devided[devided_queueX][devided_queueY] = *copied++;		// x,0 공백 제거하며 저장
		}
		nospace[slen] = devided[devided_queueX][devided_queueY];		// 1차원 배열에도 저장
		devided_queueY++;
	}
	nospace_char_total = (int)strlen(s) - space_count;

	// 다른 char이 덧붙여질 경우, 앞/뒤 char를 하나씩 지워보며 모두 비교해보는 경우를 구한다.
	for (int srmslen = 0; srmslen < nospace_char_total; srmslen++)
	{
		nospace_first_pos++;
		find_space = 1;
		printf("Basis strings: ");
		// 앞부터 하나씩 지운다.
		for (int sslen = nospace_char_total; sslen > srmslen; sslen--)
		{
			nospace_last_char = 0;
			// Basis strings를 기반으로 뒤에서 하나씩 지운다.
			for (int lslen = srmslen; lslen < sslen; lslen++)
			{
				nospace_last_char++;
				nospace_realtime[lslen] = nospace[lslen];
				printf("%c", nospace_realtime[lslen]);
			}

			if (nospace_last_char - find_space == space_pos[space_count - find_space])
			{
				printf(" ※SPACE: %d(%d Spaces) ", nospace_last_char - find_space, space_count - (find_space - 1));
				find_space++;
			}

			// ★ 이 밑에부분 뭔가 수정이 필요할 듯 하다..
			if ((nospace_realtime[nospace_first_pos - 1] == nospace_realtime[sslen - 1]) && (nospace_first_pos - 1 != sslen - 1))
			{
				printf(" ★ %d, %d GOTCHAAAAAAA", nospace_first_pos - 1, sslen - 1);
				for (int is_pal = 1; is_pal < (sslen / 2) + 1; is_pal++)
				{
					if (nospace_realtime[is_pal] == nospace[is_pal, sslen - 1 - is_pal])
					{
						is_pal_count++;
						printf("\nis_pal: %d / rev Count: %d is same! go to NEXT", is_pal, sslen - 1 - is_pal);
						if ((sslen - 1) / 2 == is_pal_count)
						{
							printf(" ★★★ YOU ARE REAL PALINDROME ★★★");
							printf(" chars: %d, spaces: %d", is_pal * 2 + 1, space_count - (find_space - 1));
							// 홀수일 때.
							answer_highest = (is_pal * 2 + 1) + (space_count - (find_space - 1));
							// 짝수일 때.
							if (sslen - 1 - is_pal > is_pal)
								answer_highest = (is_pal * 2 + 1) + (space_count - (find_space - 1)) + 1;
						}
					}
				}
			}
			nospace_realtime[nospace_last_char] = '\0';
			printf("\n");
		}
		printf("\n");
	}
	printf("★공백 개수: %d", space_count);
	printf("(공백 위치: %d %d %d %d)\n", space_pos[0], space_pos[1], space_pos[2], space_pos[3]);
	printf("글자 개수: %d (총합: %d)★\n", nospace_char_total, nospace_char_total + space_count);

	// 100% 대칭 문자열이 아닐 때의 palindrome(회문)을 찾아봄.
	// 단어간 공백을 만나면 다음 2차 행렬로 넘어가고, null을 만나면 프로그램을 종료함.
	for (int slen = 0; slen<(int)strlen(s); slen++)
	{
		// printf("%c", devided[find_queueX][find_queueY]);
		// printf(" (%d %d)\n", find_queueX, find_queueY);
		if (devided[find_queueX][find_queueY] != '\0')
		{
			exception_count = 1;
			find_queueY++;
			// for_queueY 번째의 char까지 도달하는동안 모든 문자를 비교.
			for (for_queueY = 0; for_queueY<find_queueY; for_queueY++)
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
							exception_count++;
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
								// printf(" --> palindrome Found!! answer_highest's value: %d\n", answer_highest);
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
									// printf(" ★%d %d★\n", answer_highest, exception_count);
									// printf(" --> same char palindrome Found!! answer_highest's value: %d\n", answer_highest);
								}
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
								// printf(" ★%d %d★\n", answer_highest, exception_count);
								// printf(" --> palindrome Found!! answer_highest's value: %d\n", answer_highest);
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
					answer_Y = 0;
				}
			}
			// 특정 char이 반복되어 나올 때의 예외처리.
			if (devided[find_queueX][slen] == devided[find_queueX][slen - 1])
			{
				exception_count++;
				// printf(" --> EX1)exception Found!! exception_highest's value: %d %d\n", exception_count, find_queueY);
				if (answer > answer_highest)
					answer_highest = answer;
				if (exception_count > answer_highest)
					answer_highest = exception_count;
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
	printf("★★ >>>>> result(return): %d <<<<< ★★", result);
	return result;
}

int main()
{
	/*
	// Basic Tests 중 baa가 failed. 이유를 찾아봐야 한다..
	// Random Tests 중에서는 lslen = 2 일때부터 제대로 계산이 되지 않고 있다. line 71 근처에서 해결점이 필요해보임.
	*/
	char *s = "7tgq1!0 zjavn829zfc 4qhahw99499whahq4 cfz928nvajz 0!1qgt76xz";
	// another test: m8xka.1s88eq9mh?lh9safq1091g!xv2mz4qpeagiq7mp2qrq2pm7qigaepq4zm2vx!g1901qfas9hl?hm9qe88nm 
	printf("The test string is: 7tgq1!0 zjavn829zfc 4qhahw994499whahq4 cfz928nvajz 0!1qgt76xz\n");
	longest_palindrome(s);

	system("pause");
	return 0;
}
