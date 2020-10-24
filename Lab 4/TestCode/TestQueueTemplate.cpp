

#include <iostream>

class CCat {
  public:
    CCat( int a, int b ) : mFleas(a), mHair(b)
    {}
    void CleanFleas() { --mFleas; }
    void ShedHair() { --mHair; }
    void Report()
    {
      std::cout << mFleas << ", "
                << mHair << std::endl;
    }

    CCat( const CCat& src ){
      std::cout << "copying" << std::endl;
      mFleas = src.mFleas;
      mHair = src.mHair;  }

  private:
    int mFleas;
    int mHair;
};

class CGroomer {
  public:
    void Groom( CCat& Cat ){
      Cat.ShedHair();
      Cat.CleanFleas();
      Cat.Report();
    }
};

int main()
{
  CCat Cat1(3,40);
  //CCat Cat2(Cat1);
  //CCat Cat3=Cat1;

  CGroomer Groomer;
  Groomer.Groom( Cat1 );
  Cat1.Report();
}


/*
int i = 37;
int j = 43;

int& r = i;   // initialising the reference
int* p = &i;  // initialising the pointer
std::cout << i << ", " << j << std::endl;
std::cout << r << ", " << *p << std::endl;
p = &j;  // reassigning the pointer
*p = 3;  // modifying what's pointed to by p
std::cout << i << ", " << j << std::endl;std::cout << r << ", " << *p << std::endl;
r = j;   // modifying what's referenced by r// NOT reassigning r
std::cout << i << ", " << j << std::endl;
std::cout << r << ", " << *p << std::endl;


int k = r;
std::cout << r << ", " << k << std::endl;
*/
