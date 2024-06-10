#pragma once
#include "istatistics.h"

class Min : public IStatistics {
  public:
    Min(double m_val);
    virtual void update(double next) override;
    virtual double eval() const override;
    virtual const char* name() const override;

  private:
    double m_min;
};
