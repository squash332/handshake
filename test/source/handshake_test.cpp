#include "lib.hpp"

auto main() -> int
{
  auto const lib = library {};

  return lib.name == "handshake" ? 0 : 1;
}
