#include <iostream>
#include "sSort.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    musicListener carlos("MusicHistory");
    print_Sorted(carlos);
    getSongMinutes(carlos);
    return 0;
}