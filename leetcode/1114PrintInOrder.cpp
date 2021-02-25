#include "stdafx.h"

/**
 * The same instance of Foo will be passed to three different threads. 
 * Thread A will call first(), thread B will call second(), and thread C will call third(). 
 * Design a mechanism and modify the program to ensure that 
 * 	- second() is executed after first(), 
 * 	- third() is executed after second().
 * 
 */

// a classic semaphore use case for thread synchronisation
class Foo
{
private:
    mutex m;
    bool is_f, is_s;
    condition_variable cv_f, cv_s;

public:
    Foo() : is_f(false), is_s(false)
    {
    }

    void first(function<void()> printFirst)
    {
        unique_lock<mutex> lk(m);
        printFirst();
        is_f = true;
        cv_f.notify_all();
    }

    void second(function<void()> printSecond)
    {
        unique_lock<mutex> lk(m);
        cv_f.wait(lk, [this] { return is_f; });
        printSecond();
        is_s = true;
        cv_s.notify_all();
    }

    void third(function<void()> printThird)
    {
        unique_lock<mutex> lk(m);
        cv_s.wait(lk, [this] { return is_f; });
        cv_s.wait(lk, [this] { return is_s; });
        printThird();
    }
};
