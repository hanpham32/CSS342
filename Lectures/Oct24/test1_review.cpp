//// Test 1 Question 6
// My Code
template <class T>
void CountUniqueObjects(T[] v)
{
    for (int i = 0; i < v.size(); i++)
    {
        T obj = v[i];

        int count = 0;

        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] == obj)
            {
                count++;
            }
        }
        cout << v[i] << " occurs: " << count << endl;
    }
}

// Correct Code
template <class T>
void CountDuplicates(const vector<T> &input)
{
    vector<T> unique;
    for (int i = 0; i < input.size(); i++)
    {
        if (Contains(input[i], unique))
        {
            continue;
        }
        else
        {
            for (int j = i + 1; j < input.size(); j++)
            {
                int count = 1;
                unique.push_back(input[i]);
                if (input[i] == input[j])
                {
                    count += 1;
                }
            }
            count << input[i] << " " << count;
        }
    }
}

template <class T>
bool Contains(const T &item, const vector<T> unique)
{
    bool ret_val = false;
    for (int i = 0; i < unique.size(); i++)
    {
        if (item == unique[i])
        {
            return true;
        }
    }
    return false;
}