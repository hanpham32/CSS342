#ifndef TEST_H_
#define TEST_H_

template <class T>
class Test
{
public:
    Test();
    void set_value(T obj_i);
    T get_value();

private:
    T m_obj_;
};

#endif