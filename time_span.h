#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_

class TimeSpan
{
    public:
        TimeSpan();
        TimeSpan(int seconds);
        TimeSpan(int minutes, int seconds);
        TimeSpan(int hours, int minutes, int seconds);

        int getHours() const;
        int getMinutes() const;
        int getSeconds() const;

        void setTime(int hours, int minutes, int seconds);

    private:
        int hours_;
        int minutes_;
        int seconds_;
};
#endif