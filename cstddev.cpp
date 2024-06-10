#include "cstddev.h"
#include "math.h"
#include <numeric>

StdDev::StdDev(double val) : m_values{val} {}

void StdDev::update(double next) {
    m_values.push_back(next);
}

double StdDev::eval() const {
    double summ{std::accumulate(m_values.begin(), m_values.end(), 0.)};
    double mean{summ / m_values.size()};
    double summSquare{0};
    for (auto val : m_values) {
        summSquare += pow(val - mean, 2);
    }
    return sqrt(summSquare / m_values.size());
}

const char* StdDev::name() const {
    return "std";
}