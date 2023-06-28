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

#ifndef __IPCALC_H__
# define __IPCALC_H__

# include <argp.h>

/* Enumeration of the indexes of the arguments structure */
enum idx_ipmask
{
	IP,
	MASK
};

/* Default values for the netmask */
# define MASK_DFL 	"255.255.255.0"
# define MASK_DFL_BITS 	4294967040

/* Used by main to communicate with parse_opt. */
struct arguments
{
	char 		*args[2];
	int 		color;
	int 		nobinary;
};

/* Used to join the string of the address with the raw bits */
struct ipmask
{
	const char	*addr;
	unsigned int 	rawbits;
};

/* Argument parser */
void	parse(struct arguments *arguments, int argc, char **argv);

/* Argument validator */
void	get_raw_bits(struct ipmask *ipmask);

/* Error handling */
void	errmsg(const char *msg);

/* Utilities for printing */
void	print_line(struct ipmask ipmask, char *title);

/* Utilities */
struct ipmask get_wildcard(struct ipmask ipmask);

#endif
