#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>

class registro{
    public:
            registro();
            virtual ~registro();
            
            void setId(int id);
            int getId();

            void setUser(char user);
            char getUser();

            void setRating(int rating);
            int getRating();

    protected:

    private:
            int id;
            char user;
            int rating;
};

#endif // REGISTRO_H
