// #include<iostream>
// #include<stdlib.h>
// #include<pthread.h>
// #include<unistd.h>
// #include<boost/thread.hpp>

// using namespace std;

// pthread_mutex_t SA;
// int turn = 1;
// int i = 0;


// void ThreadProc1(){
//     while(i++ < 100)
//     {
//         while(turn != 0);
//         // pthread_mutex_lock(&SA);
//         // turn = 1;
//         // cout << turn << endl;
//         cout << "thread 1 :" << turn << endl;
//         // pthread_mutex_unlock(&SA);
//     }
// }

// void ThreadProc2(){
//     while(i++ < 100)
//     {
//         // while(turn != 1);
//         // pthread_mutex_lock(&SA);
//         // turn = 0;
//         // cout << "thread 2 :" ;
//         // pthread_mutex_unlock(&SA);
//     }
// }

// int main(){
    
//     pid_t fpid;
//     pthread_mutex_init(&SA, NULL);

//     boost::thread t1(ThreadProc1);
//     //::thread t2(ThreadProc2);
//     t1.join();
//     return 0;
// }
#include<iostream>

#include<boost/thread.hpp>

using namespace std;

void threadFunc(){
    cout<<"hello boost threads!"<<endl;
}

void wait(int seconds)
{
  boost::this_thread::sleep(boost::posix_time::seconds(seconds));
}

void thread()
{
  for (int i = 0; i < 5; ++i)
  {
    wait(1);
    std::cout << i << std::endl;
  }
}

struct ThreadFunc2{
    void operator()(const int & id){
        cout<<"thread #"<<id<<"hello boost Threads from operator!";
    }
};

int main(){
    boost::thread t(threadFunc);
    t.join();

    boost::thread t2(ThreadFunc2(),2);
    t2.join();


    return 1;
}