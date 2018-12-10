#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#pragma warning(disable:4996)

int longest_palindrome(const char *s)
{
	// 동적배열로 받아와서 쓸데없이 null을 reverse하지 않게끔 한다.
	char *copied = malloc(sizeof(char)*1000);
	char *reversed;

	printf("-----------------------------------\n");
	printf("Called longest_palindrome function.\n");
	strcpy(copied, s);
	printf("Original string: %s\n", copied);
	reversed = strrev(copied);
	printf("Reversed string: %s\n", reversed);

	free(copied);
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
