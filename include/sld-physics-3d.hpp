#ifndef SLD_PHYSICS_3D_HPP
#define SLD_PHYSICS_3D_HPP

#include "sld-physics.hpp"


namespace sld {

    struct phys_3d_simulation_t;
    struct phys_3d_vector_t;       
    struct phys_3d_translation_t;  
    struct phys_3d_rotation_t;     
    struct phys_3d_scale_t;        
    struct phys_3d_transform_t;  
    struct phys_3d_position_t;     
    struct phys_3d_velocity_t;     
    struct phys_3d_acceleration_t; 
    struct phys_3d_particle_t;     
    struct phys_3d_table_t;
    struct phys_3d_table_position_t;
    struct phys_3d_table_velocity_t;
    struct phys_3d_table_acceleration_t;

    SLD_API bool phys_3d_sim_create              (phys_3d_simulation_t* const sim, const u64 size_reservation, const u64 size_arena);
    SLD_API bool phys_3d_sim_destroy             (phys_3d_simulation_t* const sim);
    SLD_API bool phys_3d_sim_run                 (phys_3d_simulation_t* const sim, const u64 dt);

    SLD_API void phys_3d_particle_entity_create  (phys_3d_simulation_t* const sim, const u32 count, const phys_entity_tag_t* tag, const f32* mass, phys_entity_id_t* id);
    SLD_API void phys_3d_particle_entity_destroy (phys_3d_simulation_t* const sim, const u32 count, const phys_entity_tag_t* tag, const f32* mass, phys_entity_id_t* id);
    
    SLD_API void phys_3d_static_entity_create    (phys_3d_simulation_t* const sim, const u32 count, const phys_entity_tag_t* tag, phys_entity_id_t* id);
    SLD_API void phys_3d_static_entity_destroy   (phys_3d_simulation_t* const sim, const u32 count, const phys_entity_tag_t* tag, phys_entity_id_t* id);

    struct phys_3d_simulation_t {
        phys_reseravation_t* reservation;
        struct {
            phys_table_entity_particle_t* entity_particle;            
            phys_table_entity_static_t*   entity_static;            
        } table;
        phys_memory_stack_t stack;
    };

};

#endif //SLD_PHYSICS_3D_HPP