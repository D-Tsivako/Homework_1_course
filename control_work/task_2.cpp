#include <iostream>

using namespace std;

void encoding(char[], int[], char[]);
void decoding(int[], char[], char[], char[]);
void codingTests();
bool equals(char[], char[]);
int stringLength(char*);

int main()
{
	codingTests();

	system("pause");
	return 0;
}

void encoding(char source[], int encoding[], char rule[])
{
	for (int i = 0; i < stringLength(source); i++)
	{
		for (int j = 0; j < stringLength(rule); j++)
		{
			if (source[i] == rule[j])
			{
				encoding[i] = j;
				break;
			}
		}
	}
}

void decoding(int source[], char decoding[], char rule[], char str[])
{
	int sLength = stringLength(str);

	for (int i = 0; i < sLength; i++)
	{
		decoding[i] = rule[source[i]];
	}

	decoding[sLength] = '\0';
}

bool equals(char lhs[], char rhs[])
{
	if (stringLength(lhs) != stringLength(rhs))
	{
		return false;
	}

	for (int i = 0; i < stringLength(lhs); i++)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

void codingTests()
{
	const int length = 11;

	char source[length] = "learn c++!";

	int numbers[length - 1] = { 0 };

	char rule[30] = "zyxwvutsrqponmlkjihgfedcba!+ ";

	encoding(source, numbers, rule);

	char expected[length];

	decoding(numbers, expected, rule, source);

	cout << equals(source, expected) << endl;

	const int M = 13;

	char givenString[M] = "hello world!";

	int encoded[M - 1] = { 0 };

	encoding(givenString, encoded, rule);

	char changed[M];

	decoding(encoded, changed, rule, givenString);

	cout << equals(givenString, changed) << endl;
}

int stringLength(char* string)
{
	int length = 0;

	while (string[length])
	{
		length++;
	}

	return length;
}