// https://www.hackerrank.com/challenges/playing-with-characters/problem

int main() 
{
    char c;
    char s[64];
    char sen[128];
    scanf("%c", &c);
    scanf("%s\n", s);
    scanf("%[^\n]%*c", sen);
    printf("%c\n%s\n%s",c,s,sen);
    return 0;
}