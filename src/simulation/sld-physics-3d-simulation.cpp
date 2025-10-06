#pragma once

#include "sld-physics-3d.hpp"

namespace sld {

    SLD_API bool
    phys_3d_sim_create(
        phys_3d_simulation_t* const sim,
        const u64                   size_reservation,
        const u64                   size_arena) {

        // check args
        bool can_create = true;
        can_create &= (sim              != NULL);
        can_create &= (size_reservation != 0);
        can_create &= (size_arena       >= PHYS_SIZE_ARENA_MIN);
        assert(can_create);

        // initialize the stack
        sim->stack.start    = (addr)&sim->stack.memory[0];
        sim->stack.size     = PHYS_SIZE_STACK_MEMORY;
        sim->stack.position = 0;
        sim->stack.save     = 0;
        can_create &= stack_validate(sim->stack);
        assert(can_create);

        // do stack allocations and reserve memory
        sim->reservation = (reservation_t*)stack_push(sim->stack, sizeof(reservation_t));
        can_create &= (sim->reservation != NULL);
        can_create &= reservation_acquire(sim->reservation, size_reservation, size_arena, PHYS_SIZE_ARENA_HEADER);
        assert(can_create);

        // commit the tables
        
    }

    SLD_API bool
    phys_3d_sim_destroy(
        phys_3d_simulation_t* const sim) {

    }

    SLD_API bool
    phys_3d_sim_run(
        phys_3d_simulation_t* const sim,
        const u64                   dt) {

    }
};