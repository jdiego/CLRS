#include <stack>
#include <iostream>
template<typename T>
class Queue
{
    public:
        void enqueue(const T& x)
        {
            buffer.push(x);
        }
        T dequeue()
        {
            std::stack<T> aux;
            T tmp;
            while(not buffer.empty())
            {
                tmp = buffer.top();
                aux.push(buffer.top());
                buffer.pop();
            }
            aux.pop();
            while(not aux.empty())
            {
                buffer.push(aux.top());
                aux.pop();
            }
            return tmp;
        }
    private:
        std::stack<T> buffer;
};
int main(void)
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    for(int i = 0; i < 3; ++i)
        std::cout << " " << q.dequeue();
    return 0;
}
