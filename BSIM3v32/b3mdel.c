/* $Id: b3mdel.c, v3.2 1998/6/16 18:00:00 Weidong Liu Release $  */
/*
 $Log:  b3mdel.c, v3.2 $
 * Revision 3.2 1998/6/16  18:00:00  Weidong 
 * BSIM3v3.2 release
 *
*/
static char rcsid[] = "$Id: b3mdel.c, v3.2 1998/6/16 18:00:00 Weidong Liu Release $";

/*************************************/

/**********
Copyright 1990 Regents of the University of California.  All rights reserved.
Author: 1995 Min-Chie Jeng and Mansun Chan.
File: b3mdel.c
**********/

#include "spice.h"
#include <stdio.h>
#include "util.h"
#include "bsim3def.h"
#include "sperror.h"
#include "suffix.h"

int
BSIM3mDelete(inModel,modname,kill)
GENmodel **inModel;
IFuid modname;
GENmodel *kill;
{
BSIM3model **model = (BSIM3model**)inModel;
BSIM3model *modfast = (BSIM3model*)kill;
BSIM3instance *here;
BSIM3instance *prev = NULL;
BSIM3model **oldmod;

    oldmod = model;
    for (; *model ; model = &((*model)->BSIM3nextModel)) 
    {    if ((*model)->BSIM3modName == modname || 
             (modfast && *model == modfast))
	     goto delgot;
         oldmod = model;
    }
    return(E_NOMOD);

delgot:
    *oldmod = (*model)->BSIM3nextModel; /* cut deleted device out of list */
    for (here = (*model)->BSIM3instances; here; here = here->BSIM3nextInstance)
    {    if(prev) FREE(prev);
         prev = here;
    }
    if(prev) FREE(prev);
    FREE(*model);
    return(OK);
}



