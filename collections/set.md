# **Set**

```c++
    set<type> variable;
```
- [References](https://www.geeksforgeeks.org/set-in-cpp-stl/)
- Method: 
    - size()
    - insert()
    - find()
    - count()
    - erase()


>Example

```c++
    set<int> v;

    /* Add element */
    v.insert(1);
    v.insert(2);
    v.insert(3);

    count << v.size() << endl; // 3

    for (int x: v) {
        cout << x << " " << endl; // 1 2 3
    }
    /* Find element */

    if (v.find(1) != v.end()) {
        cout << "Found";
    } // ==> Found

    if (v.count(1) != 0) {
        cout << "Found";
    } else {
        cout << "Not found";
    } // ==> Found

    /* Delete element */

    v.erase(3); /* v.erase(v.find(3)) */
    count << v.size() << endl; // 2

    for (int x: v) {
        cout << x << " " << endl; // 1 2 
    }
```