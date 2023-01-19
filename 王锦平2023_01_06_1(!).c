/*给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
* (实际上就是找出字符串s中，含有字符串p中所有字母的短字符串)
     字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。//'97'~'122'
       说明：
          字母异位词指字母相同，但排列不同的字符串。
       输入:
          s: "cbaebabacd" p: "abc"    
          起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
          起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词  */
#include<stdio.h>
#include<string.h>
int main()
{
    char ch[1024] = { 0 };
    char ch_search[1024] = { 0 };
    //char test[10] = { "wjp" };
    unsigned char flag = 0;
    printf("这是一个能从字符串中找出给定的三个字符的程序，即使是被打乱顺序的三个连续字符，只包含小写英文字母\n");
    printf("请输入英文数字的字符串：");
    scanf("%s", ch);
    int ch_long = strlen(ch);
    for (int num = 0; num < ch_long; num++)//逐个判断是否在小写字母范围
    {
        if (ch[num] < 'a' || ch[num] > 'z')//有任一字符不在范畴内flag++
            flag++;
    }
    if (flag != 0)//若字符都在范畴内flag应为0
    {
        printf("您输入的需要被判断的字符串中含有非小写字母部分！！！\n");
        return -1;
    }
    flag = 0;


    while (getchar() != '\n');
    printf("现在请连续输入三个字符:");
    scanf("%s", ch_search);
    int ch_secrch_long = strlen(ch_search);
    for (int num = 0; num < ch_secrch_long; num++)//逐个判断是否在小写字母范围
    {
        if (ch_search[num] < 'a' || ch_search[num] > 'z')//有任一字符不在范畴内flag++
            flag++;
    }
    //printf("flag is %d", flag);
    if (flag != 0)//若字符都在范畴内flag应为0
    {
        printf("您输入的判断字符串中含有非小写字母部分！！！\n");
    }
        
    for (int i = 0; i < ch_long - 1; i++)//循环次数是，ch字符串中，连续的字符串，的字符数的总和
    {
        flag = 0;
        for (int j = 0; j < ch_secrch_long; j++)//将ch中选出连续的三个元素，逐个于ch_search中的三个元素比较
        {
            if (ch_search[j] == ch[i])
                flag++;
            if (ch_search[j] == ch[i + 1])
                flag++;
            if (ch[i] == ch[i + 1])//若两个相邻的字符相等，则flag--
                flag--;
            if (ch_search[j] == ch[i + 2])
                flag++;
            if (ch[i + 1] == ch[i + 2])//若两个相邻的字符相等，则flag--
                flag--;
        }
        if (flag == 3)
            printf("%c%c%c\n", ch[i], ch[i + 1], ch[i + 2]);
    }  
    return 0;
}