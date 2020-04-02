#pragma GCC optimize("Os")
#define gc getchar_unlocked
#define pc putchar_unlocked
char a, b, c, d;

main()
{
    a = gc();
    ((b = gc()) & 16) ? gc() : (b = a, a = 48);
    c = gc();
    ((d = gc()) & 16) ? gc() : (d = c, c = 48);
    pc(gc());
    pc(gc());
    pc(gc());
    pc(gc());
    pc(a);
    pc(b);
    pc(c);
    pc(d);
}