#include <string_view>
namespace masking_type {
inline constexpr std::string_view none = "None";
inline constexpr std::string_view mask = "Mask";
inline constexpr std::string_view visible_inside_mask = "VisibleInsideMask";
inline constexpr std::string_view visible_outside_mask = "VisibleOutsideMask";
} // namespace masking_type
