#include "tsa.h"

tsa_mutex mut;

void release(void) TSA_RELEASE(&mut)
{
#ifndef TSA_PASS
#else
    tsa_mutex_unlock(&mut);
#endif
}

int main()
{
    tsa_mutex_lock(&mut);
    release();
}
