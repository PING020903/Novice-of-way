//Page356
//count.c
//使用标准I/O
#include<stdio.h>
#include<stdlib.h>//提供exit()的原型
int main(int argc,char* argv[])//argc传入命令行参数，argv读传入参数(字符串，默认检索当前路径)
{

	int ch;
	/*typedef struct _iobuf
    {
        void* _Placeholder;
    } FILE;
	*/
	FILE* fp;//文件指针(in<stdio.h>)
	//定义了一个结构体指针。即为对结构体中指针解引用
	unsigned long count = 0;
	if (argc != 0)
	{
		printf("路径:	%s filename,all:	%d\n", argv[0], argc);
		//exit(EXIT_FAILURE);//同等"return 1"
	}
	printf("---------\n");
	//FILE *__cdecl fopen(const char *_FileName,const char *_Mode)
	//Mode,模式
	if ((fp = fopen(argv[1], "r")) == NULL)//入口条件：参数名为空
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);//在<stdlib.h>中定义为"1"
	}
	/*int __cdecl getc()FILE *_Stream*/
	while ((ch = getc(fp)) != EOF)//在<stdio.h>中定义为"-1"
	{
		/*int __cdecl putc(int _Character,FILE *_Stream)*/
		putc(ch, stdout);//与putchar(ch)相同
		count++;
	}
	//FILE *__cdecl fclose(FILE *_Stream)
	fclose(fp);
	printf("File %s has %lu characters\n", argv[1], count);
	return 0;
}
/*在最初调用的main()中使用return与调用exit()效果相同。
* 若main()在一个递归程序中，exit()仍然会中止程序，但是return只会把控制权交给上一级递归，直至最初的一级。
即使在其他函数中（除main()以外）调用exit()也能结束整个程序*/