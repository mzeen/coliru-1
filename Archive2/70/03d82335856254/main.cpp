#include <iostream>
#include <utility>

struct foo {
    int value;
    foo(int v) : value(v) {
        std::cout << "foo(" << value << ")\n" << std::flush;
    }
    ~foo() {
        std::cout << "~foo(" << value << ")\n" << std::flush;
    }
    foo(const foo& other) : value(other.value) {
        std::cout << "copy foo(" << value << ")\n" << std::flush;
    }
    foo(foo&& other) : value(other.value) {
        std::cout << "move foo(" << value << ")\n" << std::flush;
    }
    foo& operator = (const foo&) = delete;
    friend std::ostream& operator << (std::ostream& os,
                                      const foo& f) {
        os << f.value;
        return os;
    }
};

template <typename A, typename B>
struct node { A a; B b; };

template <typename... A>
node<A...> make(A&&... a)
{
    return node<A...>{std::forward <A>(a)...};
}

template <typename N>
auto fst(N&& n)
-> decltype((std::forward <N>(n).a))
    { return std::forward <N>(n).a; }

template <typename N>
auto snd(N&& n)
-> decltype((std::forward <N>(n).b))
    { return std::forward <N>(n).b; }

int main() {
    using namespace std;
    // A: works fine (prints '2')
    foo f(0);
    cout << fst(snd(make(foo(3), make(foo(2), f)))) << endl;
    
    // B: fine in Clang, segmentation fault in GCC with -Os
    auto z = make(foo(3), make(foo(2), f));
    cout << "referencing: " << flush;
    cout << fst(snd(z)) << endl;
}
