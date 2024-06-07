#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

class IStatistics {
  public:
    virtual ~IStatistics() {}

    virtual void update(double next) = 0;
    virtual double eval() const = 0;
    virtual const char* name() const = 0;
};

class Min : public IStatistics {
  public:
    Min(double m_val) : m_min{m_val} {}

    virtual void update(double next) override {
        if (next < m_min) {
            m_min = next;
        }
    }

    virtual double eval() const override {
        return m_min;
    }

    virtual const char* name() const override {
        return "min";
    }

  private:
    double m_min;
};

class Max : public IStatistics {
  public:
    Max(double m_val) : m_max{m_val} {}

    virtual void update(double next) override {
        if (next > m_max) {
            m_max = next;
        }
    }

    virtual double eval() const override {
        return m_max;
    }

    virtual const char* name() const override {
        return "max";
    }

  private:
    double m_max;
};

class Mean : public IStatistics {
  public:
    Mean(double m_val) : m_mean{m_val}, m_summ{m_val}, m_n{1} {}

    virtual void update(double next) override {
        m_summ += next;
        m_n++;
    }

    virtual double eval() const override {
        return m_summ / m_n;
    }

    virtual const char* name() const override {
        return "mean";
    }

  private:
    double m_mean;
    double m_summ; // summ of all values
    double m_n;    // number of all values
};

class StdDev : public IStatistics {
  public:
    StdDev(double val) : m_values{val} {}

    virtual void update(double next) override {
        m_values.push_back(next);
    }

    virtual double eval() const override {
        double summ{std::accumulate(m_values.begin(), m_values.end(), 0.)};
        double mean{summ / m_values.size()};
        double summSquare{0};
        for (auto val : m_values) {
            summSquare += pow(val - mean, 2);
        }
        return sqrt(summSquare / m_values.size());
    }

    virtual const char* name() const override {
        return "std";
    }

  private:
    std::vector<double> m_values;
    double m_stdDev;
    double m_summ; // summ of all values
    double m_n;    // number of all values
};

class PctN : public IStatistics {
  public:
    PctN(double val, int pctN) : m_values{val}, m_pctN{pctN} {}

    virtual void update(double next) override {
        m_values.push_back(next);
    }

    virtual double eval() const override {
        std::vector<double> values{m_values};
        std::sort(values.begin(), values.end());
        // int pc_i = (round(1000*(double)m_values.size() *
        // ((double)m_pctN/100.))/1000);
        int pc_i = round(m_values.size() * m_pctN / 100.) - 1;
        return (m_values[pc_i]);
    }

    virtual const char* name() const override {
        std::string out = "Pct";
        out += std::to_string(m_pctN);
        return out.c_str();
    }

  private:
    std::vector<double> m_values;
    int m_pctN;
    double m_summ; // summ of all values
    double m_n;    // number of all values
};
int main() {

    const size_t statistics_count = 6;
    IStatistics* statistics[statistics_count];

    double val = 0;
    std::cin >> val;
    int i{0};
    statistics[i++] = new Min{val};
    statistics[i++] = new Max{val};
    statistics[i++] = new Mean{val};
    statistics[i++] = new StdDev{val};
    statistics[i++] = new PctN{val, 90};
    statistics[i++] = new PctN{val, 95};

    while (std::cin >> val) {
        for (size_t i = 0; i < statistics_count; ++i) {
            statistics[i]->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (size_t i = 0; i < statistics_count; ++i) {
        std::cout << statistics[i]->name() << " = " << statistics[i]->eval()
                  << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (size_t i = 0; i < statistics_count; ++i) {
        delete statistics[i];
    }

    return 0;
}