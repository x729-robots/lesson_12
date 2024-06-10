#pragma once
#include "istatistics.h"

class Max : public IStatistics {
  public:
    Max(double m_val);
    virtual void update(double next) override;
    virtual double eval() const override;
    virtual const char* name() const override;

  private:
    double m_max;
};