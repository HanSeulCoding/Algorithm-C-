#include <stdio.h>
#include <stdlib.h>
// ���� 1
// �� �Է� �� : "hello world"
// ��ȯ �� : world hello

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

// ���� 2
// int �� ���� ���� �Է� �޾� ���ڿ��� ��ȯ �ϴ� �Լ�
// �� �Է� ��: 4714, "4714"
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
	//���� 1 
	/*char input[] = "hello World";
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 11;
	Reverse(output, 11, input);
	printf("%s\n", output);*/

	//���� 2
	int input = 4714;
	char* output = (char*)malloc(sizeof(char) * 15);
	int outputArraySize = 4;
	IntToStr(output, outputArraySize, input);
	printf("%s", output);

}