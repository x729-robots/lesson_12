#pragma once
#include "istatistics.h"
#include "vector"

class CPctN : public IStatistics {
  public:
    CPctN(double val, int pctN);
    virtual void update(double next) override;
    virtual double eval() const override;
    virtual const char* name() const override;

  private:
    std::vector<double> m_values;
    int m_pctN;
    double m_summ; // summ of all values
    double m_n;    // number of all values
};