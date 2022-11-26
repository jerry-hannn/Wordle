#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>



class Controller : public ge211::Abstract_game
{
public:
    // Controller();
    explicit Controller(std::string const& filename);

    Controller( std::vector<std::string> words);

    // on key press


protected:
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;
};
