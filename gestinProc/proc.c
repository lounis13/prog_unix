#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define fils_color  "\33[1;31m"
#define pere_color  "\33[1;32m"
#define blanc_color puts("\33[1;00m")
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
        exit(0);
    }    
}

int main(int argc, char const *argv[])
{
    qst1();
    system("ps aux | grep loinis13 | grep ./proc");
    exit(EXIT_SUCCESS);
}
