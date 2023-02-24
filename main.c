#include"head.h"
int main(void)
{
	
	FILE* fp = fopen("尼玛屎了.txt", "r");
	FILE* password = fopen("key.txt", "r");
	
	servicelink myhead = Creat_list_node_service();//初始化头节点
	Read_service(fp, myhead);//读取服务
	char admin_temp[256] = { 0 };//输入暂存
	char key[256] = { 0 };//密码暂存
	strcpy(key, Read_key(password));//读取存放密码的文本赋值给key
	char ch = 0;
	while (1)
	{
		top();
		
		printf("\n客户请输入任意键，管理员请输入密码(退出请按q):"); 
		scanf("%s", admin_temp);
		if (admin_temp[0] == 'q' && admin_temp[1] == '\0')//检查使用者只按下q
			ch = 'q';
		else
			ch = strcmp(key, admin_temp);
		switch (ch)
		{
		case 'q':
			return -1;
			break;
		case 0:
		{
			admin(fp, myhead, password);
			break;
		}
		default:
		{
			connection(fp, myhead);
			break;
		}
		}
		while (getchar() != '\n');
	}	
	return 0;
}