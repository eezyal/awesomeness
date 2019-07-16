#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <pthread.h>

using namespace std;

typedef struct _runnable_args {
    int length;
    int *arr;
} runnable_args;

void sortInline(int *arr, int length)
{
    vector<int> v(length, 0);

    for (int i = 0; i < length; ++i)
        v[i] = arr[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < length; ++i)
        arr[i] = v[i];

    return;
}

void *runnableSum(void *args)
{
    runnable_args *r_args = (runnable_args *)args;
    int len = r_args->length;
    int *arr = r_args->arr;

    cout << "Running thread : " << pthread_self() << endl;
    sortInline(arr, len);
    cout << "Done sorting in thread : " << pthread_self() << endl;
    pthread_exit(0);
}

int main()
{
    pthread_t *pthr = NULL;
    int len = 0;
    int numthreads = 0;
    int *arr = NULL;
    runnable_args *pargs = NULL;
    int prev = 0;

    cin >> numthreads;
    cin >> len;
    arr = (int *)malloc(sizeof(*arr) * len);
    pthr = (pthread_t *)malloc(sizeof(pthread_t) * numthreads);
    pargs = (runnable_args *)malloc(sizeof(runnable_args) * numthreads);

    for (int i = 0; i < len; ++i)
        cin >> arr[i];

    int remaining = len % numthreads;
    int chunk = (remaining == 0)?(len/numthreads):(len/numthreads)+1;

    for (int i = 0; i < numthreads - 1; i++) {
        pargs[i].length = chunk;
        pargs[i].arr = &arr[prev];
        prev += chunk;
        pthread_create(&pthr[i], NULL, runnableSum, &pargs[i]);
    }

    pargs[numthreads - 1].length =  (remaining == 0)?chunk:remaining;
    pargs[numthreads-1].arr = &arr[prev];
    pthread_create(&pthr[numthreads-1], NULL, runnableSum, &pargs[numthreads-1]);

    for (int i = 0; i < numthreads; i++) {
        pthread_join(pthr[i], NULL);
    }

    cout << "Here's what the array looks like with all threads done working: " << endl;
    for (int i = 0 ; i < len; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
