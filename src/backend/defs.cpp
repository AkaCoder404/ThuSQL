#include "defs.h"
#define VLOG 1
#define DLOG 1
#define ELOG 1
#define TLOG 1

void eprint(const char *mes) {
    printf("\033[1;31m[ERROR]\033[0m %s\n", mes); // red
}

void tprint(const char *mes) {
    printf("\033[1;35m[DEBUG]\033[0m %s\n", mes); // purple
}

void dprint(const char *mes) {
    if (!DLOG) return;
    printf("\033[0;32m[DONE]\033[0m %s\n", mes); // green
}

void vprint(const char *mes) {
    if (!VLOG) return;
    printf("\033[0;33m[VISIT]\033[0m %s\n", mes); // yellow
}

