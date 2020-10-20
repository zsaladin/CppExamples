#pragma once


using namespace std;

struct Transaction
{
    const int txID;
    const int fromID;
    const int toID;
    const int value;

    class Builder
    {
    private:
        int _fromID;
        int _toID;
        int _value;

    public:
        Transaction build()
        {
            int txID = _fromID ^ _toID ^ _value;
            return Transaction{txID, _fromID, _toID, _value};
        }


        Builder& setFromID(int fromID)
        {
            _fromID = fromID;
            return *this;
        }

        Builder& setToID(int toID)
        {
            _toID = toID;
            return *this;
        }

        Builder& setValue(int value)
        {
            _value = value;
            return *this;
        }
    };
};





void buildTransaction()
{
    Transaction::Builder builder;
    Transaction tx = builder.build();
}
