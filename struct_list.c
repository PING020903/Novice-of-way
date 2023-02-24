#include"head.h"
#define NAME 60
#define SEX 5
#define SHOW_MODE 0//遍厉模式
#define FIND_MODE 1//寻找模式
#define DELL_MODE 2//删除模式

//初始化(技师)节点
technicianslink Creat_list_node_technician()
{
	technicianslink node = (technicianslink)malloc(sizeof(struct technician)); //指向堆，用完不会自动释放
	if (node == (technicianslink)NULL)
	{
		printf("listlink malloc failed!\n");
		return (technicianslink)-1;
	}
	memset(node, 0, sizeof(struct technician));
	node->last= node;
	node->next = node;

	return node;
}

//初始化(服务)节点
servicelink Creat_list_node_service()
{
	servicelink node = (servicelink)malloc(sizeof(struct service)); //指向堆，用完不会自动释放
	if (node == (servicelink)NULL)
	{
		printf("listlink malloc failed!\n");
		return (servicelink)-1;
	}
	memset(node, 0, sizeof(struct service));
	node->last = node;
	node->next = node;

	return node;
}

//手动输入，链表尾插(技师)
int Tail_Add_Node_Technician(technicianslink head)
{
	char name_temp[NAME] = { 0 };
	if (head == NULL)
	{
		printf("failed!\n");
		return -1;
	}

	technicianslink new_node = Creat_list_node_technician();//创建新节点
	if (new_node == (technicianslink)-1)
	{
		printf("tail node failed!\n");
		return -1;
	}
	printf("请输入新数据");
	printf("\n请输入编号：");
	scanf("%d", &new_node->count);

	printf("\n请输入姓名(仅限英文以及数字)：");
	scanf("%s", name_temp);
	strcpy(new_node->name, name_temp);

	printf("\n请输入性别(1代表男性，0代表女性)：");
	scanf("%d", &new_node->sex);

	printf("\n请输入年龄：");
	scanf("%d", &new_node->age);

	printf("\n请输入身高：");
	scanf("%f", &new_node->height);

	printf("\n请输入体重：");
	scanf("%f", &new_node->weight);

	printf("\n请输入胸围：");
	scanf("%f", &new_node->breast);

	printf("\n请输入腰围(cm)：");
	scanf("%f", &new_node->waist);

	printf("\n请输入臀围(cm)：");
	scanf("%f", &new_node->hips);

	printf("\n请输入月薪(￥)：");
	scanf("%f", &new_node->monthly_salary);

	new_node->last = head->last;				//新节点last 赋值为 传入节点last
	new_node->last->next = new_node;			//此时用 新节点last 等于传入节点，成员next赋值为新节点
	new_node->next = head;						//传入节点next 赋值为 新节点
	head->last = new_node;						//传入节点last 赋值为 新节点
	//"蛇头咬蛇尾"
	return 0;
}

//遍历链表(技师)
technicianslink Display_Technician(technicianslink head, int mode)
{
	if (head == NULL)
	{
		printf("adnormal!\n");
		return (technicianslink)0;
	}
	if (head->next == head)
	{
		printf("empty!\n");
		return (technicianslink)0;
	}

	int data = 0;
	if (mode == FIND_MODE || mode == DELL_MODE)
	{
		printf("请输入技师编号!\nCount:");
		scanf("%d", &data);

	}
	//初始化节点 赋值为 传入节点next;当前节点 不等于 传入节点;当前节点 赋值为 当前节点next
	for (technicianslink temp_node = head->next; temp_node != head; temp_node = temp_node->next)
	{
		if (mode == SHOW_MODE)
		{
			printf("%d\n", temp_node->count);
		}
		if ((mode == FIND_MODE || mode == DELL_MODE) && temp_node->count == data)
		{
			printf("hit the number!\n");
			return temp_node;
		}

	}
	if (mode == FIND_MODE || mode == DELL_MODE)
	{
		printf("找不到数据！\n");
		return 0;
	}
	return (technicianslink)0;
}

//手动输入，链表尾插(服务)
int Tail_Add_Node_Service(servicelink head)
{
	char name_temp[NAME] = { 0 };
	if (head == NULL)
	{
		printf("failed!\n");
		return -1;
	}

	servicelink new_node = Creat_list_node_service();//创建新节点
	if (new_node == (servicelink)-1)
	{
		printf("tail node failed!\n");
		return -1;
	}
	printf("请输入新数据");
	printf("\n请输入服务编号：");
	scanf("%d", &new_node->count);

	printf("\n请输入服务名称(仅限英文以及数字，空格请用'_'替代)：");
	scanf("%s", name_temp);
	strcpy(new_node->types, name_temp);

	printf("\n请输入服务价格：");
	scanf("%f", &new_node->value);

	printf("\n请输入服务价格：");
	scanf("%f", &new_node->times);

	printf("服务编号：%d,服务名称：%s,服务价格：%.2f服务价格：%.2f", new_node->count, new_node->types, new_node->value, new_node->times);

	new_node->last = head->last;				//新节点last 赋值为 传入节点last
	new_node->last->next = new_node;			//此时用 新节点last 等于传入节点，成员next赋值为新节点
	new_node->next = head;						//传入节点next 赋值为 新节点
	head->last = new_node;						//传入节点last 赋值为 新节点
	//"蛇头咬蛇尾"
	return 0;
}

//读取文本，链表尾插(服务)
int Tail_Add_Node_Service_Txt(servicelink head, FILE* fp)
{
	char name_temp[NAME] = { 0 };
	if (head == NULL)
	{
		printf("failed!\n");
		return -1;
	}

	servicelink new_node = Creat_list_node_service();//创建新节点
	if (new_node == (servicelink)-1)
	{
		printf("tail node failed!\n");
		return -1;
	}
	//读取文本数据添加到链表
	fscanf(fp, "%d %f %s %f\n ", &new_node->count, &new_node->value, new_node->types, &new_node->times);

	new_node->last = head->last;				//新节点last 赋值为 传入节点last
	new_node->last->next = new_node;			//此时用 新节点last 等于传入节点，成员next赋值为新节点
	new_node->next = head;						//传入节点next 赋值为 新节点
	head->last = new_node;						//传入节点last 赋值为 新节点
	//"蛇头咬蛇尾"
	return 0;
}

//遍历链表(服务)
servicelink Display_Service(servicelink head, int mode)
{
	if (head == NULL)
	{
		printf("adnormal!\n");
		return (servicelink)0;
	}
	if (head->next == head)
	{
		printf("empty!\n");
		return (servicelink)0;
	}

	int data = 0;
	if (mode == FIND_MODE || mode == DELL_MODE)
	{
		printf("请输入服务编号!\nCount:");
		scanf("%d", &data);

	}
	//初始化节点 赋值为 传入节点next;当前节点 不等于 传入节点;当前节点 赋值为 当前节点next
	for (servicelink temp_node = head->next; temp_node != head; temp_node = temp_node->next)
	{
		if (mode == SHOW_MODE)
		{
			printf("服务编号:%-8d，服务名称:%-10s,服务价格:%-8.2f(￥),服务时长:%-8.2f(hours)\n", temp_node->count, temp_node->types, \
				temp_node->value, temp_node->times);
		}
		if ((mode == FIND_MODE || mode == DELL_MODE) && temp_node->count == data)
		{
			printf("是否选择该服务！！！\n");
			getchar();
			return temp_node;
		}

	}
	if (mode == FIND_MODE || mode == DELL_MODE)
	{
		printf("找不到数据！\n");
		return 0;
	}
	return (servicelink)0;
}

//删除服务
int Dele_Service(servicelink head_node)
{
	if (head_node == NULL)
	{
		printf("failed!\n");
		return 0;
	}
	if (head_node->next == NULL)
	{
		printf("empty!\n");
		return 0;
	}
	servicelink del_node = Display_Service(head_node, DELL_MODE);//删除模式(遍历)
	if (del_node == (servicelink)0)
	{
		printf("del falied!\n");
		return -1;
	}

	del_node->last->next = del_node->next;//进入上一节点的next 赋值为 当前节点next
	del_node->next->last = del_node->last;//进入下一节点的last 赋值为 当前节点last

	del_node->next = NULL;//断开当前节点next
	del_node->last = NULL;//断开当前节点last

	free(del_node);//释放当前节点
	return 0;

}

//服务内容更改
int Change_Service(servicelink head_node)
{
	if (head_node == NULL)
	{
		printf("failed!\n");
		return 0;
	}
	if (head_node->next == NULL)
	{
		printf("empty!\n");
		return 0;
	}
	servicelink new_node = Display_Service(head_node, FIND_MODE);//删除模式(遍历)
	printf("——%p——\n", new_node);
	
	if (new_node == (servicelink)0)
	{
		perror(" error!\n");
		return -1;
	}
	printf("请输入新数据");
	printf("\n请输入服务编号：");
	scanf("%d", &new_node->count);

	char name_temp[NAME] = { 0 };
	printf("\n请输入服务名称(仅限英文以及数字，空格请用'_'替代)：");
	scanf("%s", name_temp);
	strcpy(new_node->types, name_temp);

	printf("\n请输入服务价格：");
	scanf("%f", &new_node->value);

	printf("\n请输入服务时间(hours)：");
	scanf("%f", &new_node->times);
	printf("服务编号：%d,服务名称：%s,服务价格：%.2f服务价格：%.2f\n", new_node->count, new_node->types,\
		new_node->value,new_node->times);
	return 0;

}

//删除技师
int Dele_Technician(technicianslink head)
{
	if (head == NULL)
	{
		printf("failed!\n");
		return 0;
	}
	if (head->next == NULL)
	{
		printf("empty!\n");
		return 0;
	}
	technicianslink del_node = Display_Technician(head, DELL_MODE);//删除模式(遍历)
	if (del_node == (technicianslink)0)
	{
		printf("del falied!\n");
		return -1;
	}

	del_node->last->next = del_node->next;//进入上一节点的next 赋值为 当前节点next
	del_node->next->last = del_node->last;//进入下一节点的last 赋值为 当前节点last

	del_node->next = NULL;//断开当前节点next
	del_node->last = NULL;//断开当前节点last

	free(del_node);//释放当前节点
	return 0;

}