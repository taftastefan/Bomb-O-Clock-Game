#pragma once
#include "question.h"
#include "predifinedQuestions.h"
#include <vector>
#include "json.hpp"

class Questions
{
protected:
    std::vector<Question> intrebari1;
    std::vector<Question> intrebari2;

public:
    Questions()
    {  

        this->intrebari1 = intmod2;

        this->intrebari2 = intrebbarimod1;
        

    }
    std::vector<Question> generare_intrebari()
    {
        std::vector<Question> questions;
        std::cout << intrebari1.size()<<"\n \n";
        srand(0);
        for (int i = 1; i <= 7; i++) {
            int  a = rand() % 25;
            questions.push_back(intrebari2[a]);
        }
        for (int i = 1; i <= 7; i++) {
                int  a = rand() % 24;
            questions.push_back(intrebari1[a]);
         //TODO no duplicate
        }

        return questions;
    }

    nlohmann::json toJson( std::vector<Question> questions) {
        nlohmann::json response;
        for (Question& question : questions) {
            response.push_back(question.toJson());
        }

        return response;
    }
    

};