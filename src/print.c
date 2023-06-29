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
#include <string.h>
#include <stdlib.h>

#include "ipcalc.h"
#include "libft.h"

static void printfcolor(const char *msg, const char *color)
{
	char	*tmp;
	char	*aux;

	if (!color)
		return (void)printf("%s", msg);
	tmp = strdup(msg);
	aux = tmp;
	tmp = ft_strjoin(color, tmp);
	free(aux);
	aux = tmp;
	tmp = ft_strjoin(tmp, RESET);
	free(aux);
	printf("%s\t", tmp);
	free(tmp);
}

static void print_bits(unsigned int n, char *color)
{
	if (color)
		printf("%s", color);
	for (int i = 31; i >= 0; i--)
	{
		if ((n >> i) & 1)
			printf("1");
		else
		 	printf("0");
		if (!(i % 8) && i)
		{
			printf("%s.", RESET);
			if (color)
				printf("%s", color);
		}
	}
	if (color)
		printf("%s", RESET);
}

void	print_line(struct ipmask ipmask, char *title)
{
	char	*color;

	color = NULL;
	printfcolor(title, NULL);
	if (arguments.color)
		color = BLUE;
	printf("\t");
	printfcolor(ipmask.addr, color);
	if (arguments.color)
		!strncmp(title, "Netmask", 7) ? (color = RED) : (color = YELLOW);
	else
		color = NULL;
	printf("\t");
	print_bits(ipmask.rawbits, color);
	printf("\n");
}
