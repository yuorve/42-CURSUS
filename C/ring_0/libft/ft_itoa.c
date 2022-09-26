int	ft_nblen(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
}

char	*ft_itoa(int n)
{
	char	*tab;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_nblen(n);
	tab = (char *) malloc (sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	tab[len--] = '\0';
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
		len--;
	}
	while (len > 0)
	{
		tab[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return(tab);
}
