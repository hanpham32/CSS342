template <class T>
void SortedList<T>::Sort(vector<T> &vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        T temp = vect[i];
        int j = i;
        while ((j > 0) && vect[j - 1] > temp)
        {
            vect[j] = vect[j - 1];
            j--;
        }
        vect[j] = temp;
    }
}

template <class T>
void SortedList<T>::Sort(vetor<T> &vect)
{
    for (int i = 1; i < vect.size(); i++)
    {
        T temp = vect[i];
        int j = i;
        while ((j > 0) && vect[j-1] > temp)
        {
            vect[j] = vect[j-1];
            j--;
        }
        vect[j] = temp;
    }
}