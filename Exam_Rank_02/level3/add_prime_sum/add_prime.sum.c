

/* Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		nb = nb % 10;
	}
	if (nb < 9)
	{
		ft_putchar(nb + '0') ;
	}
}

int	ft_atoi(char *str)
{
	int	i = 0;
	int	ret = 0;
	
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret);
}

int	is_prime(int num)
{
	int	i = 2;

	while (i < num)
	{
		if (num % i == 0)
			return (1);
		i++;
	}
	return (0);
}

int	add_prime_sum(int n)
{
	int sum = 0;
	int	i = 2;

	while (n >= i)
	{
		if (is_prime(i) == 0)
			sum = sum + i;
		i++;
	}
	return (sum);
}

int main(int ac, char **av)
{
	int	n;

	if (ac == 2 && (n = ft_atoi(av[1])))
		ft_putnbr(add_prime_sum(n));
	else
		ft_putnbr(0);
	write (1, "\n", 1);
	return (0);
}

/* int main()
{
	int	i = 0;

	while (i < 10)
	{
		printf("i is %d : %d\n", i , is_prime(i));
		i++;
	}
} */



