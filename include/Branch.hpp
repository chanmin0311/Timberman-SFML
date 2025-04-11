// Branch.hpp
#pragma once
#ifndef BRANCH_HPP
#define BRANCH_HPP

#include <SFML/Graphics.hpp>
#include <random>

// Constants for the branch type
const int NUM_BRANCHES = 6;

// Enum for the branch and player position
enum class side { LEFT, RIGHT, NONE };

// Branch class
class Branch {
   public:
    Branch();

    void update();
    void render(sf::RenderWindow& window);
    void updateBranches();

    // Getters
    side getBranchPosition(int index) const;

    // Setters
    void setBranchPosition(int index, side side);

   private:
    sf::Texture mBranchTexture;
    sf::Sprite mBranchSprite[NUM_BRANCHES];
    side mBranchPosition[NUM_BRANCHES];

    std::mt19937 mRng;
    std::uniform_int_distribution<int> mDist;
};

#endif  // BRANCH_HPP