#ifndef SLD_PHYSICS_HPP
#define SLD_PHYSICS_HPP

#include <sld.hpp>
#include <sld-math.hpp>
#include <sld-memory.hpp>

#ifndef    SLD_PHYSICS_TAG_SIZE
#   define SLD_PHYSICS_TAG_SIZE 32
#endif

namespace sld {

    constexpr u32 PHYS_TAG_SIZE = SLD_PHYSICS_TAG_SIZE;

    struct phys_entity_t;
    struct phys_entity_particle_t;
    struct phys_entity_static_t;
    struct phys_entity_id_t        : u32_t { };
    struct phys_entity_archetype_t : u32_t { };
    struct phys_entity_tag_t;
    struct phys_arena_t;

    struct phys_2d_sim_t; // 2D Simulation
    struct phys_2d_pos_t; // 2D Position
    struct phys_2d_vel_t; // 2D Velocity
    struct phys_2d_acc_t; // 2D Acceleration
    struct phys_2d_prt_t; // 2D Particle 

    struct phys_3d_sim_t; // 3D Simulation
    struct phys_3d_pos_t; // 3D Position
    struct phys_3d_vel_t; // 3D Velocity
    struct phys_3d_acc_t; // 3D Acceleration
    struct phys_3d_prt_t; // 3D Particle 

    struct phys_entiy_tag_t {
        cchar buffer[PHYS_TAG_SIZE];
    };

    struct phys_entity_t {
        phys_entity_id_t        id;
        phys_entity_archetype_t archetype;
        phys_entity_tag_t       tag;
    };

    struct phys_entity_particle_t : phys_entity_t {
        f32 mass;
    };

    struct phys_entity_static_t : phys_entity_t { };

    enum phys_attrib_flag_e32 {
        phys_attrib_flag_e32_none = 0,
        phys_attrib_flag_e32_pos  = sld::bit_value(1),
        phys_attrib_flag_e32_vel  = sld::bit_value(2),
        phys_attrib_flag_e32_acc  = sld::bit_value(3),
    };

    bool phys_2d_sim_create                 (phys_2d_sim_t* const sim_2d, const u64 reservation_size, const u64 arena_size);
    bool phys_2d_sim_destroy                (phys_2d_sim_t* const sim_2d);
    bool phys_2d_sim_run                    (phys_2d_sim_t* const sim_2d, const u64 dt);
    bool phys_2d_sim_create_entity          (phys_2d_sim_t* const sim_2d, const u32 count, const phys_tag_t* tag);
    bool phys_2d_sim_create_entity_particle (phys_2d_sim_t* const sim_2d, const u32 count, const phys_tag_t* tag, const f32 mass = 1.0f);
    bool phys_2d_sim_create_entity_static   (phys_2d_sim_t* const sim_2d, const u32 count, const phys_tag_t* tag);

    bool phys_3d_sim_create                 (phys_3d_sim_t* const sim_3d, const u64 reservation_size, const u64 arena_size);
    bool phys_3d_sim_destroy                (phys_3d_sim_t* const sim_3d);
    bool phys_3d_sim_run                    (phys_3d_sim_t* const sim_3d, const u64 dt);
    bool phys_3d_sim_create_entity          (phys_3d_sim_t* const sim_3d, const u32 count, const phys_tag_t* tag);
    bool phys_3d_sim_create_entity_particle (phys_3d_sim_t* const sim_2d, const u32 count, const phys_tag_t* tag, const f32 mass = 1.0f);
    bool phys_3d_sim_create_entity_static   (phys_3d_sim_t* const sim_2d, const u32 count, const phys_tag_t* tag);

 
    struct phys_table_t : arena_t {
        u32                 row_stride;
        u32                 row_count;
        phys_table_arena_t* next_table;
        phys_table_arena_t* prev_table;
        phys_entity_id_t*   id;
    };

    struct phys_table_entity_t : phys_table_t {
        phys_entity_archetype_t* archetype;
        phys_entity_tag_t*       tag;
    };

    struct phys_table_2d_t : phys_table_t {
        f32* x;
        f32* y;
    };

    struct phys_table_2d_pos_t : phys_table_2d_t { }
    struct phys_table_2d_vel_t : phys_table_2d_t { }; 
    struct phys_table_2d_acc_t : phys_table_2d_t { }; 

    struct phys_2d_tables {
        phys_table_2d_pos_t* pos;
        phys_table_2d_vel_t* vel;
        phys_table_2d_acc_t* acc;
    };

    struct phys_2d_sim_t {
        reservation_t* res;
        struct {
            phys_table_entity_t* ent;
            phys_table_2d_pos_t* pos;
            phys_table_2d_vel_t* vel;
            phys_table_2d_acc_t* acc;
        } tables;
    };
};

#endif //SLD_PHYSICS_HPP