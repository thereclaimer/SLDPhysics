#ifndef SLD_PHYSICS_2D_HPP
#define SLD_PHYSICS_2D_HPP

#include <sld.hpp>

namespace sld {

    struct phys_2d_sim_t; // 2D Simulation
    struct phys_2d_pos_t; // 2D Position
    struct phys_2d_vel_t; // 2D Velocity
    struct phys_2d_acc_t; // 2D Acceleration
    struct phys_2d_prt_t; // 2D Particle 

    SLD_API bool phys_2d_sim_create  (phys_2d_sim_t* const sim_2d, const u64 reservation_size, const u64 arena_size);
    SLD_API bool phys_2d_sim_destroy (phys_2d_sim_t* const sim_2d);
    SLD_API bool phys_2d_sim_run     (phys_2d_sim_t* const sim_2d, const u64 dt);

};

#endif //SLD_PHYSICS_2D_HPP