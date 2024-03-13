
#include "Board.hpp"
#include "Report.hpp"
#include "Reportable.hpp"

void tesNumBoard(NumBoard &n, Reportable &reportable){
    
    n.addNumBoard("item 1");
    n.addNumBoard("item 2");

    reportable.report();
}

void testBoard(Board & b, Reportable &reportable)  {
    std::cout << b.getTitle() << std::endl;
    b.add("item 1");
    b.add("item 2");

    reportable.report();

}

int main() {

    Board b1;
    ReportStdout rstd(b1);
    testBoard(b1, rstd);

    NumBoard n;
    ReportStdout r2(b1);
    tesNumBoard(n, r2); 
    testBoard(n, r2);
 
    return 0;
}

