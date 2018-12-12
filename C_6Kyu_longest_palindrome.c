#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int longest_palindrome(const char *s)
{
	// 포인터 매개변수는 함수 내부/외부에서 모두 사용 가능.
	const char *copied = s;
	char devided[1000][1000] = { '\0' };
	int devided_queueX = 0, devided_queueY = 0;
	int answer = 0;

	printf("-----------------------------------\n");
	printf("Called longest_palindrome function.\n");

	// C언어는 string을 지원 안하므로 2차원 배열을 이용하여 char별로 저장.
	for (int slen=0; slen<(int)strlen(s); slen++)
	{
		devided[devided_queueX][devided_queueY] = *copied++;
		printf("(%d, %d): %c", devided_queueX, devided_queueY, devided[devided_queueX][devided_queueY]);
		if (devided[devided_queueX][devided_queueY] == ' ')
		{
			printf("(%d, %d): %c\n", devided_queueX, devided_queueY, devided[devided_queueX][devided_queueY]);
			devided_queueX++;
			devided_queueY = 0;
		}
		devided_queueY++;
	}
	// test string의 끝에는 공백이 들어가지 않으므로, 임의로 넣어준다.
	devided[devided_queueX][devided_queueY] = ' ';	
	if (devided[5][5] == ' ')
		printf("TESTING");

	printf("\nReversed string: ");
	for (int slen=strlen(s); slen>0; slen--)
	{
		putchar(*--copied);
	}
	printf("\n");

	return 0;
}

int main()
{
	char *s = "I like racecars that go fast";
	printf("The test string is: I like racecars that go fast\n");
	longest_palindrome(s);

	system("pause");
	return 0;
}
