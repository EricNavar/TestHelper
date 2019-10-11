#define GET_VARIABLE_NAME(Variable) (#Variable)
#include <iostream>
#include <chrono>

//for free functions
template<typename R, typename P>
void timeFunction(P p, R(test)(P p))
{
	const clock_t start = clock();
	test(p);
	const clock_t finish = clock();
	std::cout << GET_VARIABLE_NAME(user_test) << " took " << finish - start << " milliseconds.\n";
}

//for member methods
template<typename R, typename P, typename C>
void timeFunction(C c, P p, R(C:: * test)(P p))
{
	const clock_t start = clock();
	(c.*test)(p);
	const clock_t finish = clock();
	std::cout << GET_VARIABLE_NAME(user_test) << " took " << finish - start << " milliseconds.\n";
}

//for member methods with reference parameter
template<typename R, typename P, typename C>
void timeFunction(C c, P p, R(C:: * test)(P &p))
{
	const clock_t start = clock();
	(c.*test)(p);
	const clock_t finish = clock();
	std::cout << GET_VARIABLE_NAME(user_test) << " took " << finish - start << " milliseconds.\n";
}