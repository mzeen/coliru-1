set -x ;
g++ -std=c++1y -O3 -Wall -pedantic -Wextra -pthread -Wno-unused-variable -Wno-unused-parameter -Wconversion -fno-elide-constructors main.cpp && ./a.out
# clang++ -std=c++1y -O3 -Wall -pedantic -Wextra -pthread -Wno-unused-variable -Wno-unused-parameter -Wconversion -stdlib=libc++ -fno-elide-constructors main.cpp -lsupc++ && ./a.out