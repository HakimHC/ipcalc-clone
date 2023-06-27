/* This file is part of my-ipcalc. */

/* my-ipcalc is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or */
/* (at your option) any later version. */

/* my-ipcalc is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU General Public License for more details. */

/* You should have received a copy of the GNU General Public License */
/* along with my-ipcalc.  If not, see <https://www.gnu.org/licenses/>. */

#include <stdio.h>

#include "ipcalc.h"

int	main(int argc, char **argv)
{
	static struct arguments args;

	parse(&args, argc, argv);
	/* print arguments */
	printf("%s\n", args.args[IP]);
	printf("%s\n", args.args[MASK]);
	/* print options --> 1.) color 2.) nobinary */
	printf("%d\n", args.color);
	printf("%d\n", args.nobinary);
}
