clang++ -std=c++03 -pedantic main.cpp && for a in {1..5}; do ./a.out <<< "1 2 3 4 5 $a"; done