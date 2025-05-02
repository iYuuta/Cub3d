#include "Cupid.h"
#include <stdio.h>

void	ft_error(char *message)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static int	valid_map_name(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (str[i--] == 'r' && str[i--] == 'e' && str[i--] == 'b' && str[i] == '.')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Invalid Argument: takes one argument");
	if (!valid_map_name(argv[1]))
		ft_error("Invalid map name: must end with .ber");
	return (EXIT_SUCCESS);
}
