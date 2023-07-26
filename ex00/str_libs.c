int ft_strncmp(char *s1, char *s2, unsigned int n)
{
    while (n > 0) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }

        if (*s1 == '\0') {
            break;
        }

        s1++;
        s2++;
        n--;
    }

    return 0;
}

int ft_atoi(const char *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}