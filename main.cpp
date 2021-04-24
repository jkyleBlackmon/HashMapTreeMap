#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
#include <random>
#include <vector>

using namespace std;
using namespace chrono;


int main()
{
    // Declare std::map and std::unordered_map
    map<int, int> timedMp;
    unordered_map<int, int> timedUnordMp;
    long inputSize;

    cout << "Please enter input size: ";
    cin >> inputSize;
    // Generate Random Numbers
    vector<int> nums;
    for(int i = 0; i < inputSize; i++){
        nums.push_back(rand() % inputSize + 1);
    }

    //------- Map Functions -------//
    cout << "Now printing times for Map of " << inputSize  << " integers..." << endl;

    //*===  Map [Emplace] ===*//
    auto startTime = high_resolution_clock::now();
    for(int i = 0; i < nums.size();i++){  timedMp.emplace(i,nums[i]); }
    auto stopTime = high_resolution_clock::now();
    auto totalTime = duration_cast<microseconds>(stopTime - startTime);
    cout << "std::map.emplace() time: " << totalTime.count() << endl;

    //*=== Map [Remove] ===*//
    startTime = high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){   timedMp.erase(rand() % 1000 + 1);   }
    stopTime = high_resolution_clock::now();
    totalTime = duration_cast<microseconds>(stopTime - startTime);
    cout << "std::map.remove() time: " << totalTime.count() << endl;

    //*=== Map [Find] ===*//
    startTime = high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){  timedMp.find(457);  }
    stopTime = high_resolution_clock::now();
    totalTime = duration_cast<microseconds>(stopTime - startTime);
    cout << "std::map.find() time: " << totalTime.count() << endl;


    //------- Unordered Map Functions -------//
    cout << "Now printing times for Unordered Map of " << inputSize  << " integers..." << endl;

    //*=== Unordered Map [Emplace] ===*//
    startTime = high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){   timedUnordMp.emplace(i, nums[i]);   }
    stopTime = high_resolution_clock::now();
    totalTime = duration_cast<microseconds>(stopTime - startTime);
    cout << "std::unordered_map.emplace() time: " << totalTime.count() << endl;

    //*=== Unordered Map [Remove] ===*//
    startTime = high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++) {  timedUnordMp.erase(rand() % 1000 + 1);  }
    stopTime = high_resolution_clock::now();
    totalTime = duration_cast<microseconds>(stopTime - startTime);
    cout << "std::unordered_map.remove() time: " << totalTime.count() << endl;

    //*=== Unordered Map [Find] ===*//
    startTime = high_resolution_clock::now();
    for(int i = 0; i < nums.size(); i++){  timedUnordMp.find(457); }
    stopTime = high_resolution_clock::now();
    totalTime = duration_cast<microseconds>(stopTime - startTime);
    cout << "std::unordered_map.find() time: " << totalTime.count() << endl;
}