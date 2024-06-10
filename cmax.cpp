#include "cmax.h"
#include "istatistics.h"

Max::Max(double m_val) : m_max{m_val} {}

void Max::update(double next) {
    if (next > m_max) {
        m_max = next;
    }
}

double Max::eval() const {
    return m_max;
}

const char* Max::name() const {
    return "max";
}