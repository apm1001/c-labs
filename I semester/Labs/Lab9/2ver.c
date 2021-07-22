#include <stdio.h>
#include <stdbool.h>

main() {
    int k;
    float a, b, c, d, min, max, max_3;
    bool b_a = false, b_min = false, b_max = false;

    Menu:
        printf("Choose:\n\n1) max(a,b)\n2) min(c,d)\n3) max(a, min(c, d))\n\n-->");
        scanf_s("%i", &k);

        switch (k) {
            case 1:
                switch (b_max)
                {
                    case true:
                        printf("\nmax(%g, %g) = %g", a, b, max);
                        goto Reset;
                        break;
                    case false:
                        if (b_a == false)
                        {
                            printf("a = ");
                            scanf("%f", &a);
                            b_a = true;
                        }
                        printf("b = ");
                        scanf("%f", &b);
                        if (a > b)
                        max = a;
                            else max = b;
                        b_max = true;
                        printf("max(%g, %g) = %g", a, b, max);
                        goto Reset;
                }
            case 2:
                switch (b_min)
                {
                    case true:
                        printf("\nmin(%g, %g) = %g", c, d, min);
                        goto Reset;
                        break;
                    case false:
                        printf("c = ");
                        scanf("%f", &c);
                        printf("d = ");
                        scanf("%f", &d);
                        if (c > d)
                            min = d;
                        else
                            min = c;
                        b_min = true;
                        printf("min(%g, %g) = %g", c, d, min);
                        goto Reset;
                        break;
                }
            case 3:
                switch (b_a)
                {
                    case false:
                        printf("a = ");
                        scanf("%f", &a);
                        b_a = true;
                        break;
                    default:
                        break;
                }
                switch (b_min)
                {
                    case false:
                        printf("c = ");
                        scanf("%f", &c);
                        printf("d=");
                        scanf("%f", &d);
                        if (c > d) min = d;
                            else min = c;
                        b_min = true;
                        printf("min(%g, %g) = %g", c, d, min);
                    case true:
                        if (a > min)
                            max_3 = a;
                        else
                            max_3 = min;
                        printf("\nmax(%g, %g) = %g", a, min, max_3);
                        goto Reset;
                }
        }
    Reset:
        printf("\nReset values?\n1 - yes\n2- no\n--> ");
        scanf("%d", &k);
        switch (k)
        {
            case 1:
                b_a = b_max = b_min = false;
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
