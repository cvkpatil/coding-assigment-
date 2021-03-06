#include <stdio.h>
#include <string.h>

void test(char *string_one, char *string_two);

int main()
{

    int T;
    char pattern[200][400];
    char sstring[200][400];

    //Input is successful

    scanf("%d", &T);
    int i = 0;
    for (i; i < T; i++)
    {
        scanf("%s", pattern[i]);
        scanf("%s", sstring[i]);
    }

    i = 0;
    //printf("Number is %d and String is %s\n", T, sstring[0]);
    //Now just need to check whether the pattern is in the string or not
    for (i = 0; i < T; i++)
    {
        test(pattern[i], sstring[i]);
    }
    return 0;
}

void test(char *string_one, char *string_two)
{
    //First getting all the charachter count in string One
    int i = 0;
    int alphabet_count_one[26] = {0};
    int length_string_one = strlen(string_one);
    for (int j = 0; j < length_string_one; j++)
    {
        if ((string_one[i] >= 'a' && string_one[i] <= 'z') || (string_one[i] >= 'A' && string_one[i] <= 'Z'))
        
        {
            if (string_one[i] >= 'a' && string_one[i] <= 'z')
            {
                alphabet_count_one[string_one[i] - 'a']++;
            }
            else if (string_one[i] >= 'A' && string_one[i] <= 'Z')
            {
                alphabet_count_one[string_one[i] - 'A']++;
            }
        }

        i++;
    }

    i = 0;
    int alphabet_count_two[26] = {0};
    int length_string_two = strlen(string_two);
    for (int j = 0; j < length_string_two; j++)
    {

        if ((string_two[i] >= 'a' && string_two[i] <= 'z') || (string_two[i] >= 'A' && string_two[i] <= 'Z'))
        {
            if (string_two[i] >= 'a' && string_two[i] <= 'z')
            {
                alphabet_count_two[string_two[i] - 'a']++;
            }
            else if (string_two[i] >= 'A' && string_two[i] <= 'Z')
            {
                alphabet_count_two[string_two[i] - 'A']++;
            }
        }

        i++;
    }

    //We got the count of all the alphabets in string one, now we need to do the same for string two

    int tester_one = 1;
    int tester_two = 1;

    for (i = 0; i < 26; i++)
    {
        if (alphabet_count_one[i] != 0)
        {
            if (alphabet_count_one[i] <= alphabet_count_two[i])
            {
                tester_one++;
            }
            else
            {
                tester_two++;
            }
        }
    }

    if (tester_two == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
}