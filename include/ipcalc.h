#ifndef __IPCALC_H__
# define __IPCALC_H__

# include <argp.h>

struct arguments
{
	char *args[2];
	int color, nobinary;
};

void	parse(struct arguments *arguments, int argc, char **argv);

#endif
