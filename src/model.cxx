#include "model.hxx"


Model::Model(const std::vector<std::string>& words)
        : dictionary_(words)

{
    //        current_word_ = dictionary_[index];
    //        index = index + 1;
    load_next_word_();
}


void Model::check_letters(std::vector<char> char_vec) 
{
   for (int i = 0; i < 5; i++) {
       if (char_vec.at(i) == current_word_[i]) {
           pos_check.push_back(Letter_outcome::correct_pos);
       }
       else if(char_in_word(char_vec.at(i), current_word_)) {
           pos_check.push_back(Letter_outcome::incorrect_pos);
       }
       else {
           pos_check.push_back(Letter_outcome::not_in_word);
       }
   }
}

bool Model::char_in_word(char c, std::string word)
{
    for (int i = 0; i < word.length(); i++) {
        if (c == word[i]) {
            return true;
        }
    }
    return false;
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
    else
    {
        char_count = 0;
    }
}
void Model::hit_key(char actual)
{
    if (char_count < 5)
    {
        // progress_[char_count] = actual;
        progress_.push_back(actual);
        // char_count = char_count + 1;
    }
}
char Model:: get_letter(size_t index) const
{
    if (index < progress_.size())
    {
        return progress_[index];
    }
    return 'x';
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