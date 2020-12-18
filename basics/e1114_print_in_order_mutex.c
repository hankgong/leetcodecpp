#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct {
    // User defined data may be declared here.
    pthread_mutex_t mutex_1;
    pthread_mutex_t mutex_2;
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
    pthread_mutex_init(&obj->mutex_1, NULL);
    pthread_mutex_init(&obj->mutex_2, NULL);

    pthread_mutex_lock(&obj->mutex_1);
    pthread_mutex_lock(&obj->mutex_2);

    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    pthread_mutex_unlock(&obj->mutex_1);
}

void second(Foo* obj) {
    pthread_mutex_lock(&obj->mutex_1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    pthread_mutex_unlock(&obj->mutex_1);
    pthread_mutex_unlock(&obj->mutex_2);
}

void third(Foo* obj) {
    pthread_mutex_lock(&obj->mutex_2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
    pthread_mutex_unlock(&obj->mutex_2);
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    pthread_mutex_destroy(&obj->mutex_1);
    pthread_mutex_destroy(&obj->mutex_2);
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