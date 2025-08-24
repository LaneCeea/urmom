#include <array>
#include <bit>
#include <string_view>
#include <print>

namespace {

constexpr std::uint64_t c_urmom = 0x6D6F6D7275ull;

void urmom5() {
    constexpr auto to_array_of_char = std::bit_cast<std::array<char, 8>>(c_urmom);
    std::string_view via_sv(to_array_of_char.data(), to_array_of_char.size());
    std::println("{:.5}", via_sv);
}

} // namespace

int main() {
    if constexpr (std::endian::native != std::endian::little) {
        std::println(stderr, "no bitches");
        return 0;
    }

    urmom5();
}
