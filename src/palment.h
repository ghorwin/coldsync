/* palment.h
 *
 *	Copyright (C) 2001, Andrew Arensburger.
 *	You may distribute this file under the terms of the Artistic
 *	License, as specified in the README file.
 *
 * Definitions and declarations pertaining to /etc/palms, the database
 * of Palms.
 *
 * The structure of /etc/palms is reminiscent of /etc/passwd: each
 * line represents one Palm; fields in each line are separated by '|'.
 * The fields are, in order,
 *	serial|username|userid|luser|name|conf_fname
 *
 * serial:	The Palm's serial number
 * username:	The username on the Palm
 * userid:	The user ID on the Palm
 * luser:	Local (Unix) user to setuid() to
 * name:	Palm's name in .coldsyncrc
 * conf_fname:	Config file to use
 *
 * 'name' and 'conf_fname' are optional.
 *
 * $Id: palment.h,v 2.4 2002-03-30 16:11:43 azummo Exp $
 */
#ifndef _palment_h_
#define _palment_h_

#include "config.h"
#include "pconn/pconn.h"	/* For Palm types */

/* Path to /etc/palms */
#define _PATH_PALMS	SYSCONFDIR "/palms"

struct palment
{
	const char *serial;		/* Palm serial number */
	const char *username;		/* Username on Palm */
	unsigned long userid;		/* User ID on Palm */
	const char *luser;		/* Local user (Unix user) */
	const char *name;		/* Palm name */
	const char *conf_fname;		/* Path to config file to use */
	/* XXX - Should this also include an entry for a Palm to forward
	 * the connection to?
	 */
};

extern const struct palment *getpalment(void);
/* XXX - extern const struct palment *getpalmbyname(const char *name); */
extern void setpalment(int stayopen);
extern void endpalment(void);
extern struct palment * find_palment(const char *p_snum,
	const char *p_username, const udword p_userid);

#endif	/* _palment_h_ */

/* This is for Emacs's benefit:
 * Local Variables:	***
 * fill-column:	75	***
 * End:			***
 */
