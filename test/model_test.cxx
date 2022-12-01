#include "model.hxx"
#include <catch.hxx>

TEST_CASE("Wrong word entered")
{
    std::vector<std::string> words = {"hello", "world"};
    Model model(words);
    model.hit_key('j');
    model.hit_key('e');
    model.hit_key('l');
    model.hit_key('l');
    model.hit_key('o');
    CHECK(model.get_current_word() == "hello");
    model.check_letters();
    CHECK(model.get_pos(0, 0) == Model::Letter_outcome::incorrect_pos);
    CHECK(model.get_pos(0, 1) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 2) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 3) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 4) == Model::Letter_outcome::correct_pos);

}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate your functional requirements.
//

TEST_CASE("test current word"){

}