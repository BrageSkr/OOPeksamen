//
// Created by Brage Skrettingland on 25/02/2023.
//
#ifndef EKSAMENOOP_OBSTACLE_HPP
#define EKSAMENOOP_OBSTACLE_HPP

#include "threepp/threepp.hpp"
#include "threepp/extras/imgui/imgui_context.hpp"
#include <array>
#include <string>
#include <iostream>
using namespace threepp;


class obstacle{
public:


    void change_dimensions(float l_1,float w_1){
        width = w_1;
        length = l_1;
    }
    obstacle(float l,float w){
        width = w;
        length = l;
    }
    auto create_geometry(float length,float height,float width);
private:

    float width = 0;
    float height = 1;
    float length = 0;
};

std::array<float,3> return_color(){
    float random_red = math::randomInRange(0,1) ;
    float random_green = math::randomInRange(0,1) ;
    float random_blue = math::randomInRange(0,1) ;
    std::cout <<  random_blue << " " << random_green<< "" << random_red <<std::endl;
    std::array<float,3> random_colors = {random_red, random_green, random_blue};
    return random_colors;
};
auto obstacle::create_geometry (float l,float h,float w){
    auto geometry = BoxGeometry::create(l,h,w);
    auto material = MeshBasicMaterial::create();
    std::array<float,3>random_color  = return_color();
    material->color = Color(random_color[0],random_color[1],random_color[2]);
    auto mesh = Mesh::create(geometry, material);
    mesh->position.x = 0;
    return mesh;
}

#endif //EKSAMENOOP_OBSTACLE_HPP


