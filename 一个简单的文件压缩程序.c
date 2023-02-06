//Page360
//reducto.c
//把文件压缩原来的1/3！
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40

int main(int argc, char* argv[])
{
	FILE* in, * out;//声名两个指向FILE结构体的指针(指针结构体)
	int ch;
	char name[LEN];//存储输入文件名
	int count = 0;

	//检查命令行参数
	if (argc < 2)
	{
		/*int fprintf(FILE* const _Stream, char const* const _Format,...)*/
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//设置输入
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file\"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//设置输出
	/*char __cdecl strncpy(char *_Destination,const char *_Source,size_t _Count)*/
	//size_t等价与unsigned int
	strncpy(name, argv[1], LEN - 5);//拷贝文件名
	name[LEN - 5] = '\0';
	/*char __cdecl strcat(char *_Destination,const char *_Source)*/
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Can't creat output file.\n");
		exit(3);
	}
	//拷贝数据
	/*int __cdecl getc(FILE *_Stream)*/
	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
		{
			//int __cdecl putc(int _Character,FILE *_Stream)
			putc(ch, out);//打印3个字符中的第一个字符
		}
	}
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files\n");
	}	
	return 0;
}