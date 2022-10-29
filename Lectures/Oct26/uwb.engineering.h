#ifndef UWBEngineering_H_
#define UWBEngineering_H_
#include <vector>
class UWBEngineering
{
public:
    UWBEngineering();
    UWBEngineering(ClassRoom room, Time start_time);

    ClassRoom room() const;
    Time time() const;

    bool set_room(const ClassRoom &room);
    bool set_start_time(const Time &start_time);

    bool AddStudent(const Student &student);
    bool DropStudent(const Student &student);

    // friend std::ostream& operator <<

private:
    std::vector<Students> students_;
    ClassRoom room_;
    Time start_time;
};

#endif
