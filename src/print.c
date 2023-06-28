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
#include <unistd.h>

#include "ipcalc.h"

static void print_bits(unsigned int n)
{
	for (int i = 31; i >= 0; i--)
	{
		if ((n >> i) & 1)
			printf("1");
		else
		 	printf("0");
		if (!(i % 8) && i)
			printf(".");
	}
}

void	print_line(struct ipmask ipmask, char *title)
{
	printf("%s:\t%s\t", title, ipmask.addr);
	print_bits(ipmask.rawbits);
	printf("\n");
}
