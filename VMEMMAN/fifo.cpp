#include<bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;
/// FIFO function to find page faults
int fifo(int pages[], float n, int frames)
{
	/// Set of current pages to check if pages are present or not
	unordered_set<int> s;

	/// Store the pages using FIFO
	queue<int> indexes;

	/// Initialize and loop to iterate through indicated frame size, n.
	float page_faults = 0;
	for (int i=0; i<n; i++)
	{
		/// Check if the set can store more pages
		if (s.size() < frames)
		{
			/// Insert page into set if not present
			if (s.find(pages[i])==s.end())
			{
				/// Insert current page into set
				s.insert(pages[i]);

				/// Increment page fault
				page_faults++;

				/// Push  current page into queue
				indexes.push(pages[i]);
			}
		}
        /// Perform FIFO if set is full
		else
		{
			/// Check if current page is present
			if (s.find(pages[i]) == s.end())
			{
				/// Store  first page in queue
				int val = indexes.front();

				/// Pop the first page from the queue
				indexes.pop();

				/// Remove index page from the set
				s.erase(val);

				/// insert current page in the set
				s.insert(pages[i]);

				/// push current page to queue
				indexes.push(pages[i]);

				/// Increment page faults
				page_faults++;


			}
		}
	}
	/// convert page faults to % of frame size
	float pfp = page_faults / n;
    cout<<n<< "            "<<frames<<"            FIFO "<<"         "<<pfp<<endl;
    //outfile
    ofstream outfile;
    outfile.open("outFile.txt", std::ios_base::app); // append instead of overwrite
    outfile<<n<< "            "<<frames<<"            FIFO "<<"         "<<pfp<<endl;
    outfile.close();


	return 0;
}
