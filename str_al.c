/*Copyright@DangFeng17130110003*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#define TRUE 1
#define FALSE 0

void critical_region();
void noncritical_region();

int main()
{
    int shm_id;//共享内存标识符
    void* ptr_shm = NULL;//指向共享内存地址
    key_t key = 666;
    int* turn;//轮换值指针
    pid_t pid;//进程id
    pid = fork();
    
    shm_id = shmget(key,sizeof(int),0666|IPC_CREAT);
    //创建共享内存
    if(shm_id == -1) printf("Something goes wrong:)\n");
    ptr_shm = shmat(shm_id,0,0);
    //连接共享内存
    if(ptr_shm == (void*)-1) printf("Something goes wrong:)\n");
    turn = (int*)ptr_shm;
    *turn=0;
    //设置共享内存变量值

    if(pid == 0){
        while(TRUE){
            sleep(1);
            while(*turn != 0);         //loop
            printf("pid= %d\n",pid);
            critical_region();
            *turn = 1;
            noncritical_region();
        }
    }
    else{
        while(TRUE){
            sleep(1);
            while(*turn == 0);        //loop
            printf("pid= %d\n",pid);
            critical_region();
            *turn = 0;
            noncritical_region();
        }
    }

    return 0;
}
void critical_region(){
    printf("Enter critical region!\n");
}
void noncritical_region(){
    printf("Out critical region!\n");
}