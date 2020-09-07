#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define fils_color  "\33[1;31m"
#define pere_color  "\33[1;32m"
#define blanc_color puts("\33[1;00m")

void qst1();
void qst2();
void qst3();
int main(int argc, char const *argv[])
{
    int choix = atoi(argv[1]);
    if(choix == 1)
        qst1();
    else if (choix == 2)
        qst2();
    else if (choix == 3)
        qst3();
    wait(NULL);
    exit(EXIT_SUCCESS);
}

void qst1()
{
    /*creation de proc*/
    pid_t p1 = fork();
    /*le pere*/
    if (p1)
    {   
        //for(int i = 0; i < 100000; i++);
        printf("%s PERE, mon pid : %d \n Le pid de mon fils  : %d \n",
                pere_color,    getpid(),          p1);
        blanc_color;
    }
    /*le fils*/
    else if (!p1)
    {
        for(int i = 0; i < 100000; i++);
        printf("%s FILS, mon pid : %d \n Le pid de mon pere : %d \n",
                fils_color,    getpid(),           getppid());
        blanc_color;
    }
    /*erreur*/
    else
    {
        perror("ERR  ");
        exit(EXIT_FAILURE);
    }    
}

void qst2()
{
    int x = 0 ;
    int count = 1000;
    /* creation de proc */
    pid_t p = fork();
    /* pere */
    if(p)
    {
        for (int  i = 0; i < count; i++)
            printf("%s Pere, La valeur de X est : %d @X : %p\n", pere_color, ++x, &x);
    }
    /* fils */
    else if(!p)
    {
        for (int  i = 0; i < count; i++)
        printf("%s fils, La valeur de X est : %d @X : %p\n", fils_color, x, &x);
    }
    /* erreur */
    else
    {
        perror("ERR  ");
        exit(EXIT_FAILURE);
    }
    
}

void do_f1()
{
    printf("je suis f1 mon pid : %d le fils de %d \n", getpid(), getppid());
    exit(0);
}

void do_f3(pid_t f1)
{
    printf("je suis f3 : %d le fils de f2 : %d et le neveu de f1 : %d\n",
            getpid(),               getppid(),         f1);
    exit(0);
}

void do_f2(pid_t f1)
{
    printf("je suis f2 mon pid : %d le frere de f1 : %d ppid : %d \n", getpid(), f1, getppid());
    if(fork()==0)
       do_f3(f1);
    else 
        wait(NULL);
    exit(0);
}

void qst3()
{
    pid_t f1, f2;
    /* creation de fils 1 */
    f1 = fork();
    if(f1 == 0 )
        do_f1();
    /*creation de fils 2*/
    f2 = fork();
    if(f2 == 0 )
    do_f2(f1);
    /*attendre les deux fils */
    wait(NULL);
    wait(NULL);
    
    
}
