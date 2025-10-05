#ifndef SLD_PHYSICS_HPP
#define SLD_PHYSICS_HPP

#include <sld.hpp>
#include <sld-math.hpp>

#ifndef    SLD_PHYSICS_ENTITY_STACK_SIZE_KB
#   define SLD_PHYSICS_ENTITY_STACK_SIZE_KB 64
#endif
#ifndef     SLD_PHYSICS_TAG_SIZE
    #define SLD_PHYSICS_TAG_SIZE            32
#endif
namespace sld {

    struct phys_entity_t     : u32_t { };
    struct phys_components_t : u32_t { };
    struct phys_tag_t;

    enum phys_component_e32 {
        phys_component_e32_none         = 0,
        phys_component_e32_position     = sld::bit_value(1),
        phys_component_e32_velocity     = sld::bit_value(2),
        phys_component_e32_acceleration = sld::bit_value(3),
        phys_component_e32_mass         = sld::bit_value(4)
    };

    struct phys_mass_t;

    struct phys_2d_simulation_t;
    struct phys_2d_position_t;
    struct phys_2d_velocity_t;
    struct phys_2d_acceleration_t;

    struct phys_3d_simulation_t;
    struct phys_3d_position_t;
    struct phys_3d_velocity_t;
    struct phys_3d_acceleration_t;

    phys_2d_simulation_t* phys_2d_simulation_create(const u64 reservation_size, const u64 arena_size);


};

#endif //SLD_PHYSICS_HPP