#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int rect[2][2], transformedRect[2][2], transformationAngle;

    initgraph(&gd, &gm, "");
    printf("Enter the coordinates of the rectangle: ");
    for (int i = 0; i < 2; i++)
    {
        printf("Enter x,y: ");
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &rect[i][j]);
        }
    }
    printf("Enter the transformation angle: ");
    scanf("%d", &transformationAngle);
    float transformationAngleRad = (3.14 / 180) * transformationAngle;

    printf("The transformed coordinates are: ");
    rectangle(rect[0][0], rect[0][1], rect[1][0], rect[1][1]);
    for (int i = 0; i < 2; i++)
    {
        transformedRect[i][0] = rect[i][0] * cos(transformationAngleRad) - rect[i][1] * sin(transformationAngleRad);
        transformedRect[i][1] = rect[i][0] * sin(transformationAngleRad) + rect[i][1] * cos(transformationAngleRad);
        printf("\n");
        printf("%d,%d", transformedRect[i][0], transformedRect[i][1]);
    }
    setcolor(RED);
    rectangle(transformedRect[0][0], transformedRect[0][1], transformedRect[1][0], transformedRect[1][1]);
    getch();
    return 0;
}
