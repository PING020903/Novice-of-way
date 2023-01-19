/*把一个字符串逆转，不是打印逆转*/
#include<stdio.h>
#include<string.h>
int main()
{
	char wjp[20] = {"I am wjp."};//局限于英文输入，因为中文一个字占2字节
	printf("%c", wjp[(strlen(wjp) - 1)]);//strlen(wjp)=9，而数组係从0开始，所以要-1
	printf("\n%s", wjp);//先打印一次结果
	int j = 1;
	for (int i = 0; i < strlen(wjp) / 2; i++)//需要调换的次数 係字符总数的 一半
	{
		//异或交换value
		wjp[i] ^= wjp[strlen(wjp) - j];
		wjp[strlen(wjp) - j] ^= wjp[i];
		wjp[i] ^= wjp[strlen(wjp) - j];
		j++;//每次交换以后，增加从后面倒着数的次数
	}
	printf("\n%s", wjp);
	return 0;
}