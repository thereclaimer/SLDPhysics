#pragma once

#include "sld-physics-3d.hpp"

namespace sld {

    phys_table_entity_particle_t* phys_3d_particle_entity_commit_table(phys_3d_simulation_t* const sim);

    SLD_API void
    phys_3d_particle_entity_create(
        phys_3d_simulation_t* const sim,
        const u32                   count,
        const phys_entity_tag_t*    tag,
        phys_entity_id_t*           id) {

    }

    SLD_API void
    phys_3d_particle_entity_destroy(
        phys_3d_simulation_t* const sim,
        const u32                   count,
        const phys_entity_tag_t*    tag,
        phys_entity_id_t*           id) {

    }

    SLD_FUNC phys_table_entity_particle_t*
    phys_3d_particle_entity_commit_table(
        phys_3d_simulation_t* const sim) {

        // attempt to commit an arena
        phys_memory_arena_t* arena = (phys_memory_arena_t*)arena_commit(sim->reservation);
        assert(arena);

        const u32 stride     = sizeof(phys_entity_particle_t);
        const u32 size_table = sizeof(phys_table_entity_particle_t)
        const u32 capacity   = arena_size_free(table) - size_table; 
        const u32 size_id    = capacity * sizeof(phys_entity_id_t);
        const u32 size_tag   = capacity * sizeof(phys_entity_tag_t);

        phys_table_entity_particle_t* table = (phys_table_entity_particle_t*) arena_push_bytes (arena, sizeof(phys_table_entity_particle_t));        
        phys_entity_id_t*             id    =             (phys_entity_id_t*) arena_push_bytes (arena, size_id);
        phys_entity_tag_t*            tag   =            (phys_entity_tag_t*) arena_push_bytes (arena, size_tag);

        bool is_valid = true;
        is_valid &= (table);
        is_valid &= (id);
        is_valid &= (tag);
        assert(is_valid);

        // clear the tag array
        (void)memset((void*)tag, 0, size_tag);

        // initialize the table
        table->arena       = arena;
        table->next        = NULL;
        table->prev        = NULL;
        table->index_start = 0;
        table->index_end   = capacity - 1;
        table->capacity    = capacity;
        table->stride      = stride;
        table->id          = id;
        table->tag         = tag;

        // if this is the first table, add it to the list and return
        if (sim->table.entity_particle == NULL) {
            sim->table.entity_particle = table;
            return(table);
        } 

        // otherwise, find the list tail
        phys_table_entity_particle_t* tail = NULL;
        for (
            tail = sim->table.entity_particle;
            tail != NULL && tail->next != NULL;
            tail = tail->next);
        assert(end);

        // update the indexes and make this new table the tail
        table->index_start = tail->index_end + 1;
        table->index_end   = tail->index_end + capacity;
        table->prev        = tail;
        tail->next         = table; 
        return(table);
    }


};