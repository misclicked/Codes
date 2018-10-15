#include <stdio.h>
#include <stdlib.h>
struct NODE
{
    int *ID;
    float *GPA;
    NODE *link;
    NODE() { ID = NULL, GPA = NULL, link = NULL; }
};
NODE *createnode(int *idData, float *gpaData)
{
    NODE *nodePtr = (NODE *)malloc(sizeof(NODE));
    nodePtr->ID = idData;
    nodePtr->GPA = gpaData;
    return nodePtr;
}
void travel(NODE *now)
{
    if (now == NULL)
        return;
    printf("Addr: %p\t", now);
    printf("ID: %d GPA: %f\n", *now->ID, *now->GPA);
    travel(now->link);
}
int main(void)
{
    NODE *root = NULL;
    NODE *now;
    FILE *pFile;
    pFile = fopen("C:\\Users\\misclicked\\Desktop\\NI_offine\\Codes\\MISC\\student-grade.txt", "r");
    int *newDataID;
    float *newDataGpa;
    while (!feof(pFile))
    {
        newDataID = (int *)malloc(sizeof(int));
        newDataGpa = (float *)malloc(sizeof(float));
        fscanf(pFile, "%d %f", newDataID, newDataGpa);
        if (root == NULL)
        {
            root = createnode(newDataID, newDataGpa);
            now = root;
        }
        else
        {
            now->link = createnode(newDataID, newDataGpa);
            now = now->link;
        }
        now->link = NULL;
    }
    travel(root);
    system("pause");
}