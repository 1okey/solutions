#include <string.h>
#include <cassert>

void reverse(char * str)
{
    unsigned i = 0;
    unsigned length = strlen(str) - 1;
    while(i < length) {
        char tmp = str[i];
        str[i] = str[length];
        str[length] = tmp;
        ++i;
        --length;
    }
}

int main()
{
    {
        char str[7] = "string";
        char reversed[7] = "gnirts";

        reverse(str);
        assert(strcmp(str,reversed) == 0);
    }
    {
        char str[19] = "aba ba ga la ma ga";
        char reversed[19] = "ag am al ag ab aba";

        reverse(str);
        assert(strcmp(str,reversed) == 0);
    }

}