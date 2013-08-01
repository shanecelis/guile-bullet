#include "sim-smob.h"
#include <libguile.h>

int main(int argc, char *argv[])
{
  scm_init_guile();
  scm_make_sim();
  return 0;
}
