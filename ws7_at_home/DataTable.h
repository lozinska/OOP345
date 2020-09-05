// Workshop 7 - STL Algorithms
// DataTable.h
// Krystyna Lopez
// 2019/03/18

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include<vector>
#include<iomanip>
#include<numeric>
#include <math.h>  
#include<algorithm>

extern int FW;
extern int ND;

namespace sict {

  template<typename T>
  class DataTable {

    std::vector<T> x;
    std::vector<T> y;
    T mean;
    T sigma;
    T median;
    double slope;
    double intercept;


  public:

    //A one argument constructor that reads all the records from the object
    //
    DataTable(std::ifstream& file) {

      T x_value, y_value;
      if (!file) {
        throw "Empty file";
      }
      while (file) {
        file >> x_value >> y_value;
        if (file) {
          x.push_back(x_value);
          y.push_back(y_value);
        }

      }

      T t = T(0),x_sum=T(0), in_prod_xy=T(0),y_sum=T(0), in_prod_xx = T(0);
      mean = std::accumulate(y.begin(), y.end(), (T)0) / y.size();

      t = std::accumulate(y.begin(), y.end(), (T)0,
        [=](T x, T y) { return x + (y-mean) * (y-mean); });

      sigma = sqrt(t / (y.size() - 1));
      std::vector<T> copy;
      copy = y;
      std::sort(copy.begin(), copy.end(), [](T i, T j) {return i < j; });

     if (copy.size() % 2 != 0) {
        median = (copy[copy.size() / 2 - 1] + copy[copy.size() / 2]) / 2;
      }
      else {
        median= copy[copy.size()/2];
   }
     
      x_sum = std::accumulate(x.begin(), x.end(), 0.0);
      y_sum= std::accumulate(y.begin(), y.end(), 0.0);
      in_prod_xy= std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
      in_prod_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
      slope = ((x.size()* in_prod_xy) - (x_sum * y_sum)) / ((x.size()*in_prod_xx) - (x_sum * x_sum));
    
      intercept = (y_sum - slope * x_sum) / x.size();

    }

    //A query that displays the x-y data
    //
    void displayData(std::ostream& os) const {
      os << "Data Values" << std::endl;
      os << "------------" << std::endl;
      os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

      for (size_t i = 0u; i < x.size(); i++) {
        os << std::setprecision(ND) << std::fixed << std::setw(FW) << x[i] << std::setw(FW) << y[i] << std::endl;
      }
    }

    //A query that displays the statistics for the current object
    //
    void displayStatistics(std::ostream& os) const {
      os << '\n' << "Statistics" << std::endl;
      os << "----------" << std::endl;
      os << std::setw(FW) << "y mean" << "    = " << std::setprecision(ND) << std::fixed << std::setw(FW) << std::right << mean << std::endl;
      os << std::setw(FW + 1) << "y sigma" << "   = " << std::setprecision(ND) << std::fixed << std::setw(FW) << std::right << sigma << std::endl;
      os << std::setw(FW+2) << "y median" << "  = " << std::setprecision(ND) << std::fixed << std::setw(FW) << std::right << median << std::endl;
      os << std::setw(FW) << "slope " << "    = " << std::setprecision(ND) << std::fixed << std::setw(FW) << std::right << slope << std::endl;
      os << std::setw(FW) << "  intercept " << "= " << std::setprecision(ND) << std::fixed << std::setw(FW) << std::right << intercept << std::endl;

    }
  };


}

#endif // !SICT_DATATABLE
