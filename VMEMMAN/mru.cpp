#include <iostream>
#include<bits/stdc++.h>
#include <fstream>

using namespace std;

// Function to find page faults using indexes
int mostRecentlyUsed(int pages[], float n, int frames)
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

			// Store the recently used index of
			// each page
			indexes[pages[i]] = i;
		}

		// If the set is full then need to perform mru
		// i.e. remove the least recently used page
		// and insert the current page
		else
		{
			// Check if current page is not already
			// present in the set
			if (s.find(pages[i]) == s.end())
			{
				// Find the most recently used pages
				// that is present in the set
				int mru = INT_MAX, val;
				for (auto it=s.begin(); it!=s.end(); it++)
				{
					if (indexes[*it] > mru)
					{
						mru = indexes[*it];
						val = *it;
					}
				}

				// Remove the indexes page
				s.erase(val);

				// insert the current page
				s.insert(pages[i]);

				// Increment page faults
				page_faults++;
			}

			// Update the current page index
			indexes[pages[i]] = i;
		}
	}
	///convert page faults to % of frame size
	float pfp = page_faults / n;

	cout<< n << "            "<<frames<<"            MRU "<<"          "<<pfp<<endl;

	//outfile
	ofstream outfile;
	outfile.open("outFile.txt", std::ios_base::app); // append instead of overwrite
	outfile<< n << "            "<<frames<<"            MRU "<<"          "<<pfp<<endl;
	outfile.close();
	return 0;

}

