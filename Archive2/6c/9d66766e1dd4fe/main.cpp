#include <type_traits>

template <bool B>
using expr = std::integral_constant <bool, B>;

template <bool B>
using _not = expr <!B>;

template <template <typename> class F>
struct neg_f
{
    template <typename T>
    using map = _not <F <T>{}>;
};

template <typename T>
using pred = expr <true>;

template <template <typename> class F>
struct fun;

template< template<typename> class F>
using neg = typename neg_f<F>::map;

int main ()
{
    fun<neg<pred> >{};
}
