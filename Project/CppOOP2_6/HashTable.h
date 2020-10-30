#pragma once
#include <vector>
#include <string>

using Key = std::string;
using Value = std::string;
using KeyValue = std::pair<Key, Value>;


class Bucket
{
private:
    std::vector<KeyValue> _items;

public:
    Value& get(const Key& key)
    {
        for (KeyValue& keyValue : _items)
        {
            if (keyValue.first == key)
            {
                return keyValue.second;
            }
        }
        _items.push_back(std::make_pair(key, Value()));
        return _items.back().second;
    }
};

class HashTable
{
private:
    std::vector<Bucket> _buckets;

    int hash(const Key& key) const
    {
        int h = 0;
        for (char ch : key)
        {
            h += ch;
        }
        return h;
    }

public:
    HashTable(int size = 100)
        : _buckets(std::vector<Bucket>(size))
    {

    }

    Value& operator[](const Key& key)
    {
        int bucketIndex = hash(key) % _buckets.size();
        Bucket& bucket = _buckets[bucketIndex];
        return bucket.get(key);
    }
};

// bucket, bucket, bucket, bucket, bucket, bucket...
// key: "abc" <- hash
// value: "def"

// key: "cba" <- hash 
// value:: "123"
