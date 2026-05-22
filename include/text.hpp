#pragma once 

#include "constants.hpp"

class Text {
public:
    Text(const char* text, int speed = TEXT_SPEED_SLOW, int fontSize = FONT_SIZE_MEDIUM);
    
    void update();
    void skip();
    bool isDone() const;
    int  charsShown() const;
    const char* getText() const;
    int  getFontSize() const;

private:
    const char* m_text_;
    int m_frame_counter_ = 0;
    int m_chars_shown_   = 0;
    int m_animation_speed_;
    int m_font_size_;
    bool m_done_ = false;
};