#pragma once

#include <ge211.hxx>
#include <cctype>
#include <iostream>

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
    bool is_winner();

    // if character is in the word but wrong pos (will update the pos_check
    // vector)
    void is_char_in(char);

    bool char_in_word(char);

    //checks if 5 letters are typed in
    bool is_5_letters();

    void load_next_word_();

     void set_char_count();
     void hit_key(char);
    char get_letter(size_t,size_t) const;
    size_t get_char_count() const;
    size_t get_tries_count() const;
    // bool can_evaluate();
    void hit_enter();


    //

private:
    std::string current_word_;
    std::vector<char> progress_;
    std::vector<std::string> dictionary_;
    Pos_check_vector pos_check;
    bool winner_ = 0;
    std::vector<char> unused_;
    size_t word_index = 0;
    size_t char_count = 0;
    size_t letter_index = 0;
    size_t tries=0;
    char squares_[6][5] ;
    bool enter_ = false;



};
