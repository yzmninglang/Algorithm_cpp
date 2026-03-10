#include<iostream>
#include<cstring>




class ShallCopy{
    public:
        int *data;
        ShallCopy(int val){
            data = new int(val);
        }
        ShallCopy(const ShallCopy& Other):data(Other.data){
            std::cout<<"Shallow Copy Constructor called."<<std::endl;
        }
        ~ShallCopy(){
            // delete data;
        }
        
};

class DeeCopy
{
private:
    /* data */
public:
    int *data;
    DeeCopy(int val)
    {
        data = new int(val);
    };
    DeeCopy(const DeeCopy &Other)
    {
        data = new int(*Other.data);
        std::cout<<"Deep Copy Constructor called."<<std::endl;
    };
    ~DeeCopy(){
        delete data;
    };
};

// DeeCopy::DeeCopy(int val)
// {
//     data = new int(val);   //这个不是数组
// }

// DeeCopy::DeeCopy(const DeeCopy &Other)
// {
//     data = new int(*Other.data);
// }
// DeeCopy::~DeeCopy()
// {
//     delete data;
// }


void test_copy_diff()
{
    std::cout << "=== 1. Shallow Copy Demo ===" << std::endl;
    // std::cout<<""
    ShallCopy s1(100);
    ShallCopy s2 = s1;
    std::cout << "s1.data address: " << (void*)s1.data << " | value: " << *s1.data << std::endl;
    std::cout << "s2.data address: " << (void*)s2.data << " | value: " << *s2.data << std::endl;
    std::cout << "Result: Addresses are SAME. (Dangerous!)" << std::endl;
    
    std::cout << "\n=== 2. Deep Copy Demo ===" << std::endl;
    DeeCopy d1(200);
    DeeCopy d2 = d1;
    std::cout << "d1.data address: " << (void*)d1.data << " | value: " << *d1.data << std::endl;
    std::cout << "d2.data address: " << (void*)d2.data << " | value: " << *d2.data << std::endl;
    std::cout << "Result: Addresses are DIFFERENT. (Safe!)" << std::endl;
}



int main()
{
    test_copy_diff();
    return 0;
}