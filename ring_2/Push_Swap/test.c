#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*tab;
	int		i;

	i = 0;
	tab = (char *) malloc (sizeof(char) * (ft_strlen(src) + 1));
	if (!tab)
		return (0);
	while (*src)
		tab[i++] = *src++;
	tab[i] = '\0';
	return (tab);
}

static int	ft_nblen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;

	len = ft_nblen(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tab = (char *) malloc (sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	tab[len--] = '\0';
	if (n < 0)
	{
		tab[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		tab[len--] = n % 10 + '0';
		n /= 10;
	}
	return (tab);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	number;
	int	negative;

	i = 0;
	number = 0;
	negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (str[i] - '0');
		str++;
	}
	return (number * negative);
}

int		hasDupe(int *stack, int n) {
	int i;
	int valid;

	i = 0;
	valid = 1;
	while (stack[i]) {
		if (stack[i] == n)
			valid = 0;
		i++;
	}
	return (valid);
}

// Función para validar los argumentos pasados desde la línea de comandos
// Devuelve 1 si los argumentos son válidos, en caso contrario devuelve 0
int is_valid_arguments(char **argv, int *stack_a) {
	int	i;
	int	j;
	int	valid;

	i = 0;
	valid = 1;
	while (argv[++i])
	{		
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] == ' ')
				valid = 0;
			if (!ft_isdigit(argv[i][j]))
				valid = 0;
		}
		if (valid)
		{
			if (!hasDupe(stack_a, ft_atoi(argv[i])))
				valid = 0;
			stack_a[i - 1] = ft_atoi(argv[i]);
		}
	}
	return (valid);
}

// Función para comprobar si la pila_a está ordenada
int is_sorted(int *stack_a, int size) {
    int i;
	int valid;

	i = 0;
	valid = 1;
	while (i++ < size)
	{		
		if (i <= (size - 1))
			if (stack_a[i] > stack_a[i+1])
				valid = 0;
	}
	return (valid);
}

void countSort(int *stack_a, int n, int exp, int *output, int *count) {
	int i;
	 
	i = 0;
	while (i < n) {
		int index = stack_a[i++] / exp;
		count[index % 10]++;
	}
	i = 1;
	while (i < 10) {
		count[i] += count[i - 1];
		i++;
	}
	i = n - 1;
	while (i >= 0) {
		int index = stack_a[i] / exp;
		output[count[index % 10] - 1] = stack_a[i];
		count[index % 10]--;
		i--;
	}
	i = 0;
	while (i < n) {
		stack_a[i] = output[i];
		i++;
	}
}

void radixSort(int *stack_a, int n) {
    int *output;
	int *count;
	int max;
	int i;
	int exp;

    output = malloc(n * sizeof(int*));
	count = malloc(10 * sizeof(int*));
    max = stack_a[0];
	i = 0;
	while (++i < n) {
        if (stack_a[i] > max) {
            max = stack_a[i];
        }
    }
	exp = 1;
	while (max / exp > 0) {
		i = 0;
		while(i < 10)
			count[i++] = 0;
        countSort(stack_a, n, exp, output, count);
		exp *= 10;
    }
	free(count);
	free(output);
}

int main(int argc, char **argv) {
    int *stack_a;
    //int stack_a[] = {170, 45, 75, 90, 802, 24, 2, 66};

    stack_a = malloc((argc - 1) * sizeof(int*));
    if (!is_valid_arguments(argv, stack_a)) { // Si no, liberar las pilas    
        free(stack_a);        
        return (printf("Error\n"));
    }
    if (is_sorted(stack_a, (argc - 1))) { // Está ordenado?, si es así liberar las pilas
        free(stack_a);
        return (printf("Ordenado\n"));
    }    
    // Ejemplo de uso    
    //int n = sizeof(stack_a) / sizeof(stack_a[0]);
	
    radixSort(stack_a, (argc - 1));

    // Imprime el arreglo ordenado
    printf("Arreglo ordenado: ");
    for (int i = 0; i < (argc - 1); i++) {
        printf("%d ", stack_a[i]);
    }
    printf("\n");

    // Liberar la memoria del arreglo
    free(stack_a);

    return 0;
}
