#pragma once

#include "model.hxx"
#include "view.hxx"
#include <iostream>
#include <cstdio>
#include <ge211.hxx>


class Controller : public ge211::Abstract_game
{
public:
    // Controller();
    explicit Controller(std::string const& filename);

    Controller( std::vector<std::string> words);
    ge211::Dims<int> initial_window_dimensions() const;
    std::string initial_window_title() const;

protected:
    void draw(ge211::Sprite_set& set) override;

    // Called by ge211 when the user press a key. We forward the keypress
    // to the model.
    void on_key(ge211::Key key) override;

private:
    Model model_;
    View view_;
};
