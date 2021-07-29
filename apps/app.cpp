#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

class Timer
{
public:
    explicit Timer(){
        begin_ = std::chrono::steady_clock::now();
    }
    
    ~Timer(){
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_time = end-begin_;
        std::cout << "duration = " << elapsed_time.count() << " seconds " << std::endl;
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> begin_;
};

int binarySearchRecursive(int find, const std::vector<int>& arr, int min, int max)
{
    int mid = (min + max) / 2;
    if(max < min)
        return -1;
    
    if (arr[mid] == find)
        return mid;
    else
    {
        if(mid > find)
        {
            max = mid-1;
            return binarySearchRecursive(find, arr, min, max);
        }
        else
        {
            min = mid+1;
            return binarySearchRecursive(find, arr, min, max);
        }
    }
}

int binarySearch(int find, const std::vector<int>& searchArr)
{
    int min = 0;
    int max = searchArr.size() - 1;
    binarySearchRecursive(find, searchArr, min, max);
}



int main(int argc, char* argv[])
{
    Timer t;
    std::vector<int> searchArr{3, 2, 4, 5, 2, 1};
    std::sort(searchArr.begin(), searchArr.end());
    int find = 2;
    std::cout << "index of " << find << " = " << binarySearch(find, searchArr) << std::endl;
    return EXIT_SUCCESS;
}