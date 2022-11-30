#include "model.hxx"



Model::Model(const std::vector<std::string>& words)
        : dictionary_(words)

{
    //        current_word_ = dictionary_[index];
    //        index = index + 1;

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 5; c++) {
            squares_[r][c] = ' ';
            pos_check[r][c] = Letter_outcome::not_checked;
        }
    }
    load_next_word_();
}




void
Model::load_next_word_()
{
    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 5; c++) {
            squares_[r][c] = ' ';
            pos_check[r][c] = Letter_outcome::not_checked;
        }
    }
    winner_ = winner_type::not_yet;
    char_count = 0;
    tries = 0;
    unused_.clear();

    current_word_.clear();

    //
    while (word_index < dictionary_.size() && current_word_.empty()) {
        current_word_ = dictionary_[word_index++];
    }
}
void Model::check_letters()
{
    for(int i = 0; i < 5; i++){
        char current_char = tolower(squares_[tries][i]);

        if(current_char == current_word_[i])
        {
            pos_check[tries][i] = Letter_outcome::correct_pos;
        }
        else if (char_in_word(current_char))
        {
            pos_check[tries][i] = Letter_outcome::incorrect_pos;
        }
        else{
            pos_check[tries][i] = Letter_outcome::not_in_word;
            unused_.push_back( current_char);
        }
    }
}

void Model::update_tries()
{
    tries++;
}

bool Model::char_in_word(char c)
{
    for(int i = 0; i < 5; i++){
        if(c == current_word_[i]){
            return true;
        }
    }
    return false;
}

void Model::set_char_count()
{
    // if (char_count < 4)
    // {
    char_count++;
    // }
    // else {
    //     // if (tries < 5)
    //     // {
    //     //     tries++;
    //     // }
    //
    //     char_count = 0;
    // }
}
void Model::hit_key(char actual)
{
    // if (char_count < 5)
    // {
    //     // progress_[char_count] = actual;
    //     // progress_.push_barck(actual);
    //
    //
    //     // char_count = char_count + 1;
    // }
    squares_[tries][char_count] = actual;


}
char Model:: get_letter(size_t i , size_t j) const
{
    // if (index < progress_.size())
    // {
    //     // std::cout << progress_[index] << '';
    //     // return progress_[index];
    //     return
    // }

    return squares_[i][j];
}
size_t Model::get_char_count() const
{
    return char_count;
}
// bool Model::can_evaluate()
// {
//     if ((char_count == 4) )
//     {
//
//     }
// }

size_t Model::get_tries_count() const
{
    return tries;
}
void Model::hit_enter()
{
    enter_ = true;
    char_count = 0;
}

Model::Letter_outcome Model::get_pos(int row, int col)const{
    return pos_check[row][col];
}

int
Model::size_unused() const
{
    return unused_.size();
}
char Model::get_unused(int index) const
{
    return unused_[index];
}
void Model::is_winner()
{
    int correct = 0;
    for(int i = 0; i < 5; i++)
    {
        if(pos_check[tries][i] == Letter_outcome::correct_pos)
        {
            correct++;
        }
    }
    if (correct == 5)
    {
        winner_ = winner_type::win;
    }
    else if(tries == 5 )
    {
        winner_ = winner_type::lose;
    }
}
Model::winner_type Model::get_winner() const
{
    return winner_;
}
void Model::sort_unused()
{
    sort(unused_.begin(),unused_.end());
    unused_.erase( unique( unused_.begin(), unused_.end() ), unused_.end() );
}
void Model::delete_char()
{
    squares_[tries][char_count-1] = ' ';
    char_count = char_count - 1;
}
std::string Model::get_current_word() const
{
    return current_word_;
}