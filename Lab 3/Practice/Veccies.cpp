// Practicing with vectors

#include <iostream>
#include <vector>

double mean( std::vector<double> array )
{
    double m = 0;
    for(int i = 0; i <array.size(); ++i )
    {
        m += array[i];
    }

    return m / array.size();
}

/*
int main()
{
    std::vector<double> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(6);
    std::cout << mean(a) << std::endl;
}
*/

int main()
{
  std::vector<double> v;
  for (int i = 0; i < 10; ++i)
  {
    v.push_back(i + 0.14159);
  }

  // range-based for loop to iterate (C++11)
  for( const double n : v )
  std::cout << n << std::endl;
  
  // the same using an automatic type (C++11)
  for( const auto n : v )
  std::cout << n << std::endl;
}
