set -x
clang++ -O3 -Wall -Wextra -pedantic -Wconversion -std=c++11 -pthread main.cpp && ./a.out
g++-4.8 -O3 -Wall -Wextra -pedantic -Wconversion -std=c++11 -pthread main.cpp && ./a.out