#include "../src/Maze/Model/FindPath.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(maze_case, generate_test) {
    s21::InitMaze myMaze;
    myMaze.ellersAlhoritm(5, 4);
    ASSERT_EQ(myMaze.getMazeRows(), 5);
    ASSERT_EQ(myMaze.getMazeCols(), 4);
}

TEST(maze_case, open_test) {
    s21::InitMaze myMaze;
    myMaze.initByFile("./Maze/m4x4.txt");
    ASSERT_EQ(myMaze.getMazeRows(), 4);
    ASSERT_EQ(myMaze.getMazeCols(), 4);
}

TEST(maze_case, find_test) {
    std::vector<s21::roadPoint> checkPath{{5,5}, {4, 5}, {4,6}, {3,6}, {3,5}, {3,4}
    , {4,4}, {4,3}, {3,3}, {3,2}, {3,1}, {2,1}, {2, 2}, {1,2}, {0,2}, {0,1}, {0,0}};
    s21::InitMaze myMaze;
    myMaze.initByFile("./Maze/m10x10.txt");
    s21::FindPath myPath(&myMaze);
    myPath.fillPath(0, 0);
    myPath.waveAlhoritm(5, 5);
    for (int i = 0; i < myPath.getNewCount(); i++) {
        ASSERT_EQ(checkPath.data()[i].vert, myPath.getRoadValueV(i));
        ASSERT_EQ(checkPath.data()[i].horiz, myPath.getRoadValueH(i));
    }
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}