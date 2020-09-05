// Workshop 9 - Multi-Threading
// SecureData.cpp
// Krystyna Lopez
// 2019/04/01

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include <vector>
#include "SecureData.h"

using namespace std;

namespace sict {

  void converter(char* t, char key, int n, const Cryptor& c) {
    for (int i = 0; i < n; i++)
      t[i] = c(t[i], key);
  }

  SecureData::SecureData(const char* file, char key, ostream* pOfs) {
    ofs = pOfs;

    // open text file
    fstream input(file, std::ios::in);
    if (!input)
      throw string("\n***Failed to open file ") +
      string(file) + string(" ***\n");

    // copy from file into memory
    input.seekg(0, std::ios::end);
    nbytes = (int)input.tellg() + 1;

    text = new char[nbytes];

    input.seekg(ios::beg);
    int i = 0;
    input >> noskipws;
    while (input.good())
      input >> text[i++];
    text[nbytes - 1] = '\0';
    *ofs << "\n" << nbytes - 1 << " bytes copied from file "
      << file << " into memory (null byte added)\n";
    encoded = false;

    // encode using key
    code(key);
    *ofs << "Data encrypted in memory\n";
  }

  SecureData::~SecureData() {
    delete[] text;
  }

  void SecureData::display(std::ostream& os) const {
    if (text && !encoded)
      os << text << std::endl;
    else if (encoded)
      throw std::string("\n***Data is encoded***\n");
    else
      throw std::string("\n***No data stored***\n");
  }

  void SecureData::code(char key) {
    const int NT = 4;
    //create a vector of threads
    //
    std::vector<std::thread> threads;
    for (int i = 1; i <= NT; i++) {
      threads.push_back(std::thread(converter, text, key, nbytes*(i / NT), Cryptor()));
    }
   // converter(text, key, nbytes, Cryptor());
   

    //join the thread
    //
    for (auto& thread : threads)
      thread.join();
    encoded = !encoded;
  }

  void SecureData::backup(const char* file) {
    if (!text)
      throw std::string("\n***No data stored***\n");
    else if (!encoded)
      throw std::string("\n***Data is not encoded***\n");
    else
    {
      // open a binary file for writing
      //
      std::fstream fout(file, std::ios::out | std::ios::binary | std::ios::trunc);
    
      //write data into the binary file
      //         and close the file
      //
      fout.write(text, nbytes);
      fout.close();

    }
  }

  void SecureData::restore(const char* file, char key) {

    std::ifstream fin(file, std::ios::in | std::ios::binary);

    //allocate memory here for the file content
    //
    delete[] text;

    // allocate memory here for the file content
    //
    text = new char[nbytes+1];


    // read the content of the binary file
    //
    fin.read(text, nbytes);
    text[nbytes] = '\0';


      *ofs << "\n" << nbytes << " bytes copied from binary file "
        << file << " into memory.\n";

      encoded = true;

      // decode using key
      code(key);

      *ofs << "Data decrypted in memory\n\n";
    }


  std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
    sd.display(os);
    return os;
  }
}