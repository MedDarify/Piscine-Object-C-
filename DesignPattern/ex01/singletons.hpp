#ifndef SINGLETONS_HPP
#define SINGLETONS_HPP

#include <vector>

template <typename T>
class SingletonList
{
public:
    static SingletonList<T>& getInstance()
    {
        static SingletonList<T> instance;
        return instance;
    }

    void add(T* item)
    {
        _list.push_back(item);
    }

    const std::vector<T*>& getList() const
    {
        return _list;
    }

private:
    SingletonList() {}

    ~SingletonList() {}

    SingletonList(const SingletonList&);
    SingletonList& operator=(const SingletonList&);

    std::vector<T*> _list;
};

#endif 