// Practicing with vectors


#include <iostream>
#include <list>
int main()
{
  std::list<int> l = { 7, 5, 16, 8 }; // Create a list containing integers
  l.push_front( 25 ); // add to front
  l.push_front( 2 ); // add to front
  l.push_back( 13 ); // add to back
  std::cout << l.front() << std::endl;
  std::cout << l.back() << std::endl;
  // Iterate and print values of the list using range-based for loop
  std::cout << "Separate" << std::endl;
  for( int n : l )
  std::cout << n << std::endl;
  //std::cout << l[0] << std::endl; // error! lists don’t have random access
}

/*
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

/*
int main()
{
  std::vector<double> v;
  for (int i = 0; i < 10; ++i)
  {
    v.push_back(i);
  }

  // range-based for loop to iterate (C++11)
  for( const double n : v )
  std::cout << n << std::endl;

  v.erase(v.begin());

  // range-based for loop to iterate (C++11)
  for( const double n : v )
  std::cout << n << std::endl;
  /*
  // the same using an automatic type (C++11)
  for( const auto n : v )
  std::cout << n << std::endl;
  */

//}
