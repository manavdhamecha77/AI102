/*
Write a C or C++ program to sort the input array [12, 45, 33, 87, 56, 9, 11, 7, 67] using the Bucket Sort 
algorithm with 7 buckets.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<int>& arr, int bucketCount) {
    if (arr.empty()) return;

    int minValue = *min_element(arr.begin(), arr.end());
    int maxValue = *max_element(arr.begin(), arr.end());
    int range = maxValue - minValue + 1;
    int bucketRange = (range + bucketCount - 1) / bucketCount;

    vector<vector<int>> buckets(bucketCount);

    for (int num : arr) {
        int index = (num - minValue) / bucketRange;
        buckets[index].push_back(num);
    }

    arr.clear();
    
    for (auto& bucket : buckets) {
        sort(bucket.begin(), bucket.end());
        arr.insert(arr.end(), bucket.begin(), bucket.end());
    }
}

int main() {
    vector<int> arr = {12, 45, 33, 87, 56, 9, 11, 7, 67};
    int bucketCount = 7;

    bucketSort(arr, bucketCount);

    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
