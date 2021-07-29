#include<chrono>
#include<iostream>

class Timer
{
public:
    explicit Timer(){
        begin_ = std::chrono::steady_clock::now();
    }
    
    ~Timer(){
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_time = end-begin_;
        std::cout << "duration = " << elapsed_time.count() << std::endl;
    
        using Clock = std::chrono::system_clock;
        using Duration = Clock::duration;
        std::cout << Duration::period::num << " , " << Duration::period::den << '\n';
    }
private:
    std::chrono::time_point<std::chrono::steady_clock> begin_;
};