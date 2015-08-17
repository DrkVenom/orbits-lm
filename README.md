# orbits-lm
c++ find orbits by multiplication by a numerical multiplier

Primarily used to quickly find the orbits of a cyclic group when multiplied on the  right (ie if t is a multiplier than it finds xt, where x is an element of the group). The output to the console is the list of all the orbits within the group (defined by the multiplier) along with the size of each orbit. 

This application relies on the number theory library (NTL located at http://www.shoup.net/ntl/) to allow for larger values (ie data type ZZ and ZZ_p) as well as make use of the built in gcd check.

The order of the group need not be cyclic for there to be orbits associated to the group action of multiplication; however, the greatest common denominator (GCD) must be one. For example, 399 is not a prime (ie 399=133*3), but there are orbits associated with the multiplier 101 (but not 102 as 102 is divisible by 3).

The entered multiplier need not be smaller than the order of the group. For instance, if we consider the group Z_15, then the multiplier 17 will be treated as 2. Similarly 124 is treated as 4 in Z_15.

  ==Compiling and running==
  
  1) Ensure you have a working version of NTL installed on your device. I was working with NTL 6.2.1, presumably it will work for many versions, but I have not personally checked all of the major ones. I use Linux, but I can't see there being issues on any operating system able to install NTL.
  
  2) I compile using the terminal with --->         g++ orbits.cpp -o orbits -lntl -lm
  
  ==Known Issues==
  
  1) the ZZ object allows the user to create values larger than integers. This is great in theory, but may take a long time for calculations. The device will most likely crash before a result can be obtained.
