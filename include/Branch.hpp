// Branch.hpp
#pragma once
#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <SFML/Graphics.hpp>
#include <random>

// Constants for the branch type
const int NUM_BRANCHES = 6;

// Enum for the branch position
namespace branchPosition {
enum class side { LEFT, RIGHT, NONE };
}

// Branch class
class Branch {
   public:
    Branch();

    void update();
    void render(sf::RenderWindow& window);
    void updateBranches(int seed_value);

    // Getters
    branchPosition::side getBranchPosition(int index) const;

    // Setters
    void setBranchPosition(int index, branchPosition::side side);

   private:
    sf::Texture mBranchTexture;
    sf::Sprite mBranchSprite[NUM_BRANCHES];
    branchPosition::side mBranchPosition[NUM_BRANCHES];
};

#endif  // BRANCH_HPP