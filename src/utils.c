#include "ipcalc.h"

struct ipmask get_wildcard(struct ipmask ipmask)
{
	ipmask.rawbits = ~ipmask.rawbits;
	return ipmask;
}
