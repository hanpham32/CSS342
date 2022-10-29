#include "Bird.h"
int main()
{
    Bird robin;
    Bird *p_robin;
    Bird *p_raven;

    p_robin = &robin;
    p_raven = new Bird;
    delete p_raven; // you are deleting the object (Bird) not the pointer
    p_raven = new Bird;

    p_robin->flu_;

    p_raven->wing_span_;

    (*p_robin).flu_; // dereferencing -- pointing to an object, -> will no longer work
}