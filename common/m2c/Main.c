#include "SYSTEM_.h"

#ifndef DEFINITION_Convert
#include "Convert.h"
#endif

#ifndef DEFINITION_Characte
#include "Characte.h"
#endif

#ifndef DEFINITION_Checks
#include "Checks.h"
#endif

#ifndef DEFINITION_Errors
#include "Errors.h"
#endif

#ifndef DEFINITION_Listing
#include "Listing.h"
#endif

#ifndef DEFINITION_Path
#include "Path.h"
#endif

#ifndef DEFINITION_Queues
#include "Queues.h"
#endif

#ifndef DEFINITION_Stack
#include "Stack.h"
#endif

#ifndef DEFINITION_SysError
#include "SysError.h"
#endif



void BEGIN_MODULE ARGS ((void))
{
BEGIN_Convert ();
BEGIN_Characte ();
BEGIN_Checks ();
BEGIN_Errors ();
BEGIN_Listing ();
BEGIN_Path ();
BEGIN_Queues ();
BEGIN_Stack ();
BEGIN_SysError ();

}
