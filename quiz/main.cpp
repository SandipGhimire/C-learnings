#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

struct QuizItem {
    string qn;
    array<string, 4> answers;
    char answer;
};

vector<QuizItem> quiz = {
    {
        "Capital of Nepal?",
        {
            "A. London",
            "B. Berlin",
            "C. Kathmandu",
            "D. Rome",
        },
        'C'
    },
    {
        "Highest mountain in the world located in Nepal?",
        {
            "A. K2",
            "B. Mount Everest",
            "C. Kanchenjunga",
            "D. Lhotse",
        },
        'B'
    },
    {
        "National animal of Nepal?",
        {
            "A. Tiger",
            "B. Cow",
            "C. Rhino",
            "D. Yak",
        },
        'B'
    },
    {
        "National flower of Nepal?",
        {
            "A. Rose",
            "B. Sunflower",
            "C. Rhododendron",
            "D. Lotus",
        },
        'C'
    },
    {
        "Currency of Nepal?",
        {
            "A. Rupee",
            "B. Dollar",
            "C. Yen",
            "D. Euro",
        },
        'A'
    },
    {
        "Famous heritage site located in Kathmandu?",
        {
            "A. Pashupatinath Temple",
            "B. Taj Mahal",
            "C. Angkor Wat",
            "D. Borobudur",
        },
        'A'
    },
    {
        "Which country borders Nepal to the north?",
        {
            "A. India",
            "B. Bhutan",
            "C. China",
            "D. Bangladesh",
        },
        'C'
    },
    {
        "Lumbini is famous as the birthplace of?",
        {
            "A. Lord Shiva",
            "B. Lord Buddha",
            "C. King Prithvi Narayan Shah",
            "D. Araniko",
        },
        'B'
    },
    {
        "National bird of Nepal?",
        {
            "A. Peacock",
            "B. Danphe",
            "C. Eagle",
            "D. Sparrow",
        },
        'B'
    },
    {
        "Which river is the longest in Nepal?",
        {
            "A. Koshi",
            "B. Gandaki",
            "C. Karnali",
            "D. Bagmati",
        },
        'C'
    }
};


int runQuiz()
{
    int score = 0;
    char input;

    for (int i= 0; i < quiz.size(); i++) {
        cout << "\n" << quiz[i].qn << endl;

        for (int j = 0; j < quiz[i].answers.size(); j++) {
            cout << quiz[i].answers[j] << endl;
        }

        cout << "Answers: ";
        cin >> input;

        input = toupper(input);

        if(input == quiz[i].answer) score++;
    }

    return score;
}

int main() {
    cout << "=== Welcome to Quiz ===";

    int score = runQuiz();

    cout << "\nScore: " << score << "/" << quiz.size() << endl;

    return 0;
}
