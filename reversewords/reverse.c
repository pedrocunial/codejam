#include <stdio.h>
#include <stdlib.h>



void do_case(unsigned n)
{
    unsigned L;
    char **p;
    printf("Case #%u:", n);
    scanf("%u", &L);
    p = malloc(L * sizeof(*p));

    unsigned i = L;
    while (i--)
        scanf("%s", p[j]);

    for (i = 0; i < L; i++) {
        printf(" %s", p[i]);
    }
    printf("\n");
}

char *reverse(char *str, char delim)
{
    char *end = strchr(str, delim);
    char *ret;
    char tmp;

    if (end == NULL)
        end = strchr(str, '\0');

    ret = end + 1;
    end--;

    while (end > str)
        {
            tmp = *str;
            *str = *end;
            *end = tmp;

            end--;
            str++;
        }

    return ret;
}

int main(void)
{
    unsigned char N;
    scanf("%hhu", &N);
    for (unsigned i = 1; i <= N; i++)
        do_case(i);
    return 0;
}
