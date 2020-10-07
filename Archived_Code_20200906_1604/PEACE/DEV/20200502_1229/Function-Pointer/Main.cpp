#include <iostream>
#include <functional>
#include <map>
#include <chrono>
#include <string>
#include "Functions.h"

#define DEF_FOO_1 "Foo1"
#define DEF_FOO_2 "Foo2"
#define DEF_FOO_3 "Foo3"
#define DEF_FOO_4 "Foo4"
#define DEF_FOO_5 "Foo5"
#define DEF_FOO_6 "Foo6"
#define DEF_FOO_7 "Foo7"
#define DEF_FOO_8 "Foo8"
#define DEF_FOO_9 "Foo9"
#define DEF_FOO_10 "Foo10"
#define DEF_FOO_11 "Foo11"
#define DEF_FOO_12 "Foo12"
#define DEF_FOO_13 "Foo13"
#define DEF_FOO_14 "Foo14"
#define DEF_FOO_15 "Foo15"
#define DEF_FOO_16 "Foo16"
#define DEF_FOO_17 "Foo17"
#define DEF_FOO_18 "Foo18"
#define DEF_FOO_19 "Foo19"
#define DEF_FOO_20 "Foo20"

using fn_vd_ptr_vd = void (*)();

int main (int argc, char *argv[]) {
    auto start = std::chrono::high_resolution_clock::now();
    std::map<Pointer, std::function<void()>> fp_map;
    fp_map[Pointer::FOO_1_PTR] = &foo1;
    fp_map[Pointer::FOO_2_PTR] = &foo2;
    fp_map[Pointer::FOO_3_PTR] = &foo3;
    fp_map[Pointer::FOO_4_PTR] = &foo4;
    fp_map[Pointer::FOO_5_PTR] = &foo5;
    fp_map[Pointer::FOO_6_PTR] = &foo6;
    fp_map[Pointer::FOO_7_PTR] = &foo7;
    fp_map[Pointer::FOO_8_PTR] = &foo8;
    fp_map[Pointer::FOO_9_PTR] = &foo9;
    fp_map[Pointer::FOO_10_PTR] = &foo10;
    fp_map[Pointer::FOO_11_PTR] = &foo11;
    fp_map[Pointer::FOO_12_PTR] = &foo12;
    fp_map[Pointer::FOO_13_PTR] = &foo13;
    fp_map[Pointer::FOO_14_PTR] = &foo14;
    fp_map[Pointer::FOO_15_PTR] = &foo15;
    fp_map[Pointer::FOO_16_PTR] = &foo16;
    fp_map[Pointer::FOO_17_PTR] = &foo17;
    fp_map[Pointer::FOO_18_PTR] = &foo18;
    fp_map[Pointer::FOO_19_PTR] = &foo19;
    fp_map[Pointer::FOO_20_PTR] = &foo20;
    for (auto it = fp_map.begin(); it != fp_map.end(); ++it) {
        it->second();
    }
    auto it1 = fp_map.find(Pointer::FOO_9_PTR);
    if (it1 != fp_map.end()) {
        std::cout << "----->>\n";
        it1->second();
        std::cout << "<<-----\n";
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = finish - start;
    std::cout << "Elapsed Time: " << elapsed.count() << " ms." << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::map<std::string, fn_vd_ptr_vd> fptr_map;
    fptr_map[DEF_FOO_1] = &foo1;
    fptr_map[DEF_FOO_2] = &foo2;
    fptr_map[DEF_FOO_3] = &foo3;
    fptr_map[DEF_FOO_4] = &foo4;
    fptr_map[DEF_FOO_5] = &foo5;
    fptr_map[DEF_FOO_6] = &foo6;
    fptr_map[DEF_FOO_7] = &foo7;
    fptr_map[DEF_FOO_8] = &foo8;
    fptr_map[DEF_FOO_9] = &foo9;
    fptr_map[DEF_FOO_10] = &foo10;
    fptr_map[DEF_FOO_11] = &foo11;
    fptr_map[DEF_FOO_12] = &foo12;
    fptr_map[DEF_FOO_13] = &foo13;
    fptr_map[DEF_FOO_14] = &foo14;
    fptr_map[DEF_FOO_15] = &foo15;
    fptr_map[DEF_FOO_16] = &foo16;
    fptr_map[DEF_FOO_17] = &foo17;
    fptr_map[DEF_FOO_18] = &foo18;
    fptr_map[DEF_FOO_19] = &foo19;
    fptr_map[DEF_FOO_20] = &foo20;

    for (auto it = fptr_map.begin(); it != fptr_map.end(); ++it) {
        it->second();
    }
    auto it2 = fptr_map.find(DEF_FOO_9);
    if (it2 != fptr_map.end()) {
        std::cout << "----->>\n";
        it2->second();
        std::cout << "<<-----\n";
    }
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "Elapsed Time: " << elapsed.count() << " ms." << std::endl;
    return 0;
}

