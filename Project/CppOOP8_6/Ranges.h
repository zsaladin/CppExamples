#pragma once
class Ranges
{
    class Iterator
    {
    private:
        unsigned _num;
    public:
        Iterator(unsigned num);
        Iterator operator++();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        unsigned operator*() const;
    };

private:
    unsigned _begin;
    unsigned _end;

public:
    Ranges(unsigned begin, unsigned end);
    Iterator begin() const;
    Iterator end() const;

};
