
#include <stdio.h> 
#include <string.h> 
#include <ctype.h>

int main()
{
    char dt[4][10] = {"char", "int", "float", "double"};
    int val[4] = {1, 2, 4, 8};
    char c;
    int i, j, add = 1000, flag;
    char str[10];

    FILE *fp = fopen("test.c", "r");
    if (fp == NULL)
    {
        printf("Failed to open the file.\n");
        return 1;
    }

    printf("Address\t\tDatatype\tSymbol\t\tValue\n");

    while ((c = fgetc(fp)) != EOF)
    {
        if (isalpha(c))
        {

            i = 0;
            do
            {

                str[i] = c;
                i++;
                c = fgetc(fp);

            } while (isalpha(c) || isdigit(c) || c == '_');
            str[i] = '\0';

            flag = 0;
            for (j = 0; j < 4; j++)
            {
                if (strcmp(str, dt[j]) == 0)
                {
                    printf("%d\t\t%s\t\t%s\t\t%d\n", add, dt[j], str, val[j]);
                    add++;

                    flag = 1;
                    break;
                }
            }

            if (!flag)
            {
                printf("%d\t\t-\t\t%s\t\t-\n", add, str);
                add++;
            }

            if (c == ';')
            {
                add += 4;
            }
        }
        else if (isdigit(c))
        {

            i = 0;
            do
            {

                str[i] = c;
                i++;
                c = fgetc(fp);

            } while (isdigit(c) || c == '.');

            str[i] = '\0';
            printf("%d\t\t-\t\t-\t\t%s\n", add, str);
            add++;

            if (c == ';')
            {
                add += 4;
            }
        }
    }

    fclose(fp);

    return 0;
}
