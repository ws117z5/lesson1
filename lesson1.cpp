struct A {
public:
    static int someStaticVar;
    const int i = 1;
    int *numberPointer = new int;
    A(int number) {
        *numberPointer = number;
    }

    virtual void someFunction() {
        cout << "Class A here" << endl;
    }

    A() {
        //someth
    }

    ~A() {
        delete A::numberPointer;
    }
private:
    void somePrivateFunc() {
        cout << "This is private" << endl;
    }
};

class C {
public:
    void someOtherFunction() {
        cout << "Class C here" << endl;
    }
};

class B : public A, C {
public:
    B(int i) : A(i) {

    }
    void someFunction() {
        cout << "B lass here" << endl;
    }

    void dosomething(int i, int j, function<void(int)> callback) {
        int newData = i+j;
        cout << "here something was done" << endl;
        callback(newData);
    }
};

class animal {
    int weight;
    int length;
    string habitat;

    virtual void talk() {

    }

    bool operator< (const animal other) {
        return this->weight < other.weight;
    }
};

class cat : animal  {
    void talk() {
        cout << "Meow" << endl;
    }
};

class dog : animal {
    void talk() {
        cout << "Wof" << endl;
    }
};

int A::someStaticVar = 1;

//template of a stack
template<class T>
class storage {
public:
    T arr[20];
    int position = -1;
    T pull() {
        if (position > -1) {
            return arr[position--];
        }

        return 0;
    }

    void push(T i) {
        arr[++position] = i;
    }
};

struct LinkedList {
    int i;
    LinkedList * next = nullptr;

    void push(int i) {
        LinkedList nl = LinkedList{i};

        //LinkedList * tmp = &this;
        //while (tmp.next != nullptr) {
             //tmp = tmp.next;
        //}
        //tmp.next = &nl;
    }

    int pop() {
        return 0;
    }
};

template<typename T>
void myPrintPtr(T * el) {
        cout << *el;
}

template<typename T>
void myPrint(T el) {
        std::cout << el << " ";
}

void someFunc() {
    //do someth
};

// void recursivePrint(int, string);

void recursivePrint(int n, string toPrint) {
    if (n > 0) {
        std::cout << toPrint << " " << --n << "\n"; 
        recursivePrint(n, toPrint);
    }
}

int fib(long long int n) {
    if (n <= 2) {
        return 1;
    }

    return fib(n-2);
};

// int_4 -127 127    sign bit
// unsigned int_4    255 
// unint 64          18446744073709551615

// 1   fib
// 2   n
// 3   fib(1)
// 4   n-2
// 5   fib(2)
// 6   n-4
// 7   fib(3)
// 8   n-6
// 9   addr of fib(2) 

//1 1 2 3 5 8 13 ...

//                 5(5)
//          3(2)          4(3)
//    *2(1)   *1(1)     3(2)   *2(1)
//                 *2(1)  *1(1)
// (x + y)^n
// x^n + 2x^(n-1)*y^1 + 3x^n-2y^2 + ....  + x^0 y^n
//            1
//          1   1
//        1   2   1
//      1   3   3   1
// (n coose k)x^k-n*y^x-k
// n choose k
//    n! 
// (n-k)!k!   
//  ( n )
//  ( k )

void temp() {
        /**
     * stack
     * 1    someFunc()
     * 2        *
     * 3        *
     * 4    arr[]
     * 5    arr[0]
     * 6    arr[1]
     * 7    arr[2]
     * 8    Node1
     * 9    data
     * 10   ptr = 17
     * 11
     * 12
     * ...
     * 17   Node2
     * 18   data
     * 19   ptr 
     */

    // node1 (data, ptr) -> node2 (data, ptr) 
    cout << &someFunc << "\n";
    function<void(int)> callback = [&](int i) {
        cout << "We have got some calculated data: " << i << " then we've added 1";
        return i+1;
    };

    vector<string> vec1{"test", "test2"};

    

    char arr[] = {"testtest2"}; // \0 
    int64_t arr2[] = {10, 20, 30};

    cout << *(arr2+4) << "\n";

    Node<int> * firstNode = new Node<int>{1};
    Node<int> firstNode_data = *(firstNode);
    Node<int> * firstNode_ptr = &firstNode_data;

    cout << firstNode << "\n";
    //int*arrPtr;
    //arrPtr = arr2;

    //cout << *(arrPtr+2) << endl;

    int x = 1;
    //lvalue/rvalue
    A classA = A{2};
    A * cls = &classA;
    A *classARef = new A(1);

    B classB = B{1};
    classB.someStaticVar++;

    //classB.dosomething(1, 2, callback);

    //classB.someFunction();

    //cout << classA.someStaticVar << endl;

    storage<string> mystore = storage<string>{};
    mystore.push("hi");
    //cout << mystore.pull() << endl;


    int a, *b, **c;
    a = 1;
    b = &a;
    *b = 2;
    c = &b;
    **c = 3;

    //cout << "\n" << a;
    //cout << *b;
    //cout << **c;

    
    /**
     * 01 a1
     * 02 a2
     * 03 a3
     * 04 ...
     * 
     * 
     * 
     * 11 b1
     */

    //cout << arr;

    // Queue<int> r1 = Queue<int>{3};
    // Queue<int> r2 = Queue<int>{5};

    // //hwid spoofer 
    // r1.add(4);
    // r1.add(5);

    // r1.traverse();

    // r2.add(8);

    // int poppedValue = r1.pop();

    // r1.traverse();


    for (auto val : vec1) {
        cout << val << endl;
    }

    int length = sizeof(arr)/sizeof(arr[0]);
    for(int n=0; n<length; n++) {
        std::cout << arr[n] << "\n";
    };

    do {

    } while (false);

    while(false) {

    }

    vector<int> ar = { 1, 2, 3, 4, 5 };
    vector<int>::iterator ptr;
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
        cout << *ptr << " ";
    //        Min-Heap         Binary Search Tree               AVL BTree   
    //          1                    6                              6
    //         / \                  / \                            / \
    //      2       3             4     8                         
    //     / \     / \           / \     \
    //    4   5   6    7            5     16
    //                                      \
    //                                      24
    // O(n) O(logN)   log_2(8) = 3  2^n = 8   2^log_2(x) = x  log_2(2^x) = x
    //
    //possible errors with complex types
    // Node<int> node = Node(1);

    //      
    //    4
    //  3   5

    //TODO Look at BinarySearchTree.h file, prepare questions.
    AVLTree<int> AVLRoot = AVLTree<int>{10};
    AVLRoot.add(20);
    AVLRoot.add(30);
    AVLRoot.add(40);
    AVLRoot.add(50);
    AVLRoot.add(25);


    //TODO read about dfs and bfs online
    cout << "\n DFS Preorder traversal \n";
    AVLRoot.preorderTraverse(myPrint);

    //TODO use debugger step into function to trace how this method works using function callback
    cout << "\n DFS Inorder traversal \n";
    AVLRoot.inorderTraverse(myPrint);

    cout << "\n DFS Postorder traversal \n";
    AVLRoot.postorderTraverse(myPrint);

    cout << "\n BST traversal \n";
    AVLRoot.breadthFirstTraversal(myPrint);






}