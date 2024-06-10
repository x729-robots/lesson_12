#include "cpctn.h"
#include <algorithm>
#include <cmath>
#include <string>

CPctN::CPctN(double val, int pctN) : m_values{val}, m_pctN{pctN} {}

void CPctN::update(double next) {
    m_values.push_back(next);
}

double CPctN::eval() const {
    std::vector<double> values{m_values};
    std::sort(values.begin(), values.end());
    int pc_i = round(m_values.size() * m_pctN / 100.) - 1;
    return (m_values[pc_i]);
}

const char* CPctN::name() const {
    std::string out = "Pct";
    out += std::to_string(m_pctN);
    return out.c_str();
}
