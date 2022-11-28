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

    ge211::Rectangle_sprite const box_sprite;
    ge211::Rectangle_sprite const box_sprite_wrong;

    ge211::Font sans30_{"sans.ttf", 30};
    ge211::Text_sprite letter_sprite_[6][5];

};
