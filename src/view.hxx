#pragma once

#include "model.hxx"

class View
{
public:
    using Dimensions = ge211::Dims<int>;

    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

private:
    Model const& model_;

    ge211::Rectangle_sprite const box_sprite_right;
    ge211::Rectangle_sprite const box_sprite_bad_pos;
    ge211::Rectangle_sprite const box_sprite_wrong;
    ge211::Rectangle_sprite const box_sprite_empty;

    ge211::Font sans30_{"sans.ttf", 30};
    ge211::Font sans72_{"sans.ttf", 72};
    ge211::Font sans20_{"sans.ttf", 20};

    ge211::Text_sprite letter_sprite_[6][5];
    ge211::Text_sprite letter_sprite2_[3][10];
    ge211::Text_sprite win_message{"You Win", sans72_};
    ge211::Text_sprite word;
    ge211::Text_sprite word2;
    ge211::Text_sprite exit_mes;
    ge211::Text_sprite exit_mes2;
    ge211::Text_sprite instructions;
    ge211::Text_sprite instructions1;
    ge211::Text_sprite instructions2;
    ge211::Text_sprite instructions3;
    ge211::Text_sprite instructions4;


};
