

class Queue
{
public:
    void push(int x)
    {
        A_.emplace(x);
    }

    void pop(void)
    {
        peek();
        B_.pop();
    }

    int peek(void)
    {
        if (B_.empty())
        {

            while (!A_.empty())
            {
                B_.emplace(A_.top());
                A_.pop();
            }
        }
        if (B_.empty())
        {
            throw length_error("empty queue");
        }
        return B_.top();
    }

    bool empty(void)
    {
        return A_.empty() && B_.empty();
    }

private:
    stack<int> A_, B_;
};
