if (tmp == 0)
                    cout << "{ ";
                else if (tmp == X)
                    cout << "} ";
                else {
                    tmp += x;
                    if (tmp != X)
                        cout << x << " ";
                    else {
                        cout << x;
                        tmp = 0;
                    }
                }