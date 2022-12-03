#include "view.hxx"
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;
static int const grid_size_guess = 50;
static int const grid_size_wrong = 25;
static int const border_buffer = 50;
static int const inbetween = 25;
static int const wrong_start = 500;
static ge211::Color const white {255, 255, 255};
static ge211::Color const black {0, 0, 0};
static ge211::Color const green {11, 82, 30};
// Shouldn't need this
// static ge211::Color const red {255, 0, 0};
static ge211::Color const grey {128, 128, 128};
static ge211::Color const yellow{237, 237, 92};



View::View(Model const& model)
        : model_(model),
          box_sprite_right( {(grid_size_guess-1),(grid_size_guess-1)} ,green),
          box_sprite_wrong( {(grid_size_guess-1),(grid_size_guess-1)} ,grey),
          box_sprite_bad_pos({(grid_size_guess-1),(grid_size_guess-1)}, yellow),
          box_sprite_empty({(grid_size_guess-1),(grid_size_guess-1)}, white)



{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    for (int j = 0; j < 6; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            // set.add_sprite(box_sprite, {50,50});
            set.add_sprite(box_sprite_empty, {border_buffer + i*grid_size_guess, border_buffer +j*(grid_size_guess+inbetween)});
        }
    }

    ge211::Text_sprite::Builder name_builder4(sans20_);
    name_builder4.color(white);
    name_builder4<<"Instructions";
    instructions.reconfigure(name_builder4);
    set.add_sprite(instructions, {450,70},4);

    ge211::Text_sprite::Builder name_builder5(sans20_);
    name_builder5<<"Hit '1' to exit";
    instructions1.reconfigure(name_builder5);
    set.add_sprite(instructions1, {370,100},4);

    ge211::Text_sprite::Builder name_builder6(sans20_);
    name_builder6<<"Hit '2' to get a new word ";
    instructions2.reconfigure(name_builder6);
    set.add_sprite(instructions2, {370,140},4);





    if(model_.get_winner() != Model::winner_type::not_yet)
    {
        ge211::Text_sprite::Builder name_builder2(sans30_);
        ge211::Color test2 = Color({255,16,240});
        name_builder2.color(test2);
        name_builder2<<"Press 'n' to get new word ";
        exit_mes.reconfigure(name_builder2);
        set.add_sprite(exit_mes, {370,400},4);

        ge211::Text_sprite::Builder name_builder3(sans30_);
        ge211::Color test3 = Color({255,16,240});
        name_builder3.color(test3);
        name_builder3<<"or 'q' to quit";
        exit_mes2.reconfigure(name_builder3);
        set.add_sprite(exit_mes2, {475,450},4);

        if(model_.get_winner() == Model::winner_type::win)
        {
            ge211::Text_sprite::Builder name_builder(sans72_);
            ge211::Color test = Color({255,16,240});
            name_builder.color(test);
            name_builder<<"YOU WIN";
            win_message.reconfigure(name_builder);
            set.add_sprite(win_message, {370,200},4);

        }
        if(model_.get_winner() == Model::winner_type::lose)
        {
            ge211::Text_sprite::Builder name_builder(sans72_);
            ge211::Color test = Color({255,16,240});
            name_builder.color(test);
            name_builder<<"YOU LOSE";
            win_message.reconfigure(name_builder);
            set.add_sprite(win_message, {370,200},4);

            ge211::Text_sprite::Builder name_builder9(sans30_);
            ge211::Color test3 = Color({255,16,240});
            name_builder9.color(test3);
            name_builder9 << "Correct word was";
            word2.reconfigure(name_builder9);
            set.add_sprite(word2, {410,300},6);

            ge211::Text_sprite::Builder name_builder1(sans30_);
            ge211::Color test1 = Color({255,16,240});
            name_builder1.color(test1);
            name_builder1 << "\""<<model_.get_current_word()<< "\"";
            word.reconfigure(name_builder1);
            set.add_sprite(word, {520,340},6);


        }
    }

    for (int r= 0; r < 6; r++) {
        for (int c = 0; c < 5; c++) {
            //fill text sprite with letter
            ge211::Text_sprite::Builder letter_builder(sans30_);
            letter_builder.color(black);
            letter_builder << model_.get_letter(r, c);
            //letter_builder << 'a';
            letter_sprite_[r][c].reconfigure(letter_builder);

            // put at position
            set.add_sprite(letter_sprite_[r][c], {border_buffer
                                                  +c*grid_size_guess+20, border_buffer +r*
                                                                                        (grid_size_guess+inbetween)},4);
            if (model_.get_pos(r,c) == Model::Letter_outcome::correct_pos)
            {
                set.add_sprite(box_sprite_right, {border_buffer
                                                  +c*grid_size_guess, border_buffer +r*
                                                                                     (grid_size_guess+inbetween)},2);
            }
            else if (model_.get_pos(r,c) == Model::Letter_outcome::not_in_word)
            {
                set.add_sprite(box_sprite_wrong, {border_buffer
                                                  +c*grid_size_guess, border_buffer +r*
                                                                                     (grid_size_guess+inbetween)},2);
            }
            else if (model_.get_pos(r,c) == Model::Letter_outcome::incorrect_pos)
            {
                set.add_sprite(box_sprite_bad_pos, {border_buffer +
                                                    c*grid_size_guess, border_buffer +r*
                                                                                      (grid_size_guess+inbetween)},2);
            }
        }
    }

    int r = 0;
    int c = 0;
    for(int i =0; i < model_.size_unused(); i++ )
    {

        ge211::Text_sprite::Builder letter_builder(sans30_);
        letter_builder << model_.get_unused(i);
        letter_sprite2_[r][c].reconfigure(letter_builder);
        set.add_sprite(letter_sprite2_[r][c], {border_buffer +c*grid_size_wrong,wrong_start +r*(grid_size_wrong)});
        if(c == 9 )
        {
            c = 0;
            r++;
        }
        c++;
    }
}

View::Dimensions
View::initial_window_dimensions() const
{
    return {800,650};
}

std::string
View::initial_window_title() const
{
    return "Wordle";
}