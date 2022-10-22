#include <stdio.h>

void fat_read()
{
    printf("fat read \n");
}

void ext_read() // 被回调函数
{
    printf("ext read \n");
}

struct func_oper 
{
    void (*fat_read)(void); // 回调函数
    void (*ext_read)(void);
};

struct raedfile // 基类
{
    char name[20];
    struct func_oper func;
};

int main()
{
    struct raedfile f1; // 创建子类变量
 /*   f1.name = {'h','e','l','l','o'};
    printf("%s\n", f1.name); */
    f1.func.ext_read = fat_read; // 初始化
    
    struct raedfile f2; // 创建子类变量
    f2.func.ext_read = ext_read;

    struct raedfile *func; // 创建基类指针
    func = &f1; // 基类指针指向子类
    func->func.ext_read();
    func = &f2;
    func->func.ext_read();

    


    return 0;
}