#include "cmin.h"
#include "istatistics.h"
Min::Min(double m_val) : m_min{m_val} {}

void Min::update(double next) {
    if (next < m_min) {
        m_min = next;
    }
}

double Min::eval() const {
    return m_min;
}

const char* Min::name() const {
    return "min";
}