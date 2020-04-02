#import <unistd.h>
#import <stdio.h>

char st[9], ed[8], ans[8];

main()
{
    fread(st, 1, 9, stdin);
    fread(ed, 1, 8, stdin);
    ans[7] = ed[7] - st[7] + '0';
    if (ed[7] < st[7])
    {
        ans[7] += 10;
        ed[6]--;
    }
    ans[6] = ed[6] - st[6] + '0';
    if (ed[6] < st[6])
    {
        ans[6] += 6;
        ed[4]--;
    }
    ans[4] = ed[4] - st[4] + '0';
    if (ed[4] < st[4])
    {
        ans[4] += 10;
        ed[3]--;
    }
    ans[3] = ed[3] - st[3] + '0';
    if (ed[3] < st[3])
    {
        ans[3] += 6;
        ed[1]--;
    }
    ans[1] = ed[1] - st[1] + '0';
    if (ed[1] < st[1])
    {
        ans[1] += 10;
        ed[0]--;
    }
    ans[0] = ed[0] - st[0] + '0';
    ans[2] = ans[5] = ' ';
    write(STDOUT_FILENO, ans, 8);
    return close(STDOUT_FILENO);
}