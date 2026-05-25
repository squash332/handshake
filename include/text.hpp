#pragma once 

#include "constants.hpp"

class Text {
public:
    Text(const char** lines_, int speed = TEXT_SPEED_FAST, int fontSize = FONT_SIZE_MEDIUM);
    
    void update();
    void skip();
    bool isDone() const;
    bool isLineDone() const;
    int  charsShown() const;
    const char* getText() const;
    int  getFontSize() const;

    void next();
    int getCurrentLine() const;

private:
    const char** m_lines_ = {0};
    int m_current_line_   = 0;
    int m_delay_counter_ = 0;
    bool m_waiting_ = false;
    int m_frame_counter_ = 0;
    int m_chars_shown_   = 0;
    int m_animation_speed_;
    int m_font_size_;
    bool m_done_ = false;

};