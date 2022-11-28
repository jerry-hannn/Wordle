#include "view.hxx"
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;
static int const grid_size_guess = 50;
static int const grid_size_wrong = 25;
static int const border_buffer = 50;
static int const inbetween = 25;
static int const wrong_start = 500;



View::View(Model const& model)
        : model_(model),
        box_sprite( {(grid_size_guess-1),(grid_size_guess-1)} ,{255,255,255}),
        box_sprite_wrong( {(grid_size_wrong-1),(grid_size_wrong-1)} ,{255,255,255})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    // for (int j = 0; j < 6; j++)
    // {
    //     for (int i = 0; i < 5; i++)
    //     {
    //         // set.add_sprite(box_sprite, {50,50});
    //         set.add_sprite(box_sprite, {border_buffer + i*grid_size_guess, border_buffer +j*(grid_size_guess+inbetween)});
    //     }
    // }
    //
    // int count = 0;
    // for (int j = 0; j < 3; j++)
    // {
    //     for (int i = 0; i < 10; i++)
    //     {
    //         // set.add_sprite(box_sprite, {50,900});
    //         if (count < 26)
    //         {
    //             set.add_sprite(box_sprite_wrong, {border_buffer + i*grid_size_wrong,
    //                                               wrong_start +j*(grid_size_wrong)});
    //             count = count + 1;
    //         }
    //
    //     }
    // }
    // model_.letter_;

    // for(size_t i = 0; i < model_.get_char_count(); i++)
    // {
    //     ge211::Text_sprite::Builder letter_builder(sans30_);
    //     letter_builder << model_.get_letter(i);
    //     letter_sprite_.reconfigure(letter_builder);
    //     set.add_sprite(letter_sprite_, {100*int(i),100*int(i)});
    // }

    // for(size_t j = 0; j <= model_.get_tries_count(); j++) {
    //     for (size_t i = 0; i < model_.get_char_count(); i++) {
    //         ge211::Text_sprite::Builder letter_builder(sans30_);
    //         letter_builder << model_.get_letter(i);
    //
    //         letter_sprite_.reconfigure(letter_builder);
    //         set.add_sprite(letter_sprite_,
    //                        {border_buffer + int(i) * grid_size_guess,
    //                         border_buffer + int(j) * (grid_size_guess +
    //                         inbetween)});
    //     }
    // }
    for (int r= 0; r < 6; r++) {
        for (int c = 0; c < 5; c++) {
            //fill text sprite with letter
            ge211::Text_sprite::Builder letter_builder(sans30_);
            letter_builder << model_.get_letter(r, c);
            //letter_builder << 'a';
            letter_sprite_[r][c].reconfigure(letter_builder);

            // put at position
            set.add_sprite(letter_sprite_[r][c], {border_buffer +
            c*grid_size_guess, border_buffer +r*(grid_size_guess+inbetween)});
        }
    }

    // set.add_sprite(box_sprite_wrong, {0,500});
    // set.add_sprite(box_sprite, {50,50});
    // set.add_sprite(box_sprite, {100,50});
}

View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return {485,250};
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Wordle";
}