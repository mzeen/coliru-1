#include <iostream>

// file foo_base.h:

struct foo_base 
{ 
    constexpr foo_base() = default; 
};

constexpr foo_base faux(foo_base const&)
{ 
    return foo_base{}; 
}

template<class T, class = decltype(faux(T{}))>
struct aux;

template<class T>
struct aux<T, foo_base> 
{ 
    enum { value = 1 }; 
};

// file foo.h:

template<typename T> 
struct foo : foo_base  
{ 
    constexpr foo() = default; 
};

// file bar.h:

template<typename T> 
struct bar : foo<T> 
{ 
    constexpr bar() = default; 
};

template<class T>
constexpr bar<T> faux(bar<T> const&) 
{ 
    return bar<T>{}; 
}

template<class T, class U>
struct aux<T, bar<U>> 
{ 
    enum { value = 2 }; 
};

// file meow.h

template<class T>
struct meow : bar<T>
{
    constexpr meow() = default;    
};

int main()
{
    std::cout << aux<foo_base>::value;  // 1
    std::cout << aux<foo<int>>::value;  // 1
    std::cout << aux<bar<int>>::value;  // 2
    std::cout << aux<meow<int>>::value; // 2
}
