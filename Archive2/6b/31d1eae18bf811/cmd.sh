set -x ; clang++ --version && clang++ -std=c++11 -O2 -Wall -pedantic -pthread -o main main.cpp && ./main