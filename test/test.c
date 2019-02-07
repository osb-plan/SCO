#include <stdio.h>
#include "interface.h"
#include "sco_generic_defs.h"

int main()
{
    _printc(_STDOUT,"Just a Test", BOLD_GREEN, 1);
    return 0;
}
