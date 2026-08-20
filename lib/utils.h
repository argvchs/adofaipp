#ifndef UTILS_H
#define UTILS_H
#include <format>
template <typename T> constexpr std::string get_kv(std::string_view k, std::optional<T> x) {
    if (x) return std::format(R"("{}":{},)", k, *x);
    return "";
}
constexpr std::string get_kv(std::string_view k, std::optional<std::string_view> x) {
    if (x) return std::format(R"("{}":"{}",)", k, *x);
    return "";
}
template <typename T>
constexpr std::string get_kv(std::string_view k, std::optional<T> x, std::optional<T> y) {
    if (x) {
        if (y) return std::format(R"("{}":[{},{}],)", k, *x, *y);
        return std::format(R"("{}":[{},null],)", k, *x);
    }
    if (y) return std::format(R"("{}":[null,{}],)", k, *y);
    return "";
}
#endif
