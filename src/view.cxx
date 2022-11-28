#include "view.hxx"

// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;
static int const grid_size = 50;
static ge211::Color const white {255, 255, 255};
static ge211::Color const black {0, 0, 0};
static ge211::Color const green {11, 82, 30};
// Shouldn't need this
// static ge211::Color const red {255, 0, 0};
static ge211::Color const grey {128, 128, 128};
static ge211::Color const yellow{237, 237, 92};

View::View(Model const& model)
        : model_(model)
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    for(size_t i = 0; i < model_.get_char_count(); i++)
    {
        ge211::Text_sprite::Builder letter_builder(sans30_);
        letter_builder << model_.get_letter(i);
        letter_sprite_.reconfigure(letter_builder);
        set.add_sprite(letter_sprite_, {100*int(i),100*int(i)});
    }

}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Wordle";
}