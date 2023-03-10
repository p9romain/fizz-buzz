#include <iostream>  

void fizzBuzz(int n)
{
  if ( n%3 == 0 and n%5 == 0 )
  {
    std::cout << n << ": FizzBuzz" << std::endl ;
  }
  else if ( n%3 == 0 )
  {
    std::cout << n << ": Fizz" << std::endl ;
  }
  else if ( n%5 == 0 )
  {
    std::cout << n << ": Buzz" << std::endl ;
  }
  else
  {
    std::cout << n << ": " << std::endl ;
  }
}

void fizzBuzzRec(int n)
{
  if ( n != 0 )
  {
    fizzBuzzRec(n-1) ;
    fizzBuzz(n) ;
  }
}

void fizzBuzzRecTerm_bis(int n, int i)
{
  if ( i != n+1 )
  {
    fizzBuzz(i) ;
    fizzBuzzRecTerm_bis(n, i+1) ;
  }
}

void fizzBuzzRecTerm(int n)
{
  fizzBuzzRecTerm_bis(n, 1) ;
}

void fizzBuzzIt(int n)
{
  for ( int i = 1 ; i < n+1 ; i++ )
  {
    fizzBuzz(i) ;
  }
}

// void fizzBuzzNthRec(int n)
// {
//   if ( n != 0 )
//   {
//     fizzBuzzNthRec(n-1) ;
//     if ( n%3 == 0 or n%5 == 0 )
//     {
//       fizzBuzz(n) ;
//     }
//     else
//     {
//        
//     }
//   }
// }

void fizzBuzzNthRecTerm_bis(int n, int i)
{
  if ( i != n+1 )
  {
    if ( i%3 == 0 or i%5 == 0 )
    {
      fizzBuzz(i) ;
      fizzBuzzNthRecTerm_bis(n, i+1) ;
    }
    else
    {
      fizzBuzzNthRecTerm_bis(n+1, i+1) ;
    }
  }
}

void fizzBuzzNthRecTerm(int n)
{
  fizzBuzzNthRecTerm_bis(n, 1) ;
}

void fizzBuzzNthIt(int n)
{
  int i = 1 ;
  while ( i != n+1 )
  {
    if ( i%3 == 0 or i%5 == 0 )
    {
      fizzBuzz(i) ;
    }
    else
    {
      n++ ;
    }
    i++ ;
  }
}


int main(int argc, char const **argv)
{
  int i = 0 ;
  int n = 0 ;
  std::cout << "The nth first (0) or until n (1) ? " ;
  std::cin >> i ;
  std::cout << std::endl ;
  do
  {
    std::cout << "Choose your n. \nIt must be a stricly positive integer : " ;
    std::cin >> n ;
  } while ( n <= 0 ) ;

  if ( i )
  {
    std::cout << std::endl << "Recursion : " << std::endl ;
    fizzBuzzRec(n) ;
    std::cout << std::endl << "Recursion (terminal) : " << std::endl ;
    fizzBuzzRecTerm(n) ;
    std::cout << std::endl << "Iterative : " << std::endl ;
    fizzBuzzIt(n) ;
    std::cout << std::endl ;
  }
  else
  {
    std::cout << std::endl << "Recursion : " << std::endl ;
    fizzBuzzNthRec(n) ;
    std::cout << std::endl << "Recursion (terminal) : " << std::endl ;
    fizzBuzzNthRecTerm(n) ;
    std::cout << std::endl << "Iterative : " << std::endl ;
    fizzBuzzNthIt(n) ;
    std::cout << std::endl ;
  }

  return 0 ;
}