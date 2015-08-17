# orbits-lm
c++ find orbits by multiplication by a numerical multiplier

Primarily used to quickly find the orbits of a cyclic group when multiplied on the  right (ie if t is a multilier than it finds xt). The output to the console is the list of all the orbits within the group (defined by the multiplier) along with the size of each orbit. 

This application relies on the number theory library (NTL located st http://www.shoup.net/ntl/) to allow for larger values (ie data type ZZ and ZZ_p) as well as make use of hte built in gcd check.
