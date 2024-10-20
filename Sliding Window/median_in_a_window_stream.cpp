#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() || maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if (maxHeap.size() > 1 + minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
        {
            if (maxHeap.empty())
                return 0;
            else
            {
                double avg = (maxHeap.top() + minHeap.top()) / 2.0;
                return avg;
            }
        }
        else
        {
            return maxHeap.size() > minHeap.size() ? maxHeap.top()
                                                   : minHeap.top();
        }
    }
};