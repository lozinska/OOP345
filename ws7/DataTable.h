// Workshop 7 - STL Algorithms
// DataTable.h
// Krystyna Lopez
// 2019/03/15

#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H
#include<vector>
#include<iomanip>
#include<numeric>
#include <math.h>  

extern int FW;
extern int ND;

namespace sict {

  template<typename T>
  class DataTable {

    std::vector<T> x;
    std::vector<T> y;
    T mean;
    T sigma;

  public:

    //A one argument constructor that reads all the records from the object
    //
    DataTable(std::ifstream& file) {

      T x_value,y_value;
      if (!file) {
        throw "Empty file";
      }
        while(file){
          file >>x_value>>y_value;
          if (file) {
            x.push_back(x_value);
            y.push_back(y_value);
          }
        
      }

        T t = T(0);
        mean = std::accumulate(y.begin(), y.end(), (T)0)/ y.size();

        for (size_t i = 0u; i < y.size();i++) {
          t += (y[i] - mean)*(y[i] - mean);
        }
        sigma = sqrt(t / (y.size() - 1));
    }

    //A query that displays the x-y data
    //
    void displayData(std::ostream& os) const {
      os << "Data Values" << std::endl;
      os << "------------" << std::endl;
      os <<std::setw(FW)<< "x" << std::setw(FW) << "y" << std::endl;

      for (size_t i = 0u; i < x.size(); i++) {
        os<<std::setprecision(ND)<<std::fixed<< std::setw(FW)<<x[i] <<std::setw(FW)<< y[i] << std::endl;
      }
    }

    //A query that displays the statistics for the current object
    //
    void displayStatistics(std::ostream& os) const {
      os<<'\n' << "Statistics" << std::endl;
      os << "----------" << std::endl;
      os <<std::setw(FW)<< "y mean"<<"    = "<<std::setprecision(ND) << std::fixed<< std::setw(FW) << std::right << mean<<std::endl;
      os <<std::setw(FW+1)<< "y sigma"<<"   = " <<std::setprecision(ND) << std::fixed<< std::setw(FW)<<std::right << sigma<< std::endl;
      
    }
  };


}

#endif // !SICT_DATATABLE
