#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct {
    int n;
    int flag;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;
    obj->flag = 0;

    pthread_mutex_init(&obj->mutex, NULL);
    pthread_cond_init(&obj->cond, NULL);

    return obj;
}

void printFoo() {
    printf("foo");
}

void printBar() {
    printf("bar");
}

void foo(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while(1==obj->flag) pthread_cond_wait(&obj->cond, &obj->mutex);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        obj->flag=1;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex);
        while(0==obj->flag) pthread_cond_wait(&obj->cond, &obj->mutex);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        obj->flag=0;
        pthread_cond_signal(&obj->cond);
        pthread_mutex_unlock(&obj->mutex);
    }
}

void fooBarFree(FooBar* obj) {
    if(NULL!=obj){
        pthread_mutex_destroy(&obj->mutex);
        pthread_cond_destroy(&obj->cond);
        free(obj);
    }
}

int main() {
    FooBar *f=fooBarCreate(5);

    pthread_t tidf, tidb;

    pthread_create(&tidb, NULL, (void *)&bar, (void *)f);
    pthread_create(&tidf, NULL, (void *)&foo, (void *)f);

    pthread_join(tidf, NULL);
    pthread_join(tidb, NULL);
}