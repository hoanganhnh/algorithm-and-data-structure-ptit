# **Map**
```c++
    map<type, type> variable = { key, value };
```

>Example


```c++
    map<int, int> mp;
    m.insert({ 1, 100 });
    m[2] = 200;

    for (pair<int, int> p : mp) {
        cout << p.first << " " << p.second <<  endl;
    }
    /*
        1 100
        2 200    
    */

    /* Find element by key */

    if (mp.count(1) != 0) {
        cout << "Found";
    } // ==> Found

    if (mp.find(1) != mp.end()) {
        cout << "Found";
    } // ==> Found

    /* Delete element */

    mp.erase(2);
```