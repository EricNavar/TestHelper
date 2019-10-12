#include <chrono>

//these functions calculate take in a function as a parameter, run it,
//and return in milliseconds how long it took
//type R is the return type
//type P is the parameter type
//type C is the class that the method belongs to, if applicable

//for free functions
template<typename R, typename P>
clock_t timeFunction(P &p, R(test)(P p))
{
	clock_t start, finish;
	start = clock();
	test(p);
	finish = clock();
	return finish - start;
}

//for member methods
template<typename R, typename P, typename C>
clock_t timeFunction(C &c, P &p, R(C:: * test)(P p))
{
	clock_t start, finish;
	start = clock();
	(c.*test)(p);
	finish = clock();
	return finish - start;
}

//for member methods with reference parameter   ↓
template<typename R, typename P, typename C>
clock_t timeFunction(C &c, P &p, R(C:: *test)(P &p))
{
	clock_t start, finish;
	start = clock();
	(c.*test)(p);
	finish = clock();
	return finish - start;
}