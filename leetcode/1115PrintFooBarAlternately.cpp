#include "stdafx.h"

/**
 * The same instance of FooBar will be passed to two different threads. 
 * Thread A will call foo() while thread B will call bar(). 
 * Modify the given program to output "foobar" n times.
 */

class FooBar
{
private:
    int n;
    bool is_foo_print, is_bar_print;
    mutex m;
    condition_variable cv_foo, cv_bar;

private:
    void wait(condition_variable &cv, bool &s)
    {
        unique_lock<mutex> lk(m);
        cv.wait(lk, [&] { return s; });
        s = !s;
    }

    void signal(condition_variable &cv, bool &s)
    {
        unique_lock<mutex> lk(m);
        s = !s;
        cv.notify_one();
    }

public:
    FooBar(int n) : is_foo_print(true), //print foo first, so the inital sephomore is true
                    is_bar_print(false)
    {
        this->n = n;
    }

    void foo(function<void()> printFoo)
    {
        for (int i = 0; i < n; i++)
        {
            wait(cv_foo, is_foo_print); //wait if sephomore is_foo_print is false
            printFoo();
            signal(cv_bar, is_bar_print); //notify a bar output
        }
    }

    void bar(function<void()> printBar)
    {

        for (int i = 0; i < n; i++)
        {
            wait(cv_bar, is_bar_print); //wait if sephomore is false
            printBar();
            signal(cv_foo, is_foo_print); //notify a foo output
        }
    }
};