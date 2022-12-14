#include "model.hxx"
#include <catch.hxx>


TEST_CASE("Enter the wrong word, no shared letters."){
    std::vector<std::string> words = {"hello", "world"};
    Model model(words);
    CHECK(model.get_winner() == Model::winner_type::not_yet);
    model.hit_key('w');
    model.set_char_count();
    model.hit_key('a');
    model.set_char_count();
    model.hit_key('v');
    model.set_char_count();
    model.hit_key('i');
    model.set_char_count();
    model.hit_key('n');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 1);
    CHECK(model.get_pos(0,0) == Model::Letter_outcome::not_in_word);
    CHECK(model.get_pos(0,1) == Model::Letter_outcome::not_in_word);
    CHECK(model.get_pos(0,2) == Model::Letter_outcome::not_in_word);
    CHECK(model.get_pos(0,3) == Model::Letter_outcome::not_in_word);
    CHECK(model.get_pos(0,4) == Model::Letter_outcome::not_in_word);
    CHECK(model.size_unused() == 5);

    //the sort function should sort the unused letters in alphabetical order
    CHECK(model.get_unused(0) == 'a');
    CHECK(model.get_unused(1) == 'i');
    CHECK(model.get_unused(2) == 'n');
    CHECK(model.get_unused(3) == 'v');
    CHECK(model.get_unused(4) == 'w');
}

TEST_CASE("test correct word, followed by pressing n and another correct word"){
    std::vector<std::string> words = {"hello", "world"};
    Model model(words);
    CHECK(model.get_winner() == Model::winner_type::not_yet);
    model.hit_key('h');
    model.set_char_count();
    model.hit_key('e');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    //Simulates pressing enter
    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_pos(0, 0) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 1) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 2) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 3) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 4) == Model::Letter_outcome::correct_pos);

    CHECK(model.get_winner() == Model::winner_type::win);
    CHECK(model.get_tries_count() == 1);
    CHECK(model.size_unused() == 0);

    //Simulates pressing n
    model.hit_key('n');
    model.load_next_word_();

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 0);
    CHECK(model.size_unused() == 0);
    CHECK(model.get_current_word() == "world");


    //second word
    model.hit_key('w');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    model.hit_key('r');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('d');
    model.set_char_count();
    CHECK(model.get_current_word() == "world");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_winner() == Model::winner_type::win);
    CHECK(model.get_tries_count() == 1);
    CHECK(model.size_unused() == 0);
}


//checks entering the wrong word 6 times. Should end with a loss.
TEST_CASE("6 wrong words. End in loss")
{
    std::vector<std::string> words = {"hello", "world"};
    Model model(words);
    CHECK(model.get_winner() == Model::winner_type::not_yet);
    model.hit_key('j');
    model.set_char_count();
    model.hit_key('e');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    //Simulates pressing enter
    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_pos(0, 0) == Model::Letter_outcome::not_in_word);
    CHECK(model.get_pos(0, 1) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 2) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 3) == Model::Letter_outcome::correct_pos);
    CHECK(model.get_pos(0, 4) == Model::Letter_outcome::correct_pos);

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 1);
    CHECK(model.size_unused() == 1);
    CHECK(model.get_unused(0) == 'j');

    //second word
    model.hit_key('j');
    model.set_char_count();
    model.hit_key('e');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 2);
    CHECK(model.size_unused() == 1);

    //third word
    model.hit_key('j');
    model.set_char_count();
    model.hit_key('e');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 3);

    //fourth word
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    model.hit_key('u');
    model.set_char_count();
    model.hit_key('s');
    model.set_char_count();
    model.hit_key('y');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 4);

    //fifth word
    model.hit_key('c');
    model.set_char_count();
    model.hit_key('r');
    model.set_char_count();
    model.hit_key('a');
    model.set_char_count();
    model.hit_key('z');
    model.set_char_count();
    model.hit_key('y');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 5);

    //sixth and final word
    model.hit_key('f');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('u');
    model.set_char_count();
    model.hit_key('t');
    model.set_char_count();
    model.hit_key('e');
    model.set_char_count();
    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    //Should be lose.
    CHECK(model.get_winner() == Model::winner_type::lose);
    CHECK(model.get_tries_count() == 6);

}


TEST_CASE("test word with common letters, in the wrong place"){
    std::vector<std::string> words = {"hello", "world"};
    Model model(words);
    CHECK(model.get_winner() == Model::winner_type::not_yet);
    model.hit_key('b');
    model.set_char_count();
    model.hit_key('l');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    model.hit_key('o');
    model.set_char_count();
    model.hit_key('m');
    model.set_char_count();

    CHECK(model.get_current_word() == "hello");

    model.hit_enter();
    model.check_letters();
    model.sort_unused();
    model.is_winner();
    model.update_tries();

    CHECK(model.get_pos(0, 0) == Model::Letter_outcome::not_in_word);
    CHECK(model.get_pos(0, 1) == Model::Letter_outcome::incorrect_pos);
    CHECK(model.get_pos(0, 2) == Model::Letter_outcome::incorrect_pos);
    CHECK(model.get_pos(0, 3) == Model::Letter_outcome::incorrect_pos);
    CHECK(model.get_pos(0, 4) == Model::Letter_outcome::not_in_word);

    CHECK(model.get_winner() == Model::winner_type::not_yet);
    CHECK(model.get_tries_count() == 1);
    CHECK(model.size_unused() == 2);
    CHECK(model.get_unused(0) == 'b');
    CHECK(model.get_unused(1) == 'm');

}

TEST_CASE("Press 2 immediately, get the second word correct."){
        std::vector<std::string> words = {"hello", "world"};
        Model model(words);
        CHECK(model.get_winner() == Model::winner_type::not_yet);

        model.hit_key('2');
        model.load_next_word_();
        CHECK(model.get_current_word() == "world");

        model.hit_key('h');
        model.set_char_count();
        model.hit_key('e');
        model.set_char_count();
        model.hit_key('l');
        model.set_char_count();
        model.hit_key('l');
        model.set_char_count();
        model.hit_key('o');
        model.set_char_count();

        model.hit_enter();
        model.check_letters();
        model.sort_unused();
        model.is_winner();
        model.update_tries();

        CHECK(model.get_pos(0, 0) == Model::Letter_outcome::not_in_word);
        CHECK(model.get_pos(0, 1) == Model::Letter_outcome::not_in_word);
        CHECK(model.get_pos(0, 2) == Model::Letter_outcome::incorrect_pos);
        CHECK(model.get_pos(0, 3) == Model::Letter_outcome::correct_pos);
        CHECK(model.get_pos(0, 4) == Model::Letter_outcome::incorrect_pos);

        CHECK(model.get_winner() == Model::winner_type::not_yet);
        CHECK(model.get_tries_count() == 1);
        CHECK(model.size_unused() == 2);
        CHECK(model.get_unused(0) == 'e');
        CHECK(model.get_unused(1) == 'h');


        model.hit_key('w');
        model.set_char_count();
        model.hit_key('o');
        model.set_char_count();
        model.hit_key('r');
        model.set_char_count();
        model.hit_key('l');
        model.set_char_count();
        model.hit_key('d');
        model.set_char_count();
        CHECK(model.get_current_word() == "world");

        model.hit_enter();
        model.check_letters();
        model.sort_unused();
        model.is_winner();
        model.update_tries();

        CHECK(model.get_pos(1, 0) == Model::Letter_outcome::correct_pos);
        CHECK(model.get_pos(1, 1) == Model::Letter_outcome::correct_pos);
        CHECK(model.get_pos(1, 2) == Model::Letter_outcome::correct_pos);
        CHECK(model.get_pos(1, 3) == Model::Letter_outcome::correct_pos);
        CHECK(model.get_pos(1, 4) == Model::Letter_outcome::correct_pos);

        CHECK(model.get_winner() == Model::winner_type::win);
        CHECK(model.get_tries_count() == 2);
        CHECK(model.size_unused() == 2);



}