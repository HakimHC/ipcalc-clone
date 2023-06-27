#include <argp.h>

#include "ipcalc.h"

const char	*argp_program_version		= "v0.0";
const char 	*argp_program_bug_address 	= "hakahmed@student.42madrid.com";


const char		doc[]		= "My IPCALC: a mini ipcalc clone made for educational purposes";

const char		args_doc[]	= "IP MASK";

static struct argp_option options[] 	= {
					{"nobinary",	'b', 0, 0, "Surpress the bitwise output", 0},
					{"color",	'c', 0, 0, "Display ANSI color codes", 0},
					/* {"nocolor", 	'n', 0, 0, "Don't display ANSI color codes"}, */
					{ 0 }
};

static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	struct arguments *args = state->input;

	switch (key)
	{
		case 'c':
			args->color = 1;
			break;
		case 'b':
			args->nobinary = 1;
			break;

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

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

void	parse(struct arguments *arguments, int argc, char **argv)
{
	arguments->color = 0;
	arguments->nobinary = 0;

	argp_parse(&argp, argc, argv, 0, 0, arguments);
}
