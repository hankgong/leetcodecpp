#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct {
    // User defined data may be declared here.
    sem_t b;
    sem_t c;
} Foo;

void printFirst() {
    printf("1\n");
}

void printSecond(){
    printf("2\n");
}

void printThird() {
    printf("3\n");
}

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    
    // Initialize user defined data here.
    sem_init(&obj->b, 0, 0);
    sem_init(&obj->c, 0, 0);
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    sem_post(&obj->b);
}

void second(Foo* obj) {
    sem_wait(&obj->b);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    sem_post(&obj->c);
}

void third(Foo* obj) {
    sem_wait(&obj->c);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    sem_destroy(&obj->b);
    sem_destroy(&obj->c);
    free(obj);
}

int main() {
    Foo *f = fooCreate();
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_create(&tid3, NULL, (void *)&third, (void*)f);
    pthread_create(&tid2, NULL, (void *)&second, (void*)f);
    pthread_create(&tid1, NULL, (void *)&first, (void*)f);
    

    // second(f);

    // first(f);
    // third(f);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);
}