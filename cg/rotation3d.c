#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>

int main()
{
    int gd = DETECT, gm;
    int rect3d[2][2], depth, transformedRect[2][2], transformationAngle;

    initgraph(&gd, &gm, "");
    int maxX = getmaxx();
    int maxY = getmaxy();
    int midX = maxX / 2;
    int midY = maxY / 2;
    // Axis banako
    line(midX, 0, midX, maxY);
    line(0, midY, maxX, midY);

    // Take input for the coordinates of the cube
    printf("Enter the coordinates of the cube: ");
    for (int i = 0; i < 2; i++)
    {
        printf("Enter x,y: ");
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &rect3d[i][j]);
        }
    }
    printf("Enter depth");
    scanf("%d", &depth);
    printf("Enter the transformation angle: ");
    scanf("%d", &transformationAngle);
    float transformationAngleRad = (3.14 / 180) * transformationAngle;

    printf("The transformed coordinates are: ");
    rectangle(rect3d[0][0], rect3d[0][1], rect3d[1][0], rect3d[1][1]);
    for (int i = 0; i < 2; i++)
    {
        transformedRect[i][0] = (rect3d[i][0] + midX) * cos(transformationAngleRad) - (rect3d[i][1] + midY) * sin(transformationAngleRad);
        transformedRect[i][1] = (rect3d[i][0] + midX) * sin(transformationAngleRad) + (rect3d[i][1] + midY) * cos(transformationAngleRad);
        printf("\n");
        printf("%d,%d", transformedRect[i][0], transformedRect[i][1]);
    }
    setcolor(RED);
    bar3d(transformedRect[0][0], transformedRect[0][1], transformedRect[1][0], transformedRect[1][1], depth, 1);
    getch();
    return 0;
}
