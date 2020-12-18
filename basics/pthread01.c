#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define N 5

void *worker_thread(void *arg) {
    printf("This is worker_thread() %ld\n", (long)arg);
    pthread_exit(NULL);
}

// int main(int argc, char const *argv[])
// {
//     pthread_t my_thread;
//     int ret;

//     printf("In main: creating thread\n");
//     ret = pthread_create(&my_thread, NULL, &worker_thread, NULL);

//     if(ret!=0){
//         printf("Error: pthread_create() failed\n");
//         exit(EXIT_FAILURE);
//     }
//     pthread_exit(NULL);
// }

int main() {
    pthread_t my_thread[N];

    for (int i = 1; i <=N; ++i) {
        int ret = pthread_create(&my_thread[i], NULL, &worker_thread, (void*)i);
        if(ret) {
            printf("Error: pthread_create() failed\n");
            exit(EXIT_FAILURE);
        }
    }
    pthread_exit(NULL);
}