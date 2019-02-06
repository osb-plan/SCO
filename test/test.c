#include <stdio.h>
#include "interface.h"
#include "sco_generic_defs.h"

int main()
{
    _printc(_STDOUT,"Just a Test\n", BOLD_GREEN);
    return 0;
}
