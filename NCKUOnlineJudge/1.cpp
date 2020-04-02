#import <unistd.h>

main()
{
    write(STDOUT_FILENO, "Hello, NCKU Online Judge!", 25);
    return close(STDOUT_FILENO);
}