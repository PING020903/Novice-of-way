#include"head.h"
//管理员
int admin(FILE* fp, servicelink myhead, FILE* password)
{
	if (fp == NULL || password == NULL)
	{
		perror("文件打开失败！！！\n");
		return -1;
	}
	while (1)
	{
		char ch = 0;
		Display_Service(myhead, SHOW_MODE);
		printf("\n\n管理员模式\n");
		printf("按s显示所有服务\n按a增加一项服务\n按d删除选择的服务\n按c更改选择的服务\n\
按k查看且修改密码\n按q退出：");
		scanf("%c", &ch);
		switch (ch)//管理员权限
		{
		case 'q':
		{
			fclose(fp);
			//先关闭，重新用 截零更改 模式打开
			FILE* fp = fopen("尼玛屎了.txt", "w+");
			Save_file_service(fp, myhead);
			fclose(fp);
			return -1;
			break;
		}
		case 'd':
		{
			Dele_Service(myhead);
			Display_Service(myhead, SHOW_MODE);
			break;
		}
		case 's':
		{
			Display_Service(myhead, SHOW_MODE);
			break;
		}
		case 'c':
		{
			Change_Service(myhead);
			Display_Service(myhead, SHOW_MODE);
			break;
		}
		case 'a':
		{
			Tail_Add_Node_Service(myhead);
			Display_Service(myhead, SHOW_MODE);
		}
		case 'k':
		{
			printf("现在密码是："); 
			char key[256] = { 0 };
			strcpy(key, Read_key(password));
			printf("%s\n", key);
			Change_key(password);
		}
		default:
			break;
		}
		while (getchar() != '\n');//当选择分支结束后再去除空格，否则会有bug(此bug让我心力憔悴)
	}
	return 0;
}