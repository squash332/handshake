#include <cstring>

#include "text.hpp"
#include "constants.hpp"

Text::Text(const char* text, int speed, int fontSize)
    : m_text_(text)
    , m_animation_speed_(speed)
    , m_font_size_(fontSize)
    , m_frame_counter_(0)
    , m_chars_shown_(0)
    , m_done_(false)
{
}

void Text::skip()
{
  if (m_chars_shown_ < (int)strlen(m_text_)) {
    m_frame_counter_ = strlen(m_text_) * m_animation_speed_;
  } else {
    m_done_ = true;
  }
}

void Text::update()
{
  m_frame_counter_++;
  m_chars_shown_ = m_frame_counter_ / m_animation_speed_;
  if (m_chars_shown_ >= (int)strlen(m_text_)) {
    m_done_ = true;
  }
  
  // if we set animation speed to instant, instantly render text
  if(m_animation_speed_ == TEXT_SPEED_INSTANT) {
    m_chars_shown_ = (int)strlen(m_text_);
    m_done_ = true;
  }
}

const char* Text::getText() const
{
  return m_text_;
}

int Text::charsShown() const
{
  return m_chars_shown_;
}

int Text::getFontSize() const
{
  return m_font_size_;
}

bool Text::isDone() const
{
  return m_done_;
}
