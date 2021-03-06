/******************************
*
*   This is the header file for the routine that reads the forcefield file
*   into memory in order to speed up searching.
*
*   It defines the data structures used to store the force field in memory
*/

#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>


#ifdef	FF_MAIN
#define _EX
#else
#define _EX	extern
#endif

#define MAX_NO_MEMS 5
#define MAX_NO_PARAMS 8
#define MAX_LINE 200

struct FrcFieldData
{
  float 	ver;		/* Version number of forcefield entry */
  int		ref;		/* Reference within forcefield */
  char	        ff_types[MAX_NO_MEMS][5];
  double        ff_param[MAX_NO_PARAMS];
};

struct FrcFieldItem
{
  char		keyword[25];
  int		number_of_members;	/* number of members of item */
  int		number_of_parameters;	/* number of parameters of item */
  int 		entries;		/* number of entries in item list */
  struct FrcFieldData *data;		/* contains all eqiuv and param data */
};

_EX	struct	FrcFieldItem ff_atomtypes, equivalence, \
		ff_vdw,ff_bond, ff_ang, ff_tor, ff_oop, \
		ff_bonbon, ff_bonang, ff_angtor, ff_angangtor, \
                ff_endbontor, ff_midbontor, ff_angang, ff_bonbon13;

#undef _EX
