#define GET_VARIABLE_NAME(Variable) (#Variable)
#include "Timer.h"

void Timer::timeFunction(void(user_test)()) const
{
    const clock_t start = clock();
    user_test();
    const clock_t finish = clock();
    printf("%s took %f seconds.\n",GET_VARIABLE_NAME(user_test),finish-start);
}