#include <boost/scoped_array.hpp>

int main (int argc, char const *argv[])
{
    boost::scoped_array<int> p{new int[2]};
    *p.get() = 14;
    p[1] = 20;
    p.reset(new int[3]);
    return 0;
}

