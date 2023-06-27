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

#include <string.h>

#include "ipcalc.h"

void	get_raw_bits(struct ipmask *ipmask)
{
	if (!strcmp(ipmask[MASK].addr, MASK_DFL))
		ipmask[MASK].rawbits = MASK_DFL_BITS;
}
