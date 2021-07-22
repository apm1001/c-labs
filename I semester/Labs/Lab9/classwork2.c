#include <stdio.h>
#include <stdbool.h>

main() {
    int k;
    float a, b, x, y, c, z;
    bool b_x = false, b_y = false, b_z = false;

    Menu:
        printf("Choose:\n\n1) x = a + b\n2) y = x*c + 2\n3) z = x + y\n\n-->");
        scanf("%i", &k);

        switch (k) {
            case 1:
                switch (b_x)
                {
                    case true:
                        printf("\nx = %g + %g = %g", a, b, x);
                        goto Reset;
                        break;
                    case false:
                        printf("a = ");
                        scanf("%f", &a);
                        printf("b = ");
                        scanf("%f", &b);
                        x = a + b;
                        b_x = true;
                        printf("\nx = %g + %g = %g", a, b, x);
                        goto Reset;
                }
            case 2:
                switch (b_y)
                {
                    case true:
                        printf("\ny = %g * %g + 2 = %g", x, c, y);
                        goto Reset;
                        break;
                    case false:
                        switch (b_x)
                        {
                            case true:
                                printf("\nx = %g + %g = %g", a, b, x);
                                break;
                            case false:
                                printf("a = ");
                                scanf("%f", &a);
                                printf("b = ");
                                scanf("%f", &b);
                                x = a + b;
                                b_x = true;
                                printf("\nx = %g + %g = %g", a, b, x);
                        }
                        printf("\nc = ");
                        scanf("%f", &c);
                        y = x*c + 2;
                        b_y = true;
                        printf("\ny = %g * %g + 2 = %g", x, c, y);
                        goto Reset;
                }
            case 3:
                switch (b_z)
                {
                    case true:
                        printf("\nz = %g + %g = %g", x, y, z);
                        goto Reset;
                        break;
                    case false:
                        switch (b_y)
                        {
                            case true:
                                printf("\nx = %g + %g = %g", a, b, x);
                                printf("\ny = %g * %g + 2 = %g", x, c, y);
                                break;
                            case false:
                                switch (b_x)
                                {
                                    case true:
                                        printf("\nx = %g + %g = %g", a, b, x);
                                        break;
                                    case false:
                                        printf("a = ");
                                        scanf("%f", &a);
                                        printf("b = ");
                                        scanf("%f", &b);
                                        x = a + b;
                                        b_x = true;
                                        printf("\nx = %g + %g = %g", a, b, x);
                                }
                                printf("\nc = ");
                                scanf("%f", &c);
                                y = x*c + 2;
                                b_y = true;
                        }
                        z = x + y;
                        printf("\nz = %g + %g = %g", x, y, z);
                        goto Reset;
                }
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
