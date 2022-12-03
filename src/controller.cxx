#include "controller.hxx"

static std::vector<std::string>
load_dictionary(std::string const& filename)
{
    std::ifstream dictionary = ge211::open_resource_file(filename);
    std::vector<std::string> result;
    std::string buffer;

    while (std::getline(dictionary, buffer)) {
        result.push_back(buffer);
    }

    if (dictionary.bad()) {
        throw std::runtime_error("could not read dictionary: " + filename);
    }

    return result;
}

Controller::Controller(std::string const& filename)
        : Controller(load_dictionary(filename))
{ }

Controller::Controller(std::vector<std::string> words)
        : model_(words),
          view_(model_)

{

}
void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_key(ge211::Key key)
{

    if(key.code() == '1' )
    {
        quit();
    }

    else if(key.code() == '2' )
    {
        model_.load_next_word_();
    }

    if((key.code() >= 65 && key.code() <= 122) || key.code() == '\r'|| key
                                                                               .code() == '\b')
    {
        if(model_.get_winner() != Model::winner_type::not_yet)
        {
            if(key.code() == 'n' ||key.code() == 'N' )
            {
                model_.load_next_word_();
            }
            if(key.code() == 'q' ||key.code() == 'Q' )
            {
                quit();
            }
        }
        else{
            if (key.code() == '\r' )
            {
                if(model_.get_char_count() >= 5)
                {
                    model_.hit_enter();
                    model_.check_letters();
                    model_.sort_unused();
                    model_.is_winner();
                    model_.update_tries();
                }


            }
            else if(key.code() == '\b' )
            {
                model_.delete_char();
            }
            else if (key != key.other() ) {
                if (model_.get_char_count() >= 5)
                {
                    return;
                }
                if (model_.get_char_count() < 5)
                {
                    model_.hit_key(char(key.code()));

                }

                model_.set_char_count();


            }
        }
    }


}

ge211::Dims<int>
Controller::initial_window_dimensions() const
{
    return view_.initial_window_dimensions();
}
std::string
Controller::initial_window_title() const
{
    return view_.initial_window_title();
}

