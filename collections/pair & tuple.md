# **Pair**

```c++
    pair<type, type> variable = { first_value, second_value };
```
>Example

```c++
    pair<int, int> v = {100, 200};
    cout << v.first << ' ' << v.second << endl;    // 100 200
```

# **Tuple**

```c++
    tuple<type, type, type> variable = { first_value, second_value, third_value };
```
>Example

```c++
    tuple<int, int, int> v = {100, 200, 300}; /*v = make_pair(100, 200)*/
    cout << get<0>(v) << ' ' << get<1>(v) << get<2>(v) << endl;    // 100 200 300
    
    tuple <char, int, float> geek;
    geek = make_tuple('a', 10, 15.5);
    cout << get<0>(v) << ' ' << get<1>(v) << get<2>(v) << endl; // a 10 15.5
```
