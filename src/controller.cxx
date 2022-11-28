#include "controller.hxx"

// void Controller::Controller()
//         : view_(model_)
// { }
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
    if (key.code() == '\r')
    {
        model_.hit_enter();
    }
    else
    {
        model_.hit_key(char(key.code()));
        model_.set_char_count();
    }


    //    if (model_.game_is_finished()) {
    //        model_ = Model {"gameover"};
    //    }
    //
    //    if (model_.typing_progress().empty()) {
    //        load_word_();
    //    }
}
