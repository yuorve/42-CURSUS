#include	<stdio.h>

void	*ft_memset(void *b, int c, size_t len);

int main(void)
{
	char	str[] = "Hola";
	ft_memset(str, '$', 3);
	printf("Resultado: %s\n", str);
}
