#ifndef REGISTRO_H
#define REGISTRO_H
#include <iostream>
#include <string.h>

using namespace std;

class registro{
    public:
            registro();
            virtual ~registro();
            
            void setId(int id);
            int getId();

            void setUser(string user);
            string getUser();

            void setRating(int rating);
            int getRating();

	    void setDescricao(string descricao);
	    string getDescricao();
    protected:

    private:
            int id;
            string user;
            int rating;
	    string descricao;
};

#endif // REGISTRO_H
