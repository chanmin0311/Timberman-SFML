// Branch.cpp
#include "../include/Branch.hpp"

Branch::Branch() : mRng(std::random_device{}()), mDist(0, 4) {
    if (!mBranchTexture.loadFromFile("../assets/images/branch.png")) {
        throw std::runtime_error("Failed to load branch texture");
    }

    for (int i = 0; i < NUM_BRANCHES; i++) {
        mBranchSprite[i].setTexture(mBranchTexture);
        mBranchSprite[i].setPosition(-2000, -2000);
        mBranchSprite[i].setOrigin(220, 20);
        mBranchPosition[i] = side::NONE;
    }
}

void Branch::update() {
    for (int i = 0; i < NUM_BRANCHES; i++) {
        float height = i * 150;
        if (mBranchPosition[i] == side::LEFT) {
            mBranchSprite[i].setPosition(610, height);
            mBranchSprite[i].setRotation(180);
        } else if (mBranchPosition[i] == side::RIGHT) {
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

void Branch::updateBranches() {
    for (int j = NUM_BRANCHES - 1; j > 0; j--) {
        mBranchPosition[j] = mBranchPosition[j - 1];
    }

    int rand_int = mDist(mRng);
    switch (rand_int) {
        case 0:
            mBranchPosition[0] = side::LEFT;
            break;
        case 1:
            mBranchPosition[0] = side::RIGHT;
            break;
        default:
            mBranchPosition[0] = side::NONE;
            break;
    }
}

// Getter and setter
side Branch::getBranchPosition(int index) const { return mBranchPosition[index]; }

void Branch::setBranchPosition(int index, side side) { mBranchPosition[index] = side; }