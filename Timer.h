#define GET_VARIABLE_NAME(Variable) (#Variable)
#include <iostream>
#include <chrono>

template<typename T>
class Timer
{
public:
    void timeFunction(T(user_test)()) const;
};

template<typename T>
void Timer<T>::timeFunction(T(user_test)()) const
{
    const clock_t start = clock();
    user_test();
    const clock_t finish = clock();
    cout << "finish: " << finish << endl;
    cout << "start: " << start << endl;
    printf("%s took %f milliseconds.\n",GET_VARIABLE_NAME(user_test),finish-start);
}