clang++ main.cpp -shared -fPIC -o get_dir_list.so -I/usr/include/python2.7 -lboost_python && python -c "import get_dir_list,os;get_dir_list.get_dir_list(os.listdir('../../'))"