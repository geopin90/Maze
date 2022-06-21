#pragma once
#include "../Model/InitMaze.h"
#include "../Model/FindPath.h"
#include <QString>

namespace s21 {

class Controller {
 private:
    InitMaze* Model;
 public:
    FindPath* myPath;
    explicit Controller(InitMaze* otherModel);
    ~Controller();
    size_t getRight(int i, int j);
    size_t getBottom(int i, int j);
    void initModel(std::string fName);
    void generateMaze(int height, int width);
    void saveToFile(const QString& filePath);
    InitMaze& getModel();
    int& getCount();
    int& getPValue(int i, int j);
    int& getRoadValH(int pos);
    int& getRoadValV(int pos);
    int getMRows();
    int getMCols();
    Controller(const Controller& other) = delete;
    Controller& operator=(const Controller& other) = delete;
};

}  // namespace s21
