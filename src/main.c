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

struct arguments arguments;

int	main(int argc, char **argv)
{
	static struct ipmask 	ipmask[2];

	parse(&arguments, argc, argv);
	if (!arguments.args[MASK])
		arguments.args[MASK] = MASK_DFL;
	ipmask[IP].addr = arguments.args[IP];
	ipmask[MASK].addr = arguments.args[MASK];
	get_raw_bits(ipmask);
	print_line(ipmask[IP], "Address: ");
	print_line(ipmask[MASK], "Netmask: ");
	print_line(get_wildcard(ipmask[MASK]), "Wildcard:");
	return 0;
}
