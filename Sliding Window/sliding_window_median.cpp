#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> delayed;
    int windowSize, minHeapSize, maxHeapSize;
    MedianFinder(int k)
    {
        this->windowSize = k;
        this->minHeapSize = 0;
        this->maxHeapSize = 0;
    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
            maxHeapSize++;
        }
        else
        {
            minHeap.push(num);
            minHeapSize++;
        }
        rebalanceHeaps();
    }
    void removeNum(int num)
    {
        delayed[num]++;
        if (num <= maxHeap.top())
        {
            maxHeapSize--;
            if (num == maxHeap.top())
            {
                prune(maxHeap);
            }
        }
        else
        {
            minHeapSize--;
            if (num == minHeap.top())
            {
                prune(minHeap);
            }
        }
        rebalanceHeaps();
    }
    template <typename T>
    void prune(T &heap)
    {
        while (!heap.empty() && delayed[heap.top()])
        {
            if (--delayed[heap.top()] == 0)
            {
                delayed.erase(heap.top());
            }
            cout << "Removed = " << heap.top() << endl;
            heap.pop();
        }
    }
    void rebalanceHeaps()
    {
        if (maxHeapSize > minHeapSize + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeapSize--;
            minHeapSize++;
            // Re-prune in case the top element is meant to be delayed-removed.
            prune(maxHeap);
        }
        else if (maxHeapSize < minHeapSize)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            maxHeapSize++;
            minHeapSize--;
            // Re-prune in case the top element is meant to be delayed-removed.
            prune(minHeap);
        }
    }
    double findMedian()
    {
        if (windowSize & 1)
        {
            return maxHeap.top();
        }
        else
        {
            return (static_cast<double>(minHeap.top()) + static_cast<double>(maxHeap.top())) * 0.5;
        }
    }
};
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        MedianFinder finder(k);
        for (int i = 0; i < k; i++)
        {
            finder.addNum(nums[i]);
        }
        vector<double> medians;
        medians.push_back(finder.findMedian());
        for (int i = k; i < nums.size(); i++)
        {
            finder.addNum(nums[i]);
            finder.removeNum(nums[i - k]);
            medians.push_back(finder.findMedian());
        }
        return medians;
    }
};
int main()
{
    Solution S;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<double> arr = S.medianSlidingWindow(nums, k);
}