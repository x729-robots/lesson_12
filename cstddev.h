#pragma once
#include "istatistics.h"
#include "vector"
class StdDev : public IStatistics {
  public:
    virtual void update(double next) override;
    virtual double eval() const override;
    virtual const char* name() const override;
    StdDev(double val) ;

  private:
    std::vector<double> m_values;
    double m_stdDev;
    double m_summ; // summ of all values
    double m_n;    // number of all values
};