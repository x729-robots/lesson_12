#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

#include "cmax.h"
#include "cmean.h"
#include "cmin.h"
#include "cpctn.h"
#include "cstddev.h"
#include "istatistics.h"

int main() {

    double val = 0;//TODO not very nice, don't want get first val separately
    std::cin >> val;
    IStatistics* statistics[] = {
        new Min{val},    new Max{val},       new Mean{val},
        new StdDev{val}, new CPctN{val, 90}, new CPctN{val, 95}};

    const size_t statistics_count = sizeof(statistics)/sizeof(*statistics);

    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval()
                  << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }

    return 0;
}