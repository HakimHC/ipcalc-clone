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

#include <math.h>
#include <string.h>

#include "ipcalc.h"

static int get_exp(const char *addr)
{
	int	i;

	i = 0;
	while (addr[i] && addr[i] != '.' && addr[i] != '/')
		i++;
	return (pow(10, i - 1));
}

static unsigned int parse_bits(const char *addr)
{
	int	i 		= 0;
	int	j 		= 0;
	unsigned int res 	= 0;
	int	tmp		= 0;
	int	shift 		= 24;

	while (addr[i] && addr[i] != '/')
	{
		j = 0;
		int pos = get_exp(addr + i);
		tmp = 0;
		while (addr[i + j] && addr[i + j] != '.')
		{
			if (!isdigit(addr[i + j]))
				errmsg(addr);
			tmp += pos * (addr[i + j] - '0');
			pos /= 10;
			j++;
		}
		printf("%d\n", tmp);
		if (tmp > 255)
			errmsg(addr);
		if (!addr[i + j])
			return 0;
		i += j + 1;
	}
	(void) shift;
	return res;
}

void	get_raw_bits(struct ipmask *ipmask)
{
	if (!strcmp(ipmask[MASK].addr, MASK_DFL))
		ipmask[MASK].rawbits = MASK_DFL_BITS;
	parse_bits(ipmask[IP].addr);
}
