#pragma once

#include "Board.hpp"
#include "Reportable.hpp"
#include <fstream>
#include <iostream>


class ReportFile : public Reportable {
    private:
        Board board;
        std::ofstream _ofs;

    public:
        ReportFile(Board &board, const std::string & filename) : board(board),_ofs(filename)  {}


        void report() override {
            for (const std::string & item : board.getItems())
                _ofs << item << std::endl;
            _ofs << std::endl;
        }
};

class ReportStdout : public Reportable  {
    private:
        Board board;

    public:
        ReportStdout(Board &board) : board(board) {}

        void report() override {
            for (const std::string & item : board.getItems())
                std::cout << item << std::endl;
            std::cout << std::endl;
        }
};



