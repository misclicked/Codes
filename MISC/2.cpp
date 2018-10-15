#include <bits/stdc++.h>
using namespace std;
struct NODE
{
    int *ID;
    float *GPA;
    NODE *link;
    NODE() { ID = NULL, GPA = NULL, link = NULL; }
};
int main()
{
    NODE *A;
    A = (NODE *)malloc(sizeof(NODE));
    NODE *B;
    A->link = B;
    B = (NODE *)malloc(sizeof(NODE));
    printf("%p %p\n", A->link, B);
    system("pause");
}