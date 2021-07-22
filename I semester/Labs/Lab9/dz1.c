#include <stdio.h>
#include <stdbool.h>
#include <math.h>
main() {
    int k;
    float a, b, c, d, x, y, z, max;
    bool b_x = false, b_y = false, b_z = false;

    Menu:
        printf("Choose:\n\n1) Calculate x\n2) Calculate y\n3) Calculate z\n-->");
        scanf("%d", &k);
        switch (k) {
            case 1:
                switch (b_x)
                {
                    case true:
                        printf("\nx = %g", x);
                        goto Reset;
                        break;
                    case false:
                        printf("a = ");
                        scanf("%f", &a);
                        printf("b = ");
                        scanf("%f", &b);
                        printf("c = ");
                        scanf("%f", &c);
                        printf("d = ");
                        scanf("%f", &d);
                        if ((a-1/b)>c*d) x = pow(a-1/b,2);
                            else x = pow (c*d,2);
                        b_x = true;
                        printf("\nx = %g",x);
                        goto Reset;
                }
            case 2:
                switch (b_y)
                {
                    case true:
                        printf("\ny = %g", y);
                        goto Reset;
                        break;
                    case false:
                        switch (b_x)
                        {
                            case true:
                                printf("\nx = %g", x);
                                break;
                            case false:
                                printf("a = ");
                                scanf("%f", &a);
                                printf("b = ");
                                scanf("%f", &b);
                                printf("c = ");
                                scanf("%f", &c);
                                printf("d = ");
                                scanf("%f", &d);
                                if ((a-1/b)>c*d) x = pow(a-1/b,2);
                                else x = pow (c*d,2);
                                b_x = true;
                                printf("\nx = %g",x);
                        }
                        if (c>a) max = c;
                            else max = a;
                        if (x+max>d) y = d;
                            else y = x + max;
                        b_y = true;
                        printf("\ny = %g", y);
                        goto Reset;
                }
            case 3:
                switch (b_z)
                {
                    case true:
                        printf("\nz = %g",z);
                        goto Reset;
                        break;
                    case false:
                        switch (b_y)
                        {
                            case true:
                                printf("\nx = %g",x);
                                printf("\ny = %g",y);
                                break;
                            case false:
                                switch (b_x)
                                {
                                    case true:
                                        printf("\nx = %g",x);
                                        break;
                                    case false:
                                        printf("a = ");
                                        scanf("%f", &a);
                                        printf("b = ");
                                        scanf("%f", &b);
                                        printf("c = ");
                                        scanf("%f", &c);
                                        printf("d = ");
                                        scanf("%f", &d);
                                        if ((a-1/b)>c*d) x = pow(a-1/b,2);
                                            else x = pow (c*d,2);
                                        b_x = true;
                                        printf("\nx = %g",x);
                                }
                                if (c>a) max = c;
                                    else max = a;
                                if (x+max>d) y = d;
                                    else y = x + max;
                                b_y = true;
                                printf("\ny = %g", y);
                        }
                        if (x<y) z = max + y;
                            else z = x - y;
                        printf("\nz = %g - %g = %g", x, y, z);
                        goto Reset;
                }
            default:
                printf("Wrong value!!! Try again\n");
                goto Menu;
                break;
        }
    Reset:
        printf("\nReset values?\n1 - yes\n2- no\n--> ");
        scanf("%d", &k);
        switch (k)
        {
            case 1:
                b_x = b_y = b_z = false;
                break;
            case 2:
                break;
            default:
                printf("Wrong value!!! Try again");
                goto Reset;
                break;
        }
        printf("\Repeat?\n1 - yes\n2- no\n--> ");
        scanf("%d", &k);
        switch (k)
        {
            case 1:
                goto Menu;
                break;
            case 2:
                break;
            default:
                printf("Wrong value!!! Try again");
                goto Reset;
                break;
        }
    return 0;
}
