#ifndef FILE_H
#define FILE_H
#include <fstream>
#include <vector>
inline std::vector<double> read_angle_data(const char *src) {
    std::ifstream in(src, std::ios::binary | std::ios::ate);
    std::string s;
    std::streamsize n = in.tellg();
    s.resize(n);
    in.seekg(std::ios::beg);
    in.read(s.data(), n);
    std::size_t p = s.find("\"angleData\":");
    p = s.find('[', p);
    std::vector<double> v;
    while (s[++p] != ']')
        if (('0' <= s[p] && s[p] <= '9') || s[p] == '-') {
            double x;
            p = std::from_chars(s.data() + p, s.data() + s.size(), x).ptr - s.data();
            v.push_back(x);
        }
    return v;
}
inline void inject(const char *src, const char *dst, std::string_view actions,
                   std::string_view decorations) {
    std::ifstream in(src, std::ios::binary | std::ios::ate);
    std::ofstream out(dst);
    std::string s;
    std::streamsize n = in.tellg();
    s.resize(n);
    in.seekg(std::ios::beg);
    in.read(s.data(), n);
    in.close();
    std::size_t p = s.find("\"actions\":");
    p = s.find('[', p) + 1;
    out << std::string_view(s.data(), s.data() + p);
    out << actions;
    std::size_t q = s.find("\"decorations\":", p);
    q = s.find('[', q) + 1;
    out << std::string_view(s.data() + p, s.data() + q);
    out << decorations;
    out << std::string_view(s.data() + q, s.data() + n);
}
inline void inject(const char *src, const char *dst, const std::vector<double> &angle_data,
                   std::string_view actions, std::string_view decorations) {
    std::ifstream in(src, std::ios::binary | std::ios::ate);
    std::ofstream out(dst);
    std::string s;
    std::streamsize n = in.tellg();
    s.resize(n);
    in.seekg(std::ios::beg);
    in.read(s.data(), n);
    in.close();
    std::size_t p = s.find("\"angleData\":");
    p = s.find('[', p) + 1;
    out << std::string_view(s.data(), s.data() + p);
    for (double x : angle_data) out << x << ',';
    p = s.find(']', p);
    std::size_t q = s.find("\"actions\":", p);
    q = s.find('[', q) + 1;
    out << std::string_view(s.data() + p, s.data() + q);
    out << actions;
    p = s.find("\"decorations\":", q);
    p = s.find('[', p) + 1;
    out << std::string_view(s.data() + q, s.data() + p);
    out << decorations;
    out << std::string_view(s.data() + p, s.data() + n);
}
#endif
