#include <cstring>

#include "text.hpp"

#include "constants.hpp"

Text::Text(const char** text, int speed, int fontSize)
    : m_lines_(text)
    , m_animation_speed_(speed)
    , m_font_size_(fontSize)
    , m_frame_counter_(0)
    , m_delay_counter_(0)
    , m_chars_shown_(0)
    , m_done_(false)
{
}

void Text::skip()
{
  int lineLen = strlen(m_lines_[m_current_line_]);
  if (m_chars_shown_ < lineLen) {
    m_chars_shown_ = lineLen;
    m_frame_counter_ = lineLen * m_animation_speed_;
  } else {
    m_waiting_ = false;
    m_delay_counter_ = 0;
    next();
  }
}


int Text::getCurrentLine() const
{
  return m_current_line_;
}

void Text::update()
{
  if (m_animation_speed_ == TEXT_SPEED_INSTANT) {
    m_chars_shown_ = (int)strlen(m_lines_[m_current_line_]);
    return;
  }
  if (m_waiting_) {
    if (++m_delay_counter_ >= LINE_DELAY) {
      m_waiting_ = m_done_ = false;
      m_delay_counter_ = 0;
      next();
    }
    return;
  }

  if (isLineDone()) {
    m_waiting_ = true;
  }

  m_frame_counter_++;
  m_chars_shown_ = m_frame_counter_ / m_animation_speed_;
  if (m_chars_shown_ >= (int)strlen(m_lines_[m_current_line_])) {
    m_chars_shown_ =
        (int)strlen(m_lines_[m_current_line_]);  // clamp, don't mark done
  }
}

void Text::next()
{
  if (m_lines_[m_current_line_ + 1] != nullptr) {
    m_current_line_++;
    m_frame_counter_ = 0;
    m_chars_shown_ = 0;
    m_done_ = false;
  } else {
    m_done_ = true;
  }
}

const char* Text::getText() const
{
  return m_lines_[m_current_line_];
}

int Text::charsShown() const
{
  return m_chars_shown_;
}

int Text::getFontSize() const
{
  return m_font_size_;
}

bool Text::isLineDone() const
{
  return m_chars_shown_ >= (int)strlen(m_lines_[m_current_line_]);
}

bool Text::isDone() const
{
  return m_done_;
}
