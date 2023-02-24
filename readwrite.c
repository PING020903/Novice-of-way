#include"head.h"

//求得文件大小(tips:获取的文件大小就不能超过2G，否则就会出错)
int file_size(char* filename)
{
	FILE* fp = fopen(filename, "r");
	if (!fp)
		return -1;
	fseek(fp, 0L, SEEK_END);//0L 等价于 long初始化0
	int size = ftell(fp);//返回文件内的当前位置
	fclose(fp);

	return size;
}

//保存技师信息(已被打开的stream流,当前技师节点)
int Save_file_technician(FILE* fp, technicianslink head)
{
	if (fp == NULL)
	{
		perror("Open the file error!!!\n");
		return -1;
	}

	for (technicianslink temp_node = head->next; temp_node != head; temp_node = temp_node->next)
	{
		fprintf(fp, "%d %s %d %d %.2f %.2f %.2f %.2f %.2f %.2f\n ", temp_node->count, temp_node->name, temp_node->sex, temp_node->age, \
			temp_node->height, temp_node->weight, temp_node->breast, temp_node->waist, temp_node->hips, temp_node->monthly_salary);
	}
	
	rewind(fp);//复位文件中的光标
	return 1;
}

// 读取技师信息(已被打开的stream流, 当前技师节点)
int Read_technician(FILE * fp, technicianslink head)
{
	if (fp == NULL)
	{
		perror("Open the file error!!!\n");
		exit EOF;
	}

	//注意：使用fscanf的时候，不能使用"%.2f"诸如类似的截取，读不到数据
	fscanf(fp, "%d %c %d %d %f %f %f %f %f %f", &head->count, head->name, &head->sex, &head->age, &head->height, \
		& head->weight, &head->breast, &head->waist, &head->hips, &head->monthly_salary);	
	printf("————————————————————\n");
	printf("人员编号：%d	姓名：%s(性别：%d)	\n年龄：%d	身高：%.2f	体重：%.2f	\n\
胸围：%.2f	腰围：%.2f	臀围：%.2f	月薪：%.2f\n", head->count, \
	head->name, head->sex, head->age, head->height, head->weight, head->breast, head->waist, head->hips, head->monthly_salary);
	printf("————————————————————\n");
	rewind(fp);//复位文件中的光标
	return 1;
}

//保存当前链表的服务信息(已被打开的stream流,当前服务节点)
int Save_file_service(FILE* fp, servicelink head)
{
	if (fp == NULL)
	{
		perror("Open the file error!!!\n");
		return -1;
	}
	//顺着链表的数据顺序逐个保存
	for (servicelink temp_node = head->next; temp_node != head; temp_node = temp_node->next)
	{
		fprintf(fp, "%d %.2f %s %.2f\n ", temp_node->count, temp_node->value, temp_node->types, temp_node->times);
	}

	rewind(fp);//复位文件中的光标
	return 1;
}

// 读取已保存的服务信息(已被打开的stream流, 当前技师节点)
int Read_service(FILE* fp, servicelink head)
{
	if (fp == NULL)
	{
		perror("Open the file error!!!\n");
		exit EOF;
	}

	//注意：使用fscanf的时候，不能使用"%.2f"诸如类似的截取，读不到数据
	while (feof(fp) == 0)//文件未到结尾返回0，结束返回非零
	{	
		Tail_Add_Node_Service_Txt(head, fp);
	}
	rewind(fp);//复位文件中的光标
	return 1;
}

//保存用户服务选择历史
int Save_history(servicelink temp)
{
	FILE* fp = fopen("select_history.txt", "a+");
	if (fp == NULL)
	{
		perror("open history '.txt' error!!!");
		return -1;
	}
	time_t timep;
	time(&timep); //存入time_t类型的timep
	fprintf(fp, "%d %.2f %s %.2f   time:%s\n", temp->count, temp->value, temp->types, temp->times, ctime(&timep));
	rewind(fp);
	fclose(fp);
	return 0;
}

//读取文本密码
char* Read_key(FILE* fp)
{
	char key[256] = { 0 };
	if (fp == NULL)
	{
		perror("Open the file error!!!\n");
		exit EOF;
	}
	fscanf(fp, "%s", key);//读取文本字符串
	return key;
}

//修改文本密码
int Change_key(FILE* fp)
{
	if (fp == NULL)
	{
		perror("Open the file error!!!\n");
		exit EOF;
	}
	char key[256] = { 0 };
	printf("请输入新密码：");
	scanf("%s", key);
	fclose(fp);
	fp=fopen("key.txt", "w+");
	fprintf(fp, "%s", key);
	printf("\n修改密码成功！\n");
	fclose(fp);
	return 0;
}