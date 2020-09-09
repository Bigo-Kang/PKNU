#include <stdio.h>
#define mil 1000000

int main()
{
    int n, tax=0;

    scanf("%d", &n);

    if (n > 12){ tax += 12 * 0.06 * mil; n-=12; }
    else { tax += n * 0.06 * mil; n -= n; }

    if (n > 34){ tax += 34 * 0.15 * mil; n-=34; }
    else { tax += n * 0.15 * mil; n -= n; }

    if (n > 42){ tax += 42 * 0.24 * mil; n-=42; }
    else { tax += n * 0.24 * mil; n -= n; }

    if (n > 62){ tax += 62 * 0.35 * mil; n-=62; }
    else { tax += n * 0.35 * mil; n -= n; }

    if (n > 350){ tax += 350 * 0.38 * mil; n-=350; }
    else { tax += n * 0.38 * mil; n -= n; }

    tax += n * 0.4 * mil;

    printf("%d\n", tax);
    return 0;
}