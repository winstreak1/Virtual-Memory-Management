#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

int predict(int pages[], vector<int>& fr, float n, int index) {
   // Store the index of pagess which are going
   // to be used recently in future
   int res = -1, farthest = index;
   for (int i = 0; i < fr.size(); i++) {
      int j;
      for (j = index; j < n; j++) {
         if (fr[i] == pages[j]) {
            if (j > farthest) {
               farthest = j;
               res = i;
            }
            break;
         }
      }
      // Return the pages which are
      // are never referenced in future,
      if (j == n)
         return i;
   }
   // If all of the frames were not in future,
   // return any of them, we return 0. Otherwise
   // we return res.
   return (res == -1) ? 0 : res;
}
bool search(int key, vector<int>& fr) {
   for (int i = 0; i < fr.size(); i++)
   if (fr[i] == key)
   return true;
   return false;
}
void optimal(int pages[], float n, int frames) {
   /// Declare and initialize variables
   //float page_faults = 0;
   vector<int> fr;
   float hit = 0;
   for (int i = 0; i < n; i++) {
      // pages found in a frame : HIT
      if (search(pages[i], fr)) {
         hit++;
         continue;
      }
      //If a pages not found in a frame : MISS
      // check if there is space available in frames.
      if (fr.size() < frames)
      fr.push_back(pages[i]);
      // Find the pages to be replaced.
      else {
         int j = predict(pages, fr, n, i + 1);
         fr[j] = pages[i];
      }
   }
   //formulas to convert hits, misses and page faults to page fault %.
   float hitRatio = hit / n;
   float page_faults = n - hit;
   float pfp = page_faults / n;

   cout<< n << "            "<<frames<<"            Optimal "<<"      "<<pfp<<endl;

   // outfile
   ofstream outfile;
   outfile.open("outFile.txt", std::ios_base::app); // append instead of overwrite
   outfile<< n << "            "<<frames<<"            Optimal "<<"      "<<pfp<<endl;
   outfile.close();
   cout<<endl;
   /*
   cout<<"***Hits and Misses***"<<endl;
   cout << "Hits = " << hit << endl;
   cout << "Misses = " << n - hit << endl;
   cout << "Hit Ratio = "<<hitRatio<<endl;
   cout << "Page Faults = "<<page_faults<<endl;
   */
}

