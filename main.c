#include <stdio.h>
#include <stdlib.h>

typedef void (*ColumnConsumer)(int, int, char*);

void printRow(int rowIndex, int totalColumns, ColumnConsumer colConsumer) {

    char cellBuffer[50];

    for (int colIndex = 0; colIndex < totalColumns; colIndex++) {
        colConsumer(rowIndex, colIndex, cellBuffer);

        printf("%s", cellBuffer);
    }

    printf("\n");
}

// void coordinateFormatConsumer(int row, int col, char* outputBuffer) {
//     sprintf(outputBuffer, "(R%d,C%d)", row, col);
// }
//
// void matrixFormatConsumer(int row, int col, char* outputBuffer) {
//     sprintf(outputBuffer, "[%d-%d]", row, col);
// }

void chessFieldConsumer(int row, int col, char* outputBuffer) {
    if (col == 0) {
        sprintf(outputBuffer, "|  |");
    } else {
        sprintf(outputBuffer, "  |");
    }

}

void chessFieldLineConsumer(int row, int col, char* outputBuffer) {
    sprintf(outputBuffer, "---");

}

int main() {

    int totalColumns = 8;

    // printf("--- Using Coordinate Consumer ---\n");
    //
    // for (int i = 0; i < totalColumns; i++) {
    //     printRow(i, totalColumns, coordinateFormatConsumer);
    // }
    //
    // printf("\n--- Using Matrix Consumer ---\n");
    //
    // for (int i = 0; i < totalColumns; i++) {
    //     printRow(i, totalColumns, matrixFormatConsumer);
    // }

    printf("\n--- Using Chess Consumer ---\n");

    printRow(0, totalColumns, chessFieldLineConsumer);
    for (int i = 0; i < totalColumns; i++) {
        printRow(i, totalColumns, chessFieldConsumer);
        printRow(-1, totalColumns, chessFieldLineConsumer);
    }

    return 0;
}