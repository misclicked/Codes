#include <iostream>
#include <unistd.h>

using namespace std;

char O[40], S[20], len, *o = O;
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, d, mm, dd, i;

int main()
{
    advance(o, read(STDIN_FILENO, o, 20));
    advance(o, read(STDIN_FILENO, o, 20));
    sscanf(O, "%d%d%d%d", &y, &d, &mm, &dd);
    if (y % 4 == 0)
    {
        if (y % 100 == 0)
        {
            if (y % 400 == 0)
                month[2]++;
        }
        else
        {
            month[2]++;
        }
    }
    if (mm > 12 || mm < 1)
    {
        len = sprintf(S, "%d", -1);
        write(STDOUT_FILENO, S, len);
        return close(STDOUT_FILENO);
    }
    if (dd > month[mm] || dd < 1)
    {
        len = sprintf(S, "%d", -2);
        write(STDOUT_FILENO, S, len);
        return close(STDOUT_FILENO);
    }
    for (i = 1; i < mm; i++)
        dd += month[i];
    len = sprintf(S, "%d", (dd + d - 1) % 7);
    write(STDOUT_FILENO, S, len);
    return close(STDOUT_FILENO);
}