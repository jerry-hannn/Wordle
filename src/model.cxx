#include "model.hxx"



Model::Model(const std::vector<std::string>& words)
        : dictionary_(words)

{
    //        current_word_ = dictionary_[index];
    //        index = index + 1;

    for (int r = 0; r < 6; r++) {
        for (int c = 0; c < 5; c++) {
            squares_[r][c] = ' ';
        }
    }
    load_next_word_();
}




void
Model::load_next_word_()
{
    progress_.clear();

    current_word_.clear();

    //
    while (word_index < dictionary_.size() && current_word_.empty()) {
        current_word_ = dictionary_[word_index++];
    }
}
void Model::is_char_in(char X, size_t i)
{
    if (current_word_[i] == X)
    {
        pos_check[i] = Letter_outcome::correct_pos;
    }

}
void Model::set_char_count()
{
    if (char_count < 5)
    {
        char_count++;
    }
    else {
        if (tries < 5)
        {
            tries++;
        }

        char_count = 0;
    }
}
void Model::hit_key(char actual)
{
    // if (char_count < 5)
    // {
    //     // progress_[char_count] = actual;
    //     // progress_.push_back(actual);
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
}