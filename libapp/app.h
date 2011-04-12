#ifndef APP_H
#define APP_H

#include <libapp/base.h>
#include <stdio.h>

/*
 * libapp: an utility library to simplify
 * common tasks in app development.
 * (C) 2010 - Domenico Rotiroti
 * Licensed under the LGPL 3.0
 */

typedef struct app_t app;

typedef enum {
	OPT_FLAG,
	OPT_STRING,
	OPT_PASSWD,
	OPT_INT,
	OPT_CALLBACK
} opt_type;

typedef struct {
	char short_name;
	char * long_name;
	opt_type type;
	void * val;
	char * description;
} opt;

typedef void (*app_callback)( app*, const char* );
/* Auto help function */
extern app_callback app_help;

/* Functions */
app*	app_new();
void	app_free(app* theapp);

void	app_opt_add(app* theapp, opt* theopt);
void	app_opts_add(app* theapp, opt opts[], int len);
void	app_opt_add_help(app* theapp);
void	app_opt_on_error(app* theapp, app_callback error_handler);

bool	app_parse_opts(app * theapp, int *argc, char** argv[]);
bool	app_parse_opts_from(app * theapp, FILE * stream);

const char *	app_get_program_name(app * theapp);
void	app_set_description(app * theapp, const char * desc);

void	app_term_set_echo(bool enable);
char*	app_term_askpass(const char * prompt);
char*	app_term_readline();
char*   app_term_readline_from(FILE* stream);

void	app_daemonize();
#endif //APP_H
