#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <functional>
#include "MinHeap.h"
#include "MaxHeap.h"
#include "SafeStack.h"
#include "Stack.h"

using namespace std;

namespace l3
{
   

//polymorphic comparator
class animal {
protected:
    int weight;
    int length;
    string habitat;

public:
    animal(int weight, int length) : weight(weight), length(length) {}

    virtual void talk() {}

    virtual int getWeight() {
        return this->weight;
    };

    bool operator< (const animal &other) const {
        return this->weight < other.weight;
    }
};

class cat : protected animal  {
    using animal::animal;
    void talk() {
        cout << "Meow" << endl;
    }

    bool operator < (animal &other) const {
        if (auto *a = dynamic_cast<animal *>(&other)) {
            if (typeid(*this) != typeid(*a)) {
                return false; 
            }
            // compare fields of *this and *a for equality
            return this->weight < a->getWeight();
        }
        return false;
    }
};

class dog : protected animal {
    using animal::animal;
    void talk() {
        cout << "Wof" << endl;
    }

    bool operator < (animal &other) const {
        if (auto *a = dynamic_cast<animal *>(&other)) {
            if (typeid(*this) != typeid(*a)) {
                // `a` is some other class derived from Version1
                return false; 
            }
            // compare fields of *this and *a for equality
            return this->weight < a->getWeight();
        }
        return false;
    }
};

template<typename T, typename R>
void pushToStack(R * stack, vector<T> data) {
    for (T val: data) {
        //std::this_thread::sleep_for(100ms);
        stack->push(val);
    }
}

template <template<typename> class S, typename T>
class ThreadSafeStack {
private:
    S<T> stack;
	mutable std::mutex m;
    std::condition_variable data_cond;
public:
    ThreadSafeStack(S<T> stack) : stack(stack) {}

    std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lock(m);
        data_cond.wait(lock, [this] { 
            return !stack.empty();
        });
        T ret = stack.pop();
		return ret;
		//return res;
	}

    void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		stack.push(new_value);
	}

    void traverse() {
        std::lock_guard<std::mutex> lock(m);
        stack.traverse();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return stack.length() > 0;
    }

    friend std::ostream& operator<< (std::ostream &out, ThreadSafeStack const& data) {
        data.traverse(out);
        return out;
    }
};

enum Mode { NotSafe, Safe, Safest, IntIncrement, IntIncrementAtomic };

//threads
//atomics
//futures
//promises
void not_main(Mode mode, int times) 
{
    vector<string> data{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
    vector<thread> pool;

    switch(mode) {
        case NotSafe:
        {
            //basic stack no smart pointers, will most likely crash
            Stack<string> * stack = new Stack<string>{};
            cout << "\nNot Safer:\n";

            // pushToStack<string, Stack<string>>(stack, data);

            // std::thread thread1 = std::thread(pushToStack<string, Stack<string>>, stack, data);
            // std::thread thread2 = std::thread(pushToStack<string, Stack<string>>, stack, data);

            // thread1.join();
            // thread2.join();


            for (int i=0;i<times;i++) {
                pool.emplace_back(pushToStack<string, Stack<string>>, stack, data);
            }

            for (auto & th : pool) {
                th.join();
            }
            
            stack->traverse();
        }
            
        break;

        case Safe:
        {
            //Safe stack, using Safe node with smart pointers and move operations, will hold but will miss data
            SafeStack<string> * stack = new SafeStack<string>{};

            cout << "\nSafer:\n";

            for (int i=0;i<times;i++) {
                pool.emplace_back(pushToStack<string, SafeStack<string>>, stack, data);
            }

            for (auto & th : pool) {
                th.join();
            }
            
            stack->traverse();
        }
            
        break;

        case Safest:
        {
            //Safe stack wrapped into mutex container, will not loose data
            SafeStack<string> stack = SafeStack<string>{};
            ThreadSafeStack<SafeStack, string> * stack_wrapper = new ThreadSafeStack{stack};

            //mutex
            cout << "\nSafe:\n";

            for (int i=0;i<times;i++) {
                pool.emplace_back(pushToStack<string, ThreadSafeStack<SafeStack, string>>, stack_wrapper, data);
            }

            for (auto & th : pool) {
                th.join();
            }
            
            stack_wrapper->traverse();
        }
        break;

        case IntIncrement:
        {
            //regular int variable
            int cnt = 0;
            auto f = [&]{cnt++;};

            for (int i=0;i<times;i++) {
                pool.emplace_back(f);
            }

            for (auto & th : pool) {
                th.join();
            }
        }
        break;

        case IntIncrementAtomic:
        {
            //atomic int variable
            std::atomic<int> cnt_a{0};
            auto f_a = [&]{cnt_a++;};
            
            for (int i=0;i<times;i++) {
                pool.emplace_back(f_a);
            }

            for (auto & th : pool) {
                th.join();
            }
        }
        default: break;
    }

//     MinHeap minH = MinHeap(5);
//     MaxHeap maxH = MaxHeap(5);

//     minH.insert(4);
//     minH.insert(2);
//     minH.insert(1);
//     minH.insert(5);
//     minH.insert(8);

//     maxH.insert(4);
//     maxH.insert(2);
//     maxH.insert(1);
//     maxH.insert(5);
//     maxH.insert(8);

//     cout << "\n Min Heap: \n";
//     minH.print();
//     cout << "\n Max Heap: \n";
//     maxH.print();

//     return 0;
// };
 
}

};