#include <stdio.h>

void speak(const char *arg) {
    printf("my sound is %c\n",*arg);
}

int is_fly(int a)
{
    if (a < 0) return 1; // can fly 1
    else return 0; // can't fly 0
}

struct fun_operations{
    void (*speak)(const char *);
    int (*is_fly)(int);
};

struct animal{
    int age;
    char spk;
    struct fun_operations fp;
};

struct cat{
    struct animal *p;
    struct animal ani;
    int weight;
};

int main()
{
    printf("hello\n");
    struct animal a1;
    a1.age = 3;
    a1.spk = 'h';
    a1.fp.speak = speak;
    a1.fp.is_fly = is_fly; // 结构体里面的函数指针需要初始化
    printf("age:%d,spk:%c\n",a1.age, a1.spk);
    a1.fp.speak(&a1.spk); 
    
    struct cat c1;
    c1.weight = 5;
    printf("cat1's weight:%d\n",c1.weight);
    
    c1.p = &a1;
    printf("cat1 with farth speak:%c\n",c1.p->spk) ;

    int b = (c1.p->fp.is_fly)(c1.weight);
    (b != 0) ? ("i am cat1 can fly\n") : printf("i am cat1 i can't fly but i am very happy!\n");
    return 0;
}