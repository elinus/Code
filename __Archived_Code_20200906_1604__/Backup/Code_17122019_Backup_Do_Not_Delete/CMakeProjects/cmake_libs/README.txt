echo $LD_LIBRARY_PATH
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/elinus/__code__/CppRevision/libs
echo $LD_LIBRARY_PATH
export LD_LIBRARY_PATH

g++ Main.cpp -L./bin -lHelloworld
./a.out
