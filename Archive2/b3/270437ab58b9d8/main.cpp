#include <string>
#include <boost/variant.hpp>

struct HourlyInfo {
    int    hoursWorked;
    double hourlyRate;
};

struct SalaryInfo {
    double salary;
    double bonus;
};

namespace detail {

    template <template <typename...> class Allocator = std::allocator>
    struct basic_employee {
        using string = std::basic_string<char, std::char_traits<char>, Allocator<char>>;
        string firstName;
        string lastName;
        string title;

        using RateInfo = boost::variant<HourlyInfo, SalaryInfo>;
        RateInfo rates;
    };
}

using Employee = detail::basic_employee<>;

int main()
{
    Employee staff1 = { 
        "John", "Cage", "From accounting", 
        SalaryInfo { 1900.00, 120.0 } 
    };
    Employee contractor = { 
        "Joe", "Duffy", "Plumbing jobs", 
        HourlyInfo { 3, 46.00 } 
    };
}
