#include <stdio.h>
#include <graphics.h>

int main()
{
    // Initialize variables
    long x, y, center_x, center_y, radius_x, radius_y;
    long radius_x_sqr, radius_y_sqr, fx, fy, decision_param, a_sqr, b_sqr, tmp1, tmp2;
    int g_driver = DETECT, g_mode;

    // Initialize graphics mode
    initgraph(&g_driver, &g_mode, "");

    // Display program title and prompt user for inputs
    printf("********* MID POINT ELLIPSE ALGORITHM *********\n\n");
    printf("Enter center coordinates (x, y): ");
    scanf("%ld%ld", &center_x, &center_y);
    printf("Enter radii (radius_x and radius_y): ");
    scanf("%ld%ld", &radius_x, &radius_y);

    // Initialize variables for region 1 of the ellipse
    x = 0;
    y = radius_y;
    a_sqr = radius_x * radius_x;
    b_sqr = radius_y * radius_y;
    fx = 2 * b_sqr * x;
    fy = 2 * a_sqr * y;
    decision_param = b_sqr - (a_sqr * radius_y) + (a_sqr * 0.25);

    // Loop for region 1 of the ellipse
    do
    {
        // Plot points in all four quadrants
        putpixel(center_x + x, center_y + y, 15);
        putpixel(center_x - x, center_y - y, 15);
        putpixel(center_x + x, center_y - y, 15);
        putpixel(center_x - x, center_y + y, 15);

        // Update decision parameter based on the slope of the ellipse
        if (decision_param < 0)
        {
            decision_param = decision_param + fx + b_sqr;
        }
        else
        {
            y = y - 1;
            decision_param = decision_param + fx - fy + b_sqr;
            fy = fy - (2 * a_sqr);
        }
        x = x + 1;
        fx = fx + (2 * b_sqr);
        delay(10);

    } while (fx < fy);

    // Initialize variables for region 2 of the ellipse
    tmp1 = (x + 0.5) * (x + 0.5);
    tmp2 = (y - 1) * (y - 1);
    decision_param = b_sqr * tmp1 + a_sqr * tmp2 - (a_sqr * b_sqr);

    // Loop for region 2 of the ellipse
    do
    {
        // Plot points in all four quadrants
        putpixel(center_x + x, center_y + y, 15);
        putpixel(center_x - x, center_y - y, 15);
        putpixel(center_x + x, center_y - y, 15);
        putpixel(center_x - x, center_y + y, 15);

        // Update decision parameter based on the slope of the ellipse
        if (decision_param >= 0)
            decision_param = decision_param - fy + a_sqr;
        else
        {
            x = x + 1;
            decision_param = decision_param + fx - fy + a_sqr;
            fx = fx + (2 * b_sqr);
        }
        y = y - 1;
        fy = fy - (2 * a_sqr);
    } while (y > 0);

    // Close graphics mode
    getch();
    closegraph();

    return 0;
}
