#include <stdio.h>
#include <stdlib.h>
#include<graphics.h>
#include<conio.h>
int main()
{
    int gd = DETECT, gm;
    int rect[2][2],transformedRect[2][2], transformationVector[2];
    initgraph(&gd, &gm, "");
    printf("Enter the coordinates of the rectangle: ");
    for (int i = 0; i < 2; i++)
    {
        printf("Enter x,y:");
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &rect[i][j]);
        }
    }
    printf("Enter the transformation vector: ");
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &transformationVector[i]);
    }
    printf("The transformed coordinates are: ");
    rectangle(rect[0][1],rect[0][2],rect[1][0],rect[1][1]);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d",rect[i][j]);
            printf("%d ", rect[i][j] + transformationVector[j]);
            transformedRect[i][j]=rect[i][j] + transformationVector[j];
        }
        printf("\n");
    }
    setcolor(RED);
rectangle(transformedRect[0][1],transformedRect[0][2],transformedRect[1][0],transformedRect[1][1]);
getch();
    return 0;
}
