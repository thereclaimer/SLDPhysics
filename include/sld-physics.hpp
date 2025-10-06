#ifndef SLD_PHYSICS_HPP
#define SLD_PHYSICS_HPP

#include <sld.hpp>
#include <sld-math.hpp>
#include <sld-memory.hpp>

#ifndef    SLD_PHYSICS_TAG_SIZE
#   define SLD_PHYSICS_TAG_SIZE             32
#endif
#ifndef    SLD_PHYSICS_STACK_MEMORY_SIZE_KB 
#   define SLD_PHYSICS_STACK_MEMORY_SIZE_KB 64
#endif
#ifndef    SLD_PHYSICS_ARENA_HEADER_SIZE
#   define SLD_PHYSICS_ARENA_HEADER_SIZE    512
#endif
#ifndef    SLD_PHYSICS_ENTITY_ID_INVALID
#   define SLD_PHYSICS_ENTITY_ID_INVALID    0x00000000
#endif

namespace sld {

    constexpr u32 PHYS_SIZE_TAG          = SLD_PHYSICS_TAG_SIZE;
    constexpr u32 PHYS_SIZE_STACK_MEMORY = size_kilobytes(SLD_PHYSICS_STACK_MEMORY_SIZE_KB); 
    constexpr u32 PHYS_SIZE_ARENA_HEADER = SLD_PHYSICS_ARENA_HEADER_SIZE; 
    constexpr u32 PHYS_SIZE_ARENA_MIN    = sizeof(SLD_PHYSICS_ARENA_HEADER_SIZE * 2); // at least twice the header size 

    struct phys_memory_arena_t;
    struct phys_memory_reseravation_t;
    struct phys_memory_stack_t;

    struct phys_entity_t;
    struct phys_entity_id_t;
    struct phys_entity_tag_t;
    struct phys_entity_particle_t;
    struct phys_entity_static_t;

    struct phys_table_t;
    struct phys_table_entity_static_t;
    struct phys_table_entity_particle_t;

    struct phys_memory_reservation_t : reservation_t { };
    struct phys_memory_arena_t       : arena_t { };
    struct phys_memory_stack_t       : stack_t {
        byte memory[PHYS_SIZE_STACK_MEMORY];
    };

    struct phys_entiy_tag_t {
        cchar buffer[PHYS_TAG_SIZE];
    };

    struct phys_entity_t {
        phys_entity_id_t         id;
        const phys_entity_tag_t* tag;
    };

    struct phys_entity_particle_t : phys_entity_t { f32 mass; };
    struct phys_entity_static_t   : phys_entity_t { };

    struct phys_table_t {
        phys_memory_arena_t* arena;
        phys_table_t*        next;
        phys_table_t*        prev;
        u32                  index_start;
        u32                  index_end;
        u32                  capacity;
        u32                  stride;
        phys_entity_id_t*    id;
    };

    struct phys_table_entity_static_t : phys_table_t {
        phys_entity_tag_t* tag;                
    };

    struct phys_table_entity_particle_t : phys_table_t {
        phys_entity_tag_t* tag;
        f32*               mass;
    };

};

#endif //SLD_PHYSICS_HPP