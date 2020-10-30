#include <iostream>
#include "Vector.h"
#include "String.h"
#include "HashTable.h"


using namespace std;


int main()
{
    Vector v{ 1, 2, 3 };
    cout << v[-1] << endl; // 1
    cout << v[0] << endl;  // 1
    cout << v[1] << endl;  // 2
    cout << v[2] << endl;  // 3
    cout << v[3] << endl;  // 3


    v[0] = 100;
    cout << v[0] << endl;

    const Vector cv{ 1, 2, 3 };
    cout << cv[-1] << endl; // 1
    cout << cv[0] << endl;  // 1
    cout << cv[1] << endl;  // 2
    cout << cv[2] << endl;  // 3
    cout << cv[3] << endl;  // 3


    String s("abc");
    cout << s << endl;
    cout << s[0] << endl;
    cout << s[1] << endl;
    cout << s[2] << endl;
    
    s[0] = 'd';
    cout << s << endl;
    cout << s[0] << endl;


    HashTable hashTable;
    hashTable["abc"] = "def";
    cout << hashTable["abc"] << endl;

    hashTable["abc"] = "123";
    cout << hashTable["abc"] << endl;

    hashTable["cba"] = "456";
    cout << hashTable["cba"] << endl;
    cout << hashTable["abc"] << endl;
}