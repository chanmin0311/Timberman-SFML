// Branch.cpp
#include "../include/Branch.hpp"

Branch::Branch() {
    if (!mBranchTexture.loadFromFile("../assets/images/branch.png")) {
        throw std::runtime_error("Failed to load branch texture");
    }

    for (int i = 0; i < NUM_BRANCHES; i++) {
        mBranchSprite[i].setTexture(mBranchTexture);
        mBranchSprite[i].setPosition(-2000, -2000);
        mBranchSprite[i].setOrigin(220, 20);
    }
}

void Branch::update() {
    for (int i = 0; i < NUM_BRANCHES; i++) {
        float height = i * 150;
        if (mBranchPosition[i] == branchPosition::side::LEFT) {
            mBranchSprite[i].setPosition(610, height);
            mBranchSprite[i].setRotation(180);
        } else if (mBranchPosition[i] == branchPosition::side::RIGHT) {
            mBranchSprite[i].setPosition(1330, height);
            mBranchSprite[i].setRotation(0);
        } else {
            mBranchSprite[i].setPosition(3000, height);
        }
    }
}

void Branch::render(sf::RenderWindow& window) {
    for (auto& branch : mBranchSprite) {
        window.draw(branch);
    }
}

void Branch::updateBranches(int seed_value) {
    for (int j = NUM_BRANCHES - 1; j > 0; j--) {
        mBranchPosition[j] = mBranchPosition[j - 1];
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 3);
    int rand_int = dist(gen) * seed_value;
    switch (rand_int) {
        case 0:
            mBranchPosition[0] = branchPosition::side::LEFT;
            break;
        case 1:
            mBranchPosition[0] = branchPosition::side::RIGHT;
            break;
        default:
            mBranchPosition[0] = branchPosition::side::NONE;
            break;
    }
}

// Getter and setter
branchPosition::side Branch::getBranchPosition(int index) const { return mBranchPosition[index]; }

void Branch::setBranchPosition(int index, branchPosition::side side) {
    mBranchPosition[index] = side;
}