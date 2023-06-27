#include <argp.h>

static const char	*version	= "v0.0";
static const char 	*bug_address 	= "hakahmed@student.42madrid.com";
const char		*doc		= "My IPCALC: a mini ipcalc clone made for educational purposes";

static char		*args_doc	= "IP MASK";

static struct argp_option options[] 	= {
					{"nobinary",	'b', 0, 0, "Surpress the bitwise output"},
					{"color",	'c', 0, 0, "Display ANSI color codes"},
					/* {"nocolor", 	'n', 0, 0, "Don't display ANSI color codes"}, */
					{ 0 }
};

struct arguments
{
	char *args[2];
	int color, nobinary;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *args = state->input;

	switch (key)
	{
		case 'c':
			args->color = 1;
		case 'n':
			args->nobinary = 1;

		case ARGP_KEY_ARG:
			if (state->arg_num >= 2)
				argp_usage(state);
			args->args[state->arg_num] = arg;
			break;
		case ARGP_KEY_END:
			if (state->arg_num < 1)
				argp_usage(state);
			break;
		default:
			return ARGP_ERR_UNKNOWN;

	}
	return 0;
}
