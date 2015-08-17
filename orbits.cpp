//Name: 			Tony Ranieri
//Created:			April 2015
//Modified:			July 2015

// uses "NTL: A Library for doing Number Theory", packages and readmes can be located at http://www.shoup.net/ntl/
// the code presented here is written with NTL 6.2.1 in mind

#include <stdio.h>
#include <vector>
#include <NTL/ZZ.h>
#include <NTL/ZZ_p.h>

NTL_CLIENT

int main()
{
	//initialize the modulus to be used
	ZZ m_mod;
	
	cout << "Please enter the value of the modulus: \n";
	cin >> m_mod;
	cout << "\n";
	
	//initialize (mod m_mod)
	ZZ_p::init(m_mod);
	
	//initialize the multiplier to be used
	ZZ_p t_mult_p;
	
	cout << "Please enter the value of the multiplier: \n";
	cin >> t_mult_p;
	cout << "\n";
	
	//t_mult is created in class ZZ_p, but we need it as ZZ to perform GCD checks, thus we create a representative t_mult_p of class ZZ to hold the value of t_mult but in the correct ZZ class
	ZZ t_mult;
	t_mult = rep(t_mult_p);
	bool pass=true;

	// check to ensure gcd of  m_mod and t_mult is 1
	if (GCD(m_mod, t_mult) != 1)
	{
		pass=false;
	}
	
	//loop to ensure that the program can continue using a proper multiplier
	while (pass==false)
	{
		cout << "We're sorry but the gcd of the modulus, " << m_mod << ", and the multiplier, "<< t_mult << ", is not 1. Please choose a different multiplier such that their gcd is 1. \n";
		cin >> t_mult_p;
		t_mult = rep(t_mult_p);
		cout << "\n";
		if (GCD(m_mod, t_mult) == 1)
		{
			//exit the loop
			pass=true;
		}
	}
	
	//since we don't know the number of orbits, nor the length of them, we use a vector of vectors
	std::vector< std::vector<ZZ_p> > orbits;
	orbits.resize(1); 
	
	orbits[0].resize(1);
	orbits[0][0]=0;
	long i_last=0;
	long k=1;
	ZZ_p value;
	
	bool check=false;
	while (k<m_mod)
	{
		for (long i=0;i<orbits.size();i++)
		{
			for (long j=0;j<orbits[i].size();j++)
			{	
				if (k==orbits[i][j])
				{
					check=true;
					j=orbits[i].size();
					i=orbits.size();
					break;
				}
				else
				{
					check=false;
				}
			}
		}
		if (check==true)
		{
			k++;
		}
		else
		{
			orbits.resize(orbits.size()+1);
			i_last++;
			orbits[i_last].push_back(conv<ZZ_p>(k));
			value = k*t_mult_p;
			while (value != orbits[i_last][0])
			{
				orbits[i_last].push_back(value);
				value = value*t_mult_p;
			}
			k++;
			check=false;
		}
	}
	
	cout << "There are " << orbits.size() << " distinct orbits of the multiplier " << t_mult_p << " in Z_" << m_mod << "\n";
	//print out the orbits
	for (int x=0; x<orbits.size(); x++)
	{
	    cout << "|[" << orbits[x][0] << "]| = " << orbits[x].size() << "\t { ";
	    for (int y=0; y<orbits[x].size(); y++)
	    {
			cout << orbits[x][y] << " ";
	    }
	    cout << "} \n \n";
	}
}
