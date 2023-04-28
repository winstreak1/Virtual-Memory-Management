#include <iostream>
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

/// Function to find page faults using indexes
int leastRecentlyUsed(int pages[], float n, int frames)
{
    /// Declare and initialize variables
	float page_faults = 0;

	// To represent set of current pages. We use
	// an unordered_set so that we quickly check
	// if a page is present in set or not
	unordered_set<int> s;

	// To store least recently used indexes
	// of pages.
	unordered_map<int, int> indexes;


	for (int i=0; i<n; i++)
	{
		// Check if the set can hold more pages
		if (s.size() < frames)
		{
			// Insert it into set if not present
			// already which represents page fault
			if (s.find(pages[i])==s.end())
			{
				s.insert(pages[i]);

				// increment page fault
				page_faults++;
			}

			/// Store most recently used index
			indexes[pages[i]] = i;
		}

		else
		{
			/// Check if current page is present
			if (s.find(pages[i]) == s.end())
			{
				/// Find lru
				int lru = INT_MAX, val;
				/// loop to iterate through index
				for (auto it=s.begin(); it!=s.end(); it++)
				{
					if (indexes[*it] < lru)
					{
						lru = indexes[*it];
						val = *it;
					}
				}

				/// Remove the index page
				s.erase(val);

				/// Insert the current page
				s.insert(pages[i]);

				/// Increment page faults
				page_faults++;
			}

			/// Update the current page index
			indexes[pages[i]] = i;
		}
	}
	///convert page faults to % of frame size
	float pfp = page_faults / n;
	cout<< n << "            "<<frames<<"            LRU"<<  "           "<<pfp<<endl;
	/// outfile
	ofstream outfile;
	outfile.open("outFile.txt", std::ios_base::app); // append instead of overwrite
	outfile<< n << "            "<<frames<<"            LRU"<<  "           "<<pfp<<endl;
    outfile.close();
	return 0;

}


