#pragma once
#include "cmean.h"
#include "istatistics.h"
Mean::Mean(double m_val) : m_mean{m_val}, m_summ{m_val}, m_n{1} {}

void Mean::update(double next) {
    m_summ += next;
    m_n++;
}

double Mean::eval() const {
    return m_summ / m_n;
}

const char* Mean::name() const {
    return "mean";
}
