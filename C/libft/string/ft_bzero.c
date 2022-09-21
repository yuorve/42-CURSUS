
void	bzero(void *s, size_t n)
{
	if (n > 0)
	{
		while (*s && n > 0)
		{
			s = 0;
			s++;
			n--;
		}
	}
}
