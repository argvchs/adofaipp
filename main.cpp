#include "lib/actions.h"
#include "lib/file.h"
#include "lib/notes.h"
#include <algorithm>
#include <cmath>
#include <numbers>
#include <string>
#include <vector>
std::vector<double> angle_data;
std::string actions;
constexpr double normalize(double x) { return std::fmod(std::fmod(x, 360) + 360, 360); }
constexpr void hezi(double bpm, double duration, std::vector<double> hzs, double start = 0,
                    double end = 0) {
    for (double &hz : hzs) hz = std::ceil(hz / 4);
    int n = 0;
    for (double hz : hzs) n += std::ceil(60 * duration * hz / bpm);
    double b = (180 * n + start - end) * bpm / (180 * duration);
    std::vector<double> v;
    for (double hz : hzs) {
        int m = std::ceil(60 * duration * hz / bpm);
        for (int i = 0; i < m; i++)
            v.push_back(i * (180 * n + start - end) * bpm / (60 * duration * hz));
    }
    std::sort(v.begin(), v.end());
    static constexpr double eps = 0.2;
    for (int i = 1; i < (int)v.size(); i++)
        if (v[i] < v[i - 1] + eps) v[i] = v[i - 1] + eps;
    actions += position_track{.floor = (int)angle_data.size() + 1,
                              .position_offset_x = 5 * cos(start * std::numbers::pi / 180),
                              .position_offset_y = 5 * sin(start * std::numbers::pi / 180)}
                   .to_string();
    actions += set_speed{.floor = (int)angle_data.size() + 1, .beats_per_minute = b}.to_string();
    for (int i = 0; i < (int)v.size(); i++)
        angle_data.push_back(normalize(start + (i & 1) * 180 - v[i]));
}
constexpr void hezi2(double bpm, double duration, const std::vector<double> &hzs,
                     double offset = 360) {
    static double total = 0;
    hezi(bpm, duration, hzs, total, total + offset), total += offset;
}
int main() {
    using namespace notes;
#define B5 AS5
#define B6 AS6

#define E4 DS4
#define E5 DS5
#define E6 DS6

    hezi2(320, 1, {1}, 45);
    hezi2(320, 1, {A4, F5}, 45);
    hezi2(320, 1, {D5, B5}, 45);
    hezi2(320, 1, {F5, C6}, 45);
    hezi2(320, 1, {F5, D6}, 45);
    hezi2(320, 1, {E5, E6}, 45);
    hezi2(320, 1, {F5, D6}, 45);
    hezi2(320, 1, {F5, C6}, 45);

    hezi2(320, 3, {B5}, 0);
    hezi2(320, 3, {F5}, 0);
    hezi2(320, 3, {B5}, 0);

    hezi2(320, 3, {A5}, 720);
    hezi2(320, 2, {B5}, 720);
    hezi2(320, 2, {C6}, 720);
    hezi2(320, 3, {E6}, 720);
    hezi2(320, 3, {D6}, 720);
    hezi2(320, 2, {C6}, 720);

    hezi2(320, 1, {C6}, 3600);
    hezi2(320, 1, {B5}, 3600);
    hezi2(320, 1, {A5}, 3600);
    hezi2(320, 3, {B5}, 3600);
    hezi2(320, 2, {F6}, 3600);
    hezi2(320, 3, {F6}, 3600);
    hezi2(320, 2, {B5}, 3600);
    hezi2(320, 1, {F5}, 3600);
    hezi2(320, 1, {A5}, 3600);
    hezi2(320, 1, {B5}, 3600);

    hezi2(320, 1, {F6}, 30);
    hezi2(320, 1, {E6}, 30);
    hezi2(320, 1, {D6}, 30);
    hezi2(320, 2, {B5}, 30);
    hezi2(320, 1, {F5}, 30);
    hezi2(320, 1, {B5}, 30);
    hezi2(320, 1, {D6}, 30);
    hezi2(320, 1, {E6}, 30);
    hezi2(320, 1, {D6}, 30);
    hezi2(320, 1, {B5}, 30);
    hezi2(320, 2, {F5}, 30);
    hezi2(320, 2, {B5}, 30);
    hezi2(320, 0.5, {A5}, 180);
    hezi2(320, 0.5, {B5}, 180);

    hezi2(320, 1, {C6}, 720);
    hezi2(320, 1, {F5}, 720);
    hezi2(320, 1, {B5}, 720);
    hezi2(320, 1, {C6}, 720);
    hezi2(320, 1, {D6}, 720);
    hezi2(320, 1, {E6}, 720);
    hezi2(320, 1, {D6}, 720);
    hezi2(320, 1, {C6}, 720);
    hezi2(320, 3, {B5}, 0);
    hezi2(320, 3, {F5}, 0);
    hezi2(320, 3, {B5}, 0);

    hezi2(320, 3, {A5}, 3600);
    hezi2(320, 2, {B5}, 3600);
    hezi2(320, 2, {C6}, 3600);
    hezi2(320, 3, {E6}, 3600);
    hezi2(320, 3, {D6}, 3600);
    hezi2(320, 2, {A6}, 3600);

    hezi2(320, 1, {C7}, 90);
    hezi2(320, 1, {B6}, 90);
    hezi2(320, 1, {A6}, 90);
    hezi2(320, 3, {B6}, 90);
    hezi2(320, 1, {D6}, 90);
    hezi2(320, 1, {E6}, 90);
    hezi2(320, 3, {F6}, 90);
    hezi2(320, 2, {B5}, 90);
    hezi2(320, 1, {F5}, 120);
    hezi2(320, 1, {A5}, 120);
    hezi2(320, 1, {B5}, 120);

    hezi2(320, 1, {F6}, 180);
    hezi2(320, 1, {E6}, 180);
    hezi2(320, 1, {D6}, 180);
    hezi2(320, 1, {B5}, 180);
    hezi2(320, 1, {1}, 90);
    hezi2(320, 1, {F5}, 3600);
    hezi2(320, 1, {B5}, 3600);
    hezi2(320, 1, {D6}, 3600);
    hezi2(320, 1, {E6}, 3600);
    hezi2(320, 1, {D6}, 3600);
    hezi2(320, 1, {E6}, 3600);
    hezi2(320, 2, {F6}, 3600);
    hezi2(320, 2, {B5}, 3600);
    hezi2(320, 0.5, {A5}, 90);
    hezi2(320, 0.5, {B5}, 180);

    hezi2(320, 1, {C6}, 0);
    hezi2(320, 1, {F5}, 0);
    hezi2(320, 1, {B5}, 0);
    hezi2(320, 1, {C6}, 0);
    hezi2(320, 1, {D6}, 0);
    hezi2(320, 1, {C6}, 0);
    hezi2(320, 1, {B5}, 0);
    hezi2(320, 1, {A5}, 0);
    hezi2(320, 8, {B5}, 90);

    inject("level.adofai", "level_output.adofai", angle_data, actions, "");
}
