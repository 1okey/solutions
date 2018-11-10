#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Whole numbers (integers)");
    printf("char    from %d - to %d\n", CHAR_MIN, CHAR_MAX);
    printf("schar   from %d - to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("uchar   from %d - to %u\n", 0, UCHAR_MAX);

    printf("int     from %d - to %d\n", INT_MIN, INT_MAX);
    printf("uint    from %d - to %u\n", 0, UINT_MAX);

    printf("short   from %d - to %d\n", SHRT_MIN, SHRT_MAX);
    printf("ushort  from %d - to %u\n", 0, USHRT_MAX);

    printf("long    from %ld - to %ld\n", LONG_MIN, LONG_MAX);
    printf("ulong   from %d - to %lu\n", 0, ULONG_MAX);

    printf("llong   from %lld - to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("ullong  from %d - to %llu\n", 0, ULLONG_MAX);

    printf("\nReal numbers (floats)");
    printf("float   from %f - to %f\n", FLT_MIN, FLT_MAX);
    printf("double  from %f - to %f\n", DBL_MIN, DBL_MAX);
    printf("ldouble from %Lf - to %Lf\n", LDBL_MIN, LDBL_MAX);

    return 0;
}