#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

typedef struct {
    // User defined data may be declared here.
    int mutex_1;
    int mutex_2;

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
    obj->mutex_1=1;
    obj->mutex_2=2;
    
    return obj;
}

void first(Foo* obj) {
    
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->mutex_1=0;
}

void second(Foo* obj) {
    while(obj->mutex_1);
    // printSecond() outputs "second". Do not change or remove this line.
    printSecond();
    obj->mutex_2=0;
}

void third(Foo* obj) {
    while(obj->mutex_2);
    // printThird() outputs "third". Do not change or remove this line.
    printThird();
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
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