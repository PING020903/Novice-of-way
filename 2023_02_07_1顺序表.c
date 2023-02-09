#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
struct numbers
{
    int num[100];
    int flag;
};

//初始化
struct numbers *rst()
{
    struct numbers *form = malloc(sizeof(struct numbers));//指向堆，函数运行结束后不释放
    bzero(form->num, sizeof(form->num));//初始化结构体数组成员
    form->flag = -1;//初始化结构体成员
    return form;//返回结构体zero
}

//增加
int *Add_of_form(struct numbers *form, int NewData)
{
    form->num[form->flag + 1] = NewData;//将数据填入结构体数组成员中
    form->flag++;//有效标记+1
    return 1;
}

//修改
int Change(struct numbers* form, int num, int num_change)
{
    form->num[num - 1] = num_change;
    return 1;
}

//删除顺序表中数据
//把deldata从form所代表的顺序表中删除
int seqform_delete(struct numbers *form, int deldata)
{
    int i, j;
    //判断顺序表是否空了
    if (form->flag < 0)
    {
        printf("顺序表为空，无法删除!\n");
        return -1;
    }
    //第一步：遍历顺序表找到deldata
    for (i = 0; i <= form->flag; i++)
    {
        if (form->num[i] == deldata)  //找到要删除的数据
        {
            //数组后面的元素往前挪动--》删除
            for (j = i; j < form->flag; j++)
                form->num[j] = form->num[j + 1];
            //为了防止漏掉重复的数据
            i--;
            //更新flag
            form->flag--;
        }
    }
    return 0;//删除顺序表中数据
}

/*查询*/
int Zero_Print_All(struct numbers *form)
{

    for (int i = 0; i <= form->flag; i++)
    {
        printf("form[%d] :    %d\n", i + 1, form->num[i]);
    }
    return 1;
}

int main()
{
    struct numbers* mynum =rst();
    Add_of_form(mynum, 233);
    Add_of_form(mynum, 23);
    Add_of_form(mynum, 2333);
    Add_of_form(mynum, 666);
    Add_of_form(mynum, 444);
    Add_of_form(mynum, 999);
    Add_of_form(mynum, 777);
    Zero_Print_All(mynum);
    Change(mynum, 2, 67);
    Change(mynum, 5, 67);
    printf("---------\n");
    Zero_Print_All(mynum);
    printf("---------\n");
    seqform_delete(mynum, 999);
    seqform_delete(mynum, 666);
    Zero_Print_All(mynum);
    return 0;
}