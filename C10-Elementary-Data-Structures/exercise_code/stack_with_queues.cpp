#include <queue>
#include <iostream>
template<typename T>
class Stack
{
    public:
        void push(const T& data)
        {
            buffer.push(data);
        }
        T pop()
        {
            std::queue<T> aux;
            T tmp = buffer.front();
            buffer.pop();
            while(not buffer.empty())
            {
                aux.push(tmp);
                tmp = buffer.front();
                buffer.pop();
            }
            while(not aux.empty())
            {
                buffer.push(aux.front());
                aux.pop();
            }
            return tmp;
        }
    private:
        std::queue<T> buffer;
};
int main(void)
{
    Stack<int> s;
    for(int i = 0; i < 10; ++i)
        s.push(i);
    for(int i = 0; i < 10; ++i)
        std::cout<< " " << s.pop();
    std::cout << std::endl;
}
