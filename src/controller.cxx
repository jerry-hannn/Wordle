#include "controller.hxx"


// Controller::Controller()
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

// on key press



void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

