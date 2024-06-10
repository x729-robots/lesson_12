#pragma once
#include "istatistics.h"
class Mean : public IStatistics {
  public:
    virtual void update(double next) override;
    virtual double eval() const override;
    virtual const char* name() const override;
    Mean(double m_val);

  private:
    double m_mean;
    double m_summ; // summ of all values
    double m_n;    // number of all values
};