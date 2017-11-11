#include <iostream>
#include <vector>
template <typename T>
class Deque {
    public:
        Deque(int size)
            : m_size(0), m_head(-1), m_tail(0), m_capacity(size), m_buffer(size)
        {}
        bool push_front(const T& data)
        {
            if (this->full())
                return false;
            if (m_head == -1)
            {
                m_head = 0;
                m_tail = 0;
            }
            else{
                m_head = (m_head == 0) ? m_capacity - 1: m_head - 1;
            }
            m_buffer[m_head] = data;
            m_size++;
            return true;
        }
        bool push_back(const T& data)
        {
            if (this->full())
                return false;

            if (m_head == -1)
            {
                m_head = 0;
                m_tail = 0;
            }
            else
                m_tail = (m_tail + 1) % m_capacity;
            m_buffer[m_tail] = data;
            m_size++;

            return true;
        }
        bool pop_front(void)
        {
            if (this->empty())
                return false;
            if(m_head == m_tail)
            {
                m_head = -1;
                m_tail = -1;
            }
            else
                m_head = (m_head + 1) % m_capacity;
            m_size--;
            return true;
        }
        bool pop_back(void)
        {
            if (this->empty())
                return false;
            if(m_head == m_tail)
            {
                m_head = -1;
                m_tail = -1;
            }
            else
            {
                if (m_tail == 0)
                    m_tail = m_capacity - 1;
                else
                    --m_tail;
            }
            m_size--;
            return true;
        }
        T front(void) const
        {
            return m_buffer[m_head];
        }
        T back(void) const
        {
            return m_buffer[m_tail];
        }
        bool empty(void) const
        {
            return m_size == 0;
        }
        bool full(void) const
        {
            return m_size == m_capacity;
        }
        int size(void) const { return m_size; }
    private:
        int m_size;
        int m_head;
        int m_tail;
        int m_capacity;
        std::vector<T> m_buffer;
};
int main() {
    Deque<int> mydeque(3);
    mydeque.push_front(1);
    mydeque.push_back(3);
    std::cout << mydeque.front() << " " << mydeque.back() << std::endl;
    std::cout << mydeque.size() << std::endl;
    mydeque.pop_back();
    std::cout << mydeque.front() << " " << mydeque.back() << std::endl;
    std::cout << mydeque.size() << std::endl;
}
