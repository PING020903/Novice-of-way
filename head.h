#ifndef _HEAD_H
#define _HEAD_H
#define SHOW_MODE 0//遍厉模式
#define FIND_MODE 1//寻找模式
#define DELL_MODE 2//删除模式
#define NAME 60
#define SEX 5

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<stdbool.h>
#include <fcntl.h>
#include<time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

//#include <sys/mman.h>
//#include <linux/input.h>

//技师
typedef struct technician
{
	unsigned int count;//人员编号
	char name[NAME];//姓名
	bool sex;//性别
	unsigned int age;//年龄
	float height;//身高
	float weight;//体重
	float breast;//胸围
	float waist;//腰围
	float hips;//臀围
	float monthly_salary;//月薪
	struct technician* last;//上一技师
	struct technician* next;//下一技师
}technicians,*technicianslink;

//服务种类
typedef struct service
{
	unsigned int count;//服务编号
	float value;//价格
	char types[NAME];//服务名称
	float times;//时间(hours)
	struct service* last;
	struct service* next;
}sevices,*servicelink;

extern int top(void);

extern technicianslink Creat_list_node_technician();
extern servicelink Creat_list_node_service();

//extern int Head_Add_Node(technicianslink head);

extern int Tail_Add_Node_Technician(technicianslink head);

//extern int Tail_Add_Node_Technician_Txt(technicianslink head, FILE* fp);

extern int Tail_Add_Node_Service(servicelink head);
extern int Tail_Add_Node_Service_Txt(servicelink head, FILE* fp);

extern technicianslink Display_Technician(technicianslink head, int mode);
extern servicelink Display_Service(servicelink head, int mode);

extern int Dele_Technician(technicianslink head);
extern int Dele_Service(servicelink head);
extern int Change_Service(servicelink head_node);

extern int file_size(char* filename);
extern int Save_file_technician(FILE* fp, technicianslink head);
extern int Read_technician(FILE* fp, technicianslink head);
extern int Read_service(FILE* fp, servicelink head);

extern int Save_file_service(FILE* fp, servicelink head);

extern int admin(FILE* fp, servicelink myhead, FILE* password);
extern int connection(FILE* fp, servicelink myhead);
extern int Save_history(servicelink temp);
extern char* Read_key(FILE* fp);
extern int Change_key(FILE* fp);


#endif