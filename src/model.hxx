#pragma once

#include <ge211.hxx>
#include <cctype>
#include <iostream>
#include<algorithm>

class Model
{
public:
    enum class Letter_outcome
    {
        correct_pos,
        incorrect_pos,
        not_in_word,
        not_checked
    };
    enum class winner_type
    {
        win,
        lose,
        not_yet
    };
    explicit Model(const std::vector<std::string>& words);

    explicit Model(Model const&);

    using Pos_check_vector = std::vector<Letter_outcome>;

    // Check if typed word is correct. (might use strcmp)
    void is_winner();


    // Called on Enter, assigns the correct values to the pos_check array.
    void check_letters();

    bool char_in_word(char);



    void load_next_word_();
    void sort_unused();



    void set_char_count();
    void hit_key(char);
    char get_letter(size_t,size_t) const;
    size_t get_char_count() const;
    size_t get_tries_count() const;
    // bool can_evaluate();
    void hit_enter();
    Letter_outcome get_pos(int row,int col)const;
    void update_tries();
    int size_unused() const;
    char get_unused(int index)const;
    winner_type get_winner()const;
    void delete_char();
    std::string get_current_word()const;

    //

private:
    std::string current_word_;
    // std::vector<char> progress_;
    std::vector<std::string> dictionary_;
    // Pos_check_vector pos_check;
    winner_type winner_ = winner_type::not_yet;
    std::vector<char> unused_;
    size_t word_index = 0;
    size_t char_count = 0;
    size_t tries=0;
    char squares_[6][5] ;
    bool enter_ = false;
    Letter_outcome pos_check[6][5];



};
