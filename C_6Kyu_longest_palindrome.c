#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

int longest_palindrome(const char *s)
{
	// 포인터 매개변수는 함수 내부/외부에서 모두 사용 가능.
	const char *copied = s;

	printf("-----------------------------------\n");
	printf("Called longest_palindrome function.\n");
	printf("Original string: ");
	for (int slen=0; slen<(int)strlen(s); slen++)
	{
		putchar(*copied++);
	}
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
