#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "../hutility.hpp"

using namespace std;

int &func1(){
    static int x = 10;
    // int x = 10;
    return x;
}

int func2(int &x){
    return x;
}

int func3(char* &str1, char* &str2){
    char *temp = str1;
    str1 = str2;
    str2 = temp;
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 30};
    int *p;

    //here p++ increase the pointer address
    p = arr;
    for (int i = 0; i < 3; ++i)
    {
        cout << *p << endl;
        p++;
    }

    //here q++ increment arr[0]++
    int &q = arr[0];
    for (int i = 0; i < 3; ++i)
    {
        cout << q << endl;
        q++;
    }

    int a = 5;
    int b = 6;
    int *m;
    m = &a;
    m = &b;

    cout << *m << endl;

    int &n = a;
    n = 20;
    int &t = n;
    t = 30;
    cout << n << " " << a << " " << t << " " << endl;

    vector<int> v = {10, 20 , 30, 40};

    for (auto &x : v)
        x += 5;

    cout << v << endl;

    func1() = 30;
    cout << func1() << endl;

    int z = 10;
    cout << func2(z) << endl;

    char const *str1 = "geeks";
    // str1 = "gee";
    char const *str2 = "for geeks";
    swap(str1, str2);
    cout << str1 << str2 << endl;

    return 0;
}
