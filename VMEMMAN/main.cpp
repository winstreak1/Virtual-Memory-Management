#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
#include "fifo.cpp"
#include "lru.cpp"
#include "mru.cpp"
#include "optimal.cpp"

using namespace std;

//Functions Prototype
int fifo(int pages[], float n, int frames); //fifo
int leastRecentlyUsed(int pages[], float n, int frames); //lru
int mostRecentlyUsed(int pages[], float n, int frames); //mru

//optimal functions
int predict(int pages[], vector<int>& fr, int n, int index);
bool search(int key, vector<int>& fr);
void opr(int pages[], float n, int frames);

//main function to run code
int main()
{
    //Declare and Initialize Variables
    ifstream data;
    data.open("data.txt");
    int arraySize;
    int pages[arraySize];   // Array of n elements
    int n = sizeof(pages)/sizeof(pages[0]);
	int frames;


    int i = 0;             // Loop counter variable
    ifstream inputFile;        // Input file stream object

    while (i < arraySize && data >> pages[i]){
        i++;
    }

    cout<<"Enter Page Size: "<<endl;
    cin>>n;
    cout<<"Enter # of Frames: "<<endl;
    cin>>frames;
    cout<<endl;
    cout<<"Page Size"<<"   "<<"# of Frames"<<"   "<<"Algorithm"<<"   "<<"  Page Fault %"<<endl;
    cout<<"****************************************************"<<endl;
	fifo(pages, n, frames); ///call and output fifo
	leastRecentlyUsed(pages, n, frames);///call and output lru
	mostRecentlyUsed(pages, n, frames); ///call and output mru
    optimal(pages, n, frames);///call optimal function

    /// Outfile data
    ofstream outfile;
    outfile.open("outFile.txt", std::ios_base::app); // append instead of overwrite
    outfile<<"Page Size"<<"   "<<"# of Frames"<<"   "<<"Algorithm"<<"   "<<"  Page Fault %"<<endl;
    outfile<<"****************************************************"<<endl;

    outfile.close();

	cout<<endl;

	//return 0;
}
