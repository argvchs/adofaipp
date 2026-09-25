#include "../attributes.h"
#include "../utils.h"
struct add_decoration {
    std::optional<int> floor = std::nullopt;
    std::optional<bool> visible = std::nullopt;
    std::optional<bool> locked = std::nullopt;
    std::string_view decoration_image = "";
    std::string_view tag = "";
    float position_x = 0;
    float position_y = 0;
    std::string_view relative_to = relative_to::global;
    bool stick_to_floor = false;
    float pivot_offset_x = 0;
    float pivot_offset_y = 0;
    float rotation = 0;
    bool lock_rotation = false;
    float scale_x = 100;
    float scale_y = 100;
    bool lock_scale = false;
    int tile_x = 1;
    int tile_y = 1;
    std::string_view color = "ffffff";
    float opacity = 100;
    int depth = -1;
    bool sync_floor_depth = false;
    float parallax_x = 0;
    float parallax_y = 0;
    float parallax_offset_x = 0;
    float parallax_offset_y = 0;
    bool image_smoothing = true;
    std::string_view blend_mode = blend_mode::none;
    std::string_view masking_type = masking_type::none;
    std::string_view masking_target = "";
    bool use_masking_depth = false;
    int masking_front_depth = -1;
    int masking_back_depth = -1;
    std::string_view hitbox = hitbox::none;
    std::string_view hitbox_trigger_type = hitbox_trigger_type::once;
    float hitbox_repeat_interval = 1000;
    std::string_view hitbox_event_tag = "";
    std::string_view hitbox_detect_target = hitbox_detect_target::planet;
    std::string_view hitbox_target_planet = hitbox_target_planet::any;
    std::string_view hitbox_deco_tag = "";
    std::string_view fail_hitbox_type = fail_hitbox_type::box;
    float fail_hitbox_scale_x = 100;
    float fail_hitbox_scale_y = 100;
    float fail_hitbox_offset_x = 0;
    float fail_hitbox_offset_y = 0;
    float fail_hitbox_rotation = 0;
    std::string_view components = "";
    constexpr std::string to_string() const {
        return std::format(
            R"({{{}"eventType":"AddDecoration",{}{}"decorationImage":"{}","tag":"{}","position":[{},{}],"relativeTo":"{}","stickToFloor":{},"pivotOffset":[{},{}],"rotation":{},"lockRotation":{},"scale":[{},{}],"lockScale":{},"tile":[{},{}],"color":"{}","opacity":{},"depth":{},"syncFloorDepth":{},"parallax":[{},{}],"parallaxOffset":[{},{}],"imageSmoothing":{},"blendMode":"{}","maskingType":"{}","maskingTarget":"{}","useMaskingDepth":{},"maskingFrontDepth":{},"maskingBackDepth":{},"hitbox":"{}","hitboxTriggerType":"{}","hitboxRepeatInterval":{},"hitboxEventTag":"{}","hitboxDetectTarget":"{}","hitboxTargetPlanet":"{}","hitboxDecoTag":"{}","failHitboxType":"{}","failHitboxScale":[{},{}],"failHitboxOffset":[{},{}],"failHitboxRotation":{},"components":"{}"}},)",
            get_kv("floor", floor), get_kv("visible", visible), get_kv("locked", locked),
            decoration_image, tag, position_x, position_y, relative_to, stick_to_floor,
            pivot_offset_x, pivot_offset_y, rotation, lock_rotation, scale_x, scale_y, lock_scale,
            tile_x, tile_y, color, opacity, depth, sync_floor_depth, parallax_x, parallax_y,
            parallax_offset_x, parallax_offset_y, image_smoothing, blend_mode, masking_type,
            masking_target, use_masking_depth, masking_front_depth, masking_back_depth, hitbox,
            hitbox_trigger_type, hitbox_repeat_interval, hitbox_event_tag, hitbox_detect_target,
            hitbox_target_planet, hitbox_deco_tag, fail_hitbox_type, fail_hitbox_scale_x,
            fail_hitbox_scale_y, fail_hitbox_offset_x, fail_hitbox_offset_y, fail_hitbox_rotation,
            components);
    }
};
