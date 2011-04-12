#ifndef BOXHTTP_H
#define BOXHTTP_H

#include <stdio.h>
#include <stdarg.h>
#include "boxapi.h"

/* 2010-02-03 Domenico Rotiroti
   Licensed under the GPLv2

   HTTP(S) transfer functions and related utilities
*/

/* A type for data to be posted */
struct postdata {
   struct curl_httppost * post;
   struct curl_httppost * last;
};
typedef struct postdata * postdata_t;

postdata_t	post_init();
void		post_free(postdata_t postdata);

/* Fetching (GET) of pages and files */
char *	http_fetch(const char * url);
char *	http_fetchf(const char * fmt, ...);
int	http_fetch_file(const char * url, const char * dest, int append);

/* Data POSTing */
void post_add(postdata_t buf, const char * name, const char * val);
long post_addfile(postdata_t rbuf, const char * name, const char * tmpfile);
char * post_addfile_part(postdata_t rbuf, const char * name,
        const char * tmpfile, size_t offset, size_t len);
void http_post(const char * url, postdata_t data);
char * http_postfile(const char * url, postdata_t data);


#endif
//BOXHTTP_H
