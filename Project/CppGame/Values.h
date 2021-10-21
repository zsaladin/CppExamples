#pragma once

#include <vector>
#include <functional>

template<typename T>
class ObservableValue
{
    using Observer = std::function<void(const T&)>;
private:
    T _value;
    std::vector<Observer> _observers;

public:
    const T& get() const
    {
        return _value;
    }

    void set(const T& value)
    {
        _value = value;
        for (auto& observer : _observers)
        {
            observer(value);
        }
    }

    void observe(Observer func)
    {
        _observers.push_back(func);
    }
};


struct Values
{
    ObservableValue<int> score;
};


