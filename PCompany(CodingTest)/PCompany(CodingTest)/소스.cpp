#include <stdio.h>
#include <stdlib.h>
// 문제 1
// 예 입력 값 : "hello world"
// 반환 값 : world hello

void Reverse(char* output, int outputArraySize, const char* input)
{
	int index = 0;

	for (int i = 0; i < outputArraySize; ++i)
	{
		if (input[i] == ' ')
		{
			index = i;
		}
	}

	for (int i = 0; i < outputArraySize; ++i)
	{
		if (index > i)
		{
			int tempIndex = (index + 1) + i;
			output[i] = input[tempIndex];
		}
		if (index == i)
		{
			output[i] = ' ';
		}
		else if(index < i)
		{
			int tempIndex = i - (index + 1);
			output[i] = input[tempIndex];
		}
	}
	output[outputArraySize] = NULL;
}

// 문제 2
// int 형 정수 값을 입력 받아 문자열로 반환 하는 함수
// 예 입력 값: 4714, "4714"
void IntToStr(char* output, int outputArraySize, int input)
{
	int count = 0;
	int tenGob = 1;
	while (input / tenGob != 0)
	{
		tenGob *= 10;
		count++;
	}
	tenGob *= 0.1f;
	for (int i = 0; i < count; ++i)
	{
		output[i] = (input / tenGob) + '0';
		input %= tenGob;
		tenGob *= 0.1f;
	}
	output[outputArraySize] = NULL;
}

int main()
{
	//문제 1 
	/*char input[] = "hello World";
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 11;
	Reverse(output, 11, input);
	printf("%s\n", output);*/

	//문제 2
	int input = 4714;
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 4;
	IntToStr(output, outputArraySize, input);
	printf("%s", output);

}