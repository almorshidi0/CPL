#include <stdio.h>
#include <limits.h>
#include <float.h>

#define ALL_LOW_LONG    (0x0UL)
#define ALL_HIGH_LONG   (~ALL_LOW_LONG)

/* my integer types */
#define MY_SCHAR_MIN    ((signed    char)   ~(((unsigned    char)   ALL_HIGH_LONG) >> 1))
#define MY_SSHORT_MIN   ((signed    short)  ~(((unsigned    short)  ALL_HIGH_LONG) >> 1))
#define MY_SINT_MIN     ((signed    int)    ~(((unsigned    int)    ALL_HIGH_LONG) >> 1))
#define MY_SLONG_MIN    ((signed    long)   ~(((unsigned    long)   ALL_HIGH_LONG) >> 1))

#define MY_SCHAR_MAX    ((signed    char)   (((unsigned     char)  ALL_HIGH_LONG) >> 1))
#define MY_SSHORT_MAX   ((signed    short) (((unsigned      short)  ALL_HIGH_LONG) >> 1))
#define MY_SINT_MAX     ((signed    int)   (((unsigned      int)    ALL_HIGH_LONG) >> 1))
#define MY_SLONG_MAX    ((signed    long)  (((unsigned      long)   ALL_HIGH_LONG) >> 1))

#define MY_UCHAR_MIN    ((unsigned  char)   ALL_LOW_LONG)
#define MY_USHORT_MIN   ((unsigned  short)  ALL_LOW_LONG)
#define MY_UINT_MIN     ((unsigned  int)    ALL_LOW_LONG)
#define MY_ULONG_MIN    ((unsigned  long)   ALL_LOW_LONG)

#define MY_UCHAR_MAX    ((unsigned  char)   ALL_HIGH_LONG)
#define MY_USHORT_MAX   ((unsigned  short)  ALL_HIGH_LONG)
#define MY_UINT_MAX     ((unsigned  int)    ALL_HIGH_LONG)
#define MY_ULONG_MAX    ((unsigned  long)   ALL_HIGH_LONG)

int main(){
    printf("integer types through calculation:\n\n");

    printf("Minimum Signed Char     %hhd\n",    MY_SCHAR_MIN);
    printf("Minimum Signed Short    %hd\n",     MY_SSHORT_MIN);
    printf("Minimum Signed Int      %d\n",      MY_SINT_MIN);
    printf("Minimum Signed Long     %ld\n\n",   MY_SLONG_MIN);

    printf("Maximum Signed Char     %hhd\n",    MY_SCHAR_MAX);
    printf("Maximum Signed Short    %hd\n",     MY_SSHORT_MAX);
    printf("Maximum Signed Int      %d\n",      MY_SINT_MAX);
    printf("Maximum signed Long     %ld\n\n",   MY_SLONG_MAX);

    printf("Minimum Unsigned Char   %hhu\n",    MY_UCHAR_MIN);
    printf("Minimum Unsigned Short  %hu\n",     MY_USHORT_MIN);
    printf("Minimum Unsigned Int    %u\n",      MY_UINT_MIN);
    printf("Minimum Unsigned Long   %lu\n\n",   MY_ULONG_MIN);

    printf("Maximum Unsigned Char   %hhu\n",    MY_UCHAR_MAX);
    printf("Maximum Unsigned Short  %hu\n",     MY_USHORT_MAX);
    printf("Maximum Unsigned Int    %u\n",      MY_UINT_MAX);
    printf("Maximum Unsigned Long   %lu\n\n\n", MY_ULONG_MAX);


    printf("integer types from standard headers:\n\n");

    printf("Minimum Signed Char     %hhd\n",    SCHAR_MIN);
    printf("Minimum Signed Short    %hd\n",     SHRT_MIN);
    printf("Minimum Signed Int      %d\n",      INT_MIN);
    printf("Minimum Signed Long     %ld\n\n",   LONG_MIN);

    printf("Maximum Signed Char     %hhd\n",    SCHAR_MAX);
    printf("Maximum Signed Short    %hd\n",     SHRT_MAX);
    printf("Maximum Signed Int      %d\n",      INT_MAX);
    printf("Maximum signed Long     %ld\n\n",   LONG_MAX);

    printf("Minimum Unsigned Char   %hhu\n",    0U);
    printf("Minimum Unsigned Short  %hu\n",     0U);
    printf("Minimum Unsigned Int    %u\n",      0U);
    printf("Minimum Unsigned Long   %lu\n\n",   0UL);

    printf("Maximum Unsigned Char   %hhu\n",    UCHAR_MAX);
    printf("Maximum Unsigned Short  %hu\n",     USHRT_MAX);
    printf("Maximum Unsigned Int    %u\n",      UINT_MAX);
    printf("Maximum Unsigned Long   %lu\n\n\n", ULONG_MAX);


    printf("floating-point types from standard headers:\n");

    printf("Minimum float           %f\n",      FLT_MIN);
    printf("Minimum double          %lf\n",     DBL_MIN);
    printf("Minimum long double     %Lf\n\n",   LDBL_MIN);

    printf("Maximum float           %f\n",      FLT_MAX);
    printf("Maximum double          %lf\n",     DBL_MAX);
    printf("Maximum long double     %Lf\n\n\n", LDBL_MAX);
    
    return 0;
}