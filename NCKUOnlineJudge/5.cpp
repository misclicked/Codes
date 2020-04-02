#import <unistd.h>
#import <stdio.h>

#define gc getchar_unlocked

char n, c;

int main()
{
    for (c = gc(); c >= '0'; c = gc())n = (n << 3) + (n << 1) + (c ^ '0');
    if (n < 1)write(STDOUT_FILENO, "Calm", 4);
    else if (n < 4)write(STDOUT_FILENO, "Light air", 9);
    else if (n < 28)write(STDOUT_FILENO, "Breeze", 6);
    else if (n < 48)write(STDOUT_FILENO, "Gale", 4);
    else if (n < 64)write(STDOUT_FILENO, "Storm", 5);
    else write(STDOUT_FILENO, "Hurricane", 9);
    return close(STDOUT_FILENO);
}