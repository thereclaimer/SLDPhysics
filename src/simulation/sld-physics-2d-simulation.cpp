#pragma once

#include "sld-physics.hpp" 

namespace sld {

    SLD_API bool
    phys_2d_sim_create(
        phys_2d_sim_t* const sim_2d,
        const u64            reservation_size,
        const u64            arena_size) {

        constexpr u32 phys_arena_size = sizeof()

        bool is_valid = true;
        is_valid &= (sim_2d           != 0);
        is_valid &= (reservation_size != 0);
        is_valid &= (arena_size       != 0);
        assert(is_valid);

        bool is_created = true;
        is_created &= reservation_acquire(sim_2d->res, reservation_size, arena_size, PHYS_TABLE_ARENA_SIZE);
        

    }

    SLD_API bool
    phys_2d_sim_destroy(
        phys_2d_sim_t* const sim_2d) {

    }

    SLD_API bool
    phys_2d_sim_run(
        phys_2d_sim_t* const sim_2d,
        const u64            dt);

    SLD_API bool
    phys_2d_sim_create_entity(
        phys_2d_sim_t* const sim_2d,
        const u32            count,
        const phys_tag_t*    tag) {

    }

    SLD_API bool
    phys_2d_sim_create_entity_particle(
        phys_2d_sim_t* const sim_2d,
        const u32            count,
        const phys_tag_t*    tag,
        const f32            mass) {

    }

    SLD_API bool
    phys_2d_sim_create_entity_static(
        phys_2d_sim_t* const sim_2d,
        const u32            count,
        const phys_tag_t*    tag) {

    }
};