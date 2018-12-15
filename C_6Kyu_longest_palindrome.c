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
	int for_queueX = 0, for_queueY = 0;
	int answer_queue = 0, answer = 0;

	printf("-----------------------------------\n");
	printf("Called longest_palindrome function.\n");

	// C언어는 string을 지원 안하므로 2차원 배열을 이용하여 char별로 저장.
	// 공백 개수를 포함한 char 개수만큼 for문 반복. 단어의 끝에 공백도 붙는다.
	for (int slen=0; slen<(int)strlen(s); slen++)
	{
		devided[devided_queueX][devided_queueY] = *copied++;
		if (devided[devided_queueX][devided_queueY] == ' ')
		{
			devided_queueX++;
			devided_queueY = 0;
			devided[devided_queueX][devided_queueY] = *copied++;		// x,0 공백 제거용
		}
		devided_queueY++;
	}

	// 실질적으로 palindrome을 찾는 부분.
	// 단어간 공백을 만나면 다음 2차 행렬로 넘어가고, null을 만나면 프로그램을 종료함.
	for (int slen=0; slen<(int)strlen(s); slen++)
	{
		printf("%c", devided[find_queueX][find_queueY]);
		if (devided[find_queueX][find_queueY] != '\0')
		{
			find_queueY++;
			answer_queue++;
			if (devided[find_queueX][find_queueY] == ' ')
			{
				if (answer_queue > answer)
					answer = answer_queue;
				answer_queue = 0;
				find_queueX++;
				find_queueY = 0;
				printf("(%d) ", answer);
			}
			else if (devided[find_queueX][find_queueY] == '\0')
			{
				if (answer_queue > answer)
					answer = answer_queue;
				printf("(%d) ", answer);
				break;
			}
		}
		else
			return 0;
	}
	return answer;
}

int main()
{
	char *s = "I like racecars that go fast";
	printf("The test string is: I like racecars that go fast\n");
	longest_palindrome(s);

	system("pause");
	return 0;
}
