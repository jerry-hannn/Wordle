#pragma once

#include "model.hxx"

class View
{
public:
    /// View dimensions will use `int` coordinates.
    using Dimensions = ge211::Dims<int>;

    /// View positions will use `int` coordinates.
    using Position = ge211::Posn<int>;

    /// View rectangles will use `int` coordinates.
    using Rectangle = ge211::Rect<int>;

    explicit View(Model const&);

    void draw(ge211::Sprite_set& set);

    Dimensions initial_window_dimensions() const;

    std::string initial_window_title() const;

    // // Converts an abstract board position to a concrete screen
    // // position.
    // Position
    // board_to_screen(Model::Position board_pos) const;
    //
    // // Converts a concrete screen (pixel) position to an abstract board
    // // position.
    // Model::Position
    // screen_to_board(Position screen_pos) const;

private:
    Model const& model_;
};
