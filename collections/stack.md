# **Map**
```c++
    stack<type> variable;
```

>Example

```c++
    stack<int> st;
    /*
        push
    */
    st.push(1);
    st.push(2);
    st.push(3);
    /*
        top
    */
    cout << st.top() << endl; // 3
    /*
        pop
    */
    st.pop();

    cout << st.size() << endl; // 2

    st.pop();
    st.pop();
    /*
        empty
    */
    if (st.empty()) {
        cout << "Empty" << endl;
    }
```