#include "ipcalc.h"

int	main(int argc, char **argv)
{
	static struct arguments arguments;
	parse(&arguments, argc, argv);

	printf("%d\n", arguments.color);
	printf("%d\n", arguments.nobinary);
	return 0;
}
