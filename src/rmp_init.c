#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME:
 Check these declarations against the C/Fortran source code.
 */

/* .C calls */
extern void npmpois_C(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void rmg_C(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);

static const R_CMethodDef CEntries[] = {
  {"npmpois_C", (DL_FUNC) &npmpois_C, 13},
  {"rmg_C",     (DL_FUNC) &rmg_C,     16},
  {NULL, NULL, 0}
};

void R_init_rmp(DllInfo *dll)
{
  R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
