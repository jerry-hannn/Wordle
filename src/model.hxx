#pragma once

#include <ge211.hxx>
#include <cctype>

class Model
{
public:

    enum class Letter_outcome
    {
        correct_pos,
        incorrect_pos,
        not_in_word,
    };

    explicit Model(const std::vector<std::string>& words);

    explicit Model(Model const&);

    using Pos_check_vector = std::vector<Letter_outcome>;

    // Check if typed word is correct. (might use strcmp)


    // if character is in the word but wrong pos (will update the pos_check
    // vector)


    //

private:
    std::string current_word_;
    std::vector<char> progress_;
    std::vector<std::string> dictionary_;
    Pos_check_vector pos_check;
    bool winner_;



};
