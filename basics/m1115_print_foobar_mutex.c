#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

typedef struct {
    int n;
    pthread_mutex_t mutex1;
    pthread_mutex_t mutex2;
} FooBar;

FooBar* fooBarCreate(int n) {
    FooBar* obj = (FooBar*) malloc(sizeof(FooBar));
    obj->n = n;

    pthread_mutex_init(&obj->mutex1, NULL);
    pthread_mutex_init(&obj->mutex2, NULL);

    // pthread_mutex_lock(&obj->mutex1);
    pthread_mutex_lock(&obj->mutex2);
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
        pthread_mutex_lock(&obj->mutex1);
        // printFoo() outputs "foo". Do not change or remove this line.
        printFoo();
        pthread_mutex_unlock(&obj->mutex2);
    }
}

void bar(FooBar* obj) {
    
    for (int i = 0; i < obj->n; i++) {
        pthread_mutex_lock(&obj->mutex2);
        // printBar() outputs "bar". Do not change or remove this line.
        printBar();
        pthread_mutex_unlock(&obj->mutex1);
    }
}

void fooBarFree(FooBar* obj) {
    pthread_mutex_destroy(&obj->mutex1);
    pthread_mutex_destroy(&obj->mutex2);
    free(obj);
}

int main() {
    FooBar *f=fooBarCreate(5);

    pthread_t tidf, tidb;

    pthread_create(&tidb, NULL, (void *)&bar, (void *)f);
    pthread_create(&tidf, NULL, (void *)&foo, (void *)f);

    pthread_join(tidf, NULL);
    pthread_join(tidb, NULL);
}